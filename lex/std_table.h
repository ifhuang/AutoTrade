#ifndef LEX_STD_TABLE_H_
#define LEX_STD_TABLE_H_

#include <string>
#include <unordered_map>
#include <vector>
#include "execution/execution.h"
#include "global.h"
#include "program.h"

namespace lex
{
    class StdFunction
    {
    public:
        StdFunction(VType result, std::vector<VType> paras) : result(result), paras(paras), min(-1) {}

        virtual Value call(int bar, std::vector<Value> ps) const = 0;

        VType result;
        std::vector<VType> paras;
        int min;
    private:
        DISALLOW_COPY_AND_ASSIGN(StdFunction);
    };

    class StdTable
    {
    public:
        StdTable();
        const StdFunction* GetStdFunction(std::string name);

    protected:
        std::unordered_map<std::string, const StdFunction *> func_table_;
    };

}  // namespace lex
#endif  // LEX_STD_TABLE_H_
