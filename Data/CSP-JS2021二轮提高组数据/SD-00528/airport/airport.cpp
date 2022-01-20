#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#define ls (now<<1)
#define rs ((now<<1)|1)
#define mid ((l+r)>>1)
using namespace std;
const int maxn=100005;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int l[maxn],r[maxn],id[maxn];
int n,m1,m2,mx;
int ans,dp[maxn],dp2[maxn],num[maxn];
struct node{
	int mn;
}t[4*maxn];
bool cmp(int a,int b){
	return l[a]<l[b];
}
int query(int now,int l,int r,int v){
	if(l==r)return l;
	int ans=0;
	if(v>t[ls].mn)ans=query(ls,l,mid,v);
	else if(v>t[rs].mn)ans=query(rs,mid+1,r,v);
	return ans;
}
void update(int now,int l,int r,int x,int v){
	if(l==r){
		t[now].mn=v;
		return;
	}
	if(x<=mid)update(ls,l,mid,x,v);
	else if(x>mid)update(rs,mid+1,r,x,v);
	t[now].mn=min(t[ls].mn,t[rs].mn);
}
void build(int now,int l,int r){
	if(l==r){
		t[now].mn=0;
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[now].mn=0;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++){
		id[i]=i;
		l[i]=read();r[i]=read();
	}
	sort(id+1,id+m1+1,cmp);
	for(int i=1;i<=m1;i++){
		int j=query(1,1,n,l[i]);
		if(!j)continue;
		dp[j]++;
		update(1,1,n,j,r[i]);
	}
	for(int i=1;i<=n;i++)dp[i]+=dp[i-1];
	
	build(1,1,n);
	for(int i=1;i<=m2;i++){
		id[i]=i;
		l[i]=read();r[i]=read();
	}
	sort(id+1,id+m2+1,cmp);
	for(int i=1;i<=m2;i++){
		int j=query(1,1,n,l[i]);
		if(!j)continue;
		dp2[j]++;
		update(1,1,n,j,r[i]);
	}
	for(int i=1;i<=n;i++)dp2[i]+=dp2[i-1];	
	for(int i=0;i<=n;i++)ans=max(ans,dp[i]+dp2[n-i]);
	cout<<ans;
	return 0;
} 
