#include<bits/stdc++.h>
using namespace std;
#define T1 tree1[p]
#define L1 tree1[T1.l]
#define R1 tree1[T1.r]
#define T2 tree2[p]
#define L2 tree2[T2.l]
#define R2 tree2[T2.r]
int n,m1,m2,dp1[100005],dp2[100005],len1,len2,ans;
int t1[100005],t2[100005];
struct p{
	int cm,lve;
}a1[100005],a2[100005];
struct node{
	int l,r,v;
}tree1[100005],tree2[100005]; 
int find_1(int x,int l,int r,int p){
	if(l==r){
		T1.v=a1[x].lve;
		return l;
	}int s;
	T1.l=p<<1;T1.r=p<<1|1;
	int mid=(l+r)>>1;
	if(L1.v<a1[x].cm){
		s=find_1(x,l,mid,T1.l);
	}else{
		s=find_1(x,mid+1,r,T1.r);
	}T1.v=min(L1.v,R1.v);
	return s;
}
int find_2(int x,int l,int r,int p){
	if(l==r){
		T2.v=a2[x].lve;
		return l;
	}int s;
	T2.l=p<<1;T2.r=p<<1|1;
	int mid=(l+r)>>1;
	if(L2.v<a2[x].cm){
		s=find_2(x,l,mid,T2.l);
	}else{
		s=find_2(x,mid+1,r,T2.r);
	}T2.v=min(L2.v,R2.v);
	return s;
}
void work2(){
	for(int i=1;i<=m1;i++){
		int can=find_1(i,1,m1,1);
		dp1[can]++;
	}
	for(int i=1;i<=m2;i++){
		int can=find_2(i,1,m2,1);
		dp2[can]++;
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)cin>>a1[i].cm>>a1[i].lve;
	for(int i=1;i<=m2;i++)cin>>a2[i].cm>>a2[i].lve;
	work2();
	for(int i=2;i<=min(n,max(m1,m2));i++){
		dp1[i]+=dp1[i-1];
		dp2[i]+=dp2[i-1];
	}for(int i=0;i<=n;i++){
		ans=max(ans,dp1[i]+dp2[n-i]);
	}printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
