#ifndef LEX_LEX_IMPL_H_
#define LEX_LEX_IMPL_H_

#include "interface/lex_interface.h"

class LexImpl : public LexInterface
{
    virtual std::vector<LexStudy> ListStudies() override;

    virtual void Compiler(std::string study_name) override;

    virtual LexSignalDetail GetSignalDetail(std::string signal_name) override;

    virtual LexRunnerInterface* New(std::string signal_name, LexSignalDetail details,
        TCBarInterface *tc_bar) override;
};

#endif  // LEX_LEX_IMPL_H_
