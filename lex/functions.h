#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include <vector>
#include "execution.h"
#include "table.h"

namespace Func
{

	class SNumToStr : public lex::StdFunction
	{
    public:
        SNumToStr();

        lex::Value call(int bar, std::vector<lex::Value> ps) const;

	};
}

#endif