#ifndef LEX_CHECK_VISITOR_H_
#define LEX_CHECK_VISITOR_H_

#include <string>
#include <boost/variant.hpp>

#include "global.h"
#include "tree.h"
#include "type_checker.h"

namespace lex
{
    class CheckVisitor : public boost::static_visitor<>
    {
    public:
        CheckVisitor(TypeChecker &checker) : checker_(checker) {}

        void operator()(if_stmt & is) const;

        void operator()(once_stmt & os) const;

        void operator()(for_stmt & fs) const;

        void operator()(while_stmt & ws) const;

        void operator()(switch_stmt & ws) const;

        void operator()(order_stmt & os) const;

        void operator()(func_stmt & fs) const;

        void operator()(asm_stmt & as) const;

        void operator()(block_stmt & bs) const;

        void operator()(var_stmt & vs) const;

        void operator()(print_stmt & ps) const;

    private:
        void check_asm_variable(std::string name, asm_stmt &as) const;
        int check_n_m(ast &print) const;

        TypeChecker &checker_;
        DISALLOW_COPY_AND_ASSIGN(CheckVisitor);
    };
}
#endif  // LEX_CHECK_VISITOR_H_
