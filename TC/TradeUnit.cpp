#include "TradeUnit.h"

TradeUnit::TradeUnit(QuoteItem* quote)
{
    this->quote = quote;
    openPriceFile();
    tradefp = NULL;
    price = NULL;

    // added by xie
    barPeriod = 30; // unit=second
    maxRefBarNum = 2;
    tickPrice = NULL;
    barStartTime = 0;//time(0); 
    timeDiff = 0;
    stepTickNum = -1;
    stepMoney = -1;
    stepQty = 0;
}

TradeUnit::~TradeUnit()
{
    fclose(pricefp);
    saveTradeRecord();

    // add by xie
    for (Bar* bar : bars) {
        delete bar;
    }
}

OrderItem* TradeUnit::getOrder(long orderRefId)
{
    OrderItem* oi = NULL;
    if (orderQueue.count(orderRefId) == 1)
    {
        oi = orderQueue[orderRefId];
    }
    return oi;
}

int TradeUnit::updateOrder(OrderItem* oi)
{
    long refId = oi->getOrderRefId();
    if (orderQueue.count(refId) > 0)
    {
        delete orderQueue[refId];
        orderQueue[refId] = oi;
        return 0;
    }
    else
        return -1;
}

int TradeUnit::deleteOrder(long orderRefId)
{
    OrderItem* oi = this->getOrder(orderRefId);
    if (oi != NULL)
    {
        delete oi;
        orderQueue.erase(orderRefId);
        return 0;
    }
    else
    {
        //MessageBox(NULL, _T("Returned Order from server is not found in local order queues"), _T("Process ORDER_ACCEPT_MSG error"), MB_OK|MB_ICONSTOP);
        return -1;
    }
}
PriceItem* TradeUnit::getPrice()
{
    return this->price;
}

void TradeUnit::updatePrice(PriceItem* priceItem)
{
    if (this->price != NULL) {
        // add by xie
        /*char currentTime[256] = {0};
        time_t t = time(0);
        strftime( currentTime, sizeof(currentTime), "%Y-%m-%d %H:%M:%S",localtime(&t));
        */
        // 这里改成时间戳方便k线数据的计算
        time_t t = time(0);
        fprintf(pricefp, "%ld\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", (long)t,
            price->lastPrice1, price->lastPrice2, price->lastPrice3, price->lastPrice4, price->lastPrice5,
            price->bidPrice1, price->bidPrice2, price->bidPrice3, price->bidPrice4, price->bidPrice5,
            price->askPrice1, price->askPrice2, price->askPrice3, price->askPrice4, price->askPrice5);

        delete this->price;
        this->price = priceItem;
    }
    else {
        this->price = priceItem;
    }
}

void TradeUnit::updateTickPrice(PriceItem* pi) {
    if (this->tickPrice != NULL) {
        delete this->tickPrice;
    }
    this->tickPrice = pi;

    // 有数据来的时候是一定要更新bar的, added by xie
    time_t current = time(0);
    // 更新服务器时间和本地时间的差别
    timeDiff = current - pi->currentTime;
    cout << "time diff:" << timeDiff << endl;
    updateBars();
}

void TradeUnit::setQuote(QuoteItem* quote)
{
    this->quote = quote;
}

QuoteItem* TradeUnit::getQuote()
{
    return this->quote;
}

Position* TradeUnit::getPosition(int pos_ago)
{
    Position* pos = NULL;
    if (positionQueue.size() > pos_ago)
        return positionQueue.at(positionQueue.size() - 1 - pos_ago);
    return pos;
}

TradeItem* TradeUnit::getTrade(int tradeNo)
{
    TradeItem* ti = NULL;
    map<long, TradeItem*>::iterator iter = tradeQueue.find(tradeNo);
    if (iter != tradeQueue.end())
        ti = iter->second;
    return ti;
}

string TradeUnit::getQuoteId()
{
    return quote->getQuoteId();
}

int TradeUnit::getTradePlatform()
{
    return quote->getTradePlatform();
}

map<long, OrderItem*>& TradeUnit::getOrderQueue()
{
    return this->orderQueue;
}

int TradeUnit::addTrade(TradeItem* tradeRecord)
{
    //cout<<tradeRecord->getTradeNo()<<endl;
    // tradeQueue.insert({ tradeRecord->getTradeNo(), tradeRecord });
    tradeQueue.insert(std::pair<long, TradeItem*>(tradeRecord->getTradeNo(), tradeRecord));
    return 0;
}

int TradeUnit::addPosition(Position* position)
{
    positionQueue.push_back(position);
    return 0;
}

