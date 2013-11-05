#ifndef TC_SIGNAL_H_
#define TC_SIGNAL_H_

#include <string>
#include "../lex/interface/lex_interface.h"
#include "study.h"

class Signal : public Study
{
public:
    static std::unique_ptr<Signal> GetSignal(std::string name, TCBarInterface *bar);
    ~Signal();
    std::vector<lex::OrderAction> Run();

private:
    Signal(std::unique_ptr<lex::SignalRunnerInterface> runner);

    std::unique_ptr<lex::SignalRunnerInterface> runner_;
};

#endif  // TC_SIGNAL_H_
