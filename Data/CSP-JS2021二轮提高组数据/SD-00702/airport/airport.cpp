//ver 2.0 sgt ACed
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int N=100005;
int n,m1,m2,ans,p1[N<<1],p2[N<<1],t1,t2,tot,siz1[N],siz2[N],sum1[N],sum2[N],lst[N];
pair<int,int> a[N],b[N];
int q1(int x) {
	return lower_bound(p1+1,p1+t1+1,x)-p1;
}
int q2(int x) {
	return lower_bound(p2+1,p2+t2+1,x)-p2;
}
int tr[N*10];
#define mid ((l+r)>>1)
#define lson (now<<1)
#define rson (now<<1|1)
void update(int now) {
	tr[now]=min(tr[lson],tr[rson]);
}
void build(int now,int l,int r) {
	if(l==r) {tr[now]=N*2;return;}
	build(lson,l,mid),build(rson,mid+1,r);
	update(now);
}
void change(int now,int l,int r,int x,int z) {
	if(l==r) {tr[now]=z;return;}
	if(x<=mid) change(lson,l,mid,x,z);
	else change(rson,mid+1,r,x,z);
	update(now);
}
int ask(int now,int l,int r,int x,int y) {
	if(x>y) return N*2;
	if(x<=l&&r<=y) return tr[now]; 
	int res=N*2;
	if(x<=mid) res=min(res,ask(lson,l,mid,x,y));
	if(y>mid) res=min(res,ask(rson,mid+1,r,x,y));
	return res;
} 
#undef mid
#undef lson
#undef rson
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&a[i].first,&a[i].second),p1[++t1]=a[i].first,p1[++t1]=a[i].second;
	for(int i=1;i<=m2;i++) scanf("%d%d",&b[i].first,&b[i].second),p2[++t2]=b[i].first,p2[++t2]=b[i].second;
	sort(p1+1,p1+t1+1),sort(p2+1,p2+t2+1);
	for(int i=1;i<=m1;i++) a[i].first=q1(a[i].first),a[i].second=q1(a[i].second);
	for(int i=1;i<=m2;i++) b[i].first=q2(b[i].first),b[i].second=q2(b[i].second);
	sort(a+1,a+m1+1),sort(b+1,b+m2+1);
	build(1,1,t1);
	for(int i=1;i<=m1;i++) {
		int x=ask(1,1,t1,1,a[i].first-1);
		if(x==N*2) tot++,siz1[tot]++,change(1,1,t1,a[i].second,tot),lst[tot]=a[i].second;
		else siz1[x]++,change(1,1,t1,lst[x],N*2),change(1,1,t1,a[i].second,x),lst[x]=a[i].second; 
	}
	build(1,1,t2);
	tot=0;
	memset(lst,0,sizeof lst);
	for(int i=1;i<=m2;i++) {
		int x=ask(1,1,t2,1,b[i].first-1);
		if(x==N*2) tot++,siz2[tot]++,change(1,1,t2,b[i].second,tot),lst[tot]=b[i].second;
		else siz2[x]++,change(1,1,t2,lst[x],N*2),change(1,1,t2,b[i].second,x),lst[x]=b[i].second;
	}
	for(int i=1;i<=n;i++) sum1[i]=sum1[i-1]+siz1[i],sum2[i]=sum2[i-1]+siz2[i];
	int maxi=-1;
	for(int i=0;i<=n;i++) {
		if(ans<sum1[i]+sum2[n-i]) ans=sum1[i]+sum2[n-i],maxi=i;
//		ans=max(ans,sum1[i]+sum2[n-i]);
	}
//	cout<<"D "<<maxi<<endl;
	printf("%d\n",ans);
	return 0;
}

