#include "SPTrader.h"

#ifndef Q_MOC_RUN
#include <boost/lexical_cast.hpp>
#endif
#include "sptrader/sptrader_order.h"
#include "sptrader/sptrader_price.h"
#include "sptrader/sptrader_ticker.h"
#include "string_processor.h"

using std::thread;
using boost::lexical_cast;
using namespace boost::posix_time;

// changed by xie, 非单例化
SPTrader::SPTrader(
    PlatformInfo& platformInfo)
    : Dispatcher(), platformInfo_(platformInfo), check_timer_(io_service_),
    resolver_(io_service_)
{
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
    int return_code = sp_trader->login();
    if (return_code != 0)
    {
        delete sp_trader;
        return nullptr;
    }
    sp_trader->order_->DoRead();
    sp_trader->startCheckConnection();
    if (!sp_trader->startPriceThread() || !sp_trader->startTickerThread())
    {
        delete sp_trader;
        return nullptr;
    }
    return sp_trader;
}

// added by xie
//bool SPTrader::requestLinkState(LinkID linkID)
//{
//LogHandler::getLogHandler().alert(1, "Connection status", "Send message for checking connection status failed!");
//}

int SPTrader::login()
{
    auto endpoint_iterator = Resolve(platformInfo_.orderPort);
    order_ = new SPTraderOrder(io_service_, *this);
    if (!order_->Connect(endpoint_iterator))
    {
        return -1;
    }
    int return_code = order_->Login(platformInfo_.accountNo, platformInfo_.password, platformInfo_.server);
    return return_code;
}

bool SPTrader::startPriceThread()
{
    auto endpoint_iterator = Resolve(platformInfo_.pricePort);
    price_ = new SPTraderPrice(io_service_, *this);
    if (!price_->Connect(endpoint_iterator))
    {
        return false;
    }
    price_->DoRead();
    return true;
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
bool SPTrader::startTickerThread()
{
    auto endpoint_iterator = Resolve(platformInfo_.tickPort);
    ticker_ = new SPTraderTicker(io_service_, *this);
    if (!ticker_->Connect(endpoint_iterator))
    {
        return false;
    }
    ticker_->DoRead();
    io_service_thread_ = new std::thread([this]()
    {
        io_service_.run();
    });
    return true;
}

void SPTrader::stopOrderThread()
{
    delete order_;
    order_ = nullptr;
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
    price_->Request(quoteId);
    //quoteEvent = CreateEvent(NULL, FALSE, FALSE, L"ADD_QUOTE");
    //cout << "Send price update msgid error, please check the connection to server!" << endl;

    ticker_->Request(quoteId);
    // added by xie
    //// 这里为什么socket 会还是0呢？线程应该早就启动了
    //LogHandler::getLogHandler().alert(3, "Add quote", "Request tick price failed for new quote!");
    //WaitForSingleObject(quoteEvent, INFINITE);
    //CloseHandle(quoteEvent);
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
    price_->Release(quoteId);
    //cout << "Send price release msgid error, please check the connection to server!" << endl;
    // added by xie
    ticker_->Release(quoteId);
    //LogHandler::getLogHandler().alert(3, "Delete quote", "Cancel tick price failed!");
    LogHandler::getLogHandler().log("Quote is deleted:" + quoteId);
    return 0;
}

map<int, TradeItem*>& SPTrader::getDoneTrades()
{
    //doneTradeEvent = CreateEvent(NULL, FALSE, FALSE, L"GET_TRADE_DONE_LIST");
    string msg = "3181,0\r\n";
    order_->Send(msg);
    //        LogHandler::getLogHandler().alert(3, "Load done trade", "Load done trade failed!");
    return doneTrades;
    //WaitForSingleObject(doneTradeEvent, INFINITE);
    //CloseHandle(doneTradeEvent);
    //doneTradeEvent = NULL;
    return doneTrades;
}

map<int, OrderItem*>& SPTrader::getCurrentOrders()
{
    //curOrderEvent = CreateEvent(NULL, FALSE, FALSE, L"LOAD_ORDER_BOOK");
    string msg = "3186,0\r\n";
    //string get = AsioHelper::Get(msg);
    //if (send(orderSocket, msg.c_str(), msg.length(), 0) < 0) {
    LogHandler::getLogHandler().alert(3, "Load order book", "Load order book failed!");
    return currentOrders;
    //}
    //WaitForSingleObject(curOrderEvent, INFINITE);
    //CloseHandle(curOrderEvent);
    //curOrderEvent = NULL;
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

//void SPTrader::processOrder()
//LogHandler::getLogHandler().alert(2, "Processing order", "error occured when receive data from order socket!");
/** decode ordermsg string to an order instance and forward to OrderItem Dispatcher Thread **/

boost::asio::ip::tcp::resolver::iterator SPTrader::Resolve(int port)
{
    tcp::resolver::query query(platformInfo_.server, to_string(port));
    auto endpoint_iterator = resolver_.resolve(query);
    return endpoint_iterator;
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
