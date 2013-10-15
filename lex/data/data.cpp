#include "data.h"

#include <exception>
#include <string>
#include <boost/lexical_cast.hpp>

using std::exception;
using std::string;
using boost::lexical_cast;

namespace lex{

    void Statement::Reset(sqlite3 *db)
    {
        if (!stmt_)
        {
            int return_code = sqlite3_prepare_v2(db, query_, -1, &stmt_, nullptr);
            if (return_code != SQLITE_OK)
            {
                throw exception("error code " + return_code);
            }
        }
        else
        {
            sqlite3_reset(stmt_);
        }
    }

    void Statement::Bind(int n, const char *text)
    {
        int return_code = sqlite3_bind_text(stmt_, n, text, -1, SQLITE_TRANSIENT);
        if (return_code != SQLITE_OK)
        {
            throw exception(("error code " + lexical_cast<string>(return_code)).c_str());
        }
    }

    bool Statement::Step()
    {
        int return_code = sqlite3_step(stmt_);
        if (return_code != SQLITE_ROW && return_code != SQLITE_DONE)
        {
            throw exception(("error code " + lexical_cast<string>(return_code)).c_str());
        }
        return return_code == SQLITE_ROW;
    }

    const char* Statement::ColumnText(int n)
    {
        return reinterpret_cast<const char*>(sqlite3_column_text(stmt_, n));
    }

    Data::Data() : insert_study_stmt_(insert_study_query_), select_study_stmt_(select_study_query_)
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

    const char* Data::insert_study_query_ = "begin transaction;"
        "delete from study where name = ?001;"
        "insert into study values(?001, 1, 1, ?002);"
        "commit;";

    void Data::InsertStudy(const char *program)
    {
        char *error_message = nullptr;
        int error_code = sqlite3_exec(db, insert_study_query_, nullptr, nullptr, &error_message);
        string em;
        if (error_message)
        {
            em = error_message;
            sqlite3_free(error_message);
        }
        if (error_code != SQLITE_OK || !em.empty())
        {
            throw exception(("error code " + lexical_cast<string>(error_code)+":" + em).c_str());
        }
    }

    const char* Data::select_study_query_ = "select program from study where name = ?";

    const char* Data::SelectStudy()
    {
        select_study_stmt_.Reset(db);
        select_study_stmt_.Bind(1, "text");
        select_study_stmt_.Step();
        return select_study_stmt_.ColumnText(0);
    }




}
