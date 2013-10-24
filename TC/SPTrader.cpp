#include "SPTrader.h"

#pragma comment(lib,"ws2_32.lib")
#ifndef Q_MOC_RUN
#include <boost/lexical_cast.hpp>
#endif
#include "asio_helper.h"
#include "socket_helper.h"
#include "sptrader/sptrader_order.h"
#include "sptrader/sptrader_ticker.h"
#include "string_processor.h"

using std::thread;
using boost::lexical_cast;
using namespace boost::posix_time;

// changed by xie, 非单例化
SPTrader::SPTrader(
    PlatformInfo& platformInfo)
    : Dispatcher(), platformInfo_(platformInfo), check_timer_(io_service_)
{
    hPriceThread = INVALID_HANDLE_VALUE;
    quoteEvent = doneTradeEvent = curOrderEvent = NULL;
    timerInterval = 3;

    order_ = nullptr;
    io_service_thread_ = nullptr;
}

SPTrader::~SPTrader()
{
    if (order_)delete order_;
    if (io_service_thread_)
    {
        io_service_thread_->join();
        delete io_service_thread_;
    }
}

SPTrader* SPTrader::GetSPTrader(PlatformInfo& platformInfo)
{
    SPTrader *sp_trader = new SPTrader(platformInfo);
    sp_trader->startOrderThread();
    int return_code = sp_trader->login();
    if (return_code != 0)
    {
        delete sp_trader;
        return nullptr;
    }
    sp_trader->order_->Do();
    sp_trader->startCheckConnection();
    sp_trader->startPriceThread();
    sp_trader->startTickerThread();
    return sp_trader;
}

// added by xie
//bool SPTrader::requestLinkState(LinkID linkID)
//{
//LogHandler::getLogHandler().alert(1, "Connection status", "Send message for checking connection status failed!");
//}

int SPTrader::login()
{
    int return_code = order_->Login(platformInfo_.accountNo, platformInfo_.password, platformInfo_.server);
    return return_code;
}

void SPTrader::startOrderThread()
{
    tcp::resolver resolver(io_service_);
    tcp::resolver::query query(platformInfo_.server, to_string(platformInfo_.orderPort));
    auto endpoint_iterator = resolver.resolve(query);
    order_ = new SPTraderOrder(io_service_, endpoint_iterator, *this);
}

HANDLE SPTrader::startPriceThread()
{
    initPriceConnection();
    hPriceThread = CreateThread(NULL, 0, this->priceThreadAdapter, this, 0, &priceThreadId);
    return hPriceThread;
}

// added by xie
void SPTrader::startCheckConnection()
{
    check_timer_.expires_from_now(boost::posix_time::seconds(timerInterval));
    check_timer_.async_wait(
        [this](const boost::system::error_code& ec)
    {
        HitCheckConnection();
    });
}

void SPTrader::HitCheckConnection()
{
    checkConnection();
    check_timer_.expires_at(check_timer_.expires_at() + boost::posix_time::seconds(timerInterval));
    check_timer_.async_wait(
        [this](const boost::system::error_code& ec)
    {
        HitCheckConnection();
    });
}

/**
*检查与服务器的连接情况 by xie
*/
void SPTrader::checkConnection()
{
    map<LinkID, string> linkInfo;
    linkInfo[TRANSACTION_CLIENT_LINK] = "Transaction client link";
    //linkInfo[TRANSACTION_ADMIN_LINK] = "Transaction admin link";
    linkInfo[PRICE_LINK] = "Price link";
    //linkInfo[LONG_DEPTH_LINK] = "Long depth link";
    //linkInfo[INFORMATION_LINK] = "Information link";
    //linkInfo[MARGIN_CHECK_LINK] = "Margin check link";

    //LogHandler::getLogHandler().log("3 seconds-----------");
    for (auto it : linkInfo) {
        order_->RequestLinkState(it.first);
        //LogHandler::getLogHandler().log("Check " + it->second);
    }
}

// added by xie
void SPTrader::startTickerThread()
{
    tcp::resolver resolver(io_service_);
    tcp::resolver::query query(platformInfo_.server, to_string(platformInfo_.tickPort));
    auto endpoint_iterator = resolver.resolve(query);
    ticker_ = new SPTraderTicker(io_service_, endpoint_iterator, *this);
    io_service_thread_ = new std::thread([this](){ io_service_.run(); });
}

DWORD WINAPI SPTrader::priceThreadAdapter(LPVOID lpParam)
{
    SPTrader *spoi = (SPTrader *)lpParam;
    spoi->processPrice();
    return 0;
}

void SPTrader::stopOrderThread()
{
    delete order_;
    order_ = nullptr;
}

