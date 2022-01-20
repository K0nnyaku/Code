#include <bits/stdc++.h>
using namespace std;
#define N 114514
#define ll long long
int n, m, T, d, cnt = 0, num;
ll ans = (ll)pow(2, 60);
int col[510][510];
struct node {
	int wz1x, wz1y, wz2x, wz2y, dis;
} e[N];
int q_read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
	return x;
}
void work() {
	ll abc = 0;
	for (int i = 1; i <= num; ++i) {
		if (col[e[i].wz1x][e[i].wz1y] != col[e[i].wz2x][e[i].wz2y]) {
			abc += (ll)e[i].dis;
		}
	}
	ans = min(ans, abc);
	return ;
}
void dfs(int x, int y) {
	if (x > n) {
		work();
		return ;
	}
	for (int i = 0; i <= 1; ++i) {
		col[x][y] = i;
		if (y == m) {
			dfs(x + 1, 1);
		} else {
			dfs(x, y + 1);
		}
	}
	return ;
}
int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	n = q_read() ; m = q_read(); T = q_read();
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			d = q_read();
			e[++cnt].dis = d;
			e[cnt].wz1x = i;
			e[cnt].wz1y = j;
			e[cnt].wz2x = i + 1;
			e[cnt].wz2y = j;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			d = q_read();
			e[++cnt].dis = d;
			e[cnt].wz1x = i;
			e[cnt].wz1y = j;
			e[cnt].wz2x = i;
			e[cnt].wz2y = j + 1;
		}
	}
	while (T--) {
		num = cnt;
		int p, xx, yy, tox, toy;
		int k = q_read();
		for (int i = 1; i <= k; ++i) {
			e[++num].dis = q_read();
			p = q_read();
			if (p <= m) {
				xx = 0;
				yy = p;
				tox = 1;
				toy = p;
			} else if (p <= m + n) {
				xx = p - m;
				yy = m + 1;
				tox = p - m;
				toy = m;
			} else if (p <= 2 * m + n) {
				xx = n + 1;
				yy = (2 * m + n - p + 1);
				tox = n;
				toy = (2 * m + n - p + 1);
			} else {
				xx = (2 * m + 2 * n - p + 1);
				yy = 0;
				tox = (2 * m + 2 * n - p + 1);
				toy = 1;
			}
			e[num].wz1x = xx;
			e[num].wz1y = yy;
			e[num].wz2x = tox;
			e[num].wz2y = toy;
			col[xx][yy] = q_read();
		}
		dfs(1, 1);
		cout << ans << endl;
	}
	return 0;
}
