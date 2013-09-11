#include "type.h"

#include <string>
#include <boost/variant.hpp>
#include <boost/lexical_cast.hpp>
using namespace std;

#include "table.h"
#include "tree.h"

namespace Type
{
	SetUpEnviroment enviroment;

	int ReserveSpace(VType value_type, int size = 1)
	{
		if (value_type == VType::VOID)throw exception();
		int vt = static_cast<int>(value_type);

		int position = Type::enviroment.nums[vt];
		Type::enviroment.nums[vt] += size;
		return position;
	}

	VType get_type(ast_t &idx, bool is_input = false);

	string get_var(ast_t idx)
	{
		ast &node = astV[idx];
		if (node.type != NodeType::VAR)throw exception("Internal get_var");
		return strVector[node.idx];
	}

	void check_paras(StdFunction function, asts_t idx, bool is_input = false)
	{
		auto &paras = function.paras;
		if (idx < 0)
		{
			if (!paras.empty() && function.min != 0)
			{
				throw exception("Invalid number of parameters");
			}
			return;
		}
		vector<ast_t> &args = astsV[idx];
		if (function.min == -1 && paras.size() != args.size()
			|| function.min != -1 && paras.size() < args.size())
		{
			throw exception("Invalid number of parameters");
		}
		for (size_t i = 0; i < args.size(); i++)
		{
			VType at = get_type(args[i], is_input);
			if (at != paras[i])
			{
				throw exception("Incorrect argument type");
			}
		}
	}

	VType check_func(ast_t &idx, bool is_input = false)
	{
		ast &func = astV[idx];
		string name = get_var(func.left);
		VSource source = find_name(name);
		switch (source)
		{
		case VSource::StdFunction: {
			StdFunction &function = funcTable[name];
			check_paras(function, func.right, is_input);
			return function.result;
								   }
		case VSource::Input: {
			if (is_input)throw exception("input cannot contain input");
			if (func.right != -2)throw exception("not a function, is input");
			Input input = inputTable[name];
			idx = input.exp;
			return input.type;
							 }
		case VSource::Variable:	{
			if (is_input)throw exception("input cannot contain variable");
			if (func.right != -2)throw exception("not a function, is variable");
			Variable variable = varTable[name];
			return variable.type;
								}
		case VSource::Undefined:
			throw exception("Unknown Function");
		default:
			throw exception();
		}
	}

	VType get_type(ast_t &idx, bool is_input)
	{
		ast &node = astV[idx];
		switch (node.type)
		{
			VType l, r;
		case NodeType::ADD:
			l = get_type(node.left);
			r = get_type(node.right);
			if ((l == VType::NUMERIC || l == VType::TEXT) && l == r)return l;
			throw InvalidTypeOperation();
		case NodeType::SUB:
		case NodeType::MUL:
		case NodeType::DIV:
			l = get_type(node.left);
			r = get_type(node.right);
			if (l == VType::NUMERIC && l == r)return l;
			throw InvalidTypeOperation();
		case NodeType::AND:
		case NodeType::OR:
			l = get_type(node.left);
			r = get_type(node.right);
			if (l == VType::TF && l == r)return l;
			throw InvalidTypeOperation();
		case NodeType::NOT:
			l = get_type(node.left);
			if (l == VType::TF)return l;
			throw InvalidTypeOperation();
		case NodeType::BAR:
			l = get_type(node.left);
			r = get_type(node.right);
			if (r == VType::TEXT)throw InvalidTypeOperation();
			return l;
		case NodeType::UMINUS:
			l = get_type(node.left);
			if (l == VType::NUMERIC)return l;
			throw InvalidTypeOperation();
		case NodeType::NUMERIC:
			node.dv = boost::lexical_cast<double>(strVector[node.idx]);
			return VType::NUMERIC;
		case NodeType::TF:
			return VType::TF;
		case NodeType::TEXT:
			return VType::TEXT;
		case NodeType::EQ:
		case NodeType::NE:
			l = get_type(node.left);
			r = get_type(node.right);
			if (l == r)return l;
			throw InvalidTypeOperation();
		case NodeType::GT:
		case NodeType::LT:
		case NodeType::GE:
		case NodeType::LE:
			l = get_type(node.left);
			r = get_type(node.right);
			if ((l == VType::NUMERIC || l == VType::TEXT) && l == r)return l;
			throw InvalidTypeOperation();
		case NodeType::CA:
		case NodeType::CB:
			l = get_type(node.left);
			r = get_type(node.right);
			if (l == VType::NUMERIC && l == r)return l;
			throw InvalidTypeOperation();
		case NodeType::FUNC:
			return check_func(idx, is_input);
		default:
			throw exception();
		}
	}

