#include "data.h"

#include <exception>
#include <string>
#include <boost/lexical_cast.hpp>

using std::exception;
using std::string;
using boost::lexical_cast;

namespace lex{

    

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
        select_study_stmt_.Step();
        return select_study_stmt_.ColumnText(0);
    }




}
