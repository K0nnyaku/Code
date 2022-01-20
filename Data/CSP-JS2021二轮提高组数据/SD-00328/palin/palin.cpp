#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define M 500001

typedef long long ll;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
inline void read(int &T) {
	int x = 0; bool f = 0; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = !f; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	T = f ? -x : x;
}

int t, n, a[M << 1], c[M << 1], sd[M << 1];

bool check() {
	int l = 1, r = 2 * n;
	for (int i = 1; i <= n * 2; ++i) {
		if (sd[i] == 0) c[i] = a[l++];
		else  c[i] = a[r--];
	}
	bool f = true;
	for (int i = 1; i <= n; ++i) {
		if (c[i] != c[2 * n - i + 1]) { f = false; break; }
	}
	return f;
}

bool dfs(int step) {
	if (step > 2 * n) {
		if (check()) return true;
		return false;
	}
	for (int i = 0; i <= 1; ++i) {
		sd[step] = i;
		if (dfs(step + 1)) return true;
		else continue;
	}
	return false;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(t);
	while (t--) {
		read(n);
		for (int i = 1; i <= 2 * n; ++i) read(a[i]);
		if (dfs(1)) {
			for (int i = 1; i <= 2 * n; ++i) printf(sd[i] ? "R" : "L");
			puts("");
		}else puts("-1");
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
