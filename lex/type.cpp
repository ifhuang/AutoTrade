#include "type.h"

#include "bison/front.h"
#include "data/data_repository.h"
#include "table.h"
#include "type_checker.h"

namespace lex
{
    int SetUpEnviroment::ReserveSpace(ast_t exp, int size /*= 1*/)
    {
        int position = num_variables;
        num_variables += size;
        Initialize init;
        init.size = size;
        init.exp = exp;
        initialize_list.push_back(init);
        return position;
    }

    void init()
    {
        init_table();
    }

    void storage(TypeChecker &checker)
    {
        Program p = { root, &checker.enviroment_, &strVector, &astV, &astsV, &stmtV, &stmtsV };
        DataRepository::SaveProgram(p);
    }

    void type_check()
    {
        init();
        TypeChecker checker;
        checker.check();
        storage(checker);
    }
}  // namespace lex
