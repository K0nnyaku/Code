#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
const int MAXN=100005;
int m1,m2,n,nothing[MAXN],ans[2][MAXN],del[MAXN],num,lastans;
struct P
{
	int f,s;
}a[MAXN],b[MAXN];
int read(void)
{
	int f=1,x;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')
		ch=getchar();
	if(ch=='-')
		f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x*10)+(ch-'0'),ch=getchar();
	return f*x;
}
/*void dfs1(int u,int fa)
{
	f[u]=fa;
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=e[i].nxt)
		if(e[i].to!=fa)
		{
			siz[u]++;
			dfs1(e[i].to,u);
		}
	return ;
}
void dfs2(int u,int tp)
{
	top[u]=tp;
	if(!siz[u])
		return ;
	int maxsiz=0,Son=0;
	for(int i=head[u];i;i=e[i].nxt)
		if(e[i].to!=f[u])
			if(siz[e[i].to]>maxsiz)
				Son=e[i].to,maxsiz=siz[e[i].to];
	for(int i=head[u];i;i=e[i].nxt)
		if(e[i].to!=f[u])
		{
			if(e[i].to==Son)
				dfs2(e[i].to,tp);
			else
				dfs2(e[i].to,e[i].to);
		}
	return ;
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	if(dep[fa[top[u]]]<)
}*/
/*
struct Segment_tree
{
	#define lson (o<<1)
	#define rson (o<<1|1)
	int sumv[MAXN<<2],tag[MAXN<<2];
	void pushup(int o)
	{
		sumv[o]=sumv[lson]+sumv[rson];
		return ;
	}
	void pushdown(int o,int l,int r)
	{
		if(!tag[o])
			return ;
		int mid=(l+r)>>1;
		sumv[lson]=tag[o]*(mid-l+1);
		sumv[rson]=tag[o]*(r-mid);
		tag[lson]=(tag[rson]=tag[o]);
		tag[o]=0;
		return ;
	}
	void build(int o,int l,int r)
	{
		if(l==r)
		{
			sumv[o]=nothing[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(lson,l,mid);
		build(rson,mid+1,r);
		pushup(o);
	}
	int retv(int o,int l,int r,int pos)
	{
		if(l==r)
			return sumv[o];
		int mid=(l+r)>>1;
		pushdown(o,l,r);
		if(pos<=mid)
			return retv(lson,l,mid,pos);
		else 
			return retv(rson,mid+1,r,pos);
	}
	void change(int o,int l,int r,int pl,int pr,int v)
	{
		if(pl<=l&&pr>=r)
		{
			tag[o]+=v;
			sumv[o]+=(r-l+1)*v;
			return ;
		}
		pushdown(o,l,r);
		int mid=(l+r)>>1;
		if(pl<=mid)
			change(lson,l,mid,pl,pr,v);
		if(pr>mid)
			change(rson,mid+1,r,pl,pr,v);
		pushup(o);
		return ;
	}
}seg1,seg2;*/
bool cmp(P a,P b)
{
	return a.f<b.f;
}
int main(void)
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	/*seg1.build(1,1,m1);
	seg2.build(1,1,m2);*/
	for(int i=1;i<=m1;i++)
		scanf("%d %d",&a[i].f,&a[i].s);
	for(int i=1;i<=m2;i++)
		scanf("%d %d",&b[i].f,&b[i].s);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int j=1;j<=n&&num<m1;j++)
	{
		for(int i=1;i<=m1;)
		{
			int L=i+1,R=m1,fl=0;
			while(R>L)
			{
				int mid=(L+R)>>1;
				if(a[mid].f<a[i].s)
					L=mid+1;
				else
				{
					R=mid;
					fl=1;
				}
			}
			if(a[L].f>=a[i].s)
					fl=1;
			while(i<=m1&&del[i])
				i++;
			del[i]=1;
			num++;
			ans[0][j]++;
			if(!fl)
				break;
			if(num==m1)
				break;
			i=L;
			while(i<=m1&&del[i])
				i++;
			if(i==m1+1)
				break;
			/*int s1=seg1.retv(1,1,n,i);
			for(int i=1;i<=s1*4;i++)
				printf("")*/
		/*if(seg1.retv(1,1,m1,i)==0)
			cout << i << endl;*/
		//ans[0][seg2.retv(1,1,m2,i)]++;
		}
	}
	memset(del,0,sizeof(del));
	num=0;
	for(int j=1;j<=n&&num<m2;j++)
	{
		for(int i=1;i<=m2;)
		{
			int L=i+1,R=m2,fl=0;
			while(R>L)
			{
				int mid=(L+R)>>1;
				if(b[mid].f<b[i].s)
					L=mid+1;
				else
				{
					R=mid;
					fl=1;
				}
			}
			if(b[L].f>=b[i].s)
					fl=1;
			while(i<=m2&&del[i])
				i++;
			del[i]=1;
			num++;
			if(num==m2)
				break;
			ans[1][j]++;
			if(!fl)
				break;
			i=L;
			while(i<=m2&&del[i])
				i++;
			if(i==m2+1)
				break;
			/*int s1=seg1.retv(1,1,n,i);
			for(int i=1;i<=s1*4;i++)
				printf("")*/
		/*if(seg1.retv(1,1,m1,i)==0)
			cout << i << endl;*/
		//ans[0][seg2.retv(1,1,m2,i)]++;
		}
	}
	int sum=0;
	for(int i=0;i<=n;i++)
		ans[0][i]+=sum,sum=ans[0][i];
	sum=0;
	for(int i=0;i<=n;i++)
		ans[1][i]+=sum,sum=ans[1][i];
	for(int i=0;i<=n;i++)
		lastans=max(lastans,ans[0][i]+ans[1][n-i]);
	printf("%d",lastans);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
