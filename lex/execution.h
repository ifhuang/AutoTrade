#ifndef EXECUTION_H
# define EXECUTION_H

#include <string>
#include <boost/variant.hpp>

namespace Execution{

	typedef boost::variant<double, bool, std::string> Value;

	struct Internal_exception
	{

	};
}

#endif