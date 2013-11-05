#include "type.h"

#include "bison/front.h"
#include "data/data_repository.h"
#include "table.h"
#include "type_checker.h"

namespace lex
{
    void type_check(const std::string &study_name)
    {
        TypeChecker checker;
        checker.Check();
        Program p = checker.GetProgram();
        DataRepository::SaveProgram(study_name, p);
    }
}  // namespace lex
