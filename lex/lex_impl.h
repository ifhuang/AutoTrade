#ifndef LEX_LEX_IMPL_H_
#define LEX_LEX_IMPL_H_

#include "interface/lex_interface.h"

namespace lex
{
    class LexImpl : public LexInterface
    {
        virtual std::vector<LexStudy> ListStudies() override;

        virtual void Compiler(std::string study_name) override;

        virtual SignalDetail GetSignalDetail(std::string signal_name) override;

        virtual LexRunnerInterface* New(std::string signal_name, SignalDetail details,
            TCBarInterface *tc_bar) override;

        virtual SignalRunnerInterface* NewSignal(std::string signal_name,
            SignalDetail details, TCBarInterface *tc_bar) override;

    };
}  // namespace lex
#endif  // LEX_LEX_IMPL_H_
