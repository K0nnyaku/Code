#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
ll a,b,c,u1[1000010],n,w[1000010];
/*struct e
{
	ll d,z;
}t[2000010];*/
ll r[N],s[N],r1[N],s1[N],t[N],t1[N],n,n1,y[N];
bool cmp(e a,e b)
{
	return a.d<b.d;
}
void yyy()
{
	for(int i=0;i<=max(n,n1);i++) y[i]=0;
}
map<ll,ll> u,v,o,o1;
int main() 
{ 
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>a>>b>>c;
	for(int i=1;i<=b;i++) cin>>r[i]>>s[i],t[++n]=r[i],t[++n]=s[i],u[r[i]]=s[i];
	for(int i=1;i<=c;i++) cin>>r1[i]>>s1[i],t1[++n1]=r1[i],t1[++n1]=s1[i],u1[r1[i]]=s1[i];
	sort(t+1,t+n+1);
	sort(t1+1,t1+n1+1);
	for(int i=1;i<=n;i++) 
	{
		if(u[t[i]])
		{
			for(int j=i+1;j<=n;j++)
			{
				if(t[j]==u[t[i]])
				{
					o[t[i]]=j; break;
				}
			}
		}
	}
	for(int i=1;i<=n1;i++) 
	{
		if(u1[t1[i]])
		{
			for(int j=i+1;j<=n1;j++)
			{
				if(t1[j]==u1[t1[i]])
				{
					o1[t1[i]]=j; break;
				}
			}
		}
	}
	/*sort(t+1,t+n+1,cmp); 
	sort(r+1,r+b+1);
	for(int i=1;i<=n;i++) t[i]=i;
	for(int i=1;i<=b;i++)
	{
		if(v[i]) continue;
		else
		{
			ll u=1,wz=i;
			w[i]=w[i-1];
			for(int j=1;j<=b;j++)
			{
				
			}
		}
	}*/
	ll ans=0;
	for(int i=1;i<=a;i++)
	{
		ll p=0,m=i,zz=0;
		//for(int j=1;j<=n;j++) y[j]=t[j];
		for(int j=1;j<=n;j++)
		{
			if(m>0&&u[t[j]]) p++,y[o[t[j]]]=1,m--;
			else m=m+y[j];
		}
		yyy();
		zz+=p; p=0,m=a-i;
		for(int j=1;j<=n1;j++)
		{
			if(m>0&&u1[t1[j]]) p++,y[o1[t1[j]]]=1,m--;
			else m=m+y[j];
		}
		zz+=p; 
		ans=max(ans,zz);
		yyy();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
