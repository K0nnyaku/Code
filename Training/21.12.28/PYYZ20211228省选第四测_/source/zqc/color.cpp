#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int f=1,s=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<1)+(s<<3)+(c^48);
		c=getchar();
	}
	return f*s;
}
struct edge
{
	int next,to;
}e[300010];
struct segmenttree
{
	int l,r;
	int lc,rc,tag;
	long long val1,val2;
}t[1000010];
int n,colcnt,q;
char ch[5];
int head[150010],tot;
int dep[150010],siz[150010],in[150010],out[150010];
int fa[150010][30],id[150010],cnt;
int msz[150010],mss[150010],top[150010];
void add(int from,int to)
{
	e[++tot].next=head[from];
	e[tot].to=to;
	head[from]=tot;
}
void dfs(int now,int fat)
{
	siz[now]=1;
	dep[now]=dep[fat]+1;
	fa[now][0]=fat;
	for(int i=1;i<=25;i++) fa[now][i]=fa[fa[now][i-1]][i-1];
	for(int i=head[now];i;i=e[i].next)
	{
		if(e[i].to==fat) continue;
		dfs(e[i].to,now);
		siz[now]+=siz[e[i].to];
		if(siz[e[i].to]>msz[now])
		{
			msz[now]=siz[e[i].to];
			mss[now]=e[i].to;
		}
	}
}
void dfs2(int now,int fat,int tp)
{
	top[now]=tp;id[++cnt]=now;
	in[now]=cnt;
	if(mss[now]) dfs2(mss[now],now,tp);
	for(int i=head[now];i;i=e[i].next)
	{
		if(e[i].to==fat) continue;
		if(e[i].to==mss[now]) continue;
		dfs2(e[i].to,now,e[i].to);
	}
	out[now]=cnt;
}
void pushup(int p)
{
	t[p].val1=t[p*2].val1+t[p*2+1].val1;
	t[p].val2=t[p*2].val2+t[p*2+1].val2;
	t[p].lc=t[p*2].lc;
	t[p].rc=t[p*2+1].rc;
	if(t[p*2].rc==t[p*2+1].lc) return;
	t[p].val1++;
	if(fa[id[t[p*2].r]][0]==id[t[p*2+1].l]) t[p].val2+=1LL*siz[id[t[p*2].r]];
	else t[p].val2+=1LL*siz[id[t[p*2+1].l]];
}
void pushdown(int p)
{
	if(t[p].tag)
	{
		t[p*2].tag=t[p].tag;
		t[p*2+1].tag=t[p].tag;
		t[p*2].lc=t[p*2+1].lc=t[p].tag;
		t[p*2].rc=t[p*2+1].rc=t[p].tag;
		t[p*2].val1=t[p*2+1].val1=0;
		t[p*2].val2=t[p*2+1].val2=0;
		t[p].tag=0;
	}
}
void build(int l,int r,int p)
{
	t[p].l=l;t[p].r=r;
	if(l==r)
	{
		t[p].lc=t[p].rc=id[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	pushup(p);
}
void change(int l,int r,int x,int p)
{
	if(t[p].l>=l&&t[p].r<=r)
	{
		t[p].lc=t[p].rc=x;
		t[p].val1=t[p].val2=0;
		t[p].tag=x;
		return;
	}
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	if(l<=mid) change(l,r,x,p*2);
	if(r>mid) change(l,r,x,p*2+1);
	pushup(p);
}
long long ask1(int l,int r,int p)
{
	if(t[p].l>=l&&t[p].r<=r) return t[p].val1;
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	long long res=0;
	if(l<=mid) res+=ask1(l,r,p*2);
	if(mid<r) res+=ask1(l,r,p*2+1);
	if(l<=mid&&mid<r) if(t[p*2].rc!=t[p*2+1].lc) res++;
	return res;
}
long long ask2(int l,int r,int p)
{
	if(t[p].l>=l&&t[p].r<=r) return t[p].val2;
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	long long res=0;
	if(l<=mid) res+=ask2(l,r,p*2);
	if(mid<r) res+=ask2(l,r,p*2+1);
	if(l<=mid&&mid<r)
	{
		if(t[p*2].rc!=t[p*2+1].lc)
		{
			if(fa[id[t[p*2].r]][0]==id[t[p*2+1].l]) res+=siz[id[t[p*2].r]];
			else res+=siz[id[t[p*2+1].l]];
		}
	}
	return res;
}
int getcol(int x,int p)
{
	if(x==t[p].l) return t[p].lc;
	if(x==t[p].r) return t[p].rc;
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	if(x<=mid) return getcol(x,p*2);
	else return getcol(x,p*2+1);
}
void listchange(int p,int x)
{
	while(top[p]!=1)
	{
		change(in[top[p]],in[p],x,1);
		p=fa[top[p]][0];
	}
	change(in[1],in[p],x,1);
}
long long listask(int p)
{
	long long res=0,lstcol=0;
	while(top[p]!=1)
	{
		res+=ask1(in[top[p]],in[p],1);
		if(lstcol!=getcol(in[p],1)) res++;
		lstcol=getcol(in[top[p]],1);
		p=fa[top[p]][0];
	}
	res+=ask1(in[1],in[p],1);
	if(lstcol!=getcol(in[p],1)) res++;
	return res-1;
}
void segmenttree_print(int p)
{
	printf("%d %d %d %d %d %lld %lld\n",p,t[p].l,t[p].r,t[p].lc,t[p].rc,t[p].val1,t[p].val2);
	if(t[p].l==t[p].r) return;
	segmenttree_print(p*2);
	segmenttree_print(p*2+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read();colcnt=n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=read();v=read();
		u++;v++;
		add(u,v);add(v,u);
	}
	dfs(1,0);dfs2(1,0,1);
	build(1,n,1);
//	segmenttree_print(1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int u;
		scanf("%s",ch);
		u=read();u++;
		if(ch[0]=='q')
		{
			long long res=listask(u)*siz[u];
//			printf("%lld ",res);
			res+=ask2(in[u],out[u],1);
//			printf("%lld\n",res);
			printf("%.10f\n",(double)res/siz[u]);
		}
		else if(ch[0]=='O')
		{
			colcnt++;
			listchange(u,colcnt);
		}
	}
}
/*
12
1 2
1 3
2 4
2 5
4 6
4 7
5 8
5 9
3 10
10 11
11 12



*/
