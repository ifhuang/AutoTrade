#ifndef RUN_TIME_ENVIRONMENT_H_
#define RUN_TIME_ENVIRONMENT_H_

#include <vector>

#include "execution.h"
#include "global.h"
#include "type.h"

namespace lex{

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
        Value GetVar(int position);

    private:
        int num_variables_;
        Value *variable_array_;
        DISALLOW_COPY_AND_ASSIGN(RunTimeEnvironment);
    };

}  // namespace lex
#endif  // RUN_TIME_ENVIRONMENT_H_
