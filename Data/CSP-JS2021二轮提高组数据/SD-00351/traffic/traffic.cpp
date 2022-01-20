#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int N=6;
int n,m,T,c[N][N],l[N][N],t,cn[N][N];
struct data{
	int t,p,x;
}d[55];
struct node{
	int x,y;
};
node change(int x)
{
	while(x>m*2+n*2)
	{
		
		x-=m*2+n*2;
	}
	if(x<=m)
	{
		return (node){1,x};
	}
	if(m+1<=x&&x<=n+m)
	{
		return (node){x-m,m};
	}
	if(m+n+1<=x&&x<=n+m+m)
	{
		return (node){n,m-(x-m-n)+1};
	}
	if(m+1+n+m<=x)
	{
		return (node){n-(x-m*2-n)+1,m};
	}
}
int read()
{
	int x=0,f=1;
	char cc=getchar();
	while(!isdigit(cc))
	{
		if(cc=='-')f=-f;
		cc=getchar();
	}
	while(isdigit(cc))
	{
		x=x*10+cc-'0';
		cc=getchar();
	}
	return x*f;
}
void init()
{
	cin>>n>>m>>T;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&l[i][j]);
		}
	}
}
void solve()
{
	while(T--)
	{
		int ans=0;
		int t;
		scanf("%d",&t);
		for(int i=1;i<=t;i++)
		{
			scanf("%d%d%d",&d[i].x,&d[i].p,&d[i].t);
			ans+=d[i].p;
		}
		int num=1<<(n*m)-1;
		for(int k=0;k<=num;k++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int i=1;i<=m;i++)
				{
					int x=1<<(j+(i-1)*n-1);
					if(x&k)
					{
						cn[j][i]=1;
					}
					else
					{
						cn[j][i]=0;
					}
				}
			}
			int sum=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(cn[i][j]!=cn[i][j+1])sum+=c[i][j];
			}
		}
		for(int i=1;i<m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(cn[i][j]!=cn[i+1][j])sum+=l[i][j];
			}
		}
		for(int i=1;i<=t;i++)
		{
			if(d[i].t!=cn[change(d[i].x).x][change(d[i].x).y])sum+=d[i].p;
		}
		
		}
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout); 
	init();
	solve();
	
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
