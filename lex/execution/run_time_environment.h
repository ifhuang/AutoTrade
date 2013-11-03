#ifndef LEX_EXECUTION_RUN_TIME_ENVIRONMENT_H_
#define LEX_EXECUTION_RUN_TIME_ENVIRONMENT_H_

#include <vector>

#include "../global.h"
#include "../program.h"
#include "execution.h"

namespace lex
{
    struct RteInitialize
    {
        int size;
        Value value;
    };

    class RunTimeEnvironment
    {
    public:
        RunTimeEnvironment(std::vector<RteInitialize> list);
        ~RunTimeEnvironment();
        Value& GetVar(int position);

    private:
        int num_variables_;
        Value *variable_array_;
        DISALLOW_COPY_AND_ASSIGN(RunTimeEnvironment);
    };

}  // namespace lex
#endif  // LEX_EXECUTION_RUN_TIME_ENVIRONMENT_H_
