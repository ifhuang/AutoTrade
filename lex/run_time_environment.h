#ifndef RUN_TIME_ENVIRONMENT_H_
#define RUN_TIME_ENVIRONMENT_H_

#include "execution.h"
#include "type.h"

class RunTimeEnvironment
    {
    public:
        RunTimeEnvironment(Type::SetUpEnviroment sue);
        ~RunTimeEnvironment();
        Execution::Value GetVar(int position);

    private:
        int num_variables_;
        Execution::Value *variable_array_;
    };


#endif  // RUN_TIME_ENVIRONMENT_H_
