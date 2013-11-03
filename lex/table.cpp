#include "table.h"

namespace lex
{
    Table::Table() : num_variables_(0), num_inputs_(0)
    {

    }

    lex::VSource Table::FindName(std::string name)
    {
        if (func_table_.count(name))return VSource::StdFunction;
        if (input_table_.count(name))return VSource::Input;
        if (var_table_.count(name))return VSource::Variable;
        return VSource::Undefined;
    }

    int Table::DeclareVar(std::string name, VType type, ast_t exp)
    {
        int position = ReserveSpace(exp);
        Variable var;
        var.position = position;
        var.type = type;
        var_table_[name] = var;
        return position;
    }

    int Table::NewInput(std::string name, VType type, ast_t exp)
    {
        Input in;
        in.id = num_inputs_++;
        in.name = name;
        in.type = type;
        in.exp = exp;
        input_table_[name] = in;
        sue_.inputs.push_back(in);
        return in.id;
    }

    int Table::ReserveSpace(ast_t exp, int size)
    {
        int position = num_variables_;
        num_variables_ += size;
        Initialize init;
        init.size = size;
        init.exp = exp;
        sue_.initialize_list.push_back(init);
        return position;
    }

    int Table::ReserveSpace(ast_t exp)
    {
        return ReserveSpace(exp, 1);
    }

    Input Table::GetInput(std::string name)
    {
        return input_table_.at(name);
    }

    Variable Table::GetVariable(std::string name)
    {
        return var_table_.at(name);
    }

    SetUpEnviroment Table::GetSetupEnviroment() const
    {
        return sue_;
    }

}  // namespace lex
