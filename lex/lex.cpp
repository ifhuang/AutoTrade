#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "tree.h"

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
}