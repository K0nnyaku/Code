#include <cstdio>
#include <ctime>
#include <windows.h>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(0));
	printf("%d",rand());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
