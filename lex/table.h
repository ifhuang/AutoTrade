#ifndef TABLE_H
# define TABLE_H

#include <string>
#include <unordered_map>
#include <vector>

#include "ast.h"
#include "type.h"

enum class VSource { StdFunction, Input, Variable, Undefined };

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
	int position;
};

extern std::unordered_map<std::string, StdFunction> funcTable;
extern std::unordered_map<std::string, Type::Input> inputTable;
extern std::unordered_map<std::string, Variable> varTable;

VSource find_name(std::string name);
void declare_var(std::string name, int postion, VType type);

#endif