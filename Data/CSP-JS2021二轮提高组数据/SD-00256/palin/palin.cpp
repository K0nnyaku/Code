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
const int N=5e5+5;
int T,n,a[2*N],ans[2*N],flag;
std::vector<char> op;
il int check1 () {
	for (int i=1;i<=n;i++) {
		if (a[i]!=a[2*n-i+1]) return 0;
	}
	return 1;
}
il int check2 () {
	for (int i=1;i<=n;i++) {
		if (ans[i]!=ans[2*n-i+1]) return 0;
	}
	return 1;
}
void dfs (int l,int r,int step) {
	if (flag) return ;
	if (step==2*n+1) {
		if (check2()) {
			for (int i=0;i<(int)op.size();i++) putchar(op[i]);
			puts("");
			flag=1;
		}
		return ;
	}
	ans[step]=a[l];
	op.push_back('L');
	dfs(l+1,r,step+1);
	op.pop_back();
	ans[step]=a[r];
	op.push_back('R');
	dfs(l,r-1,step+1);
	ans[step]=0;
	op.pop_back();
	return ;
}
int main () {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		std::memset(a,0,sizeof(a));
		std::memset(ans,0,sizeof(ans));
		op.clear();
		flag=0;
		for (int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		if (check1()) {
			for (int i=1;i<=2*n;i++) putchar('L');
			flag=1;
			continue;
		}
		dfs(1,2*n,1);
		if (!flag) puts("-1"); 
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
