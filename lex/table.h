#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include <unordered_map>

#include "ast.h"

enum class VSource { StdFunction, Input, Variable, Undefined };
enum class VType { NUMERIC, TF, TEXT, VOID };

struct TableInfo
{
	int inputsNumeric;
	int inputsTF;
	int inputsText;
	int varsNumeric;
	int varsTF;
	int varsText;
};

struct StdFunction{
	VType result;
	vector<VType> paras;
	int min = -1;
	virtual ast call(int bar, vector<ast_t> ps);

	StdFunction() {}
	StdFunction(VType result, vector<VType> paras) :result(result), paras(paras) {}
	//Function(const Function &b) :result(b.result), paras(b.paras){}
};

struct Variable{
	VType type;
};

struct Input{
	VType type;
	ast_t idx;
};

extern unordered_map<string, StdFunction> funcTable;
extern unordered_map<string, Input> inputTable;
extern unordered_map<string, Variable> varTable;

VSource find_name(string name);
void declare_input(string name, VType type, ast_t idx);
void declare_var(string name, VType type);

#endif