#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,k,a[N];
set<int>s[N];
int ans=2147483640;
void dfs(int layer)
{
	if(layer>n) 
	{
		int x=0;
		for(int i=1;i<=k;i++) x=x+abs(*(--s[i].end())-*(s[i].begin()));
		ans=min(ans,x);
		return;
	}
	for(int i=1;i<=k;i++)
	{
		if(s[i].size()>=n/k || s[i].count(a[layer])) continue;
		s[i].insert(a[layer]);
//		printf("%d just inserted %d\n",i,a[layer]);
		dfs(layer+1);
		s[i].erase(a[layer]);
//		printf("%d erased %d\n",i,a[layer]);
	}
}
signed main()
{
	clock_t c1=clock();
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);

	//======================================
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d",ans);
	//======================================
	cerr<<endl<<"Time:"<<clock()-c1<<"(ms)"<<endl;
	return 0;
}
/*
16 8
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/