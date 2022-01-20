#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=23918;
int n,m1,m2;
int gn=0,gw=0;
int ans,cnt=0;
int ct;
int t1[N],t2[N],a1[N],a2[N],b1[N],b2[N];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>a1[i]>>b1[i];
	for(int i=1;i<=m2;i++)
		cin>>a2[i]>>b2[i];
	while(gn<=n)
	{
		for(int i=1;i<=m1;i++)
			t1[i]=0x7fffffff;
		for(int i=1;i<=m2;i++)
			t2[i]=0x7fffffff;
		cnt=0;
		gw=n-gn;
		int gnn=gn;
		int gww=gw;
		ct=0;
		for(int i=1;i<=m1;i++)
		{
			int o=0;
			for(int j=1;j<=ct;j++)
				if(t1[j]<=a1[i])
				{
					t1[j]=0;
					o=1;
				}
			if(o)
			{
				for(int i=1;i<=ct;i++)
					if(t1[i]<=a1[i])
					{
						t1[i]=b1[i];
						cnt++;
						break;
					}
			}
			else if(gnn)
			{
				gnn--;
				cnt++;
				t1[++ct]=b1[i];
			}
			else
			{
				for(int i=1;i<=ct;i++)
				if(t1[i]<=a1[i])
				{
					t1[i]=b1[i];
					break;
				}
			}
		}
		ct=0;
		for(int i=1;i<=m2;i++)
		{	
			int o=0;
			for(int j=1;j<=ct;j++)
				if(t2[j]<=a2[i])
				{
					t2[j]=0;
					o=1;
				}
			if(o)
			{
				for(int i=1;i<=ct;i++)
					if(t2[i]<=a2[i])
					{
						t2[i]=b2[i];
						cnt++;
						break;
					}
			}
			else if(gww)
			{
				gww--;
				cnt++;
				t2[++ct]=b2[i];
			}
			else
			{
				for(int i=1;i<=ct;i++)
				if(t2[i]<=a2[i])
				{
					t2[i]=b2[i];
					break;
				}
			}
		}
		gn++;
		if(cnt>ans) ans=cnt;
		cnt=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
