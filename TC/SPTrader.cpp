#include "SPTrader.h"

#pragma comment(lib,"ws2_32.lib")

#ifndef Q_MOC_RUN
#include <boost/lexical_cast.hpp>
#endif
#include "socket_helper.h"
#include "string_processor.h"

using boost::lexical_cast;
using namespace boost::posix_time;

// changed by xie, 非单例化
SPTrader::SPTrader(PlatformInfo& platformInfo) :Dispatcher(platformInfo)
{
    hOrderThread = hPriceThread = hCheckConnectionThread = hTickerThread = INVALID_HANDLE_VALUE;
    quoteEvent = doneTradeEvent = curOrderEvent = NULL;
    timerInterval = 3;
    SetUp();
    login();
    startOrderThread();
    startPriceThread();
    startCheckConnectionThread();
    startTickerThread();
    Sleep(3000);
}

// added by xie
bool SPTrader::requestLinkState(LinkID linkID)
{
    char buf[256] = { 0 };
    _snprintf(buf, 256, "9000,%d\r\n", linkID);
    string req(buf);
    if (send(orderSocket, req.c_str(), req.length(), 0) < 0){
        LogHandler::getLogHandler().alert(1, "Connection status", "Send message for checking connection status failed!");
        return false;
    }
    return true;
}

int SPTrader::SetUp()
{
    //starting socket library
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    wVersionRequested = MAKEWORD(2, 0);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) 	{
        cout << "Socket2.0  initialization failed，Exit!";
        return err;
    }
    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 0){
        WSACleanup();
        return -1;
    }
    //create the sokcet
    orderSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (orderSocket == INVALID_SOCKET) {
        cout << "Socket creation failed，Exit!";
        return -1;
    }
    //define the address of SPTrader
    sockaddr_in myaddr;
    memset(&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = inet_addr(platformInfo.server.c_str());
    myaddr.sin_port = htons(platformInfo.orderPort);

    //connect to SPTrader
    if (connect(orderSocket, (sockaddr*)&myaddr, sizeof(myaddr)) == SOCKET_ERROR){
        cout << "connect failed, exit!" << endl;
        closesocket(orderSocket);
        //WSACleanup(); // the cleanup is change to the cleanup function
        return 1;
    }
    else	{
        cout << "connect succeed!" << endl;
    }
    return 0;
}

int SPTrader::login()
{
    string loginfo = "3101,0," + platformInfo.accountNo + "," + platformInfo.password
        + "," + platformInfo.server + "\r\n";
    if (send(orderSocket, loginfo.c_str(), loginfo.length(), 0) < 0){
        cout << "Send login info error!" << endl;
    }

    SocketHelper order_socket_helper(orderSocket);
    Message message = order_socket_helper.Get();
    if (message.id == 3101){
        int return_code = message.fileds.Get<int>(0);
        if (return_code == 0){
            connectStatus = true;
            return 0;
        }
    }
    return -1;
}

HANDLE SPTrader::startOrderThread()
{
    hOrderThread = CreateThread(NULL, 0, this->orderThreadAdapter, this, 0, &orderThreadId);
    return hOrderThread;
}

HANDLE SPTrader::startPriceThread()
{
    initPriceConnection();
    hPriceThread = CreateThread(NULL, 0, this->priceThreadAdapter, this, 0, &priceThreadId);
    return hPriceThread;
}

// added by xie
HANDLE SPTrader::startCheckConnectionThread()
{
    hCheckConnectionThread = CreateThread(NULL, 0, this->checkConnectionThreadAdapter, this, 0, &checkConnectionThreadId);
    return hCheckConnectionThread;
}

// added by xie
HANDLE SPTrader::startTickerThread()
{
    hTickerThread = CreateThread(NULL, 0, this->tickerThreadAdapter, this, 0, &tickerThreadId);
    return hTickerThread;
}

DWORD WINAPI SPTrader::orderThreadAdapter(LPVOID lpParam)
{
    SPTrader *spoi = (SPTrader *)lpParam;
    spoi->processOrder();
    return 0;
}

DWORD WINAPI SPTrader::priceThreadAdapter(LPVOID lpParam)
{
    SPTrader *spoi = (SPTrader *)lpParam;
    spoi->processPrice();
    return 0;
}

/**
  *检查与服务器的连接情况 by xie
  */
