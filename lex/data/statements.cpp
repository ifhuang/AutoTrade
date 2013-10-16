#include "statements.h"

#include <exception>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>

using std::exception;
using std::string;
using std::vector;
using boost::lexical_cast;

namespace lex
{
    Statement::~Statement()
    {
        if (!stmt_)sqlite3_finalize(stmt_);
    }

    void Statement::Reset(sqlite3 *db)
    {
        if (!stmt_)
        {
            int return_code = sqlite3_prepare_v2(db, query_.c_str(), -1, &stmt_, nullptr);
            if (return_code != SQLITE_OK)
            {
                throw exception("error code " + return_code);
            }
            parameter_count_ = sqlite3_bind_parameter_count(stmt_);
        }
        else
        {
            sqlite3_reset(stmt_);
        }
    }

    void Statement::Bind(int n, const char *text)
    {
        if (n > parameter_count_)return;
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

    bool Statement::ColumnBool(int n)
    {
        return sqlite3_column_int(stmt_, n);
    }

    void lex::Statements::Reset(sqlite3 *db)
    {
        if (!initialized_)Initialize();
        for (Statement &stmt : stmts_)
        {
            stmt.Reset(db);
        }
    }

    void Statements::Initialize()
    {
        vector<string> query_vector;
        boost::split(query_vector, query_, boost::is_any_of(";"));
        for (string query : query_vector)
        {
            boost::trim(query);
            if (query.empty())continue;
            stmts_.push_back(Statement(query));
        }
        initialized_ = true;
    }

    void Statements::Bind(int n, const char *text)
    {
        for (Statement &stmt : stmts_)
        {
            stmt.Bind(n, text);
        }
    }

    void Statements::Step()
    {
        for (Statement &stmt : stmts_)
        {
            stmt.Step();
        }
    }

}