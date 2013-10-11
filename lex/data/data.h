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
        void test();

    private:
        sqlite3 *db;

        sqlite3_stmt *insert_study_stmt_ = nullptr;
    };
}
#endif  // LEX_DATA_H_
