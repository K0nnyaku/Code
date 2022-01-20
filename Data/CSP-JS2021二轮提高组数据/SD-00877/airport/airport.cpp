#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m1,m2,n1,n2,ans,bf,maxx;
struct abc
{
	int a,b,vis;
}gn[111111],gj[111111];
bool cmp(abc x,abc y)
{
	return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>gn[i].a>>gn[i].b;
	for(int i=1;i<=m2;i++)
		cin>>gj[i].a>>gj[i].b;
	sort(gn+1,gn+m1+1,cmp);
	sort(gj+1,gj+m2+1,cmp);
	for(int t=0;t<=n;t++)
	{
		n1=t;n2=n-t;
		ans=0;
		for(int i=1;i<=m1;i++)gn[i].vis=0;
		for(int i=1;i<=m2;i++)gj[i].vis=0;
		for(int i=1;i<=n1;i++)
		{
			bf=0;
			for(int j=1;j<=m1;j++)
			{
				if(bf<=gn[j].a&&!gn[j].vis)
					bf=gn[j].b,ans++,gn[j].vis=1;
			}
		}
		for(int i=1;i<=n2;i++)
		{
			bf=0;
			for(int j=1;j<=m2;j++)
			{
				if(bf<=gj[j].a&&!gj[j].vis)
					bf=gj[j].b,ans++,gj[j].vis=1;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
