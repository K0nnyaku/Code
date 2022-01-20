#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<cstring>
#include<map>
#include<cmath>
#include<ctime>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x*f;
}
const int N=1e3+5;
int T,n;
int b[N],op[N],ans[N];
bool flg;
deque<int> q;
bool check(){
	for(int i=1;i<=n;i++){
		if(b[i]!=b[2*n-i+1]) return false;
	}
	return true;
}
void dfs(int now){
	if(flg) return;
	if(now>2*n){
		if(check()){
			for(int i=1;i<=2*n;i++) ans[i]=op[i];
			flg=1;
		}
		return;
	}
	
	op[now]=0;
	b[now]=q.front();
	q.pop_front();
	dfs(now+1);
	q.push_front(b[now]);
	
	op[now]=1;
	b[now]=q.back();
	q.pop_back();
	dfs(now+1);
	q.push_back(b[now]);
	b[now]=0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		while(!q.empty()) q.pop_back();
		flg=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			int a;
			scanf("%d",&a);
			q.push_back(a);
		}
		
		dfs(1);
			
		if(!flg){
			printf("-1\n");
			continue;
		}			
			
		for(int i=1;i<=2*n;i++){
			if(ans[i]==0) printf("L");
			else printf("R");
		}
		printf("\n");
	}
	return 0;
}

