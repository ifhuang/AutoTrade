#include "execution.h"

#include <string>
#include <boost/variant.hpp>
#include <boost/lexical_cast.hpp>
using namespace std;

#include "operator.h"
#include "table.h"
#include "tree.h"
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

	void exec(stmt_t stmt);

	void exec_stmts(stmts_t idx)
	{
		for (stmt_t stmt : stmtsV[idx])
		{
			exec(stmt);
		}
	}

	template<typename T>
	T check_value(ast_t idx)
	{
		return boost::get<T>(value(idx));
	}

	struct exec_visitor : public boost::static_visitor<>
	{
		void operator()(if_stmt & is) const
		{
			bool con = check_value<bool>(is.con);
			exec(con ? is.then : is.then);
		}

		void operator()(once_stmt & os) const
		{
			bool con = check_value<bool>(os.con);
			if (con)exec(os.stmt);
		}

		void operator()(for_stmt & fs) const
		{
			
		}

		void operator()(while_stmt & ws) const
		{
			if (ws.type == 0)
			{
				while (check_value<bool>(ws.con))
				{
					exec(ws.block);
				}
			}
			else
			{
				do 
				{
					exec(ws.block);
				} while (check_value<bool>(ws.con));
			}
		}

		void operator()(order_stmt & os) const
		{

		}

		void operator()(func_stmt & fs) const
		{
			
		}

		static void check_asm_variable(string name, asm_stmt &as)
		{
			
		}

		void operator()(asm_stmt & as) const
		{
			
		}

		void operator()(block_stmt & bs) const
		{
			exec_stmts(bs.stmts);
		}

		void operator()(var_stmt & vs) const
		{
			
		}

		void operator()(print_stmt & ps) const
		{

		}
	};

	void exec(stmt_t stmt)
	{
		if (stmt == -1)return;
		//boost::apply_visitor(exec_visitor(), stmtV[stmt]);
	}



	void execute()
	{

	}
}