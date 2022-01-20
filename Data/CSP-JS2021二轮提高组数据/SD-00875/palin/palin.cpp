#include <stdio.h>

int T, buck[500005], n, stk[500005], head, a[1000005], instk[500005], ss[500005];
char str[1000005];

inline int read() {
	char ch = getchar();
	int n = 0;
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') n = n * 10 + (ch ^ '0'), ch = getchar();
	return n;
}

void solve() {
	n = read(); int m = n << 1;
	for (int i = 1; i <= m; ++i) a[i] = read();
	int l = n, r = m + 1;
	int c[3] = { 0, 0, 0 };
	for (int i = 1; i <= n; ++i) ++buck[a[i]];
	for (int i = 1; i <= n; ++i) ++c[buck[i]];
	for (; l >= 0; --l, --r) {
		if (c[1] == n) break;
		--c[buck[a[l]]];
		--buck[a[l]];
		++c[buck[a[l]]];
		--c[buck[a[r - 1]]];
		++buck[a[r - 1]];
		++c[buck[a[r - 1]]];
	}
	for (int i = 1; i <= n; ++i) instk[i] = 0;
	if (l == -1) { printf("-1\n"); return; }
	head = 0;
	int i = l + 1, j = 1, k = m, len = 0;
	while (j <= l && k >= r) {
		if (!instk[a[j]]) {
			while (i < r && a[i] != a[j]) {
				stk[++head] = a[i];
				++i;
				instk[a[i]] = 1;
			}
			++i;
			str[++len] = 'L';
			++j;
		} else {
			if (stk[head] != a[j] && stk[head] != a[k]) { printf("-1"); return; }
			if (stk[head] == a[j]) str[++len] = 'L', ++j; else str[++len] = 'R', --k;
			instk[stk[head]] = 0; --head;
		}
	}
	while (j <= l) {
		if (!instk[a[j]]) {
			while (i < r && a[i] != a[j]) {
				stk[++head] = a[i];
				++i;
				instk[a[i]] = 1;
			}
			++i;
			str[++len] = 'L';
			++j;
		} else {
			if (stk[head] != a[j]) { printf("-1"); return; }
			str[++len] = 'L'; ++j;
			instk[stk[head]] = 0; --head;
		}
	}
	while (k >= r) {
		if (!instk[a[k]]) {
			while (i < r && a[i] != a[k]) {
				stk[++head] = a[i];
				++i;
				instk[a[i]] = 1;
			}
			++i;
			str[++len] = 'R';
			--k;
		} else {
			if (stk[head] != a[k]) { printf("-1"); return; }
			str[++len] = 'R'; --k;
			instk[stk[head]] = 0; --head;
		}
	}
	printf("%s", str + 1);
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = read();
	for (; T; --T) solve();
	return 0;
}
