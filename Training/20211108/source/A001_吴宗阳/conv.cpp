#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[200010],b[200010];
int c[200010];
int main()
{
	freopen("conv.in","r",stdin);
	freopen("conv.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
	{
		int maxx=0;
		for(int j=0;j<n;j++)
			maxx=max(maxx,a[j]+b[(i-j+n)%n]);
		c[i]=maxx;
	}
	for(int i=0;i<n;i++)
		printf("%d ",c[i]);
	return 0;
}
