#ifndef LEX_EXECUTION_RUNTIME_INTERFACE_H_
#define LEX_EXECUTION_RUNTIME_INTERFACE_H_

#include "../ast.h"
#include "execution.h"

namespace lex
{
    class RuntimeInterface
    {
    public:
        virtual ~RuntimeInterface() {}
        virtual Value& GetVar(int position) = 0;
        virtual ast_t GetInput(int id) = 0;
    };
}  // namespace lex
#endif // LEX_EXECUTION_RUNTIME_INTERFACE_H_
