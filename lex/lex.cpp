#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "execution.h"
#include "tree.h"
#include "type.h"

int main()
{
	FILE *f = fopen("in.txt", "r");
	int g = elparse(f);
	printf(" %d\n", g);
	fclose(f);
	if (g)
	{
		printf("%s\n", errorMessage.c_str());
		return g;
	}
	
	try
	{
		Type::type_check();
	}
	catch (Type::SemanticError e)
	{
		printf("%s\n", e.what());
	}
	Execution::execute();
	return 0;
}