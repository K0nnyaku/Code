#include <bits/stdc++.h>
typedef long long ll;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x) {
	if (x > 9) write(x / 10);
	putchar('0' ^ (x % 10));
}
const int N = 1e6 + 7;
int T, n;
int a[N], b[N];
int c[N][2], qq[N];
bool get(int x) {
	return c[a[x]][0] == x ? 0 : 1;
}
int ot(int x) {
	return c[a[x]][get(x) ^ 1];
}
bool chk(int x) {
	if (b[x]) return 0;
	return b[ot(x) - 1] > 0 || b[ot(x) + 1] > 0;
}
void print() {
	int l = 1, r = n * 2, now = 1;
	while (l <= r) {
		if (b[l] == now) {
			printf("L");
			++l;
		}
		else {
			printf("R");
			--r;
		}
		++now;
	}
	putchar('\n');
}
bool check(int opt) {
	int now = 1;
	int l = 1, r = n * 2;
	if (opt == 1) {
		b[1] = now;
		b[ot(1)] = n * 2 - now + 1;
		++l;
		if (b[l]) ++l;
	} else {
		b[2 * n] = now;
		b[ot(2 * n)] = n * 2 - now + 1;
		--r;
		if (b[r]) --r;
	}
	++now;
	bool fl = 1;
	for (; now <= n; ++now) {
		while (b[l] > 0 && b[l] < now) ++l;
		while (b[r] > 0 && b[r] < now) --r;
		if (chk(l)) {
			b[l] = now;
			b[ot(l)] = 2 * n - now + 1;
		} else if (chk(r)) {
			b[r] = now;
			b[ot(r)] = 2 * n - now + 1;
		} else {
			fl = 0;
			break;
		}
	}
	if (fl) print();
	for (int i = 1; i <= 2 * n; ++i) b[i] = 0;
	return fl;
}
int C[N];
void solve() {
	bool fl = 0;
	for (int i = 0; i < (1 << n); ++i) {
		int l = 1, r = 2 * n, now = 0;
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				C[++now] = a[l];
				b[l] = now;
				C[2 * n - now] = a[ot(l)];
				b[ot(l)] = 2 * n - now + 1;
				++l;
			} else {
				C[++now] = a[r];
				a[r] = now;
				C[2 * n - now] = a[ot(r)];
				a[ot(r)] = 2 * n - now + 1;
				--r;
			}
		}
		bool qwq = 1;
		for (int i = 1; i <= n; ++i) {
			if (C[i] != C[2 * n - i + 1]) {
				qwq = 0;
				break;
			}
		}
		if (qwq) {
			print();
			fl = 1;
			break;
		}
	}
	if (!fl) printf("-1\n");
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; ++i) qq[i] = 0;
		for (int i = 1; i <= n * 2; ++i) {
			a[i] = read();
			c[a[i]][qq[a[i]]++] = i;
		}
//		if (n <= 10) {
//			solve();
//			continue;
//		}
		if (check(1)) {
			continue;
		}
		if (check(2)) {
			continue;
		}
		printf("-1\n");
	}
	return 0;
}
