#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+5;
#define pi pair<int,int>
#define F first
#define S second
pi in[N],out[N];
int n,m1,m2;
int mx1,mx2;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar(); 
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int vis[N];
bool cmp(const pi &x,const pi &y)
{
	return x.F<y.F;
} 
int s1(int k)
{
	memset(vis,0,sizeof vis);
	int ans=0;
	for(int i=1;i<=m1;i++)
	{
		int l=in[i].F,r=in[i].S;
		if(vis[l]<k)
		{
			for(int j=l;j<=r;j++)
				vis[j]++;
			ans++;
		}
	}
	return ans;
}
int s2(int k)
{
	memset(vis,0,sizeof vis);
	int ans=0;
	for(int i=1;i<=m2;i++)
	{
		int l=out[i].F,r=out[i].S;
		if(vis[l]<k)
		{
			for(int j=l;j<=r;j++)
				vis[j]++;
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)in[i].F=read(),in[i].S=read(),mx1=max(mx1,in[i].S);
	for(int i=1;i<=m2;i++)out[i].F=read(),out[i].S=read(),mx2=max(mx2,out[i].S);
	sort(in+1,in+m1+1,cmp);
	sort(out+1,out+m2+1,cmp);
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int ans1=s1(i),ans2=s2(n-i);
		if(ans1+ans2>ans)
			ans=ans1+ans2;
	}
	printf("%d\n",ans);
	return 0;
}
