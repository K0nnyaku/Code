#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int T,n,a[1000010];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int flag=0,flag2=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
				flag=1;
			if(a[i]!=a[i+1]&&a[i]!=a[i-1])
				flag2=1;
		}
		if(!flag)
		{
			for(int i=1;i<=2*n;i++)
				printf("L");
			printf("\n");
		}
		else if(!flag2)
		{
			printf("-1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
