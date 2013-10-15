#ifndef LEX_DATA_H_
#define LEX_DATA_H_

#define SQLITE_OMIT_DEPRECATED
#include "sqlite3.h"

namespace lex{
    class Statement
    {
    public:
        Statement(const char *query) : query_(query), stmt_(nullptr) {}

        void Reset(sqlite3 *db);
        void Bind(int n, const char *text);
        bool Step();
        const char* ColumnText(int n);

    private:
        const char *query_;
        sqlite3_stmt *stmt_;
    };

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
        Statement insert_study_stmt_;
        static const char *select_study_query_;
        Statement select_study_stmt_;
    };
}
#endif  // LEX_DATA_H_
