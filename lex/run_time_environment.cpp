#include "run_time_environment.h"

using namespace Execution;
using namespace Type;


RunTimeEnvironment::RunTimeEnvironment(SetUpEnviroment sue)
{
    num_variables_ = sue.num_variables;
    variable_array_ = new Value[sue.num_variables];
    int initp = 0;
    for (Initialize init : sue.initialize_list)
    {
        Value v = value(init.exp);
        for (int i = 0; i < init.size; i++)variable_array_[initp + i] = v;
        initp += init.size;
    }
}

RunTimeEnvironment::~RunTimeEnvironment()
{
    delete[] variable_array_;
}

Value RunTimeEnvironment::GetVar(int position)
{
    if (position < 0 || position >= num_variables_)
    {
        throw RuntimeException("variable array out of range");
    }
    return variable_array_[position];
}
