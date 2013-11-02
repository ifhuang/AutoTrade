#include "program_serialization.h"

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
        //Program p{ nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
        Program p;
        ia >> p;
        return p;
    }
}
