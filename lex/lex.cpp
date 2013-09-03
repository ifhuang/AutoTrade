#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int elparse(FILE *f);

int main()
{
	FILE *f = fopen("in.txt", "r");
	int g = elparse(f);
	printf("%d\n", g);
	fclose(f);
	return 0;
}