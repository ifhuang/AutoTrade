#include "run_time_environment.h"

namespace lex
{
    RunTimeEnvironment::RunTimeEnvironment(const Program &p) : program_(p),
        initialized_(false)
    {
        auto &inputs = p.sue.inputs;
        num_inputs_ = inputs.size();
        inputs_array_ = new int[num_inputs_];
        for (int i = 0; i < num_inputs_; i++)
        {
            inputs_array_[i] = inputs[i].exp;
        }
    }

    RunTimeEnvironment::~RunTimeEnvironment()
    {
        delete[] variable_array_;
        delete[] inputs_array_;
    }

    bool RunTimeEnvironment::Initialized()
    {
        return initialized_;
    }

    void RunTimeEnvironment::Initialize(std::vector<RteInitialize> list)
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
        initialized_ = true;
    }

    Value& RunTimeEnvironment::GetVar(int position)
    {
        if (position < 0 || position >= num_variables_)
        {
            throw RuntimeException("variable array out of range");
        }
        return variable_array_[position];
    }

    ast_t RunTimeEnvironment::GetInput(int id)
    {
        if (id < 0 || id >= num_inputs_)
        {
            throw RuntimeException("input array out of range");
        }
        int idx = inputs_array_[id];
        return idx;
    }

}  // namespace lex
