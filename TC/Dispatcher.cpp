#include "Dispatcher.h" 

Dispatcher::Dispatcher(PlatformInfo& platformInfo) : platformInfo(platformInfo), connectStatus(false), doneTradeCount(0), currentOrderCount(0)
{
}


Dispatcher::~Dispatcher()
{

}

// added by xie
void Dispatcher::loseConnection()
{
    for (map<int, DWORD>::iterator it = orderThreadIdTable.begin(); it != orderThreadIdTable.end(); it++) {
        PostThreadMessage(it->second, LOSE_CONN_MSG, 0, NULL);
    }
}

int Dispatcher::addOrderThreadId(int traderId, DWORD traderThreadId)
{
    if (orderThreadIdTable.count(traderId) == 0)
    {
        // orderThreadIdTable.insert({ traderId, traderThreadId });
        orderThreadIdTable.insert(make_pair(traderId, traderThreadId));
    }
    else
    {
        cout << "This quote has been registered." << endl;
        return -1;
    }
    return 0;
}

int Dispatcher::addPriceThreadId(int tradePlatform, string quoteId, DWORD traderThreadId)
{
    for (quoteId_threadId *qt : priceThreadIdQueue)
    {
        if (qt->quoteId == quoteId && qt->threadId == traderThreadId && qt->tradePlatform == tradePlatform)
        {
            cout << "This quote has been registered." << endl;
            return SUCCESS;
        }
    }
    quoteId_threadId* qtid = new quoteId_threadId;
    qtid->quoteId = quoteId;
    qtid->threadId = traderThreadId;
    qtid->tradePlatform = tradePlatform;
    priceThreadIdQueue.push_front(qtid);
    return SUCCESS;
}

void Dispatcher::addUIThreadId(DWORD UIThreadId)
{
    this->UIThreadID = UIThreadId;
}

void Dispatcher::returnTrade(TradeItem* ti)
{
    int traderId = ti->getTraderId();
    if (orderThreadIdTable.find(traderId) != orderThreadIdTable.end()) {
        DWORD traderThreadId = orderThreadIdTable[traderId];
        PostThreadMessage(traderThreadId, TRADE_DONE_MSG, 0, (LPARAM)ti);
    }
}

void Dispatcher::returnOrder(OrderItem* po)
{
    int traderId = po->getTraderId();
    if (orderThreadIdTable.find(traderId) != orderThreadIdTable.end()) {
        DWORD traderThreadId = orderThreadIdTable[traderId];
        PostThreadMessage(traderThreadId, ORDER_ACCEPT_MSG, 0, (LPARAM)po);
    }
}

void Dispatcher::forwardPrice(PriceItem* pPriceItem)
{
    string quoteId = pPriceItem->quoteId;
    int tradePlatform = pPriceItem->tradePlatform;
    for (quoteId_threadId *qt : priceThreadIdQueue)
    {
        if (qt->quoteId == quoteId && qt->tradePlatform == tradePlatform) {
            PostThreadMessage(qt->threadId, PRICE_MSG, 0, (LPARAM)pPriceItem);

            // 在UI上更新价格数据
            if (UIThreadID > 0) {
                PostThreadMessage(UIThreadID, PRICE_MSG, 0, (LPARAM)pPriceItem);
            }
        }
    }
}

// added by xie
void Dispatcher::forwardTickPrice(PriceItem* pPriceItem)
{
    string quoteId = pPriceItem->quoteId;
    int tradePlatform = pPriceItem->tradePlatform;
    for (quoteId_threadId *qt : priceThreadIdQueue)
    {
        if (qt->quoteId == quoteId && qt->tradePlatform == tradePlatform) {
            PostThreadMessage(qt->threadId, TICK_PRICE, 0, (LPARAM)pPriceItem);
        }
    }
}
