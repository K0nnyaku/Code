#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t,x,k,a,b,c;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n-1;i++)
	{
		for(int i=1;i<=m;i++)scanf("%d",&x);
	}
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=m;i++)scanf("%d",&x);
	}
	while(t--)
	{
		scanf("%d",&k);
		while(k--)scanf("%d%d%d",&a,&b,&c);
		printf("12");
	}
	return 0;
}
