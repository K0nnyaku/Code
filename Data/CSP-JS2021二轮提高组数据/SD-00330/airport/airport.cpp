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
const int N = 1e5 + 7;
int Max(const int &a, const int &b) { return a > b ? a : b; }
int n, m, mm;
struct jgt {
	int a, b;
	bool operator<(const jgt &x) const { return a < x.a; }
} now;
std::set<jgt> c, d;
typedef std::set<jgt>::iterator It;
int s[N], ss[N], res;
It p;
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m = read(), mm = read();
	for (int i = 1; i <= m; ++i) {
		int x = read(), y = read();
		c.insert((jgt){x, y});
	}
	for (int i = 1; i <= mm; ++i) {
		int x = read(), y = read();
		d.insert((jgt){x, y});
	}
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1];
		if (c.empty()) continue;
		p = c.begin();
		while (p != c.end()) {
			++s[i];
			now = *p;
			c.erase(p);
			now.a = now.b, now.b = 0;
			p = c.upper_bound(now);
		}
	}
	for (int i = 1; i <= n; ++i) {
		ss[i] = ss[i - 1];
		if (d.empty()) continue;
		p = d.begin();
		while (p != d.end()) {
			++ss[i];
			now = *p;
			d.erase(p);
			now.a = now.b, now.b = 0;
			p = d.upper_bound(now);
		}
	}
	for (int i = 0; i <= n; ++i) { res = Max(res, s[i] + ss[n - i]); }
	printf("%d\n", res);
	return 0;
}
