#ifndef LEX_EXEC_VISITOR_H_
#define LEX_EXEC_VISITOR_H_

#include <boost/variant.hpp>

#include "abstract_executor.h"
#include "global.h"
#include "tree.h"

namespace lex
{
    class ExecVisitor : public boost::static_visitor<>
    {
    public:
        ExecVisitor(AbstractExecutor &exe);

        void operator()(const if_stmt & is) const;
        void operator()(const once_stmt & os) const;
        void operator()(const for_stmt & fs) const;
        void operator()(const while_stmt & ws) const;
        void operator()(const switch_stmt & ws) const;
        void operator()(const order_stmt & os) const;
        void operator()(const func_stmt & fs) const;
        void operator()(const asm_stmt & as) const;
        void operator()(const block_stmt & bs) const;
        void operator()(const var_stmt & vs) const;
        void operator()(const print_stmt & ps) const;

    private:
        int get_n_m(ast_t idx) const;

        AbstractExecutor &exe_;
        DISALLOW_COPY_AND_ASSIGN(ExecVisitor);
    };
}  // namespace lex
#endif  // LEX_EXEC_VISITOR_H_
