#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long

ll qread(){
	ll number=0;int zhengfu=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') zhengfu=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') number=(number<<1)+(number<<3)+(ch^48),ch=getchar();
	return number*zhengfu;
}
ll ret,n,m1,m2,a1[100010],a2[100010],b1[100010],t11[100010],t22[100010],b2[100010],l1[100010],l2[100010];
struct node{
	int a,b;
}t1[100010],t2[100010];
bool cmp1(node x,node y){
	return x.a<y.a;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=qread(),m1=qread(),m2=qread();
	for(int i=1;i<=m1;++i){
		t1[i].a=qread(),t1[i].b=qread();
		t11[i]=t1[i].b;
	}
	for(int i=1;i<=m2;++i){
		t2[i].a=qread(),t2[i].b=qread();
		t22[i]=t2[i].b;
	}
	sort(t1+1,t1+m1+1,cmp1);
	sort(t2+1,t2+m2+1,cmp1);
	sort(t11+1,t11+m1+1);
	sort(t22+1,t22+m2+1);
	for(int i=1;i<=m1;i++){
		int com=t1[i].a;
		ll l=1,r=1e9,mid,ans=0;
		while(r>l){
			mid=(l+r)>>1;
			if(mid<=m1&&t11[mid]<=com){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		l1[i]=i-ans;
	}
	for(int i=1;i<=m2;i++){
		int com=t2[i].a;
		ll l=0,r=1e9,mid,ans=0;
		while(r>l){
			mid=(l+r)>>1;
			if(mid<=m2&&t22[mid]<=com){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		l2[i]=i-ans;
	}
	sort(l1+1,l1+m1+1);
	sort(l2+1,l2+m2+1);
	for(int i=0;i<=n;i++){
		int br1=i,br2=n-i;
		ll l=0,r=1e9,mid=0,ans1=0;
		while(r>l){
			mid=(l+r)>>1;
			if(mid<=m1&&l1[mid]<=br1){
				ans1=mid;
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		
		l=0,r=1e9,mid=0;
		int ans2=0;
		while(r>l){
			mid=(l+r)>>1;
			if(mid<=m2&&l2[mid]<=br2){
				ans2=mid;
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		ret=max(ret,ans1+ans2);
		//cout<<"i:"<<i<<" "<<ans1<<" "<<ans2<<" "<<ret<<endl;
	}
	printf("%lld",ret);
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

1 2 2 2 2
1 2 3 3
-----------------
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

1 1 2 2
1 2 3 3 3 3

1010
111000
*/
