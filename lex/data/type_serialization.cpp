#include "type_serialization.h"

#include <sstream>
using namespace std;
using namespace lex;

namespace lex{
    string save(const Program &p)
    {
        stringstream ss;
        boost::archive::text_oarchive oa(ss);
        oa << p;
        return ss.str();
    }

    Program load(const std::string &s)
    {
        stringstream ss(s);
        boost::archive::text_iarchive ia(ss);
        Program p{ new SetUpEnviroment(), new vector<string>(), new VV<ast>(),
            new VV<vector<ast_t> >(), new VV<stmt>(), new VV<vector<stmt_t> >() };
        ia >> p;
        return p;
    }
}
