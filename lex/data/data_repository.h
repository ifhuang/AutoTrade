#ifndef LEX_DATA_DATA_REPOSITORY_H__
#define LEX_DATA_DATA_REPOSITORY_H__

#include "../type.h"

class DataRepository
{
public:
    static void SaveProgram(const lex::Program &p);
    static lex::Program LoadProgram();
};

#endif  // LEX_DATA_DATA_REPOSITORY_H__
