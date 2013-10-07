#ifndef EXEC_VISITOR_H_
#define EXEC_VISITOR_H_

#include <boost/variant.hpp>

#include "executor.h"
#include "global.h"
#include "tree.h"

class exec_visitor : public boost::static_visitor<>
{
public:
    exec_visitor(lex::Executor *exe);

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
    int get_n_m(ast_t idx) const;

    lex::Executor *exe_;
    DISALLOW_COPY_AND_ASSIGN(exec_visitor);
};

#endif  // EXEC_VISITOR_H_
