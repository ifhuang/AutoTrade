#ifndef __SWINGTRADER__
#define __SWINGTRADER__
#include <string> 
#include <windows.h>
#include "Dispatcher.h"
#include "Strategy.h"
#include "TradeCube.h"
#include "TradeUnit.h"
#include "../TradeCube/iswingtradedialog.h"
#include "../TradeCube/imainwindow.h"

class ISwingTradeDialog;
class IMainWindow;

class SwingTrader : public Strategy
{
public:
    SwingTrader(int traderId, Dispatcher *disp,
        ISwingTradeDialog* iSwingTradeDialog, IMainWindow* iMainWindow);
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
    virtual void updateBars() override;
    virtual void processOrderAccepted(MSG& msg);
    virtual void processTradeDone(MSG& msg);
    virtual void processPrice(MSG& msg);
    virtual void signal();
    bool isBarsEnough();

    TradeUnit* tradeUnit;
    UINT_PTR iTimerID;

    //test
    long testOrderID;

    ISwingTradeDialog* iSwingTradeDialog;
    IMainWindow* iMainWindow;
};
#endif
