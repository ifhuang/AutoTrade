#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include <vector>
#include "execution.h"
#include "table.h"

namespace Func
{

	struct Average : lex::StdFunction
	{
		Average();

		virtual lex::Value call(int bar, std::vector<ast_t> ps);

	};
}

#endif