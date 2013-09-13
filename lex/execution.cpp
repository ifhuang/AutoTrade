#include "execution.h"

#include <iostream>
#include <boost/lexical_cast.hpp>
using namespace std;

#include "exec_visitor.h"
#include "operator.h"
#include "table.h"
#include "type.h"

namespace Execution{

	Value value(ast_t idx)
	{
		ast &n = astV[idx];
		switch (n.type)
		{
		case NodeType::ADD:
			return boost::apply_visitor(add_visitor(), value(n.left), value(n.right));
		case NodeType::SUB:
			return boost::apply_visitor(sub_visitor(), value(n.left), value(n.right));
		case NodeType::MUL:
			return boost::apply_visitor(mul_visitor(), value(n.left), value(n.right));
		case NodeType::DIV:
			return boost::apply_visitor(div_visitor(), value(n.left), value(n.right));
		case NodeType::AND:
			return boost::apply_visitor(and_visitor(), value(n.left), value(n.right));
		case NodeType::OR:
			return boost::apply_visitor(or_visitor(), value(n.left), value(n.right));
		case NodeType::NOT:
			return boost::apply_visitor(not_visitor(), value(n.left));
		case NodeType::BAR:
			return boost::apply_visitor(or_visitor(), value(n.left), value(n.right));
		case NodeType::UMINUS:
			return boost::apply_visitor(not_visitor(), value(n.left));
		case NodeType::NUMERIC:
			return n.dv;
		case NodeType::TF:
			return n.bv;
		case NodeType::TEXT:
			return strVector[n.idx];
		case NodeType::EQ:
			return boost::apply_visitor(eq_visitor(), value(n.left), value(n.right));
		case NodeType::NE:
			return boost::apply_visitor(ne_visitor(), value(n.left), value(n.right));
		case NodeType::GT:
			return boost::apply_visitor(gt_visitor(), value(n.left), value(n.right));
		case NodeType::LT:
			return boost::apply_visitor(gt_visitor(), value(n.right), value(n.left));
		case NodeType::GE:
			return boost::apply_visitor(ge_visitor(), value(n.left), value(n.right));
		case NodeType::LE:
			return boost::apply_visitor(ge_visitor(), value(n.right), value(n.left));
		case NodeType::CA:
			return boost::apply_visitor(ca_visitor(), value(n.left), value(n.right));
		case NodeType::CB:
			return boost::apply_visitor(ca_visitor(), value(n.right), value(n.left));
		case NodeType::FUNC:
			//return check_func(idx);
		default:
			throw exception();
		}
		return double(0.0);
	}

	void exec_stmts(stmts_t idx)
	{
		for (stmt_t stmt : stmtsV[idx])
		{
			exec(stmt);
		}
	}

	void exec(stmt_t stmt)
	{
		if (stmt == -1)return;
		boost::apply_visitor(exec_visitor(), stmtV[stmt]);
	}

	void execute()
	{
		exec_stmts(root);
	}
}