#ifndef LEX_LEX_RUNNER_H_
#define LEX_LEX_RUNNER_H_

#include "lex_runner_interface.h"

class LexRunner :public LexRunnerInterface
{
public:
    virtual void Load() override;
    virtual void Run() override;
    virtual ~LexRunner() override;
};




#endif  // LEX_LEX_RUNNER_INTERFACE_H_