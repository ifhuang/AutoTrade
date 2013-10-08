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

}
