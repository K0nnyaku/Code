#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t;
int n;
int b[500010];
int yd[1000010];
bool fl,vis[500010];
deque<int>a;
int maxbs;
inline int read()
{
	int x=0,f=1;char ch;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void dfs2(int x)
{
	if(fl==1)return;
	int now1=a.front();
	int now2=a.back();
	int xd=2*n-x+1;
	if(now1==b[xd])
	{
		yd[x]=1;
		a.pop_front();
		if(a.empty()) 
		{
			fl=1;
			return;
		}
		dfs2(x+1);
		if(fl==1) return;
		yd[x]=0;
		a.push_front(now1);
	}
	if(now2==b[xd])
	{
		yd[x]=2;
		a.pop_back();
		if(a.empty()) 
		{
			fl=1;
			return;
		}
		dfs2(x+1);
		if(fl==1) return;
		yd[x]=0;
		a.push_back(now2);
	}
}
void dfs1(int x)
{
	if(fl==1) return;
	if(x>n) 
	{
		dfs2(x);
		return;
	}
	int now1=a.front();int now2=a.back();
    if(!vis[now1])
	{
		b[x]=now1;yd[x]=1;vis[now1]=1;
		a.pop_front();
		dfs1(x+1);
		if(fl==1) return;
		b[x]=0;yd[x]=0;vis[now1]=0;
		a.push_front(now1);
	}
	if(!vis[now2])
	{
		b[x]=now2;yd[x]=2;vis[now2]=1;
		a.pop_back();
		dfs1(x+1);
		if(fl==1) return;
		b[x]=0;yd[x]=0;vis[now2]=0;
		a.push_back(now2);
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--)
	{
		maxbs=0;fl=0;
		n=read();
		deque<int>a1;
		a=a1;
		memset(b,0,sizeof b);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=2*n;i++)
		{
			int x;
			x=read();
			a.push_back(x);
		}
		dfs1(1);
		if(!fl) 
		{
			printf("-1\n");
			continue;
		}
		else 
		{
			for(int i=1;i<=2*n;i++)
			{
				if(yd[i]==1) printf("L\n");
				if(yd[i]==2) printf("R\n");
			}
			printf("\n");
		}
	}
	return 0;
}

