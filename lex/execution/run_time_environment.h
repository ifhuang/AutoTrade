#ifndef LEX_EXECUTION_RUN_TIME_ENVIRONMENT_H_
#define LEX_EXECUTION_RUN_TIME_ENVIRONMENT_H_

#include <vector>

#include "../global.h"
#include "../program.h"
#include "runtime_interface.h"

namespace lex
{
    struct RteInitialize
    {
        int size;
        Value value;
    };

    class RunTimeEnvironment : public RuntimeInterface
    {
    public:
        RunTimeEnvironment(const Program &p);
        bool Initialized();
        void Initialize(std::vector<RteInitialize> list);
        virtual ~RunTimeEnvironment();
        virtual Value& GetVar(int position) override;
        virtual ast_t GetInput(int id) override;

    private:
        const Program &program_;
        bool initialized_;

        int num_variables_;
        Value *variable_array_;

        int num_inputs_;
        int *inputs_array_;
        DISALLOW_COPY_AND_ASSIGN(RunTimeEnvironment);
    };

}  // namespace lex
#endif  // LEX_EXECUTION_RUN_TIME_ENVIRONMENT_H_