DWORD WINAPI SPTrader::checkConnectionThreadAdapter(LPVOID lpParam)
{
    SPTrader *spoi = (SPTrader *)lpParam;
    SetTimer(NULL, CHECK_LINK_TIMER_ID, spoi->timerInterval * 1000, NULL);
    MSG  msg;

    map<LinkID, string> linkInfo;
    linkInfo[TRANSACTION_CLIENT_LINK] = "Transaction client link";
    //linkInfo[TRANSACTION_ADMIN_LINK] = "Transaction admin link";
    linkInfo[PRICE_LINK] = "Price link";
    //linkInfo[LONG_DEPTH_LINK] = "Long depth link";
    //linkInfo[INFORMATION_LINK] = "Information link";
    //linkInfo[MARGIN_CHECK_LINK] = "Margin check link";
    map<LinkID, string>::iterator it = linkInfo.begin();

    int id = 0, status = -1;
    char* pstr = NULL;
    char buf[256] = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (msg.message == WM_TIMER) {
            //LogHandler::getLogHandler().log("3 seconds-----------");
            for (it = linkInfo.begin(); it != linkInfo.end(); ++it) {
                //LogHandler::getLogHandler().log("Check " + it->second);
                if (!spoi->requestLinkState(it->first)) {
                    spoi->setConnectStatus(false);
                }
            }
        }
        else if (msg.message == LINK_STATE_MSG) {
            memset(buf, 0, sizeof(buf));
            memcpy(buf, (char*)msg.lParam, 256);
            //LogHandler::getLogHandler().log(buf);
            pstr = strtok(buf, ",");
            pstr = strtok(NULL, ",");
            if (pstr != NULL) {
                id = atoi(pstr);
            }
            it = linkInfo.find((LinkID)id);
            if (it != linkInfo.end()) {
                pstr = strtok(NULL, ",");
                if (pstr != NULL) {
                    status = atoi(pstr);
                }
                if (status == 0) {
                    //LogHandler::getLogHandler().log(it->second + " is connected!");
                }
                else if (status == 1) {
                    spoi->setConnectStatus(false);
                    LogHandler::getLogHandler().alert(3, "Connection status", it->second + " is broken!");
                }
            }
            if (!spoi->getConnectStatus()) {
                // 失去连接 
                LogHandler::getLogHandler().alert(3, "Lost Connection!", "Lost Connection!");
                spoi->loseConnection();
            }
        }
    }
    return 0;
}

// added by xie
DWORD WINAPI SPTrader::tickerThreadAdapter(LPVOID lpParam)
{
    SPTrader *spoi = (SPTrader *)lpParam;
    if (spoi->initTickConnection() < 0) return 0;

    spoi->processTickerMessage();

    return 0;
}

void SPTrader::stopOrderThread()
{
    if (TerminateThread(hOrderThread, 0) == 0){
        cout << "Terminate SPTrader's receive order thread failed, ERROR CODE=" + GetLastError() << endl;
    }
    WaitForSingleObject(hOrderThread, INFINITE);
    CloseHandle(hOrderThread);
    hOrderThread = INVALID_HANDLE_VALUE;
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

    addr.sin_addr.s_addr = inet_addr(platformInfo.server.c_str());
    addr.sin_port = htons(platformInfo.pricePort);

    if (SOCKET_ERROR == connect(priceSocket, (sockaddr*)&addr, sizeof(addr))){
        cout << "connecting to price 8089 port failed, exit!" << endl;
        closesocket(priceSocket);
        return -1;
    }
    else{
        cout << "establish price connection  successfully!" << endl;
        return 0;
    }
}



int SPTrader::initTickConnection()
{
    cout << "begin tick connection......" << endl;
    tickSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == tickSocket){
        cout << "Creating price socket  failed, Exit!" << endl;
        return -1;
    }
    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    addr.sin_addr.s_addr = inet_addr(platformInfo.server.c_str());
    addr.sin_port = htons(platformInfo.tickPort);

    if (SOCKET_ERROR == connect(tickSocket, (sockaddr*)&addr, sizeof(addr))){
        //cout<<"connecting to price 8089 port failed, exit!"<<endl;
        LogHandler::getLogHandler().alert(3, "Socket error", "connecting to ticker port failed, exit!");
        closesocket(tickSocket);
        return -1;
    }
    else{
        LogHandler::getLogHandler().log("establish tick connection  successfully!");
        return 0;
    }
    /*if((len=send(tickerSocket,orderStr.c_str(),orderStr.length(),0))<0){
            cout<<"Send ORDER orders error, please check the order socket!"<<endl;
            //exit(-1);
            }*/
}

