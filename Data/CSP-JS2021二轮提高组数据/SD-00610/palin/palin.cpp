#include<vector>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define qr read()
#define in(x) x=read()
#define mp make_pair
#define nc getchar
#define int ll
#define y0 ccf
#define y1 moe
#define ps wxj
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=' ';
	int f=1;
	ll x=0;
	for(;!isdigit(ch);ch=nc())if(ch=='-')f*=-1;
	for(;isdigit(ch);ch=nc())x=x*10+ch-'0';
	return f*x;
}
int a[1000010],pos1[1000010],pos2[1000010],p[1000010],vis[1000010];
signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=qr;
	while(T--)
	{
		int n=qr;
		for(int i=1;i<=2*n;i++)
		{
			in(a[i]);
			if(!pos1[a[i]])pos1[a[i]]=i;
			else pos2[a[i]]=i;
		}
		for(int i=1;i<=n;i++)p[pos1[i]]=pos2[i],p[pos2[i]]=pos1[i];
		int lp=1,rpos=2*n,h=0,pk;
		for(int i=1;i<=n;i++)
		{
			while(vis[lp])lp++;
			if(i==1)vis[lp]=1,vis[p[lp]]=2*n,pk=p[lp];
			else if((p[lp]>pk&&vis[p[lp]-1])||(p[lp]<pk&&vis[p[lp]+1]))vis[lp]=i,vis[p[lp]]=2*n+1-i;
			else
			{
				if(vis[rpos])h=1;
				else if((p[rpos]>pk&&vis[p[rpos]-1])||(p[rpos]<pk&&vis[p[rpos]+1]))vis[rpos]=i,vis[p[rpos]]=2*n+1-i;
				else h=1;
				rpos--;
			}
//			cout<<i<<' '<<h<<'\n';
		}
		if(!h)
		{
			lp=1,rpos=2*n;
			for(int i=1;i<=2*n;i++)
			{
				if(vis[lp]==i)cout<<'L',lp++;
				else cout<<'R',rpos--;
			}
			cout<<'\n';
			for(int i=1;i<=2*n;i++)pos1[i]=pos2[i]=p[i]=vis[i]=0;
			continue;
		}
		for(int i=1;i<=2*n;i++)vis[i]=0;
		lp=1,rpos=2*n-1,h=0,pk=p[2*n];
		vis[2*n]=1,vis[p[2*n]]=2*n;
		for(int i=2;i<=n;i++)
		{
			while(vis[lp])lp++;
			if(i==1)vis[lp]=1,vis[p[lp]]=2*n,pk=p[lp];
			else if((p[lp]>pk&&vis[p[lp]-1])||(p[lp]<pk&&vis[p[lp]+1]))vis[lp]=i,vis[p[lp]]=2*n+1-i;
			else
			{
				if(vis[rpos])h=1;
				else if((p[rpos]>pk&&vis[p[rpos]-1])||(p[rpos]<pk&&vis[p[rpos]+1]))vis[rpos]=i,vis[p[rpos]]=2*n+1-i;
				else h=1;
				rpos--;
			}
		}
		if(h)puts("-1");
		else
		{
			lp=1,rpos=2*n;
			for(int i=1;i<=2*n;i++)
			{
				if(vis[lp]==i)cout<<'L',lp++;
				else cout<<'R',rpos--;
			}
			cout<<'\n';
		}
		for(int i=1;i<=2*n;i++)pos1[i]=pos2[i]=p[i]=vis[i]=0;
	}
	return 0;
}
