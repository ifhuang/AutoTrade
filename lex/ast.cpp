#include <unordered_map>
#include <boost/algorithm/string.hpp>
#include "ast.h"
#include "vv.h"
using namespace std;

unordered_map<string, int> strTable;
int strTableSize;
vector<string> strVector;
string errorMessage;

VV<ast> VVN(astV);

int find(const char *cs)
{
	string s(cs);
	boost::algorithm::to_lower(s);
	if (strTable.count(s))
	{
		return strTable[s];
	}
	return strTable[s] = strTableSize++;
}

int newast(NodeType type, int left, int right)
{
	ast node(type);
	node.left = left;
	node.right = right;
	return astV.put(node);
}

int newname(int idx)
{
	ast node(NodeType::VAR);
	node.idx = idx;
	return astV.put(node);
}

int newdouble(int idx)
{
	ast node(NodeType::NUMERIC);
	node.idx = idx;
	return astV.put(node);
}

int newtext(int idx)
{
	ast node(NodeType::TEXT);
	node.idx = idx;
	return astV.put(node);
}

int newtf(bool bv)
{
	ast node(NodeType::TF);
	node.bv = bv;
	return astV.put(node);
}

int newcmp(int fn, int lhs, int rhs)
{
	ast node(NodeType(100 + fn));
	node.left = lhs;
	node.right = rhs;
	return astV.put(node);
}

void applyBar(ast *node, int bar)
{
	switch (node->type)
	{
	case NodeType::NUMERIC:
	case NodeType::TF:
	case NodeType::TEXT:
		/* ignore */
		break;
	case NodeType::VAR:
	case NodeType::FUNC:
		break;
	default:
		break;
	}
}

void printTree(ast* node)
{
	printf("%d", node->type);
}

void astpre()
{
	strTable.clear();
	strTableSize = 0;
	astV.clear();
	find("close");
	errorMessage.clear();
}

void astpost()
{
	strVector.resize(strTableSize);
	for (auto var : strTable)
	{
		strVector[var.second] = var.first;
	}
}