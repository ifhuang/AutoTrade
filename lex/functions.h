#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "table.h"

namespace Func
{

	struct Average : StdFunction
	{
		Average();

		virtual ast call(int bar, vector<ast_t> ps);

	};
}

#endif