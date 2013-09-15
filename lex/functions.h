#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include <vector>

#include "table.h"

namespace Func
{

	struct Average : lex::StdFunction
	{
		Average();

		virtual ast call(int bar, std::vector<ast_t> ps);

	};
}

#endif