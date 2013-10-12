#include "data.h"

namespace lex{
    Data::Data()
    {
        sqlite3_open("lex.db", &db);
    }

    Data::~Data()
    {
        sqlite3_close(db);
    }

    void Data::test()
    {
        char *error_message;
        sqlite3_exec(db, "insert into a values ('1',1)", nullptr, 0, &error_message);
    }

    void Data::InsertStudy(const char *program)
    {
        if (!insert_study_stmt_)
        {
            const char *query = "insert into study values(?, 1, 1, ?)";
            sqlite3_prepare_v2(db, query, -1, &insert_study_stmt_, nullptr);
        }
        else
        {
            sqlite3_reset(insert_study_stmt_);
        }
        sqlite3_bind_text(insert_study_stmt_, 1, "test", -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(insert_study_stmt_, 2, program, -1, SQLITE_TRANSIENT);
        sqlite3_step(insert_study_stmt_);
    }

    const unsigned char * Data::SelectStudy()
    {
        if (!select_study_stmt_)
        {
            const char *query = "select program from study where name = ?";
            sqlite3_prepare_v2(db, query, -1, &select_study_stmt_, nullptr);
        }
        else
        {
            sqlite3_reset(select_study_stmt_);
        }
        sqlite3_bind_text(select_study_stmt_, 1, "test", -1, SQLITE_TRANSIENT);
        sqlite3_step(select_study_stmt_);
        return sqlite3_column_text(select_study_stmt_, 1);
    }
}
