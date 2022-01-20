#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 5e5 + 100;

int t, n, m;
int a[2 * N], b[2 * N];
char ans[2 * N];

bool dfs(int x) {
	if(x > m) {
		int l = 1, r = m, p = 0;
		for(int i = 1; i <= m; ++i) {
			if(ans[i] == 'L') {
				b[++p] = a[l++];
			}
			else {
				b[++p] = a[r--];
			}
		}
		for(int i = 1; i <= n; ++i) {
			if(b[i] != b[m - i + 1]) return false;
		}
		return true;
	}
	
	ans[x] = 'L';
	if(dfs(x + 1)) return true;
	ans[x] = 'R';
	if(dfs(x + 1)) return true;
	return false;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		m = 2 * n;
		for(int i = 1; i <= m; ++i)
			scanf("%d", &a[i]);
		
		if(dfs(1)) {
			printf("%s\n", ans + 1);
		}
		else printf("-1\n");
	}
	return 0;
}
