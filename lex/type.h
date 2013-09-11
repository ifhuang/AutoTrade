#ifndef TYPE_H
# define TYPE_H

#include <string>
#include <vector>

#include "ast.h"

enum class VType { NUMERIC, TF, TEXT, VOID };

namespace Type{

	struct Input
	{
		std::string name;
		VType type;
		std::string exp_string;
		ast_t exp;
	};

	struct Initialize{
		int position;
		int size;
		ast_t exp;
	};

	struct SetUpEnviroment{
		std::vector<Input> inputs;
		int nums[3];
		std::vector<Initialize> initialize_list[3];
	};

	struct Invalid_type_operation{

	};

	struct Logical_expression_expected
	{

	};

	struct Types_are_not_compatible
	{

	};
}

#endif