#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
int n,m[2],sum=-1;
struct air
{
	int st;
	int en;
} fj[2][100010];
int check(int gs,int dx)
{
	int tk[gs+1],re=0,ans=0;
	for(int i=1;i<=gs;i++)
	{
		tk[i]=fj[dx][i].en;
	}
	ans+=gs; 
	for(int i=1;i<=m[dx];i++)
	{
		int t=1e+9,an=-1;
		for(int j=1;j<=gs;j++)
		{
			if(fj[dx][i].st-tk[j]>=0&&fj[dx][i].st-tk[j]<t)
			{
				t=fj[dx][i].st-tk[j];
				an=i;
			}
		}
		if(an>0)
		{
			tk[an]=fj[dx][i].en;
			ans++;
		}
	}
	return ans;
}
bool cmp(air x,air y)
{
	return x.st<y.st;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m[0],&m[1]);
	for(int i=1;i<=m[0];i++)
	{
		scanf("%d%d",&fj[0][i].st,&fj[0][i].en);
	}
	for(int i=1;i<=m[1];i++)
	{
		scanf("%d%d",&fj[1][i].st,&fj[1][i].en);
	}
	sort(fj[0]+1,fj[0]+m[0]+1,cmp);
	sort(fj[1]+1,fj[1]+m[1]+1,cmp);
	for(int i=0;i<=n;i++)
	{
		int j=n-i;
		sum=max(sum,check(i,0)+check(j,1));
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

