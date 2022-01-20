#include <cstdio>

FILE *fpi = fopen("xxx.in" , "rb");
FILE *fpo = fopen("xxx.out", "wb");

int main()
{
	fclose(fpi), fclose(fpo);
	return 0;
}

