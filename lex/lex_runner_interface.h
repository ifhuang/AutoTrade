#ifndef LEX_LEX_RUNNER_INTERFACE_H_
#define LEX_LEX_RUNNER_INTERFACE_H_

class LexRunnerInterface
{
public:
    virtual void Load() = 0;
    virtual void Run() = 0;
    virtual ~LexRunnerInterface() = 0;
};


#endif  // LEX_LEX_RUNNER_INTERFACE_H_