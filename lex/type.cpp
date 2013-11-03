#include "type.h"

#include "bison/front.h"
#include "data/data_repository.h"
#include "table.h"
#include "type_checker.h"

namespace lex
{
    void storage(const TypeChecker &checker)
    {
        Program p = checker.GetProgram();
        DataRepository::SaveProgram(p);
    }

    void type_check()
    {
        TypeChecker checker;
        checker.Check();
        storage(checker);
    }
}  // namespace lex
