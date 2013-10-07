#ifndef EXECUTION_H
# define EXECUTION_H

#include <string>
#include <boost/variant.hpp>

#include "tree.h"

namespace lex{

	typedef boost::variant<double, bool, std::string> Value;

    class RuntimeException : public std::exception
    {
    public:
        RuntimeException() {}
        RuntimeException(const char * const & message) : exception(message) {}
    };

	struct InternalException
	{

	};

	
}  // namespace lex

#endif
