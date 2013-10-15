#include "data_repository.h"

#include "data.h"
#include "type_serialization.h"
using namespace std;
using namespace lex;

void DataRepository::SaveProgram(const Program &p)
{
    const string &s = save(p);
    Data data;
    data.InsertStudy(s.c_str());
}

lex::Program DataRepository::LoadProgram()
{
    Data data;
    string s = data.SelectStudy();
    return load(s);
}
