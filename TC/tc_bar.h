#ifndef TC_TC_BAR_H_
#define TC_TC_BAR_H_

#include "../lex/interface/tc_bar_interface.h"

#include "StrategyInterface.h"

class TCBar : public TCBarInterface
{
public:
    TCBar(StrategyInterface &si);
    virtual void Buy(int id) override;
    virtual void Sell(int id) override;
    virtual void Open(int bar) override;
    virtual void Close(int bar) override;
    virtual void High(int bar) override;
    virtual void Low(int bar) override;

private:
    StrategyInterface &si_;
};



#endif  // TC_TC_BAR_H_
