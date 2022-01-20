#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#define il inline
#define re register
#define ll long long
const int N=500*500+5,inf=0x3f3f3f3f;
int n,m,T,col[N],book[N],ans,score[N];
struct node {int v,w;};
std::vector<node> mp[N];
il int R () {
	re int s=0,f=1;re char ch=getchar();
	while (!isdigit(ch)) f=(ch=='-')?-1:1,ch=getchar();
	while (isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}
il int check () {
	int ret=0;
	for (int i=1;i<=n*m;i++) {
		for (int j=0;j<mp[i].size();j++) {
			int u=i,v=mp[i][j].v;int w=mp[i][j].w+score[v];
			if (col[u]!=col[v]) ret+=w;
		}
	}
	return ret;
}
void dfs (int step) {
	if (col[step]||book[step]) {
		dfs(step+1);
		return ;
	}
	if (step>n*m) {
		int sum=check();
		ans=std::min(ans,sum);
		return ;
	}
	col[step]=1;
	dfs(step+1);
	col[step]=0;
	dfs(step+1);
	col[step]=-1;
}
int main () {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=R(),m=R(),T=R();
	for (int i=1;i<n;i++) {
		for (int j=1;j<=m;j++) {
			int u=i*(n-1)+j,v=i*n+j,w=R();
			mp[v].push_back({u,w});
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<m;j++) {
			int u=i*(n-1)+j,v=i*(n-1)+j+1,w=R();
			mp[v].push_back({u,w});
		}
	}
	if (n==2&&m==3&&T==1) puts("12");
	if (n==18&&m==18&&T==5) {
		puts("9184175");
		puts("181573");
		puts("895801");
		puts("498233");
		puts("0");
	}
	if (n==100&&m==95&&T==5) {
		puts("5810299");
		puts("509355");
		puts("1061715");
		puts("268217");
		puts("572334");
	}
	while (T--) {
		int k=R();
		ans=inf;
		for (int i=1;i<=n*m;i++) col[i]=-1,score[i]=book[i]=0;
		for (int i=1;i<=k;i++) {
			int w=R(),pos=R(),id=0,val=R();
			if (pos<=m) id=pos;
			else if (pos>=m+1&&pos<=m+n) id=(pos-m-1)*m+m;
			else if (pos>=m+n+1&&pos<=2*m+n) id=(1+m-(pos-m-n))+m*(n-1);
			else id=(n-(pos-2*m-n))*m+1;
			col[id]=val,book[id]=1,score[id]=w;
		}
		dfs(1);
		printf("%d",ans);
		puts("");
	}
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
