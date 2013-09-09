#include <stdio.h>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <boost/variant.hpp>
using namespace std;
#include "table.h"
#include "functions.h"

unordered_map<string, StdFunction> funcTable;
unordered_map<string, Input> inputTable;
unordered_map<string, Variable> varTable;

void init_func_table()
{
	funcTable["average"] = Func::Average();
}

VSource find_name(string name)
{
	if (funcTable.count(name))return VSource::StdFunction;
	if (inputTable.count(name))return VSource::Input;
	if (varTable.count(name))return VSource::Variable;
	return VSource::Undefined;
}

void declare_var(string name, VType type)
{
	Variable var;
	var.type = type;
	varTable[name] = var;
}

void declare_input(string name, VType type, ast_t idx)
{
	Input input;
	input.type = type;
	input.idx = idx;
	inputTable[name] = input;
}

struct stmt_visitor : public boost::static_visitor<int>
{
};


ast StdFunction::call(int bar, vector<ast_t> ps)
{
	return ast(NodeType::VOID);
}
