#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e6 + 5;

inline int readin() {
	int res = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
	return res;
}

int T, n, a[maxn], b[maxn]; bool flag;
char ans[maxn], t[maxn];

void dfs(int pos,int l, int r, int q) {
	if (pos > (n << 1)) {
		flag = false; bool isok = true;
		for (int i = 1; i <= (n << 1); ++i) {
			if (t[i] < ans[i]) break;
			if (t[i] > ans[i]) { isok = false; break; }
		}
		if (isok) for (int i = 1; i <= (n << 1); ++i) ans[i] = t[i];
	}
	if (a[l] == b[q]) t[pos] = 'L', dfs(pos + 1, l + 1, r, q + 1);
	if (a[r] == b[q]) t[pos] = 'R', dfs(pos + 1, l, r - 1, q + 1); 
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = readin();
	while (T--) {
		n = readin(); flag = true; memset(ans, 0x7f, sizeof(ans));
		for (int i = 1; i <= (n << 1); ++i) a[i] = readin();
		for (int i = 1; i <= n; ++i) b[i] = i;
		while (next_permutation(b + 1, b + 1 + n)) {
			for (int i = n + 1; i = (n << 1); ++i) b[i] = b[(n << 1) + 1 - i];
			dfs(1, 1, n << 1, 1);
		}
		if (flag) printf("-1\n");
		else {
			for (int i = 1; i <= (n << 1); ++i) printf("%c", ans[i]);
			putchar('\n');
		}
	}
	return 0;
}
