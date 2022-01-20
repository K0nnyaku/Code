//CSP2021 rp++ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+(ch-'0'),ch=getchar();
	return s*w;
}
const int MAXN(400010);
int edge,n,m;
struct node{int val,idx;bool type;};
node c[MAXN];
int cnt,v;
inline bool cmp(node x,node y){return x.val<y.val;}
struct air{int arr,lea;};
air a[MAXN],b[MAXN];
inline bool cmp2(air x,air y){return x.arr<y.arr;}
int sum[MAXN];
inline int Max(int x,int y){return x>y?x:y;}
int ans;
struct Segment_Tree
{
	int tree[MAXN*4],tag[MAXN*4];
	inline int lc(int p){return p<<1;}
	inline int rc(int p){return p<<1|1;}
	inline void push_up(int u)
	{
		tree[u]=Max(tree[lc(u)],tree[rc(u)]);
		return;
	}
	inline void lazy_tag(int u,int l,int r,int k)
	{
		tag[u]+=k;
		tree[u]+=k;
		return;
	}
	inline void push_down(int u,int l,int r)
	{
		int mid=(l+r)>>1;
		lazy_tag(lc(u),l,mid,tag[u]);
		lazy_tag(rc(u),mid+1,r,tag[u]);
		tag[u]=0;
		return;
	}
	inline void update(int u,int l,int r,int ln,int rn,int k)
	{
		if(ln<=l&&r<=rn)
		{
			lazy_tag(u,l,r,k);
			return;
		}
		push_down(u,l,r);
		int mid=(l+r)>>1;
		if(ln<=mid) update(lc(u),l,mid,ln,rn,k);
		if(rn>mid) update(rc(u),mid+1,r,ln,rn,k);
		push_up(u);
		return;
	}
	inline int query(int u,int l,int r,int ln,int rn)
	{
		int res(0);
		if(ln<=l&&r<=rn) return tree[u];
		int mid=(l+r)>>1;
		push_down(u,l,r);
		if(ln<=mid) res=Max(res,query(lc(u),l,mid,ln,rn));
		if(rn>mid) res=Max(res,query(rc(u),mid+1,r,ln,rn));
		return res;
	}
	inline void Clear()
	{
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		return;
	}
};
Segment_Tree seg; 
int p;
int d1[MAXN],d2[MAXN];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	edge=read(),n=read(),m=read();
	for(register int i=1;i<=n+m;i++)
	{
		c[++cnt].val=read();
		c[cnt].idx=i;
		c[cnt].type=false;
		c[++cnt].val=read();
		c[cnt].idx=i;
		c[cnt].type=true; 
	}
	sort(c+1,c+1+cnt,cmp);
	for(register int i=1;i<=cnt;i++)
	{
		if(c[i].val!=c[i-1].val) ++v;
		if(c[i].idx<=n)
		{
			if(!c[i].type) a[c[i].idx].arr=v;
			else a[c[i].idx].lea=v;
		} 
		else
		{
			if(!c[i].type) b[c[i].idx-n].arr=v;
			else b[c[i].idx-n].lea=v;
		}
	}
	sort(a+1,a+1+n,cmp2);
	sort(b+1,b+1+m,cmp2);
	for(register int i=1;i<=n;i++) d1[a[i].arr]++,d1[a[i].lea+1]--;
	for(register int i=1;i<=m;i++) d2[b[i].arr]++,d2[b[i].lea+1]--;
	for(register int i=1;i<=cnt;i++) d1[i]+=d1[i-1],d2[i]+=d2[i-1];
	for(register int i=1;i<=cnt;i++)
		d1[0]=Max(d1[0],d1[i]),d2[0]=Max(d2[0],d2[i]);
	if(d1[0]+d2[0]<=edge)
	{
		printf("%d\n",n+m);
		return 0;
	}
	for(register int fir=0;fir<=edge;fir++)
	{
		int sec=edge-fir;
		int cnt(0);
		if(fir!=0)
		{
			seg.Clear();
			for(register int i=1;i<=n;i++)
			{
				if(seg.query(1,1,v,a[i].arr,a[i].lea)<=fir-1)
				{
					++cnt;
					seg.update(1,1,v,a[i].arr,a[i].lea,1);
				} 
				if(cnt+n-i+m<=ans) break;
			}
		}
		if(sec!=0)
		{
			seg.Clear();
			for(register int i=1;i<=m;i++)
			{
				if(seg.query(1,1,v,b[i].arr,b[i].lea)<=sec-1)
				{
					++cnt;
					seg.update(1,1,v,b[i].arr,b[i].lea,1);
				}
				if(cnt+m-i<=ans) break;
			}
		}
		if(cnt>ans) ans=cnt,p=fir;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
