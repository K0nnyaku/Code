#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
int ans[1000005],now[1000005],n,yes;
deque <int> a;

int ck(){
	for(int i=1;i<=n;i++){
		if(now[i]!=now[2*n+1-i])
		return 0;
	}
	/*for(int i=1;i<=2*n;i++){
		printf("%c ",ans[i]==1?'L':'R');
	}
	printf("\n");
	for(int i=1;i<=2*n;i++){
		printf("%d ",now[i]);
	}
	printf("\n");*/
	return 1;
}

void DFS(int dep){
	if(yes) return;
	if(dep==2*n){
		yes=ck();
		return;
	}
	if(yes) return;
	int topr=a.front(),backr=a.back();
	now[dep+1]=topr;
	a.pop_front();
	ans[dep+1]=1;
	DFS(dep+1);
	if(yes) return;
	a.push_front(topr);
	now[dep+1]=backr;
	a.pop_back();
	ans[dep+1]=2;
	DFS(dep+1);
	a.push_back(backr);
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T){
		T--;yes=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			int ai;
			scanf("%d",&ai);
			a.push_back(ai);
		}
		DFS(0);
		if(yes){
			for(int i=1;i<=2*n;i++){
				if(ans[i]==1) printf("L");
				else printf("R");
			}
		}
		else printf("-1");
		while(!a.empty())
			a.pop_front();
		printf("\n");
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
