#include <cstdio>
#include <cstring>

#include "../lex/interface/lex_factory.h"

void PrintUsage(char *name)
{
    printf("Usage:\n");
    printf("%s <signal name> <input file> compile signal\n", name);
    printf("%s -l                         list studies\n", name);
}

void ListStudies()
{
    printf("%-20s ready status\n", "program name");
    for (int i = 0; i < 33; i++)putchar('-');
    putchar('\n');

    lex::LexInterface *li = lex::LexFactory::CreateLexInterface();
    auto studies = li->ListStudies();
    for (auto study : studies)
    {
        printf("%-20s %s\n", study.name.c_str(), study.ready_status ? "yes" : "no");
    }
}

void Compiler(char *signal_name, char *input_file)
{
    lex::LexInterface *li = lex::LexFactory::CreateLexInterface();
    li->Compiler(signal_name, input_file);
}

int main(int argc, char **argv)
{
    switch (argc)
    {
    case 2:
        if (strcmp(argv[1], "-l") == 0)
        {
            ListStudies();
            return 0;
        }
        break;
    case 3:
        Compiler(argv[1], argv[2]);
        return 0;
    }
    PrintUsage(argv[0]);
    return 0;
}
