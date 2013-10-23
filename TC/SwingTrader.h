#ifndef __SWINGTRADER__
#define __SWINGTRADER__
#include <time.h>
#include <iostream>
#include <string> 
#include <windows.h>
#include <sstream>
#include <tchar.h>
#include "TradeCube.h"
#include "Strategy.h"
#include "TradeUnit.h"
#include "Dispatcher.h"
#include "../TradeCube/iswingtradedialog.h"
#include "../TradeCube/imainwindow.h"

class ISwingTradeDialog;
class IMainWindow;

class SwingTrader : public Strategy
{
public:
    SwingTrader(int traderId, ISwingTradeDialog* iSwingTradeDialog, IMainWindow* iMainWindow);
    virtual ~SwingTrader();
    int setTradeUnit(TradeUnit* tradeUnit);
    TradeUnit* getTradeUnit();
    int deleteTradeUnit();
    void closeAllPositions();
    void deleteStrategyOrder();

protected:
    void triggerWaitingOrder();
    double marketposition(int pos_ago);

private:
    virtual void processTickPrice(MSG& msg);
    virtual void updateBars();
    virtual void processOrderAccepted(MSG& msg);
    virtual void processTradeDone(MSG& msg);
    virtual void processPrice(MSG& msg);
    virtual void signal();
    void executeStrategy();
    bool isBarsEnough();

    TradeUnit* tradeUnit;
    UINT_PTR iTimerID;

    //test
    long testOrderID;

    ISwingTradeDialog* iSwingTradeDialog;
    IMainWindow* iMainWindow;
};
#endif
