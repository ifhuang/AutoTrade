#ifndef TABLE_H
# define TABLE_H

#include <string>
#include <unordered_map>
#include <vector>

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
	std::vector<VType> paras;
	int min = -1;
	virtual ast call(int bar, std::vector<ast_t> ps);

	StdFunction() {}
	StdFunction(VType result, std::vector<VType> paras) :result(result), paras(paras) {}
	//Function(const Function &b) :result(b.result), paras(b.paras){}
};

struct Variable{
	VType type;
};

struct Input{
	VType type;
	ast_t idx;
};

extern std::unordered_map<std::string, StdFunction> funcTable;
extern std::unordered_map<std::string, Input> inputTable;
extern std::unordered_map<std::string, Variable> varTable;

VSource find_name(std::string name);
void declare_input(std::string name, VType type, ast_t idx);
void declare_var(std::string name, VType type);

#endif