int SPTrader::addQuote(QuoteItem *pQuoteItem)
{
    if (pQuoteItem->getTradePlatform() != SPTRADER) return -1;

    string quoteId = pQuoteItem->getQuoteId();

    quoteEvent = CreateEvent(NULL, FALSE, FALSE, L"ADD_QUOTE");
    string quotemsg = "4107,0," + quoteId + "\r\n";		  // 4107 msg is to request the price 
    if (send(priceSocket, quotemsg.c_str(), quotemsg.length(), 0) < 0)
    {
        cout << "Send price update msgid error, please check the connection to server!" << endl;
        return MY_ERROR;
    }
    // added by xie
    quotemsg = "5107,0," + quoteId + "\r\n";		  // 5107 msg is to request the price 
    // 这里为什么socket 会还是0呢？线程应该早就启动了
    if (send(tickSocket, quotemsg.c_str(), quotemsg.length(), 0) < 0)
    {
        LogHandler::getLogHandler().alert(3, "Add quote", "Request tick price failed for new quote!");
        return MY_ERROR;
    }
    WaitForSingleObject(quoteEvent, INFINITE);
    CloseHandle(quoteEvent);
    LogHandler::getLogHandler().log("Quote is added:" + quoteId);
    return SUCCESS;
}

int SPTrader::sendOrder(OrderItem* pOrderItem)
{
    int len = 0;
    if (connectStatus == true){
        string orderStr = StringProcessor::OrderItemToString(pOrderItem, platformInfo.accountNo);
        //LogHandler::getLogHandler().log(orderStr);
        pOrderItem->log();
        if ((len = send(orderSocket, orderStr.c_str(), orderStr.length(), 0)) < 0){
            cout << "Send ORDER orders error, please check the order socket!" << endl;
            //exit(-1);
        }
    }
    else
    {
        cout << "Connection to SPTrader is not established or broken!" << endl;
        //exit(-1);
    }
    return len;
}

int SPTrader::confirmTradeInfo(int tradeRecordNo)
{
    int len = 0;
    char confirmStr[50];
    if (connectStatus == true){
        sprintf(confirmStr, "3109,3,%d\r\n", tradeRecordNo);
        if ((len = send(orderSocket, confirmStr, strlen(confirmStr), 0)) < 0){
            cout << "Send Trade confirmation error, please check the order socket!" << endl;
            //exit(-1);
        }
    }
    else
    {
        cout << "Connection to SPTrader is not established or broken!" << endl;
        //exit(-1);
    }
    return len;

}

int SPTrader::confirmPriceInfo(string quoteId)
{
    string priceRep = "";
    priceRep = "4102,3," + quoteId + ",0\r\n";
    if (send(priceSocket, priceRep.c_str(), priceRep.length(), 0) < 0)
    {
        LogHandler::getLogHandler().alert(3, "Price request", "Send price reply error, please check the connection to server!");
        return -1;
    }
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
    if (pQuoteItem->getTradePlatform() != SPTRADER) return -1;
    string quoteId = pQuoteItem->getQuoteId();

    quoteEvent = CreateEvent(NULL, FALSE, FALSE, L"DELETE_QUOTE");
    string quotemsg = string("4108,0,") + quoteId + "\r\n";  // 4108 msg is to stop the price update
    if (send(priceSocket, quotemsg.c_str(), quotemsg.length(), 0) < 0)
    {
        cout << "Send price release msgid error, please check the connection to server!" << endl;
        return -1;
    }

    // added by xie
    quotemsg = string("5108,0,") + quoteId + "\r\n";  // 4108 msg is to stop the price update
    if (send(tickSocket, quotemsg.c_str(), quotemsg.length(), 0) < 0)
    {
        LogHandler::getLogHandler().alert(3, "Delete quote", "Cancel tick price failed!");
        return -1;
    }
    WaitForSingleObject(quoteEvent, INFINITE);
    CloseHandle(quoteEvent);
    LogHandler::getLogHandler().log("Quote is deleted:" + quoteId);
    return 0;
}

