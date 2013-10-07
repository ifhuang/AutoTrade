#include "functions.h"

#include <sstream>
using namespace std;
using namespace lex;

namespace Func
{

    Value SNumToStr::call(int bar, vector<Value> ps) const
    {
        double num = boost::get<double>(ps[0]);
        int dec = static_cast<int>(boost::get<double>(ps[1]));
        stringstream ss;
        ss.precision(dec);
        ss.setf(ios::fixed, ios::floatfield);
        ss << num;
        return ss.str();
    }

    SNumToStr::SNumToStr() : StdFunction(VType::TEXT, { VType::NUMERIC, VType::NUMERIC }) {}

}
