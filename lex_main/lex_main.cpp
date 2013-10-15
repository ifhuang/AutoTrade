#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "../lex/data/data_repository.h"
#include "../lex/executor.h"
#include "../lex/tree.h"
#include "../lex/type.h"
using namespace lex;

int main()
{
    FILE *f = fopen("in.txt", "r");
    int g = elparse(f);
    fclose(f);
    if (g)
    {
        printf("%s\n", errorMessage.c_str());
        return g;
    }

    try
    {
        type_check();
    }
    catch (SemanticError e)
    {
        printf("(%s): error: ", location_print(e.loc_).c_str());
        printf("%s\n", e.what());
        return 0;
    }
    Program p = DataRepository::LoadProgram();
    Executor executor(&p);
    executor.execute();
    delete p.sue;
    delete p.strVector;
    delete p.astV;
    delete p.astsV;
    delete p.stmtV;
    delete p.stmtsV;
    return 0;
}
