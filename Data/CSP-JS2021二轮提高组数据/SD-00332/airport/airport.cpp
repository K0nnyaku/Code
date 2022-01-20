#include<bits/stdc++.h>
using namespace std;
map<int,int>vis;
int vis1[100101],vis2[100101],tree[400101];
int n,m1,m2,ctop,dtop,c[100101],d[100101],ans,s[200101],stop;
struct node{
	int l,r;
}a[100101],b[100101];
bool cmp(const node &a,const node &b){
	return a.l<b.l;
}
void pushup(int o){
	tree[o]=min(tree[o<<1],tree[o<<1|1]);
}
void add(int o,int l,int r,int x,int k){
	if(l==r){
		tree[o]=k;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(o<<1,l,mid,x,k);
	else add(o<<1|1,mid+1,r,x,k);
	pushup(o);
}
int sum(int o,int l,int r,int x){
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(tree[o<<1]<=x)return sum(o<<1,l,mid,x);
	else return sum(o<<1|1,mid+1,r,x);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].l,&a[i].r),s[++stop]=a[i].l,s[++stop]=a[i].r;
	sort(s+1,s+stop+1);stop=unique(s+1,s+stop+1)-s-1;
	for(int i=1;i<=stop;i++)vis[s[i]]=i;
	for(int i=1;i<=m1;i++){
		a[i].l=vis[a[i].l];a[i].r=vis[a[i].r];
	}
	sort(a+1,a+m1+1,cmp);memset(tree,0x3f,sizeof(tree));
	for(int i=1;i<=m1;i++){
		if(tree[1]>a[i].l)c[++ctop]=1,add(1,1,m1,ctop,a[i].r);
		else{
			int x=sum(1,1,m1,a[i].l);
			c[x]++;
			add(1,1,m1,x,a[i].r);
		}
	}
	for(int i=1;i<=ctop;i++)c[i]+=c[i-1];
	stop=0;vis.clear();
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].l,&b[i].r),s[++stop]=b[i].l,s[++stop]=b[i].r;
	sort(s+1,s+stop+1);stop=unique(s+1,s+stop+1)-s-1;
	for(int i=1;i<=stop;i++)vis[s[i]]=i;
	for(int i=1;i<=m2;i++){
		b[i].l=vis[b[i].l];b[i].r=vis[b[i].r];
	}
	sort(b+1,b+m2+1,cmp);memset(tree,0x3f,sizeof(tree));
	for(int i=1;i<=m2;i++){
		if(tree[1]>b[i].l)d[++dtop]=1,add(1,1,m2,dtop,b[i].r);
		else{
			int x=sum(1,1,m2,b[i].l);
			d[x]++;
			add(1,1,m2,x,b[i].r);
		}
	}
	for(int i=1;i<=dtop;i++)d[i]+=d[i-1];
	for(int i=1;i<=min(n,ctop);i++)ans=max(ans,c[i]+d[min(dtop,n-i)]);
	cout<<ans;
	return 0;
}

