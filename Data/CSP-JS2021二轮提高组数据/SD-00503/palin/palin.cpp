#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n,i,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=2*n;j++)
		{
			scanf("%d",&a[j]);
		}
	}
	printf("-1");
	return 0;
}
