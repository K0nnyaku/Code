//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=100005; 
int n,m1,m2,ans,d1[maxn],d2[maxn],cnt1,cnt2,d[maxn*6];
struct node{
	int l,r;
}a[maxn],b[maxn];
bool cmp(node x,node y){
	return x.l<y.l;
}

inline void pushup(int id){
	d[id]=min(d[id*2],d[id*2+1]);
}
void update(int id,int l,int r,int x,int v){
	if(l==r){
		d[id]=v;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) update(id*2,l,mid,x,v);
	else update(id*2+1,mid+1,r,x,v);
	pushup(id); 
}
int query(int id,int l,int r,int v){
	if(d[id]>v) return n+1;
	if(l==r) return l;
	int mid=(l+r)/2;
	if(d[id*2]<v) return query(id*2,l,mid,v);
	return query(id*2+1,mid+1,r,v);
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	sort(a+1,a+m1+1,cmp);
	
	for(int i=1;i<=m1;i++){
		if(i==1||d[1]>a[i].l){
			if(cnt1==n) continue;
			d1[++cnt1]++;
			update(1,1,n,cnt1,a[i].r);
		}else{
			int k=query(1,1,n,a[i].l);
			d1[k]++;
			update(1,1,n,k,a[i].r);
		}
	}
	for(int i=1;i<=n;i++) d1[i]+=d1[i-1];
	
	memset(d,0x3f,sizeof(d)); 
	
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].l,&b[i].r);
	}
	sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=m2;i++){
		if(i==1||d[1]>b[i].l){
			if(cnt2==n) continue;
			d2[++cnt2]++;
			update(1,1,n,cnt2,b[i].r);
		}else{
			int k=query(1,1,n,b[i].l);
			d2[k]++;
			update(1,1,n,k,b[i].r);
		}
	}
	for(int i=1;i<=n;i++) d2[i]+=d2[i-1];
	
	for(int i=0;i<=n;i++) ans=max(ans,d1[i]+d2[n-i]);
	printf("%d\n",ans);
	return 0;
}

