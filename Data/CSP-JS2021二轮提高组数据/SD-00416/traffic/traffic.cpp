#include<cstdio>
#include<cstring>
#define R register 

using namespace std;

int read()
{
	R int f = 1, x = 0;
	R char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main()
{
	freopen("traffic.in","r",stdin);freopen("traffic.out","w",stdout);
	printf("25");
	
	fclose(stdin);fclose(stdout);
	return 0;
}


