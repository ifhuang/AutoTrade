#include "data_repository.h"

#include "data.h"
#include "program_serialization.h"
using namespace std;
using namespace lex;

void DataRepository::SaveProgram(const std::string &study_name, const Program &p)
{
    const string &s = save(p);
    Data data;
    data.InsertStudy(study_name.c_str(), s.c_str());
}

lex::Program DataRepository::LoadProgram(const std::string &study_name)
{
    Data data;
    string s = data.SelectStudy(study_name.c_str());
    return load(s);
}

vector<LexStudy> DataRepository::ListStudies()
{
    Data data;
    auto studies = data.SelectStudies();
    vector<LexStudy> lex_studies;
    for (auto study : studies)
    {
        LexStudy lex_study;
        std::tie(lex_study.name, lex_study.ready_status) = study;
        lex_studies.push_back(lex_study);
    }
    return lex_studies;
}
