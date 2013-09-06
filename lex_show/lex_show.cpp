#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <unordered_map>
#include <boost/algorithm/string.hpp>
using namespace std;
#include "..\lex\tree.h"

#define ADDNAME(x) enumName[NodeType::x] = #x

int elparse(FILE *f);

namespace{
	unordered_map<NodeType, string> enumName;

	void initName()
	{
		ADDNAME(ADD);
		ADDNAME(SUB);
		ADDNAME(MUL);
		ADDNAME(DIV);
		ADDNAME(AND);
		ADDNAME(OR);
		ADDNAME(NOT);
		ADDNAME(BAR);
		ADDNAME(UMINUS);

		ADDNAME(VARDEC);
		ADDNAME(IBPVARDEC);

		ADDNAME(NUMERIC);
		ADDNAME(TF);
		ADDNAME(TEXT);

		ADDNAME(VAR);
		ADDNAME(FUNC);

		ADDNAME(EQ);
		ADDNAME(GT);
		ADDNAME(LT);
		ADDNAME(NE);
		ADDNAME(GE);
		ADDNAME(LE);
		ADDNAME(CA);
		ADDNAME(CB);
	}

	FILE *fp;
	int tot;
	int cstot;

	int it;

	void fpr(const char *s, ...)
	{
		va_list ap;
		va_start(ap, s);
		fprintf(fp, "%*s", it * 2, "");
		vfprintf(fp, s, ap);
		va_end(ap);
	}

	int snode(int p, const string s)
	{
		int id = tot++;
		string t = boost::replace_all_copy(s, "\"", "\\\"");
		fpr("%d[label=\"%s\"];\n", id, t.c_str());
		if (~p)
		{
			fpr("%d -> %d;\n", p, id);
		}
		return id;
	}

	void dfs(int p, ast_t i)
	{
		if (i == -1)return;
		ast &node = astV[i];
		int id = tot++;
		fpr("%d[label=%s];\n", id, enumName[node.type].c_str());
		if (~p)
		{
			fpr("%d -> %d;\n", p, id);
		}
		switch (node.type)
		{
		case NodeType::NUMERIC:
		case NodeType::TEXT:
		case NodeType::VAR:
			snode(id, strVector[node.idx]);
			break;
		case NodeType::TF:
			snode(id, node.bv ? "TRUE" : "FALSE");
			break;
		case NodeType::FUNC:
			dfs(id, node.left);
			if (~node.right)
			{
				int argu = snode(id, "ARGU");
				for (ast_t ast : astsV[node.right])
				{
					dfs(argu, ast);
				}
			}
			break;
		default:
			dfs(id, node.left);
			dfs(id, node.right);
			break;
		}
	}

	void dfs_stmts(int p, stmts_t stmts);
	void dfs_stmt(int p, stmt_t stmt);

	int blockp;

	struct stmt_visitor : public boost::static_visitor<int>
	{
		inline static int fpr_stmt(const char *label)
		{
			int id = tot++;
			fpr("%d[label=%s, shape=parallelogram]\n", id, label);
			return id;
		}

		int operator()(if_stmt & is) const
		{
			int id = fpr_stmt("IF");
			dfs(id, is.con);
			int t = snode(id, "THEN");
			dfs_stmt(t, is.then);
			if (~is.els)
			{
				int e = snode(id, "ELSE");
				dfs_stmt(e, is.els);
			}
			return id;
		}

		int operator()(once_stmt & os) const
		{
			int id = fpr_stmt("ONCE");
			dfs(id, os.con);
			int t = snode(id, "THEN");
			dfs_stmt(t, os.stmt);
			return id;
		}

		int operator()(for_stmt & fs) const
		{
			int id = fpr_stmt("FOR");
			dfs(id, fs.var);
			snode(id, fs.type == 0 ? "TO" : "DOWNTO");
			dfs(id, fs.from);
			dfs(id, fs.to);
			int t = snode(id, "THEN");
			dfs_stmt(t, fs.block);
			return id;
		}

		int operator()(order_stmt & os) const
		{
			int id = fpr_stmt("ORDER");
			snode(id, "op:" + to_string(os.op));
			dfs(id, os.num);
			snode(id, "type:" + to_string(os.type));
			if (os.type == 1 || os.type == 2)
			{
				dfs(id, os.price);
			}
			return id;
		}

		int operator()(func_stmt & fs) const
		{
			int id = fpr_stmt("FUNC");
			dfs(id, fs.func);
			return id;
		}

		int operator()(asm_stmt & as) const
		{
			int id = fpr_stmt("ASM");
			dfs(id, as.var);
			static const string an[] = { "=", "+=", "-=", "*=", "/=" };
			snode(id, an[as.type]);
			dfs(id, as.exp);
			return id;
		}

		int operator()(block_stmt & bs) const
		{
			dfs_stmts(blockp, bs.stmts);
			return -1;
		}

		int operator()(var_stmt & vs) const
		{
			int id = fpr_stmt("VAR");
			for (ast_t var : astsV[vs.vars])
			{
				dfs(id, var);
			}
			return id;
		}
	};

	int new_subgraph()
	{
		int cs = cstot++;
		fpr("subgraph cluster%d {\n", cs); it++;
		return cs;
	}

	inline void end_subgraph()
	{
		it--; fpr("}\n");
	}

	void dfs_stmt(int p, stmt_t stmt)
	{
		if (stmt == -1)return;
		int cs = new_subgraph();
		fpr("color=blue;\n");
		blockp = p;
		int id = boost::apply_visitor(stmt_visitor(), stmtV[stmt]);
		end_subgraph();
		if (~id)
		{
			fpr("%d -> %d\n", p, id);
		}
	}

	void dfs_stmts(int p, stmts_t stmts)
	{
		//int cs = new_subgraph();
		for (stmt_t stmt : stmtsV[stmts])
		{
			dfs_stmt(p, stmt);
		}
		//end_subgraph();
	}

	void print_input()
	{
		int cs = new_subgraph();
		int id = stmt_visitor::fpr_stmt("INPUT");
		for (ast_t input : inputVector)
		{
			dfs(id, input);
		}
		end_subgraph();
	}

	void generateDot(stmts_t root)
	{
		fp = fopen("out.txt", "w");
		it = 0;
		fpr("digraph G {\n"); it++;
		fpr("compound=true;\n");
		fpr("ordering=out;\n");
		fpr("rankdir=LR;\n");
		fpr("0[label=root]\n");
		tot = 1;
		cstot = 0;
		print_input();
		dfs_stmts(0, root);

		it--; fpr("}\n");
		fclose(fp);
	}
}

int main()
{
	FILE *f = fopen("in.txt", "r");
	int g = elparse(f);
	printf(" %d\n", g);
	fclose(f);
	if (g)return g;
	initName();
	generateDot(root);
	//system("dot > a.txt");
	system("dot -Tpng -o out.png out.txt");
	system("start out.png");
	return 0;
}