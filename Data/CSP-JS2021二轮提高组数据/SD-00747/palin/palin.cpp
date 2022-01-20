#include <cstdio>
using namespace std;
const int maxn=2e5+10;
int n,a[maxn],c[maxn],y[maxn],f=0;
int dfs(int u)
{
	if(f==1)
		return 1;
	if(u>2*n)
	{
		//printf("1:%d\n",u);
		int l=1,r=2*n;
		for(int i=1;i<=2*n;i++)
		{
			if(c[i]==1)
			{
				a[i]=y[l];
				l++;
			}
			else
			{
				a[i]=y[r];
				r--;
			}
			//printf("%d ",a[i]);
		}
		//printf("\n");
		for(int i=1,j=2*n;i<=2*n;i++,j--)
		{
			if(a[i]!=a[j])
			{
				for(int k=1;k<=2*n;k++)
					a[k]=0;
				return 0;
			}
			//printf("%d %d\n",a[i],a[j]);
		}
		f=1;
		if(f==1)
		{
			for(int i=1;i<=2*n;i++)
			{
				if(c[i]==1)
					printf("L");
				else
					printf("R");
			}
			printf("\n");
		}
		return 1;
	}
	//printf("2:%d\n",u);
	c[u]=1;
	dfs(u+1);
	c[u]=0;
	dfs(u+1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&y[i]);
		dfs(1);
		if(f==0)
			printf("-1\n");
		for(int i=1;i<=2*n;i++)
			a[i]=0;
		f=0;
	}
	//zhx±£ÓÓ£¬BUGÔ¶Àë 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
