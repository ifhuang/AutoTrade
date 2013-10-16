#ifndef LEX_DATA_STATEMENTS_H__
#define LEX_DATA_STATEMENTS_H__

#include <string>
#include <vector>
#define SQLITE_OMIT_DEPRECATED
#include "sqlite3.h"

namespace lex{

    class Statement
    {
    public:
        Statement(const std::string &query) : query_(query), stmt_(nullptr) {}

        void Reset(sqlite3 *db);
        void Bind(int n, const char *text);
        bool Step();
        const char* ColumnText(int n);
        bool ColumnBool(int n);

    private:
        const std::string query_;
        sqlite3_stmt *stmt_;
        int parameter_count_;
    };

    class Statements
    {
    public:
        Statements(const char *query) : query_(query) {}

        void Reset(sqlite3 *db);
        void Bind(int n, const char *text);
        void Step();
        const char* ColumnText(int n);

    private:
        void Initialize();

        const char *query_;
        bool initialized_ = false;
        std::vector<Statement> stmts_;
    };
}
#endif  // LEX_DATA_STATEMENTS_H__
