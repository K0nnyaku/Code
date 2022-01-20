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
int n,m,T;
namespace sub2
{
	int id(int x,int y)
	{
		return (m-1)*(x-1)+y;
	}
	struct node
	{
		int v,dis;
		bool operator < (const node& bb)const{return dis>bb.dis;}
	};
	priority_queue<node>q;
	int s,t,dis[1000010],vis[1000010];
	struct edge
	{
		int v,w;
	};
	vector<edge>e[1000010];
	void add(int x,int y,int z)
	{
	//	cout<<x<<'-'<<y<<':'<<z<<'\n';
		e[x].push_back((edge){y,z});
		e[y].push_back((edge){x,z});
	}
	void dij(int x)
	{
		for(int i=1;i<=t+1;i++)dis[i]=1e16,vis[i]=0;
		q.push((node){x,0});
		dis[x]=0,vis[x]=1;
		while(!q.empty())
		{
			node now=q.top();q.pop();
			if(!vis[now.v])continue;
			vis[now.v]=0;
			for(int ii=0;ii<e[now.v].size();ii++)
//			for(auto i:e[now.v])
			{
				edge i=e[now.v][ii]; 
				if(dis[i.v]>dis[now.v]+i.w)
				{
					dis[i.v]=dis[now.v]+i.w;
					q.push((node){i.v,dis[i.v]});
					vis[i.v]=1;
				}
			}
		}
	}
	int a[1010][1010],b[1010][1010];
	void main()
	{
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				in(a[i][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				in(b[i][j]);
			}
		}
		while(T--)
		{
			int k=qr;
			if(k<=1)puts("0");
			else
			{
				int x1=qr,p1=qr,t1=qr;
				int x2=qr,p2=qr,t2=qr;
				if(t1==t2)
				{
					puts("0");
					continue;
				}
				int mn=min(x1,x2);
				if(p1>p2)swap(p1,p2);
				if((p1==p2+1&&(p1==m||p1==m+n||p1==2*m+n))||(p1==1&&p2==2*m+2*n))
				{
				}
				else
				{
				for(int i=1;i<n;i++)
				{
					for(int j=1;j<m;j++)
					{
						if(j!=m-1)add(id(i,j),id(i,j+1),a[i][j+1]);
						if(i!=n-1)add(id(i,j),id(i+1,j),b[i+1][j]);
					}
				}
				s=id(n-1,m-1)+1;
				t=s+1;
				for(int i=1;i<m;i++)
				{
					if(p1<=i&&i<p2)add(id(1,i),s,b[1][i]);
					else add(id(1,i),t,b[1][i]);
					if(p1<=m-i+m+n&&m-i+m+n<p2)add(id(n-1,i),s,b[n][i]);
					else add(id(n-1,i),t,b[n][i]);
				}
				for(int i=1;i<n;i++)
				{
					if(p1<=2*m+n+n-i&&2*m+n+n-i<p2)add(id(i,1),s,a[i][1]);
					else add(id(i,1),t,a[i][1]);
					if(p1<=m+i&&m+i<p2)add(id(i,m-1),s,a[i][m]);
					else add(id(i,m-1),t,a[i][m]);
				}
				dij(s);
				mn=min(mn,dis[t]);
				}
				for(int i=1;i<=t+1;i++)e[i].clear();
				cout<<mn<<'\n';
			}
		}
	}
};
signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=qr,m=qr,T=qr;
	if(n<=1&&m<=1);//sub1::main();
	else sub2::main();
	return 0;
}
