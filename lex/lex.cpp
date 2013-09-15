#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "executor.h"
#include "tree.h"
#include "type.h"
using namespace lex;

int main()
{
    FILE *f = fopen("in.txt", "r");
    int g = elparse(f);
    printf(" %d\n", g);
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
        printf("%s\n", e.what());
        return 0;
    }
    Executor executor(enviroment);
    executor.execute();
    return 0;
}