map<int, TradeItem*>& SPTrader::getDoneTrades()
{
    doneTradeEvent = CreateEvent(NULL, FALSE, FALSE, L"GET_TRADE_DONE_LIST");
    string msg = "3181,0\r\n";
    if (send(orderSocket, msg.c_str(), msg.length(), 0) < 0) {
        LogHandler::getLogHandler().alert(3, "Load done trade", "Load done trade failed!");
        return doneTrades;
    }
    WaitForSingleObject(doneTradeEvent, INFINITE);
    CloseHandle(doneTradeEvent);
    doneTradeEvent = NULL;
    return doneTrades;
}

map<int, OrderItem*>& SPTrader::getCurrentOrders()
{
    curOrderEvent = CreateEvent(NULL, FALSE, FALSE, L"LOAD_ORDER_BOOK");
    string msg = "3186,0\r\n";
    if (send(orderSocket, msg.c_str(), msg.length(), 0) < 0) {
        LogHandler::getLogHandler().alert(3, "Load order book", "Load order book failed!");
        return currentOrders;
    }
    WaitForSingleObject(curOrderEvent, INFINITE);
    CloseHandle(curOrderEvent);
    curOrderEvent = NULL;
    return currentOrders;
}

void SPTrader::getPosition(Position& position)
{
    string quoteID = position.getQuoteId();
    this->positions[quoteID] = position;
    WCHAR wsz[64];
    swprintf(wsz, L"%S", quoteID.c_str());
    positionEvents[quoteID] = CreateEvent(NULL, FALSE, FALSE, wsz);
    //LogHandler::getLogHandler().log("create position event(" + quoteID + ")");

    string msg = "9901,0," + platformInfo.accountNo + "," + quoteID.c_str() + "\r\n";
    //LogHandler::getLogHandler().log(msg);
    if (send(orderSocket, msg.c_str(), msg.length(), 0) < 0) {
        LogHandler::getLogHandler().alert(3, "Load position", "Load position failed!");
        return;
    }

    WaitForSingleObject(positionEvents[quoteID], INFINITE);
    //LogHandler::getLogHandler().log("release position event(" + quoteID + ")");
    CloseHandle(positionEvents[quoteID]);
    positionEvents[quoteID] = NULL;
    position = this->positions[quoteID];
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
            continue;
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
    while (true){
        if (connectStatus != true){
            continue;
        }
        char recvbuff[4096] = "";
        int pkglen = recv(orderSocket, recvbuff, sizeof(recvbuff), 0);
        if (pkglen < 0){
            LogHandler::getLogHandler().alert(2, "Processing order", "error occured when receive data from order socket!");
            continue;
        }
        string tmp = string(recvbuff, pkglen);
        int start = 0;
        string rmd;
        string orderStr;
        while (true){
            int end = tmp.find("\r\n", start);
            if (end == string::npos){
                rmd = tmp.substr(start, pkglen - start);
                //cout<<"*******************************"<<endl;
                //cout<<rmd<<endl;					
                break;
            }
            orderStr = tmp.substr(start, end - start);
            if (start == 0) {
                orderStr = rmd + orderStr;
            }
            /** decode ordermsg string to an order instance and forward to OrderItem Dispatcher Thread **/
            if (orderStr.find("3103,3", 0) != string::npos) {
                OrderItem* po = StringProcessor::StrintToOrderItem(orderStr);

                // 接收订单ORDER_ACCEPT_MSG
                returnOrder(po);
            }
            else if (orderStr.find("3109,0", 0) != string::npos) {
                TradeItem* ti = StringProcessor::StringToTradeItem(orderStr);
                confirmTradeInfo(ti->getTradeNo());
                //ti->log();
                // 订单完成TRADE_DONE_MSG
                returnTrade(ti);

                // added by xie, 内存问题， 在哪里释放以后要调好
                doneTrades[ti->getOrderNo()] = ti;
                if (doneTrades.size() == doneTradeCount) {
                    SetEvent(doneTradeEvent);
                }
            }
            //by xie
            else if (orderStr.find("9000", 0) != string::npos){
                char linkStateReply[256] = { 0 };
                strncpy(linkStateReply, orderStr.c_str(), 256);

                // 发送返回信息到连接状态检测线程
                PostThreadMessage(checkConnectionThreadId, LINK_STATE_MSG, 0, (LPARAM)linkStateReply);
            }
            else if (orderStr.find("3181,3", 0) != string::npos){
                doneTrades.clear();
                doneTradeCount = 0;
                int s = orderStr.find(",", 7);
                int e = orderStr.length();
                if (s != string::npos) {
                    doneTradeCount = atoi(orderStr.substr(s + 1, e - s - 1).c_str());
                    if (doneTradeCount == 0) {
                        SetEvent(doneTradeEvent);
                    }
                }
            }
            else if (orderStr.find("3186,3", 0) != string::npos){
                currentOrders.clear();
                currentOrderCount = 0;
                int s = orderStr.find(",", 7);
                int e = orderStr.length();
                if (s != string::npos) {
                    currentOrderCount = atoi(orderStr.substr(s + 1, e - s - 1).c_str());
                    cout << "order count:" << currentOrderCount << endl;
                    if (currentOrderCount == 0) {
                        SetEvent(curOrderEvent);
                    }
                }
            }
            else if (orderStr.find("3119,0", 0) != string::npos) {
                OrderItem* oi = str2UpdatedOrder(orderStr);

                currentOrders[oi->getOrderNo()] = oi;
                if (currentOrders.size() == currentOrderCount) {
                    SetEvent(curOrderEvent);
                }
            }
            else if (orderStr.find("9901,3", 0) != string::npos) {
                //LogHandler::getLogHandler().log(orderStr);
                Position* pos = StringProcessor::StringToPosition(orderStr);
                string quoteID = pos->getQuoteId();
                if (positionEvents.count(quoteID) > 0
                    && positionEvents[quoteID] != NULL) {
                    this->positions[quoteID] = *pos;
                    delete pos;
                    SetEvent(positionEvents[quoteID]);
                }
            }
            start = end + 2;
        }
    }
}

