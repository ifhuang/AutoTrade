#include "Strategy.h"

Strategy::Strategy(int traderId, Dispatcher *disp) : dispatcher_(disp)
{
    maxRefBarNum = 50;
    intraBarTrading = false;
    autoTrading = false;
    counter = 0;
    hTraderThread = NULL;
    this->traderId = traderId;
    this->optimizeOrderFlow = NO_OPTIMIZE_OFP;
    this->strategyInterface = new StrategyInterface(traderId, optimizeOrderFlow, disp);
}

Strategy::~Strategy()
{
    if (strategyInterface != NULL) {
        delete strategyInterface;
    }
}

DWORD Strategy::startTraderThread()
{
    hTraderThread = CreateThread(NULL, 0, traderThreadAdapter, this, 0, &trader_thread_id_);
    return trader_thread_id_;

}

DWORD WINAPI Strategy::traderThreadAdapter(LPVOID lpParam)
{
    Strategy* pct = (Strategy*)lpParam;
    pct->process();
    return 0;
}

void Strategy::turnOnStrategy()
{
    setAutoTrading(true);

    //这里要先检查是否已经接收或者读历史数据文件中读取了足够的数据，如果数据不足，则不能开启策略交易
    // added by xie
    if (!getIntraBarTrading()) {
        if (!isBarsEnough()) {
            LogHandler::getLogHandler().alert(3, "Strategy Start", "Not enough bars!");
            return;
        }
    }
}

// added by xie
void Strategy::process()
{
    // 启动定时器，定时更新k线，暂定为1秒钟更新一次
    int updateBarTimeID = SetTimer(NULL, UPDATE_BAR_TIMER_ID, 1000, NULL);
    MSG msg;
    // 这里改一下，以便获取WM_TIMER by xie
    while (GetMessage(&msg, NULL, 0, 0)) {
        switch (msg.message) {
        case ORDER_ACCEPT_MSG: processOrderAccepted(msg); break;
        case TRADE_DONE_MSG: processTradeDone(msg); break;
        case PRICE_MSG: processPrice(msg); break;
        case TICK_PRICE: processTickPrice(msg); break;
        case LOSE_CONN_MSG: turnOffStrategy(); LogHandler::getLogHandler().log("strategy is off"); break;
        case WM_TIMER:
            // 更新k线，但是用计数器可能会错过最高价和最低价。by xie
            if (msg.wParam == updateBarTimeID) {
                updateBars();
            }
            break;
        }
    }
}
