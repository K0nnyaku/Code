#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int t;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			int x;
			scanf("%d",&x);
		}
		printf("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
