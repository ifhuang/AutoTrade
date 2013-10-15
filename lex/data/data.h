#ifndef LEX_DATA_H_
#define LEX_DATA_H_

#include "statements.h"

namespace lex{
    

    class Data
    {
    public:
        Data();
        ~Data();
        void InsertStudy(const char *program);
        const char * SelectStudy();
        void test();

    private:
        sqlite3 *db;

        static const char *insert_study_query_;
        Statements insert_study_stmt_;
        static const char *select_study_query_;
        Statement select_study_stmt_;
    };
}
#endif  // LEX_DATA_H_
