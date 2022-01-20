#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct gn
{
	int t1,t2;
}gn[5001],gw[5001];
int lang[5001][2];//个数，时间
int ans=-999;//最终答案 
bool cmp(struct gn a,struct gn b)
{
	return a.t1<b.t1;
}
void qing(int l)
{
	for(int a=0;a<=l;a++)
	{
		lang[a][0]=0;
		lang[a][1]=0;
	}
 } 
int nei(int l)
{
	int h=0;
	for(int w=0;w<m1;w++)
	{
		for(int a=0;a<l;a++)
		{
			if(lang[a][1]<gn[w].t1)
			{
				h++;
				lang[a][0]=gn[w].t1;
				lang[a][1]=gn[w].t2;
				break;
			}
		}
	}
	qing(l);
	return h;
}
int wai(int l)
{
	int h=0;
	for(int w=0;w<m2;w++)
	{
		for(int a=0;a<l;a++)
		{
			if(lang[a][1]<gw[w].t1)
			{
				h++;
				lang[a][0]=gw[w].t1;
				lang[a][1]=gw[w].t2;
				break;
			}
		}
	}
	qing(l);
	return h;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int a=0;a<m1;a++)
		scanf("%d%d",&gn[a].t1,&gn[a].t2);
	for(int a=0;a<m2;a++)
		scanf("%d%d",&gw[a].t1,&gw[a].t2);
	sort(gn,gn+m1,cmp);
	sort(gw,gw+m2,cmp);
	for(int a=0;a<=n;a++)
	{
		ans=max(ans,nei(a)+wai(n-a));
	}
	cout<<ans;
	return 0;
}
