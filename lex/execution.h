#ifndef EXECUTION_H
# define EXECUTION_H

#include <string>
#include <boost/variant.hpp>

#include "tree.h"

namespace Execution{

	typedef boost::variant<double, bool, std::string> Value;

	struct InternalException
	{

	};

	Value value(ast_t idx);
	void exec(stmt_t stmt);
	void exec_stmts(stmts_t idx);
	void execute();

	template<typename T>
	T check_value(ast_t idx)
	{
		return boost::get<T>(value(idx));
	}
}

#endif