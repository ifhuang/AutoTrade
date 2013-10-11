#include "type_serialization.h"

#include <sstream>
using namespace std;

std::string lex::save(Program &p)
{
    stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << p;
    return ss.str();
}
