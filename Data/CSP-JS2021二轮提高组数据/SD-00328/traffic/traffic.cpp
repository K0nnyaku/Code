#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define M 648
#define inf 1061109567

typedef long long ll;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
inline void read(int &T) {
	int x = 0; bool f = 0; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = !f; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	T = f ? -x : x;
}

int n, m, t, k, ans, sd[M][M], disl[M][M], disc[M][M];
struct Node {
	int x, p, t;
}nd[M];

void check(int res) {
	for (int i = 1; i <= k; ++i) {
		if (nd[i].p >= 1 && nd[i].p <= m) {
			if (sd[1][nd[i].p] != nd[i].t) res += nd[i].x;
		}
		if (nd[i].p > m && nd[i].p <= m + n) {
			if (sd[nd[i].p - m][m] != nd[i].t) res += nd[i].x;
		}
		if (nd[i].p > m + n && nd[i].p <= 2 * m + n) {
			if (sd[n][m - (nd[i].p - m - n) + 1] != nd[i].t) res += nd[i].x;
		}
		if (nd[i].p > 2 * m + n && nd[i].p <= 2 * (m + n)) {
			if (sd[2 * (m + n) - nd[i].p + 1][1] != nd[i].t) res += nd[i].x;
		}
	}
	ans = min(ans, res);
}

void dfs(int h, int l, int res) {
	if (res > ans) return;
	if (h > n) { check(res); return; }
	for (int i = 0, x; i <= 1; ++i) {
		sd[h][l] = i, x = res;
		if (l > 1 && sd[h][l] != sd[h][l - 1]) x += disl[h][l - 1];
		if (h > 1 && sd[h][l] != sd[h - 1][l]) x += disc[h - 1][l];
		if (l != m)  dfs(h, l + 1, x);
		else dfs(h + 1, 1, x);
	}
}

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	read(n), read(m), read(t);
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			read(disc[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			read(disl[i][j]);
		}
	}
	while (t--) {
		read(k), ans = inf;
		for (int i = 1; i <= k; ++i) {
			read(nd[i].x), read(nd[i].p), read(nd[i].t);
		}
		dfs(1, 1, 0); printf("%d\n", ans); 
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
