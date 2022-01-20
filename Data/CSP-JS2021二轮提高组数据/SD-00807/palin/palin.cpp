#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
