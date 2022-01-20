#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<deque>
#include<vector>
#include<map>
#define ri int
#define ll long long
#define N 100005
using namespace std;
inline int read(){
	int rd=0,ch,flag=1;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') flag=-1;
	do rd=(rd<<1)+(rd<<3)+(ch^48);while((ch=getchar())>='0'&&ch<='9');
	return rd*flag;
}
int n,m1,m2;
struct timm{
	int l,r;
}t1[N],t2[N];
int cnt,last[N];
bool cmp(timm a,timm b){
	return a.l<b.l;
}
int ans1[N],ans2[N];
priority_queue<int> q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(ri i=1;i<=m1;++i) t1[i].l=read(),t1[i].r=read();
	for(ri i=1;i<=m2;++i) t2[i].l=read(),t2[i].r=read();
	sort(t1+1,t1+1+m1,cmp);
	sort(t2+1,t2+1+m2,cmp);
	for(int k=1;k<=n;++k){
		while(!q.empty()) q.pop();
		for(int i=1;i<=m1;++i){
			int t=t1[i].l;
			while(!q.empty()&&q.top()*-1<t) q.pop();
			if(q.size()<k) q.push(t1[i].r*-1),++ans1[k];
		}
	}
	for(ri k=1;k<=n;++k){
		while(!q.empty()) q.pop();
		for(ri i=1;i<=m2;++i){
			int t=t2[i].l;
			while(!q.empty()&&q.top()*-1<t) q.pop();
			if(q.size()<k) q.push(t2[i].r*-1),++ans2[k];
		}
	}
//	for(ri i=1;i<=n;++i) cout<<ans1[i]<<" ";
//	cout<<endl;
//	for(ri i=1;i<=n;++i) cout<<ans2[i]<<" ";
	int ans=0;
	for(ri i=0;i<=n;++i) ans=max(ans,ans1[i]+ans2[n-i]);
	cout<<ans;
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
