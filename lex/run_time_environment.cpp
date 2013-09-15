#include "run_time_environment.h"

namespace lex{

    RunTimeEnvironment::RunTimeEnvironment(std::vector<RteInitialize> list)
    {
        num_variables_ = 0;
        for (RteInitialize init : list)num_variables_ += init.size;
        variable_array_ = new Value[num_variables_];
        int initp = 0;
        for (RteInitialize init : list)
        {
            for (int i = 0; i < init.size; i++)variable_array_[initp + i] = init.value;
            initp += init.size;
        }
        /*for (Initialize init : sue.initialize_list)
        {
        Value v = exe.value(init.exp);
        for (int i = 0; i < init.size; i++)variable_array_[initp + i] = v;
        initp += init.size;
        }*/
    }

    RunTimeEnvironment::~RunTimeEnvironment()
    {
        delete[] variable_array_;
    }

    Value& RunTimeEnvironment::GetVar(int position)
    {
        if (position < 0 || position >= num_variables_)
        {
            throw RuntimeException("variable array out of range");
        }
        return variable_array_[position];
    }

}  // namespace lex
