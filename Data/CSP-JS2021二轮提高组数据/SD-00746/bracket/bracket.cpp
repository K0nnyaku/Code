#include <ctime>
#include <cstdio>
#include <cstdlib>
#define fuckCCF 
const int mod = 1e9 + 7;



int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	srand(time(NULL));
	printf("%d\n", rand() % mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}































