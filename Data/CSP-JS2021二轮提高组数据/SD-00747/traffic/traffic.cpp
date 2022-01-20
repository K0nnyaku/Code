#include <cstdio>
#include <ctime>
#include <windows.h>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(0));
	printf("%d",rand());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

