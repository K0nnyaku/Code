#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#define long long
#define dd double
#define ld long double
#define ull unsigned long long
#define N 100010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x){
	x=0;int flag=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') flag*=-1;
	for(;isdigit(c);c=getchar()){x*=10;x+=c-'0';}
	x*=flag;
}

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct Node{
	int l,r,Next;
	inline bool operator < (const Node &b)const{
		return l<b.l;
	}
}a[3][N];

struct Rode{
	int val,id;
	inline Rode(){}
	inline Rode(int val,int id) : val(val),id(id) {}
	inline bool operator < (const Rode &b)const{
		if(val!=b.val) return val<b.val;
		else return id<b.id;
	}
};

bool vis[3][N];
int h[3][N];
int n,m1,m2,all;

set<Rode> S;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m1);read(m2);
	all=m1+m2+1;
	for(int i=1;i<=m1;i++){
		read(a[1][i].l);read(a[1][i].r);
	}
	for(int i=1;i<=m2;i++){
		read(a[2][i].l);read(a[2][i].r);
	}
	sort(a[1]+1,a[1]+m1+1);
	sort(a[2]+1,a[2]+m2+1);
	
	memset(vis,0,sizeof(vis));
	S.clear();
	for(int i=1;i<=m1;i++) S.insert(Rode(a[1][i].l,i));
	for(int i=1;i<=m1;i++){
		if(vis[1][i]) continue;
		int now=i;
		while(now!=all){
			vis[1][now]=1;
			auto it=S.lower_bound(Rode(a[1][now].r,all));
			if(it!=S.end()){
				a[1][now].Next=(*it).id;
				S.erase(it);
				now=a[1][now].Next;
			}
			else{
				a[1][now].Next=all;break;
			}
		}
	}

	S.clear();
	for(int i=1;i<=m2;i++) S.insert(Rode(a[2][i].l,i));
	auto it=S.lower_bound(Rode(927,all));
//	printf("next:%d\n",(*it).id);
	for(int i=1;i<=m2;i++){
		if(vis[2][i]) continue;
		int now=i;
		while(now!=all){
			vis[2][now]=1;
			auto it=S.lower_bound(Rode(a[2][now].r,all));
			if(it!=S.end()){
				a[2][now].Next=(*it).id;
//				printf("now:%d Next:%d\n",now,a[2][now].Next);
				S.erase(it);
				now=a[2][now].Next;
			}
			else{
				a[2][now].Next=all;break;
			}
		}
	}
//	for(int i=1;i<=m2;i++){
//		printf("i:%d l:%d r:%d Next:%d\n",i,a[2][i].l,a[2][i].r,a[2][i].Next);
//	}
	
	memset(vis,0,sizeof(vis));
	int tot=0;
//	printf("here\n");
	for(int i=1;i<=m1;i++){
		if(vis[1][i]) continue;
		tot++;
		int now=i,cnt=0;
		while(now!=all){
			vis[1][now]=1;
			cnt++;
			now=a[1][now].Next;
		}
		h[1][tot]=cnt;
	}
//	printf("here\n");
	
	tot=0;
	for(int i=1;i<=m2;i++){
//		printf("i:%d vis:%d\n",i,vis[2][i]);
		if(vis[2][i]) continue;
		tot++;
		int now=i,cnt=0;
		while(now!=all){
			vis[2][now]=1;
			cnt++;
			now=a[2][now].Next;
		}
		h[2][tot]=cnt;
	}
//	printf("here\n");
//	printf("%d %d\n",h[1][1],h[1][2]);
	for(int i=1;i<=n;i++){
		h[1][i]+=h[1][i-1];
		h[2][i]+=h[2][i-1];
//		printf("h[1][%d]=%d h[2][%d]=%d\n",i,h[1][i],i,h[2][i]);
	}
//	printf("%d %d\n",h[1][1],h[1][2]);
	int ans=-INF;
	for(int i=0;i<=n;i++){
		ans=Max(ans,h[1][i]+h[2][n-i]);
	}
	printf("%d\n",ans);
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
