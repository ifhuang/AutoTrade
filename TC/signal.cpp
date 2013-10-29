#include "signal.h"

#include "../lex/interface/lex_factory.h"
#include "tc_bar.h"

Signal::Signal(lex::SignalRunnerInterface *runner) : runner_(runner)
{

}

Signal::~Signal()
{
    delete runner_;
}

Signal* Signal::GetSignal(std::string name, TCBarInterface *bar)
{
    lex::LexInterface *li = lex::LexFactory::CreateLexInterface();
    lex::SignalDetail sd = li->GetSignalDetail(name);
    auto runner = li->NewSignal(name, sd, bar);
    Signal *signal = new Signal(runner);
    return signal;
}
