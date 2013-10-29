#include "data.h"

#include <exception>
#include <string>
#include <tuple>
#include <boost/lexical_cast.hpp>

using std::exception;
using std::string;
using std::tuple;
using std::vector;
using boost::lexical_cast;

namespace lex
{
    void Data::Open(const char *database_file)
    {
        int return_code = sqlite3_open(database_file, &db);
        if (return_code != SQLITE_OK)
        {
            throw exception(("error code " + lexical_cast<string>(return_code)).c_str());
        }
    }

    Data::Data(const char *database_file)
        : insert_study_stmt_(insert_study_query_),
        select_study_stmt_(select_study_query_),
        select_studies_stmt_(select_studies_query_)
    {
        Open(database_file);
    }

    Data::Data()
        : insert_study_stmt_(insert_study_query_),
        select_study_stmt_(select_study_query_),
        select_studies_stmt_(select_studies_query_)
    {
        Open("lex.db");
    }

    Data::~Data()
    {
        sqlite3_close(db);
    }

    const char* Data::insert_study_query_ = "begin transaction;"
        "delete from study where name = ?1;"
        "insert into study values(?1, 1, 1, ?2);"
        "commit;";

    void Data::InsertStudy(const char *program)
    {
        insert_study_stmt_.Reset(db);
        insert_study_stmt_.Bind(1, "test");
        insert_study_stmt_.Bind(2, program);
        insert_study_stmt_.Step();
    }

    const char* Data::select_study_query_ = "select program from study where name = ?";

    const char* Data::SelectStudy()
    {
        select_study_stmt_.Reset(db);
        select_study_stmt_.Bind(1, "test");
        if (!select_study_stmt_.Step())return nullptr;
        return select_study_stmt_.ColumnText(0);
    }

    const char* Data::select_studies_query_ = "select * from study";

    vector<tuple<string, bool> > Data::SelectStudies()
    {
        Statement &stmt = select_studies_stmt_;
        stmt.Reset(db);
        vector<tuple<string, bool> > studies;
        while (stmt.Step())
        {
            tuple<string, bool> study(stmt.ColumnText(0), stmt.ColumnBool(1));
            studies.push_back(study);
        }
        return studies;
    }

}  // namespace lex
