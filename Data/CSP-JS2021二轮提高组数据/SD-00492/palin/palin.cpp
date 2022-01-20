#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 5e5 + 10;
int n, t, a[N], tot;
int f[N], b[N], fj;
char ans[N];

void dfs(int head, int tail){
	if(tot == n * 2){
		fj = 1;
		return;
	}
	if(fj == 0)
	if(f[a[head]] == 2){
		f[a[head]] --;
		tot ++;
		ans[tot] = 'L', b[tot] = a[head];
		dfs(head + 1, tail);
		tot --;
		f[a[head]] ++;
	}
	if(fj == 0)
	if(f[a[tail]] == 2){
		f[a[tail]] --;
		tot ++;
		ans[tot] = 'R', b[tot] = a[tail];
		dfs(head, tail - 1);
		tot --;
		f[a[tail]] ++;
	}
	if(fj == 0)
	if(f[a[head]] == 0 && f[a[tail]] == 0)
		return;
	if(fj == 0)
	if(f[a[head]] == 1 && f[a[tail]] != 2){
		if(a[head] == b[2 * n + 1 - tot - 1]){
			f[a[head]] --;
			tot ++;
			ans[tot] = 'L', b[tot] = a[head];
			dfs(head + 1, tail);
			tot --;
			f[a[head]] ++;
		}
	}
	if(fj == 0)
	if(f[a[tail]] == 1 && f[a[head]] != 2){
		if(a[tail] == b[2 * n + 1 - tot - 1]){
			f[a[tail]] --;
			tot ++;
			ans[tot] = 'R', b[tot] = a[tail];
			dfs(head, tail - 1);
			tot --;
			f[a[tail]] ++;
		}
	}
}


int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d", &t);
	for(int i = 1; i <= t; ++ i){
		scanf("%d", &n);
		for(int j = 1; j <= 2 * n; ++ j){
			scanf("%d", &a[j]);
			f[a[j]] ++;
		}
		dfs(1, n * 2);
		if(fj == 1){
			for(int j = 1;j <= n * 2; ++ j) cout << ans[j];
			cout << endl;
		}
		if(fj == 0) cout << -1 << endl;
		fj = 0; tot = 0;
		for(int i = 1; i <= 2 * n; ++ i){
			f[i] = 0; b[i] = 0; a[i] = 0;
		}
	}
	return 0;
}
