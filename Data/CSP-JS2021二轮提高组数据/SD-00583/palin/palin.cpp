#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define N 10001
using namespace std;

int T, v[N], n, a[N], flag, ans[N], tot;

void dfs(int hd, int tl,int dep)
{
	if(dep == 2 * n + 1){
		flag = 1;
		return;
	} 
	if(v[a[hd]] == 0 || v[a[hd]] == dep)
	{
		if(v[a[hd]] == 0) v[a[hd]] = 2 * n - dep + 1;
		dfs(hd + 1, tl, dep + 1);
		if(v[a[hd]] == 2 * n - dep + 1) v[a[hd]] = 0; 
		if(flag == 1) {	
			ans[++tot] = 0;
			return;
		}
	} 
	if(v[a[tl]] == 0 || v[a[tl]] == dep)
	{
		if(v[a[tl]] == 0) v[a[tl]] = 2 * n - dep + 1;
		dfs(hd, tl - 1, dep + 1);
		if(v[a[tl]] == 2 * n - dep + 1) v[a[tl]] = 0; 
		if(flag == 1){
			ans[++tot] = 1;
			return;
		} 
	}
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		memset(a, 0, sizeof(a));
		memset(ans, 0, sizeof(ans));
		memset(v, 0, sizeof(v));
		flag=0; tot = 0;
		scanf("%d", &n);
		if(n >= 30) {
			cout<<-1<<endl;
			continue;
		}
		for(int i = 1; i <= n * 2; i++)
			scanf("%d", &a[i]);
		dfs(1, n * 2, 1);
		if(flag) {
			for(int i = 2 * n; i >= 1; i--) {
				if(ans[i] == 0) cout<<"L";
				else cout<<"R";
			}
			cout<<endl;
		}
		else cout<<-1<<endl;
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
