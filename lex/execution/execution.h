#ifndef LEX_EXECUTION_EXECUTION_H_
#define LEX_EXECUTION_EXECUTION_H_

#include <string>
#include <boost/variant.hpp>

namespace lex
{
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

#endif  // LEX_EXECUTION_EXECUTION_H_
