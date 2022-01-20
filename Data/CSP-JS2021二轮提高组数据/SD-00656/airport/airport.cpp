#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

typedef long long ll;
const int maxn = 1e5 + 9, inf = 2e9;
const ll INF = 1e18;

int read() {
	int x = 0, f = 0, ch = getchar();
	for (; !isdigit(ch); f = (ch == '-'), ch = getchar()) ;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar()) ;
	return f ? -x : x; 
}

void read(ll &x) {
	int f = 0, ch = getchar();
	for (; !isdigit(ch); f = (ch == '-'), ch = getchar()) ;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar()) ;
	x = f ? -x : x;
}

int n, m1, m2;

struct Node {
	int l, r;
} a[maxn], b[maxn];

int ansa[maxn], ansb[maxn];

std::set<int> s;
std::set<int>::iterator pos;
std::map<int, int> posa, posb;

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= m1; ++i)
		a[i].l = read(), a[i].r = read();
	for (int i = 1; i <= m2; ++i)
		b[i].l = read(), b[i].r = read();
	for (int i = 1; i <= m1; ++i)
		posa[a[i].l] = i; 
	for (int i = 1; i <= m2; ++i)
		posb[b[i].l] = i;
	int ans = 0, lef = 0;
	for (int i = 1; i <= m1; ++i) s.insert(a[i].l);
	for (int i = 1; i <= n; ++i) {
		lef = 0;
		while ((!s.empty()) && (pos = s.upper_bound(lef)) != s.end()) {
			++ans;
			lef = a[posa[*pos]].r;
			s.erase(pos);
		}
		ansa[i] = ans;
	}
	s.clear();
	for (int i = 1; i <= m2; ++i) s.insert(b[i].l);
	ans = 0, lef = 0;
	for (int i = 1; i <= n; ++i) {
		lef = 0;
		while ((!s.empty()) && (pos = s.upper_bound(lef)) != s.end()) {
			++ans;
			lef = b[posb[*pos]].r;
			s.erase(pos);
		}
		ansb[i] = ans;
	}
	ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = std::max(ans, ansa[i] + ansb[n - i]);
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
