#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
#define ll long long
using namespace std;
struct N
{
	int x,y;
}plane1[100100],plane2[100001];
int n,m1,m2;
bool cmp(N a,N b)
{
	return a.x<b.x;
}
int t[101000],t2[101000],vis[101000],vis2[101000];
ll work(int home,int abroad)
{
	ll cnt=0;
	memset(vis,0,sizeof vis);
	memset(t,0,sizeof t);
	for(int i=1;i<=home;i++)
	{
		t[i]=plane1[i].y;
	}
	if(m1>home) {
		int thome=home;
		cnt=home;
		for(int i=home+1;i<=m1;i++)
		{
			for(int j=1;j<=thome;j++)
			if(plane1[i].x>=t[j] && !vis[j])
			{
				vis[j]=1;
				thome++;
				t[thome]=plane1[i].y;
				cnt++;
				break;
			}
		}
	}
	else cnt=m1;
	
	memset(vis2,0,sizeof vis2);
	ll cnt2=0;
	memset(t2,0,sizeof t2);
	for(int i=1;i<=abroad;i++)
	{
		t2[i]=plane2[i].y;
	}
	if(m2>abroad) {
		int tabroad=abroad;
		cnt2=abroad;
		for(int i=abroad+1;i<=m2;i++)
		{
			for(int j=1;j<=tabroad;j++)
			if(plane2[i].x>=t2[j] && !vis2[j])
			{
				vis2[j]=1;
				tabroad++;
				t2[tabroad]=plane2[i].y;
				cnt2++;
				break;
			}
		}
	}
	return cnt+cnt2;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) cin>>plane1[i].x>>plane1[i].y;
	for(int i=1;i<=m2;i++) cin>>plane2[i].x>>plane2[i].y;
	sort(plane1+1,plane1+m1+1,cmp);
	sort(plane2+1,plane2+m2+1,cmp);
	ll ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,work(i,n-i));
	}
	cout<<ans;
    fclose(stdin);
	fclose(stdout);
	return 0;
}

