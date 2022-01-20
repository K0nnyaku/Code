#include <bits/stdc++.h>
#define mp make_pair
#define int long long
typedef long long ll;

using namespace std;
map<int,int>p;
const int MAXN=1e8+9;
int to1,to2;
ll ans =0;
ll id1[100010],id2[100010];
ll n,m1,m2,co1[1000010],co2[1000010];
ll cnt, tot,ji1[1000100],ji2[1000100];
int max1,max2;
ll a[1000100],ct1[1000100],ct2[1000100];
struct node{
	bool operator<(const node &x)const {
		return a<x.a;
	}
	int a,b;
}q1[100010],q2[100010];
void corn {
p[x]=tot++
}
signed main()
{
freopen("airport.in","r","stdin");
freopen("airport.out","w","stdout");
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>q1[i].a>>q1[i].b,a[++cnt]=q1[i].a,a[++cnt]=q1[i].b;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>q2[i].a>>q2[i].b,a[++cnt]=q2[i].a,a[++cnt]=q2[i].b;
	}
	sort (a+1;a+1+cnt);
	a[0]=-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[i-1]){
			corn(a[i]);
		}
	}
	for(int i=0;i<m1;i++)
	{
		q1[i].a=p[q1].a],q1[i].b=p[q1[i].b];
	}
	for(int i=1;i<=m2;i++)
	{
		q2[i].a=p[q2[i].a],q2[i].b=p[q2[i].b];
	}
	for(int i=1;i<=m1;i++)
	{
		ji1[q1[i].a]=1,ji1[q1[i].b]=-1,id1[q1[i].a]=id1[q1[i].b]=i;
	}
	for(int i=0;i<m2;i++)
	{
		ji2[q2[i].a]=1,ji2[q2[i].b]=-1,id2[q2[i].a]=id2[q2[i].b]=i;
	}
	for(int i=0;i<m1;i++)
	{
		if(ji1[i]==1)
		{
			if(!q1.empty)
			{
				
			}
		}
		if(ji1[i]==-1)
		{
			
		}
	}
	for(int i=0;i<m2;i++)
	{
		if(ji2[i]==1)
		{
			
		}
		if(ji2[i]==-1)
		{
			
		}
    }  
	cout<<m1+m2-ans<<endl;
 return 0;
}
