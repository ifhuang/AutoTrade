#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
    Executor executor(enviroment);
    executor.execute();
    return 0;
}
