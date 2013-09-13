#include "exec_visitor.h"

#include <string>
using namespace std;

#include "execution.h"
using namespace Execution;

namespace{
	int get_n_m(ast_t idx)
	{
		if (idx == -1)return -1;
		double dv = check_value<double>(idx);
		return (int)dv;
	}

	string PrintGetString(ast & node)
	{
		static char buff[256];
		int n = get_n_m(node.mid);
		int m = get_n_m(node.right);

		class print_visitor : public boost::static_visitor<>
		{
		public:
			print_visitor(int n, int m) :n_(n), m_(m) {}

			void operator()(double d) const
			{
				if (~n_)
				{
					int m = ~m_ ? m_ : 6;
					_snprintf_s(buff, _TRUNCATE, "%*.*f", n_ + 1 + m, m, d);
				}
				else
				{
					_snprintf_s(buff, _TRUNCATE, "%f", d);
				}
			}

			void operator()(bool d) const
			{
				sprintf_s(buff, d ? "true" : "false");
			}

			void operator()(const string & s) const
			{
				_snprintf_s(buff, _TRUNCATE, "%s", s.c_str());
			}

		private:
			int n_, m_;
		};
		print_visitor pv(n, m);
		boost::apply_visitor(pv, value(node.left));
		return buff;
	}
}

void exec_visitor::operator()(var_stmt & vs) const
{

}

void exec_visitor::operator()(block_stmt & bs) const
{
	exec_stmts(bs.stmts);
}

void exec_visitor::operator()(asm_stmt & as) const
{

}

void exec_visitor::operator()(func_stmt & fs) const
{

}

void exec_visitor::operator()(order_stmt & os) const
{

}

void exec_visitor::operator()(switch_stmt & ws) const
{

}

void exec_visitor::operator()(while_stmt & ws) const
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

void exec_visitor::operator()(for_stmt & fs) const
{

}

void exec_visitor::operator()(once_stmt & os) const
{
	bool con = os.con == -1 || check_value<bool>(os.con);
	if (con)exec(os.stmt);
}

void exec_visitor::operator()(if_stmt & is) const
{
	bool con = check_value<bool>(is.con);
	exec(con ? is.then : is.then);
}

void exec_visitor::operator()(print_stmt & ps) const
{
	if (~ps.list)
	{
		for (ast_t item : astsV[ps.list])
		{
			ast &print = astV[item];
			string s = PrintGetString(print);
			cout << s;
		}
	}
	cout << endl;
}