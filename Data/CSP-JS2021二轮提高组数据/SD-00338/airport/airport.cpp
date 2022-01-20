#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
int n,m1,m2;
struct node
{
	ll x,y;
};
node na[100001],in[100001];
ll wei[100001],head,tail;
bool comp(node a,node b)
{
	return a.x<b.x;
}
ll lna[100001],lin[100001];
ll sum;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;++i)
		cin>>na[i].x>>na[i].y;
	for(int i=1;i<=m2;++i)
		cin>>in[i].x>>in[i].y;
	sort(na+1,na+1+m1,comp);
	memset(wei,0,sizeof(wei));
	for(int i=1;i<=m1;++i)
	{
		for(int k=1;k<=n;++k)
		{
			if(wei[k]<na[i].x)
			{
				wei[k]=na[i].y;
				lna[k]++;
				break;
			}
		}
	}
	sort(in+1,in+1+m2,comp);
	memset(wei,0,sizeof(wei));
	for(int i=1;i<=m2;++i)
	{
		for(int k=1;k<=n;++k)
		{
			if(wei[k]<in[i].x)
			{
				wei[k]=in[i].y;
				lin[k]++;
				break; 
			}
		}
	}
	for(int i=1;i<=n;++i)
		lna[i]+=lna[i-1];
	for(int i=1;i<=n;++i)
		lin[i]+=lin[i-1];
	ll maxx=0;
	for(int i=0;i<=n;++i)
		maxx=max(maxx,lna[i]+lin[n-i]);
	cout<<maxx;
	fclose(stdin);fclose(stdout);
	return 0;
}
