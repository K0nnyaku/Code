#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100;

int T, n, a[N], b[N], L, flag = 0;
char s[N];

void dfs(int step, int l, int r){
	if(flag == 1) return;
	if(step == L + 1){
		for(int i = 1; i <= n; ++i){
			if(b[i] != b[L + 1 - i]) return;
		}
		flag = 1;
		puts(s + 1);
		return;	
	}
	if(a[l] <= a[r]) {
		s[step] = 'L'; b[step] = a[l];
		dfs(step + 1, l + 1, r);
		s[step] = 'R'; b[step] = a[r];
		dfs(step + 1, l, r - 1);
	}
	else{
		s[step] = 'R'; b[step] = a[r];
		dfs(step + 1, l, r - 1);
		s[step] = 'L'; b[step] = a[l];
		dfs(step + 1, l + 1, r);
	}
}

int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		flag = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		scanf("%d", &n);
		L = 2 * n;
		for(int i = 1; i <= L; ++i) scanf("%d", &a[i]);
		dfs(1, 1, L);
		if(flag == 0) cout << -1 << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

