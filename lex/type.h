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

	class SemanticError : public std::exception
	{
	public:
		SemanticError() {}
		SemanticError(const char * const & message) : exception(message) {}
	};

	struct InvalidTypeOperation : SemanticError{
		InvalidTypeOperation() : SemanticError("invalid type operation") {}
	};

	struct LogicalExpressionExpected : SemanticError{
		LogicalExpressionExpected() : SemanticError("logical expression expected") {}
	};

	struct TypesNotCompatible : SemanticError{
		TypesNotCompatible() : SemanticError("types not compatible") {}
	};

	void type_check();
}

#endif