int SPTrader::initPriceConnection()
{
    cout << "begin price connection......" << endl;
    priceSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == priceSocket){
        cout << "Creating price socket  failed, Exit!" << endl;
        return -1;
    }
    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    addr.sin_addr.s_addr = inet_addr(platformInfo_.server.c_str());
    addr.sin_port = htons(platformInfo_.pricePort);

    if (SOCKET_ERROR == connect(priceSocket, (sockaddr*)&addr, sizeof(addr))){
        int ec = WSAGetLastError();
        cout << "connecting to price 8089 port failed, exit!" << ec << endl;
        closesocket(priceSocket);
        return -1;
    }
    else{
        cout << "establish price connection  successfully!" << endl;
        return 0;
    }
}

//int SPTrader::initTickConnection()
//{
//"begin tick connection......" << endl;
//"Creating price socket  failed, Exit!" << endl;
//connecting to price 8089 port failed, exit!"<<endl;
//LogHandler::getLogHandler().alert(3, "Socket error", "connecting to ticker port failed, exit!");
//LogHandler::getLogHandler().log("establish tick connection  successfully!");
//Send ORDER orders error, please check the order socket!"<<endl;
//}

int SPTrader::addQuote(QuoteItem *pQuoteItem)
{
    string quoteId = pQuoteItem->getQuoteId();

    quoteEvent = CreateEvent(NULL, FALSE, FALSE, L"ADD_QUOTE");
    string quotemsg = "4107,0," + quoteId + "\r\n";		  // 4107 msg is to request the price 
    if (send(priceSocket, quotemsg.c_str(), quotemsg.length(), 0) < 0)
    {
        cout << "Send price update msgid error, please check the connection to server!" << endl;
        return MY_ERROR;
    }

    ticker_->Request(quoteId);
    // added by xie
    //// 这里为什么socket 会还是0呢？线程应该早就启动了
    //LogHandler::getLogHandler().alert(3, "Add quote", "Request tick price failed for new quote!");
    WaitForSingleObject(quoteEvent, INFINITE);
    CloseHandle(quoteEvent);
    LogHandler::getLogHandler().log("Quote is added:" + quoteId);
    return SUCCESS;
}

int SPTrader::sendOrder(OrderItem* pOrderItem)
{
    int len = 0;
    if (connectStatus == true){
        string orderStr = StringProcessor::OrderItemToString(pOrderItem, platformInfo_.accountNo);
        //LogHandler::getLogHandler().log(orderStr);
        pOrderItem->log();
        order_->Send(orderStr);
    }
    else
    {
        cout << "Connection to SPTrader is not established or broken!" << endl;
    }
    return len;
}

int SPTrader::confirmTradeInfo(int tradeRecordNo)
{
    int len = 0;
    if (connectStatus == true){
        string confirm_str = "3109,3," + to_string(tradeRecordNo) + "\r\n";
        order_->Send(confirm_str);
    }
    else
    {
        cout << "Connection to SPTrader is not established or broken!" << endl;
    }
    return len;
}

int SPTrader::confirmPriceInfo(string quoteId)
{
    string priceRep = "4102,3," + quoteId + ",0\r\n";
    order_->Send(priceRep);
    //        LogHandler::getLogHandler().alert(3, "Price request", 
    //        "Send price reply error, please check the connection to server!");
    return 0;
}

bool SPTrader::isSupport(int orderType)
{
    if (orderType == LMT)
        return true;
    else
        return false;
}

OrderItem* SPTrader::str2UpdatedOrder(string orderStr)
{
    OrderItem* oi = new OrderItem();
    int start = 7;
    orderStr += ",";
    int end = orderStr.find(",", start);
    string str = "";
    int cur = 3;
    while (end != string::npos){
        str = orderStr.substr(start, end - start);
        switch (cur) {
        case 3:	oi->setStatus(atoi(str.c_str())); break;
        case 4: oi->setAccount(str); break;
        case 5: oi->setOrderNo(atoi(str.c_str())); break;
        case 6: oi->setQuoteId(str.c_str()); break;
        case 7: oi->setBuySell(str[0]); break;
        case 8: oi->setOriginalPrice(atof(str.c_str())); break;
        case 9: oi->setOriginalQty(atof(str.c_str())); break;
        case 10: oi->setOpenClose(str); break;
        case 11: oi->setOrderType(atoi(str.c_str())); break;
        case 12: oi->setValidType(atoi(str.c_str())); break;
        case 13: oi->setValidTime(atoi(str.c_str())); break;
        }
        start = end + 1;
        end = orderStr.find(",", start);
        cur++;
    }
    return oi;
}

