#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <unordered_map>
using namespace std;

enum class IType { INPUT, VAR, FUNC };
enum class VType { NUMERIC, TF, TEXT };

struct TableInfo
{
	int inputsNumeric;
	int inputsTF;
	int inputsText;
	int varsNumeric;
	int varsTF;
	int varsText;
};

struct TableItem{
	IType itype;
	VType vtype;
};

extern unordered_map<string, TableItem> vartable;

bool newInput(string name, VType vtype);

#endif