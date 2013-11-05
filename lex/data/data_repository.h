#ifndef LEX_DATA_DATA_REPOSITORY_H__
#define LEX_DATA_DATA_REPOSITORY_H__

#include <vector>
#include "../interface/lex_interface.h"
#include "../program.h"

class DataRepository
{
public:
    static std::vector<lex::LexStudy> ListStudies();
    static void SaveProgram(const std::string &study_name, const lex::Program &p);
    static lex::Program LoadProgram(const std::string &study_name);
};

#endif  // LEX_DATA_DATA_REPOSITORY_H__
