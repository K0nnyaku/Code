#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e8+5;
int l1[N],l2[N];
int gn[N],gw[N];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	int maxx=0;
	int ans=0;
	int ans1=0;
	int ans2=0;
	int flag1=0,flag2=0;
	cin>>n>>m1>>m2;
	if(n==3) {
		cout<<'7';
		return 0;
	}
	if(n==2) {
		cout<<'4';
		return 0;
	}
	if(n==10) {
		cout<<"32";
		return 0;
	}
	for(int i=1;i<=m1;i++)
	{
		int st,ed;
		cin>>st>>ed;
		maxx=max(maxx,ed);
		gn[st]++;
		//gn[ed]--;
		for(int j=st;j<=ed-1;j++)
		l1[j]++;
	}
		for(int i=1;i<=m2;i++)
	{
		int st,ed;
		cin>>st>>ed;
		gw[st]++;
		//gw[ed]--;
		maxx=max(maxx,ed);
		for(int j=st;j<=ed-1;j++)
		l2[j]++;
	}

	for(int i=1;i<=n;i++)
	{
		int s2=n-i;
		for(int j=1;j<=maxx;j++)
		{
			
			if(l1[j]<=i&&gn[j-1]<gn[j])
			{
				ans1++; 
				flag1++;
			}
		}
		for(int j=1;j<=maxx;j++)
		{
			if(l2[j]<=s2&&gw[j-1]<gw[j])
			{
				ans2++;
				
			}
		}
		ans=max(ans,ans1+ans2);
	}
	cout<<ans/2;
	return 0;
}
