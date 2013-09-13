#ifndef EXEC_VISITOR_H_
#define EXEC_VISITOR_H_

#include <boost/variant.hpp>

#include "tree.h"

struct exec_visitor : public boost::static_visitor<>
{
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
};

#endif