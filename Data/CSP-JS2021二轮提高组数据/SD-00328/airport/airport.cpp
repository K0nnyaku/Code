#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define M 114514

typedef long long ll;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
inline void read(int &T) {
	int x = 0; bool f = 0; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = !f; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	T = f ? -x : x;
}

bool vis[M];
int n, m1, m2, ans = 0, c[M], f[M], g[M];
struct flt {
	int s, t;
	friend bool operator < (flt f1, flt f2) {
		return f1.t < f2.t;
	}
	friend bool operator > (flt f1, flt f2) {
		return f1.t > f2.t;
	}
}a[M], b[M];

bool cmp(flt f1, flt f2) {
	return f1.s < f2.s;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(m1), read(m2);
	for (int i = 1; i <= m1; ++i) {
		read(a[i].s), read(a[i].t);
		b[i].s = a[i].s, b[i].t = a[i].t;
	}
	int sp = min(n, m1);
	std::sort(a + 1, a + m1 + 1, cmp);
	std::sort(b + 1, b + m1 + 1);
	for (int i = 1; i <= m1; ++i) c[i] = a[i].s;
	for (int i = 0; i <= sp; ++i) {
		memset(vis, 0, sizeof vis);
		std::priority_queue<flt, std::vector<flt>, std::greater<flt> > q;
		for (int j = 1; j <= i; ++j) { vis[j] = true; q.push(a[j]); }
		while (!q.empty()) {
			flt u = q.top(); q.pop(); ++f[i];
			int p = std::upper_bound(c + 1, c + m1 + 1, u.t) - c;
			if (p > m1) continue;
			while (vis[p]) {
				p = std::upper_bound(c + 1, c + m1 + 1, a[p].s) - c;
				if (p > m1) break;
			}
			if (p > m1) continue;
			vis[p] = true; q.push(a[p]);
		}
		if (f[i] == m1) {
			for (int j = i; j <= m1; ++j) f[j] = m1;
			break;
		}
	}
	for (int i = 1; i <= m2; ++i) {
		read(a[i].s), read(a[i].t);
		b[i].s = a[i].s, b[i].t = a[i].t;
	}
	sp = min(n, m2);
	std::sort(a + 1, a + m2 + 1, cmp);
	std::sort(b + 1, b + m2 + 1);
	for (int i = 1; i <= m2; ++i) c[i] = a[i].s;
	for (int i = 0; i <= sp; ++i) {
		memset(vis, 0, sizeof vis);
		std::priority_queue<flt, std::vector<flt>, std::greater<flt> > q;
		for (int j = 1; j <= i; ++j) { vis[j] = true; q.push(a[j]); }
		while (!q.empty()) {
			flt u = q.top(); q.pop(); ++g[i];
			int p = std::upper_bound(c + 1, c + m2 + 1, u.t) - c;
			if (p > m2) continue;
			while (vis[p]) {
				p = std::upper_bound(c + 1, c + m2 + 1, a[p].s) - c;
				if (p > m2) break;
			}
			if (p > m2) continue;
			vis[p] = true; q.push(a[p]);
		}
		if (g[i] == m2) {
			for (int j = i + 1; j <= m2; ++j) g[j] = m2;
			break;
		}
	}
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, f[i] + g[n - i]);
	}
	std::cout << ans << '\n';
	fclose(stdin), fclose(stdout);
	return 0;
}