int TradeUnit::savePrice()
{
    char str[500] = "";

    fputs(price->quoteId.c_str(), pricefp);
    sprintf(str, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        price->lastPrice1, price->lastPrice2, price->lastPrice3, price->lastPrice4, price->lastPrice5,
        price->bidPrice1, price->bidPrice2, price->bidPrice3, price->bidPrice4, price->bidPrice5,
        price->askPrice1, price->askPrice2, price->askPrice3, price->askPrice4, price->askPrice5);
    fputs(str, pricefp);
    return 0;
}

TradeUnit::TradeUnit()
{
    openPriceFile();
    tradefp = NULL;
    price = NULL;
    barStartTime = 0;//time(0); 
    stepTickNum = -1;
    stepMoney = -1;
    stepQty = 0;
}

int TradeUnit::addOrder(OrderItem* order)
{
    orderQueue.insert(map<long, OrderItem*>::value_type(order->getOrderRefId(), order));
    return 0;
}

int TradeUnit::openPriceFile()
{
    if (access(quote->getExchange().c_str(), 0)) {
        cerr << "The quote folder doesn't exist!" << endl;
        if (!mkdir(quote->getExchange().c_str())) {
            cerr << "The quote folder fails to create!" << endl;
        }
    }
    string filename = quote->getExchange() + "\\" + quote->getQuoteId() + ".data";
    //cout<<filename<<endl;
    if ((pricefp = fopen(filename.c_str(), "a+")) == NULL) {
        printf("cannot open data file\n");
        return -1;
    }
    return 0;
}

int TradeUnit::saveTradeRecord()
{
    if (tradefp == NULL)
    {
        string filename = quote->getExchange() + "\\" + quote->getQuoteId() + ".tdr";
        if ((tradefp = fopen(filename.c_str(), "a+")) == NULL)
        {
            printf("cannot open trade file\n");
            return -1;
        }
    }
    tm* pTmp = NULL;
    char datetime[20] = "";
    map<long, TradeItem*>::iterator iter = tradeQueue.begin();
    for (; iter != tradeQueue.end(); iter++)
    {
        TradeItem* ti = iter->second;
        time_t t = ti->getTradeTime();
        pTmp = localtime(&t);
        if (pTmp == NULL)
        {
            return -1;
        }
        sprintf(datetime, "%d-%d-%d %d:%d:%d", pTmp->tm_year + 1900, pTmp->tm_mon + 1, pTmp->tm_mday, pTmp->tm_hour, pTmp->tm_min, pTmp->tm_sec);
        fprintf(tradefp, "%s\t%d\t%s\t%s\t%f\t%d\t%f\t%s", ti->getQuoteId(), ti->getTradeNo(), datetime, ti->getBuySell(), ti->getTradePrice(), ti->getQty(), ti->getSubmitPrice(), ti->getOpenClose());
    }
    fclose(tradefp);
    tradeQueue.clear();
    return 0;
}

// added by xie
Bar* TradeUnit::getBar(int position)
{
    if (bars.size() > position) {
        return bars[bars.size() - position - 1];
    }
    else {
        return NULL;
    }
}

bool TradeUnit::isBarsEnough()
{
    return bars.size() >= maxRefBarNum;
}

// added by xie
void TradeUnit::updateBars()
{
    if (tickPrice == NULL) return;

    //priceItem->log();

    // 计算得到服务器时间
    time_t current = time(0) - timeDiff;
    Bar* currentBar = NULL;
    double lastPrice = tickPrice->lastPrice1;
    if (current > barStartTime + barPeriod || bars.empty()) {
        if (!bars.empty()) {
            // 这里标志着上一根k线的结束
            currentBar = bars[bars.size() - 1];
            currentBar->log();
        }
        // 新一根k线的诞生 
        barStartTime = current;
        currentBar = new Bar(lastPrice, lastPrice, lastPrice, lastPrice, barPeriod);
        bars.push_back(currentBar);

        char buff[256] = { 0 };
        strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", localtime(&barStartTime));
        LogHandler::getLogHandler().log("bar start time init:" + string(buff));

        if (bars.size() > maxRefBarNum) {
            // 如果添加后超出最大的refbarnum了。将最老的一根k线删除
            bars.erase(bars.begin());
        }
    }
    else {
        currentBar = bars[bars.size() - 1];
    }
    if (lastPrice < currentBar->getLow()) {
        currentBar->setLow(lastPrice);
    }
    if (lastPrice > currentBar->getHigh()) {
        currentBar->setHigh(lastPrice);
    }
    currentBar->setClose(lastPrice);
}

void TradeUnit::setMaxRefBarNum(int num)
{
    this->maxRefBarNum = num;
}
