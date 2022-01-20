#include <cstdio>
int n,m1,m2,ans;
const int maxn = 1e6+5;
int a[5][maxn],b[5][maxn],val[5],num[maxn],cnt[maxn];
int maxx;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a[1][i],&b[1][i]);
		if(b[1][i]>maxx) maxx=b[1][i];
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&a[2][i],&b[2][i]);
		if(b[2][i]>maxx) maxx=b[2][i];
	}
	for(int k=0;k<=n;k++)
	{
		val[1]=k;
		val[2]=n-k;
		for(int i=1;i<=m1;i++)
		{
			if(cnt[a[1][i]]+1<=val[1])
			{				
				for(int j=a[1][i];j<b[1][i];j++)
				cnt[j]++;
				num[k]++;				
			}
		}
		for(int i=1;i<=maxx;i++) cnt[i]=0;
		for(int i=1;i<=m2;i++)
		{
			if(cnt[a[2][i]]+1<=val[2])
			{
				
				for(int j=a[2][i];j<b[2][i];j++)
				cnt[j]++;
				num[k]++;				
			}
		}
		for(int i=1;i<=maxx;i++) cnt[i]=0;
	}
	for(int i=0;i<=n;i++)
		if(ans<num[i]) ans=num[i];
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