	void check(stmt_t stmt);

	void check_stmts(stmts_t idx)
	{
		for (stmt_t stmt : stmtsV[idx])
		{
			check(stmt);
		}
	}

	struct check_visitor : public boost::static_visitor<>
	{
		void operator()(if_stmt & is) const
		{
			if (get_type(is.con) != VType::TF)throw LogicalExpressionExpected();
			check(is.then);
			check(is.els);
		}

		void operator()(once_stmt & os) const
		{
			if (get_type(os.con) != VType::TF)throw LogicalExpressionExpected();
			check(os.stmt);
		}

		void operator()(for_stmt & fs) const
		{
			string name = get_var(fs.var);
			VSource source = find_name(name);
			if (source != VSource::Variable)
			{
				throw exception("array or varable expected");
			}
			Variable var = varTable[name];
			if (var.type != VType::NUMERIC)
			{
				throw TypesNotCompatible();
			}
			VType ft = get_type(fs.from);
			if (ft == VType::TEXT)throw TypesNotCompatible();
			VType tt = get_type(fs.to);
			if (tt == VType::TEXT)throw TypesNotCompatible();
			check(fs.block);
		}

		void operator()(while_stmt & ws) const
		{
			if (get_type(ws.con) != VType::TF)throw LogicalExpressionExpected();
			check(ws.block);
		}

		void operator()(switch_stmt & ws) const
		{

		}

		void operator()(order_stmt & os) const
		{

		}

		void operator()(func_stmt & fs) const
		{
			check_func(fs.func);
		}

		static void check_asm_variable(string name, asm_stmt &as)
		{
			Variable var = varTable[name];
			switch (var.type)
			{
			case VType::NUMERIC:
				break;
			case VType::TEXT:
			case VType::TF:
				if (as.type != 0)throw InvalidTypeOperation();
				break;
			}
			VType rightType = get_type(as.exp);
			if (var.type != rightType)
			{
				throw TypesNotCompatible();
			}
		}

		void operator()(asm_stmt & as) const
		{
			string name = get_var(as.var);
			VSource source = find_name(name);
			switch (source)
			{
			case VSource::Variable:
				check_asm_variable(name, as);
				break;
			default:
				throw exception("array or varable expected");
			}
		}

		void operator()(block_stmt & bs) const
		{
			check_stmts(bs.stmts);
		}

		void operator()(var_stmt & vs) const
		{
			for (ast_t idx : astsV[vs.vars])
			{
				ast &var = astV[idx];
				string name = get_var(var.left);
				VSource source = find_name(name);
				if (source != VSource::Undefined)
				{
					throw exception("this word has already been defined");
				}
				VType type = get_type(var.right);
				int position = ReserveSpace(type);
				declare_var(name, position, type);
			}
		}

		void operator()(print_stmt & ps) const
		{

		}
	};

	void check(stmt_t stmt)
	{
		if (stmt == -1)return;
		boost::apply_visitor(check_visitor(), stmtV[stmt]);
	}

	void check_input()
	{
		for (ast_t idx : inputVector)
		{
			ast &input = astV[idx];
			if (input.type == NodeType::IBPVARDEC)
			{
				throw exception("This attribute can be applied only for variables");
			}
			string name = get_var(input.left);
			VSource source = find_name(name);
			if (source != VSource::Undefined)
			{
				throw exception("this word has already been defined");
			}
			VType type = get_type(input.right, true);
			Input in;
			in.name = name;
			in.type = type;
			in.exp = input.right;
			inputTable[name] = in;
			enviroment.inputs.push_back(in);
		}
	}

	void type_check()
	{
		check_input();
		check_stmts(root);
	}
}