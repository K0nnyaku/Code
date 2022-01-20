#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
#define ll long long
#define P pair <int, int>
#define F first
#define S second
inline int read() {
	int x = 0, W = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') W = -W;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * W;
}
struct node {
	int l, r;
}a[N], b[N];
bool cmp(node x, node y) {
	return x.l < y.l;
}
int n, m1, m2, orz[N];
int get1(int cnt) {
	int res = 0;
	memset(orz, 0, sizeof(orz));
	for (int i = 1; i <= m1; i++) {
		int now = a[i].l;
		for (int j = 1; j <= cnt; j++)
			if (now >= orz[j]) {
				orz[j] = a[i].r;
				res++;
				break;
			}
	}
	return res;
}
int get2(int cnt) {
	int res = 0;
	memset(orz, 0, sizeof(orz));
	for (int i = 1; i <= m2; i++) {
		int now = b[i].l;
		for (int j = 1; j <= cnt; j++)
			if (now >= orz[j]) {
				orz[j] = b[i].r;
				res++;
				break;
			}
	}
	return res;
}
signed main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= m1; i++) a[i].l = read(), a[i].r = read();
	for (int i = 1; i <= m2; i++) b[i].l = read(), b[i].r = read();
	sort(a + 1, a + m1 + 1, cmp);
	sort(b + 1, b + m2 + 1, cmp);
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int cur = get1(i) + get2(n - i);
		ans = max(ans, cur);
	}
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
