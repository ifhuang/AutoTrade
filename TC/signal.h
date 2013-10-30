#ifndef TC_SIGNAL_H_
#define TC_SIGNAL_H_

#include <string>
#include "../lex/interface/lex_interface.h"
#include "study.h"

class Signal : public Study
{
public:
    Signal* GetSignal(std::string name, TCBarInterface *bar);
    ~Signal();

private:
    Signal(lex::SignalRunnerInterface *runner);

    lex::SignalRunnerInterface *runner_;
};

#endif  // TC_SIGNAL_H_
