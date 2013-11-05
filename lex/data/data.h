#ifndef LEX_DATA_DATA_H_
#define LEX_DATA_DATA_H_

#include <string>
#include <tuple>
#include <vector>
#include "statements.h"

namespace lex
{
    class Data
    {
    public:
        Data();
        Data(const char *database_file);
        ~Data();
        void InsertStudy(const char *name, const char *program);
        const char * SelectStudy(const char *name);
        std::vector<std::tuple<std::string, bool> > SelectStudies();

    private:
        void Open(const char *database_file);

        sqlite3 *db;

        static const char *insert_study_query_;
        Statements insert_study_stmt_;

        static const char *select_study_query_;
        Statement select_study_stmt_;

        static const char *select_studies_query_;
        Statement select_studies_stmt_;
    };
}  // namespace lex
#endif  // LEX_DATA_DATA_H_