int SPTrader::deleteQuote(QuoteItem *pQuoteItem)
{
    string quoteId = pQuoteItem->getQuoteId();

    quoteEvent = CreateEvent(NULL, FALSE, FALSE, L"DELETE_QUOTE");
    string quotemsg = string("4108,0,") + quoteId + "\r\n";  // 4108 msg is to stop the price update
    if (send(priceSocket, quotemsg.c_str(), quotemsg.length(), 0) < 0)
    {
        cout << "Send price release msgid error, please check the connection to server!" << endl;
        return -1;
    }

    // added by xie
    ticker_->Release(quoteId);
    //LogHandler::getLogHandler().alert(3, "Delete quote", "Cancel tick price failed!");
    WaitForSingleObject(quoteEvent, INFINITE);
    CloseHandle(quoteEvent);
    LogHandler::getLogHandler().log("Quote is deleted:" + quoteId);
    return 0;
}

map<int, TradeItem*>& SPTrader::getDoneTrades()
{
    doneTradeEvent = CreateEvent(NULL, FALSE, FALSE, L"GET_TRADE_DONE_LIST");
    string msg = "3181,0\r\n";
    order_->Send(msg);
    //        LogHandler::getLogHandler().alert(3, "Load done trade", "Load done trade failed!");
    return doneTrades;
    WaitForSingleObject(doneTradeEvent, INFINITE);
    CloseHandle(doneTradeEvent);
    doneTradeEvent = NULL;
    return doneTrades;
}

map<int, OrderItem*>& SPTrader::getCurrentOrders()
{
    curOrderEvent = CreateEvent(NULL, FALSE, FALSE, L"LOAD_ORDER_BOOK");
    string msg = "3186,0\r\n";
    //string get = AsioHelper::Get(msg);
    //if (send(orderSocket, msg.c_str(), msg.length(), 0) < 0) {
    LogHandler::getLogHandler().alert(3, "Load order book", "Load order book failed!");
    return currentOrders;
    //}
    WaitForSingleObject(curOrderEvent, INFINITE);
    CloseHandle(curOrderEvent);
    curOrderEvent = NULL;
    return currentOrders;
}

void SPTrader::getPosition(Position& position)
{
    string quoteID = position.getQuoteId();
    //LogHandler::getLogHandler().log("create position event(" + quoteID + ")");
    position = order_->GetPosition(quoteID, platformInfo_.accountNo);
    //LogHandler::getLogHandler().alert(3, "Load position", "Load position failed!");
    //LogHandler::getLogHandler().log("release position event(" + quoteID + ")");
}

void SPTrader::processPrice()
{
    char buff[300] = "";
    int pkglen = 0;
    string rmd = "", priceStr = "";
    while (true)
    {
        if (connectStatus != true){
            continue;
        }
        pkglen = recv(priceSocket, buff, sizeof(buff), 0);
        if (pkglen < 0){
            cout << "receive price data failed, exit!" << endl;
            break;
        }
        buff[pkglen] = 0;
        //if price is correctly received, then reply to server  a 4102 message
        int start = 0;
        priceStr = "";
        string tmp(buff);
        while (true)
        {
            int end = tmp.find("\r\n", start);
            if (end == string::npos){
                rmd = tmp.substr(start, pkglen - start);
                break;
            }
            priceStr = tmp.substr(start, end - start);

            if (start == 0)
                priceStr = rmd + priceStr;

            if (priceStr.find("4107,3", 0) != string::npos && quoteEvent != NULL)
            {
                //LogHandler::getLogHandler().log("Quote is added");
                SetEvent(quoteEvent);
            }
            else if (priceStr.find("4108,3", 0) != string::npos &&  quoteEvent != NULL)
            {
                //LogHandler::getLogHandler().log("Quote is deleted");
                SetEvent(quoteEvent);
            }
            else if (priceStr.find("4102,0", 0) != string::npos)
            {
                PriceItem* pi = StringProcessor::StringToPriceItem(priceStr);
                //LogHandler::getLogHandler().log(priceStr);
                //pi->log();
                confirmPriceInfo(pi->quoteId);
                forwardPrice(pi);
            }
            start = end + 2;
        }
    }
}

void SPTrader::processOrder()
{
    //LogHandler::getLogHandler().alert(2, "Processing order", "error occured when receive data from order socket!");
    /** decode ordermsg string to an order instance and forward to OrderItem Dispatcher Thread **/
}

//void SPTrader::processTickerMessage()
//{
//LogHandler::getLogHandler().alert(3, "Ticker error", "error occured when receive data from order socket!");
//5107,3")) != NULL) {
//LogHandler::getLogHandler().log(string(pstr) + " ticker request sucessfully!");
// todo: resend
//LogHandler::getLogHandler().alert(3, "Ticker error", string(pstr) + " ticker request failed");

//"5108,3")) != NULL) {
//LogHandler::getLogHandler().log(string(pstr) + " release ticker request sucessfully!");
// todo: resend
//LogHandler::getLogHandler().alert(3, "Ticker error", string(pstr) + " release ticker request failed");
//}
