#include "signal.h"

#include "../lex/interface/lex_factory.h"
#include "tc_bar.h"

Signal::Signal(std::unique_ptr<lex::SignalRunnerInterface> runner) : runner_(std::move(runner))
{

}

Signal::~Signal()
{
}

std::unique_ptr<Signal> Signal::GetSignal(std::string name, TCBarInterface *bar)
{
    lex::LexInterface *li = lex::LexFactory::CreateLexInterface();
    lex::SignalDetail sd = li->GetSignalDetail(name);
    auto runner = li->NewSignal(name, sd, bar);
    Signal *signal = new Signal(std::move(runner));
    return std::unique_ptr<Signal>(signal);
}

std::vector<lex::OrderAction> Signal::Run()
{
    return runner_->Run();
}
