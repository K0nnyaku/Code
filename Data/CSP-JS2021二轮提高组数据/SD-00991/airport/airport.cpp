#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100005;

struct Node {
	int l, r, tag;
} a1[maxn], a2[maxn], b1[maxn], b2[maxn];

inline int readin() {
	int res = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
	return res;
}

int n, ma, mb, ans;
int p[3][maxn]; bool vis[3][maxn];
int a[maxn], b[maxn], ta, tb;

inline bool cmp1(Node x, Node y) { return x.l < y.l; }
inline bool cmp2(Node x, Node y) { return x.r < y.r; }

inline int bsa(int x) {
	int l = 1, r = ma;
	if (a1[r].l < x) return 0x3f3f3f3f;
	while (l < r) {
		int mid = l + r >> 1;
		if (a1[mid].l < x) l = mid + 1;
		else r = mid;
	}
	return l;
}
inline int bsb(int x) {
	int l = 1, r = mb;
	if (b1[r].l < x) return 0x3f3f3f3f;
	while (l < r) {
		int mid = l + r >> 1;
		if (b1[mid].l < x) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = readin(), ma = readin(), mb = readin();
	for (int i = 1; i <= ma; ++i) a1[i].l = readin(), a1[i].r = readin(), a1[i].tag = i, a2[i] = a1[i];
	for (int i = 1; i <= mb; ++i) b1[i].l = readin(), b1[i].r = readin(), b1[i].tag = i, b2[i] = b1[i];
	sort(a1 + 1, a1 + 1 + ma, cmp1);
	sort(b1 + 1, b1 + 1 + mb, cmp1);
	sort(a2 + 1, a2 + 1 + ma, cmp2);
	sort(b2 + 1, b2 + 1 + mb, cmp2);
	for (int i = 1; i <= ma; ++i) {
		if (vis[1][a2[i].tag]) continue;
		int pos = bsa(a2[i].r); int t = pos;
		if (pos <= ma) vis[1][a1[pos].tag] = true, p[1][a2[i].tag] = a1[pos].tag, pos = bsa(a1[pos].r);
		while (pos <= ma) {
			vis[1][a1[pos].tag] = true;
			p[1][a1[t].tag] = a1[pos].tag;
			pos = bsa(a1[pos].r);
		}
	}
	for (int i = 1; i <= mb; ++i) {
		if (vis[2][b2[i].tag]) continue;
		int pos = bsb(b2[i].r); int t = pos;
		if (pos <= mb) vis[2][b1[pos].tag] = true, p[2][b2[i].tag] = b1[pos].tag, pos = bsb(b1[pos].r);
		while (pos <= mb) {
			vis[2][b1[pos].tag] = true;
			p[2][b1[t].tag] = b1[pos].tag;
			pos = bsb(b1[pos].r);
		}
	}
	for (int i = 1; i <= ma; ++i) {
		if (vis[1][i]) continue;
		a[++ta] = 1; int t = i;
		while (p[1][t] != 0) ++a[ta], t = p[1][t];
	}
	for (int i = 1; i <= mb; ++i) {
		if (vis[2][i]) continue;
		b[++tb] = 1; int t = i;
		while (p[2][t] != 0) ++b[tb], t = p[2][t];
	}
	for (int i = 1; i <= n; ++i) a[i] += a[i - 1], b[i] += b[i - 1];
	for (int i = 0; i <= n; ++i) ans = max(ans, a[i] + b[n - i]);
	printf("%d", ans);
	return 0;
}
