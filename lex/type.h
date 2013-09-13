#ifndef TYPE_H
# define TYPE_H

#include <string>
#include <vector>

#include "tree.h"

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

	class SetUpEnviroment{
	public:
		int ReserveSpace(VType value_type, ast_t exp, int size = 1);

		std::vector<Input> inputs;

	private:
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

	extern int kAstTrue;
	extern SetUpEnviroment enviroment;

	VType get_type(ast_t &idx, bool is_input = false);
	std::string get_var(ast_t idx);
	VType check_func(ast_t &idx, bool is_input = false);
	void check(stmt_t stmt);
	void check_stmts(stmts_t idx);
	void type_check();
}

#endif