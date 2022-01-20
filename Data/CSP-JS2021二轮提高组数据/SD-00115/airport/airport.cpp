#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m1,m2,v[100100],cnt,k,ans;
struct node{int t,data;
}b1[100100],b2[100100],a1[100100],a2[100100];
//int q[100100],h=1,t=0,;
bool cmp(node x,node y)
{
	return x.t<y.t;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
	{
		scanf("%d%d",&a1[i].t,&b1[i].t);
		a1[i].data=i;b1[i].data=i;
	}
	for(int i=1;i<=m2;++i)
	{
		scanf("%d%d",&a2[i].t,&b2[i].t);
		a2[i].data=i;b2[i].data=i;
	}
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	sort(b1+1,b1+1+m1,cmp);
	sort(b2+1,b2+1+m2,cmp);
//	if(n<=5000)
	for(int o=0;o<=n;++o)
	{
		int ans1=0,ans2=0;
		k=1;cnt=0;
		memset(v,0,sizeof(v));
			for(int i=1;i<=m1;++i)
		{
			while(a1[i].t>=b1[k].t)
			{
				if(v[b1[k].data])
				{
					v[b1[k].data]=0;
					cnt--;
			}
					++k;
			}
			if(cnt<o)
			{
				++cnt;
				++ans1;
				v[a1[i].data]=1;
			}
		}
		k=1;cnt=0;
		memset(v,0,sizeof(v));
		for(int i=1;i<=m2;++i)
		{
			while(a2[i].t>=b2[k].t)
			{
				if(v[b2[k].data])
				{
					v[b2[k].data]=0;
					cnt--;
				}
				++k;
			}
			if(cnt<n-o)
			{
				++cnt;
				++ans2;
				v[a2[i].data]=1;
			}
		}
		ans=max(ans,ans1+ans2);
	}
	printf("%d\n",ans);
	return 0;
}






