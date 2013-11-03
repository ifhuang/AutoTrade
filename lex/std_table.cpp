#include "std_table.h"

#include <utility>
#include "functions.h"

using std::make_pair;

namespace
{
    const Func::SNumToStr s_numtostr;
}  // namespace

namespace lex
{
    StdTable::StdTable()
    {
        func_table_.insert(make_pair("numtostr", &s_numtostr));
    }

    const StdFunction* StdTable::GetStdFunction(std::string name)
    {
        return func_table_.at(name);
    }
}  // namespace lex