void SPTrader::processTickerMessage()
{
    char* pstr = NULL;
    while (true){
        if (connectStatus == true){
            char recvbuff[4096] = "";
            int pkglen = recv(tickSocket, recvbuff, sizeof(recvbuff), 0);
            if (pkglen < 0){
                LogHandler::getLogHandler().alert(3, "Ticker error", "error occured when receive data from order socket!");
            }
            else if ((pstr = strstr(recvbuff, "5107,3")) != NULL) {
                pstr = strtok(recvbuff, ",");
                pstr = strtok(NULL, ",");
                if (pstr == NULL) continue;
                pstr = strtok(NULL, ",");
                if (pstr == NULL) continue;
                int retCode = atoi(pstr);
                pstr = strtok(NULL, ",");
                if (pstr == NULL) continue;
                if (retCode == 0) {
                    //LogHandler::getLogHandler().log(string(pstr) + " ticker request sucessfully!");
                }
                else {
                    // todo: resend
                    //this->addQuote(pstr);
                    LogHandler::getLogHandler().alert(3, "Ticker error", string(pstr) + " ticker request failed");
                }
            }
            else if ((pstr = strstr(recvbuff, "5108,3")) != NULL) {
                pstr = strtok(recvbuff, ",");
                pstr = strtok(NULL, ",");
                if (pstr == NULL) continue;
                pstr = strtok(NULL, ",");
                if (pstr == NULL) continue;
                int retCode = atoi(pstr);
                pstr = strtok(NULL, ",");
                if (pstr == NULL) continue;
                if (retCode == 0) {
                    LogHandler::getLogHandler().log(string(pstr) + " release ticker request sucessfully!");
                }
                else {
                    // todo: resend
                    //this->addQuote(pstr);
                    LogHandler::getLogHandler().alert(3, "Ticker error", string(pstr) + " release ticker request failed");
                }
            }
            else if ((pstr = strstr(recvbuff, "5102,3")) != NULL) {
                pstr = strtok(recvbuff, ",");
                pstr = strtok(NULL, ",");
                if (pstr == NULL) continue;
                pstr = strtok(NULL, ",");
                if (pstr == NULL) continue;
                PriceItem* pi = new PriceItem();
                pi->quoteId = pstr;
                pstr = strtok(NULL, ",");
                if (pstr == NULL) {
                    delete pi;
                    continue;
                }
                pi->lastPrice1 = atof(pstr);
                pstr = strtok(NULL, ",");
                if (pstr == NULL) {
                    delete pi;
                    continue;
                }
                pi->lastQty1 = atoi(pstr);
                pstr = strtok(NULL, ",");
                if (pstr == NULL) {
                    delete pi;
                    continue;
                }
                pi->currentTime = from_time_t(atoi(pstr));
                pi->tradePlatform = SPTRADER;
                forwardTickPrice(pi);
            }
        }
    }
}
