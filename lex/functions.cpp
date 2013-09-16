#include "functions.h"

using namespace std;
using namespace lex;

namespace Func
{

    lex::Value Average::call(int bar, vector<ast_t> ps)
    {
        throw std::exception("The method or operation is not implemented.");
    }

    Average::Average() :StdFunction(VType::NUMERIC, vector<VType>({ VType::NUMERIC, VType::NUMERIC }))	{}

}
