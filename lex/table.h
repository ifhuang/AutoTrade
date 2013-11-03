#ifndef TABLE_H_
#define TABLE_H_

#include <string>
#include <unordered_map>
#include <vector>
#include "execution/execution.h"
#include "global.h"
#include "program.h"
#include "std_table.h"

namespace lex
{
    enum class VSource { StdFunction, Input, Variable, Undefined };

    struct Variable
    {
        VType type;
        int position;
    };

    class Table : public StdTable
    {
    public:
        Table();
        VSource FindName(std::string name);
        Input GetInput(std::string name);
        Variable GetVariable(std::string name);
        int DeclareVar(std::string name, VType type, ast_t exp);
        int NewInput(std::string name, VType type, ast_t exp);
        int ReserveSpace(ast_t exp);
        int ReserveSpace(ast_t exp, int size);
        SetUpEnviroment GetSetupEnviroment() const;

    private:
        SetUpEnviroment sue_;
        int num_variables_;
        int num_inputs_;
        std::unordered_map<std::string, Input> input_table_;
        std::unordered_map<std::string, Variable> var_table_;
    };

}  // namespace lex
#endif  // TABLE_H_
