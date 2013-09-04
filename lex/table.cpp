#include <stdio.h>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;
#include "table.h"

unordered_map<string, TableItem> vartable;

bool newInput(string name, VType vtype)
{
	if (vartable.count(name))
	{
		return false;
	}
	TableItem item;
	item.itype = IType::INPUT;
	item.vtype = vtype;
	vartable[name] = item;
	return true;
}

//TableItem dicFind(string name)
//{
//	if(vartable.count(name))
//	{
//		return vartable[name];
//	}
//	return NULL;
//}