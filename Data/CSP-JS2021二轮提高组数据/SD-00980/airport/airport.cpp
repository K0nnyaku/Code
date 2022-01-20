#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
inline void file(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}
const int N=1e5+10;
int n,m1,m2,ans;
struct node{
	int l,r;
}a1[N],a2[N];
bool cmp(node x,node y){
	return x.l^y.l?x.l<y.l:x.r<y.r;
}
priority_queue<int> q1;
priority_queue<int> q2;
int sol1(int x){
	if(!x) return 0;
	while(!q1.empty()) q1.pop();
	int res=0;
	for(int i=1;i<=m1;i++){
		if(i<=x) res++,q1.push(-a1[i].r);
		else if(-q1.top()<a1[i].l) res++,q1.pop(),q1.push(-a1[i].r);
	}
	return res;
}
int sol2(int x){
	if(!x) return 0;
	while(!q2.empty()) q2.pop();
	int res=0;
	for(int i=1;i<=m2;i++){
		if(i<=x) res++,q2.push(-a2[i].r);
		else if(-q2.top()<a2[i].l) res++,q2.pop(),q2.push(-a2[i].r);
	}
	return res;
}
int main(){
	file();
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++) a1[i].l=read(),a1[i].r=read();
	for(int i=1;i<=m2;i++) a2[i].l=read(),a2[i].r=read();
	sort(a1+1,a1+m1+1,cmp); sort(a2+1,a2+m2+1,cmp);
	for(int i=0;i<=n;i++){
		ans=max(ans,sol1(i)+sol2(n-i));
	}
	printf("%d\n",ans);
	return 0;
}
