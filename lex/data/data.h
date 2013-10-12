#ifndef LEX_DATA_H_
#define LEX_DATA_H_

#define SQLITE_OMIT_DEPRECATED
#include "sqlite3.h"

namespace lex{
    class Data
    {
    public:
        Data();
        ~Data();
        void InsertStudy(const char *program);
        const unsigned char * SelectStudy();
        void test();
    private:
        sqlite3 *db;

        sqlite3_stmt *insert_study_stmt_ = nullptr;
        sqlite3_stmt *select_study_stmt_ = nullptr;
    };
}
#endif  // LEX_DATA_H_
