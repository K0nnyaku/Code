#include<stdio.h>
#include<algorithm>
#include<string.h>
using std::sort;
using std::lower_bound;

int n,m1,m2;
struct Pair{ int l,r; }a[100002],b[100002];
inline bool cmp(Pair x,Pair y){ return x.l<y.l; }

struct Node{ int l,r,min,tag; }t[400002];
#define lq(u) ((u)<<1)
#define rq(u) ((u)<<1|1)

inline int min(int x,int y){ return x<y?x:y; }
inline void push_up(int u){ t[u].min=min(t[lq(u)].min,t[rq(u)].min); }
inline void add_tag(int u,int tag){ t[u].tag+=tag,t[u].min+=tag; }
inline void push_down(int u){ add_tag(lq(u),t[u].tag),add_tag(rq(u),t[u].tag),t[u].tag=0; }

void build(int l,int r,int u)
{
	t[u].l=l,t[u].r=r,t[u].tag=0;
	if(l==r){ t[u].min=0; return; }
	int mid=t[u].l+t[u].r>>1;
	build(l,mid,lq(u)),build(mid+1,r,rq(u));
	push_up(u);
}
void change(int l,int r,int u,int v)
{
	if(l<=t[u].l&&t[u].r<=r){ add_tag(u,v);return; }
	int mid=t[u].l+t[u].r>>1;
	push_down(u);
	if(l<=mid) change(l,r,lq(u),v);
	if(mid+1<=r) change(l,r,rq(u),v);
	push_up(u);
}
void freeze(int p,int u)
{
	if(t[u].l==t[u].r){ t[u].min=0x3f3f3f3f;return; }
	int mid=t[u].l+t[u].r>>1;
	push_down(u);
	if(p<=mid) freeze(p,lq(u));
	else freeze(p,rq(u));
	push_up(u);
}
inline int query(int k)
{
	if(t[1].min>=k) return -1;
	int u=1;
	while(t[u].l!=t[u].r)
		push_down(u),u=(t[lq(u)].min<k?lq(u):rq(u));
	return t[u].l;
}

int f[100002],g[100002];

inline void solve(int m,Pair *a,int *ans)
{
	build(1,m,1);
	for(int i=1,p;i<=n;i++)
	{
		ans[i]=ans[i-1];
		while((p=query(i))!=-1)
		{
			ans[i]++;
			freeze(p,1);
			change(p,a[p].r,1,1);
		}
	}
}

int temp[200002];

inline int max(int x,int y){ return x>y?x:y; }

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&a[i].l,&a[i].r),temp[i]=a[i].l;
	sort(temp+1,temp+m1+1);
	for(int i=1;i<=m1;i++) a[i].l=lower_bound(temp+1,temp+m1+1,a[i].l)-temp,a[i].r=lower_bound(temp+1,temp+m1+1,a[i].r)-temp-1;
	for(int i=1;i<=m2;i++) scanf("%d%d",&b[i].l,&b[i].r),temp[i]=b[i].l;
	sort(temp+1,temp+m2+1);
	for(int i=1;i<=m2;i++) b[i].l=lower_bound(temp+1,temp+m2+1,b[i].l)-temp,b[i].r=lower_bound(temp+1,temp+m2+1,b[i].r)-temp-1;
	sort(a+1,a+m1+1,cmp),sort(b+1,b+m2+1,cmp);
	solve(m1,a,f),solve(m2,b,g);
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,f[i]+g[n-i]);
	printf("%d",ans);
	return 0;
}
