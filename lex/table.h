#ifndef TABLE_H_
#define TABLE_H_

#include <string>
#include <unordered_map>
#include <vector>

#include "ast.h"
#include "execution.h"
#include "global.h"
#include "type.h"

namespace lex{
    enum class VSource { StdFunction, Input, Variable, Undefined };

    struct TableInfo
    {
        int inputsNumeric;
        int inputsTF;
        int inputsText;
        int varsNumeric;
        int varsTF;
        int varsText;
    };

    class StdFunction{
    public:
        StdFunction(VType result, std::vector<VType> paras) : result(result), paras(paras) {}

        virtual Value call(int bar, std::vector<Value> ps) const = 0;

        VType result;
        std::vector<VType> paras;
        int min = -1;
    private:
        DISALLOW_COPY_AND_ASSIGN(StdFunction);
    };

    struct Variable{
        VType type;
        int position;
    };

    extern std::unordered_map<std::string, const StdFunction *> const funcTable;
    extern std::unordered_map<std::string, Input> inputTable;
    extern std::unordered_map<std::string, Variable> varTable;

    VSource find_name(std::string name);
    void declare_var(std::string name, int postion, VType type);

}  // namespace lex
#endif  // TABLE_H_
