#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int t;
int n;
int a[2010];
int ps[2010];
bool ans[2010];
bool flag;
void dfs(int x, int h, int t){
	if(x > 2 * n){
		for(int i = 1; i <= 2 * n; i++)
			putchar(ans[i] ? 'R' : 'L');
		puts("");
		flag = 1;
		return;
	}
	if(x <= n){
		if(!ps[a[h]]){
			ps[a[h]] = x;
//			h++;
			ans[x] = 0;
			dfs(x + 1, h + 1, t);
			ps[a[h]] = 0;
			if(flag)
				return;
		}
		if(!ps[a[t]]){
			ps[a[t]] = x;
			ans[x] = 1;
			dfs(x + 1, h, t - 1);
			ps[a[t]] = 0;
			if(flag)
				return;
		}
	}
	else{
//		puts("QWQ");
//		for(int i = 1; i <= n; i++)
//			cout << ps[i]<<" ";
//		puts("");
//		for(int i = 1; i < x; i++)
//			putchar(ans[i] ? 'R' : 'L');
//		puts("");
//		cout << ps[a[h]]<<" "<<ps[a[t]] <<" "<<2 * n - x + 1<<"\n";
		if(ps[a[h]] == 2 * n - x + 1){
			ans[x] = 0;
			dfs(x + 1, h + 1, t);
			if(flag)
				return;
		}
		if(ps[a[t]] == 2 * n - x + 1){
			ans[x] = 1;
			dfs(x + 1, h, t - 1);
			if(flag)
				return;
		}
	}
}
signed main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		memset(ps, 0, sizeof(ps));
		scanf("%d", &n);
		flag = 0;
		for(int i = 1; i <= 2 * n; i++)
			scanf("%d", &a[i]);
		dfs(1, 1, n * 2);
		if(!flag)
			puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
