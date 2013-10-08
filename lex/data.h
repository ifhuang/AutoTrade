#ifndef LEX_DATA_H_
#define LEX_DATA_H_

//extern "C"{
#define SQLITE_OMIT_DEPRECATED
#include "sqlite3.h"
//}

namespace lex{
    class Data
    {
    public:
        Data();
        ~Data();
        void test();

    private:
        sqlite3 *db;
    };
}
#endif  // LEX_DATA_H_
