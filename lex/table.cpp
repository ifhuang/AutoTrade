#include "table.h"

#include <stdio.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <boost/variant.hpp>
using namespace std;

#include "functions.h"

namespace{
    const Func::SNumToStr s_numtostr;
}

namespace lex{
    unordered_map<string, const StdFunction *> const funcTable = {
        { "numtostr", &s_numtostr },
    };
    unordered_map<string, Input> inputTable;
    unordered_map<string, Variable> varTable;

    VSource find_name(string name)
    {
        if (funcTable.count(name))return VSource::StdFunction;
        if (inputTable.count(name))return VSource::Input;
        if (varTable.count(name))return VSource::Variable;
        return VSource::Undefined;
    }

    void declare_var(string name, int postion, VType type)
    {
        Variable var;
        var.position = postion;
        var.type = type;
        varTable[name] = var;
    }

}  // namespace lex
