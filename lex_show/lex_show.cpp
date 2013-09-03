#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <unordered_map>
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
		ADDNAME(BAR);
		ADDNAME(UMINUS);

		ADDNAME(VARDEC);

		ADDNAME(NUMERIC);
		ADDNAME(TF);
		ADDNAME(TEXT);

		ADDNAME(VAR);
		ADDNAME(FUNC);

		ADDNAME(ARGU);

		ADDNAME(EQ);
		ADDNAME(GT);
		ADDNAME(LT);
		ADDNAME(NE);
		ADDNAME(GE);
		ADDNAME(LE);
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

	void snode(int p, const string s)
	{
		int id = tot++;
		fpr("%d[label=%s];\n", id, s.c_str());
		if(~p)
		{
			fpr("%d -> %d;\n", p, id);
		}
	}

	void dfs(int p, ast_t i)
	{
		if(i == -1)return;
		ast &node = astV[i];
		int id = tot++;
		fpr("%d[label=%s];\n", id, enumName[node.type].c_str());
		if(~p)
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
		int operator()(if_stmt & is) const
		{
			int id = tot++;
			fpr("%d[label=IF]\n", id);
			dfs(id, is.con);
			dfs_stmt(id, is.then);
			dfs_stmt(id, is.els);
			return id;
		}

		int operator()(order_stmt & os) const
		{
			int id = tot++;
			return id;
		}

		int operator()(func_stmt & fs) const
		{
			int id = tot++;
			dfs(id, fs.func);
			return id;
		}

		int operator()(asm_stmt & as) const
		{
			int id = tot++;
			fpr("%d[label=ASM]\n", id);
			dfs(id, as.var);
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
			int id = tot++;
			for (ast_t var : astsV[vs.vars])
			{
				dfs(id, var);
			}
			return id;
		}
	};

	void dfs_stmt(int p, stmt_t stmt)
	{
		if (stmt == -1)return;
		blockp = p;
		int id = boost::apply_visitor( stmt_visitor(), stmtV[stmt] );
		if (~id)
		{
			fpr("%d -> %d\n", p, id);
		}
	}

	void dfs_stmts(int p, stmts_t stmts)
	{
		int cs = cstot++;
		fpr("subgraph cluster%d {\n", cs); it++;
		for(stmt_t stmt : stmtsV[stmts])
		{
			dfs_stmt(p, stmt);
		}
		it--; fpr("}\n");
	}

	void generateDot(stmts_t root)
	{
		fp = fopen("out.txt", "w");
		it = 0;
		fpr("digraph G {\n"); it++;
		fpr("compound=true;\n");
		fpr("ordering=out;\n");
		fpr("0[label=root]\n");
		tot = 1;
		cstot = 0;
		dfs_stmts(0, root);

		it--; fpr("}\n");
		fclose(fp);
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

}
