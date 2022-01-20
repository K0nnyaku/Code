#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 500 + 10;
const int K = 50 + 10;

int n, m, t, k, nb, eb;

struct E {
	int u, v, w;
	
	E() {}
	E(int tu, int tv, int tw) : u(tu), v(tv), w(tw) {}
	bool operator < (const E b) const {
		return w < b.w;
	}
};
inline int plc(int x, int y) {	// num of point
	return (x - 1) * m + y;
}
inline int ert(int x, int y) {	// num of point's right edge
	return plc(x, y) * 2 - 1;
}
inline int ert(int x) {	// num of point's right edge
	return x * 2 - 1;
}
inline int edn(int x, int y) {	// num of point's down edge
	return plc(x, y) * 2;
}
inline int edn(int x) {	// num of point's down edge
	return x * 2;
}
inline int elt(int x) {	// num of point's left edge
	return 2 * x - 3;	// (x - 1) * 2 - 1
}
inline int eup(int x) {	// num of point's up edge
	return (x - m) * 2;
}
inline int enm(E x) {	// num of edge
	if(x.u > x.v) swap(x.u, x.v);
	if(x.v > nb) return eb + x.v - nb;
	if(x.u + 1 == x.v) return ert(x.u);
	return edn(x.u);
//	return eb + x - nb;
}
inline int l2p(int x) {
	if(x <= m) return x;
	if(x <= m + n) return (x - m) * m;
	if(x <= 2 * m + n) return n * m + m + n + 1 - x;
	return 2 * n * m + 2 * m * m - m * x + 1;
}
int v[2 * N * N + K];
int co[N * N + K];

priority_queue<E> q;

bool dld[2 * N * N + K];

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &t);
	nb = n * m;
	eb = nb * 2;
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j <= m; ++j) {
			int w;
			scanf("%d", &w);
			v[edn(i, j)] = w;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < m; ++j) {
			int w;
			scanf("%d", &w);
			v[ert(i, j)] = w;
		}
	}
	
	while(t--) {
		scanf("%d", &k);
		memset(dld, 0, sizeof dld);
		memset(co, 0, sizeof co);
		for(int i = 1; i <= k; ++i) {
			int x, p, c;
			scanf("%d%d%d", &x, &p, &c);
			co[nb + i] = c + 1;
			q.push(E(nb + i, l2p(p), x));
		}
		
		LL ans = 0;
		while(!q.empty()) {
			E nw = q.top();
			q.pop();
			if(dld[enm(nw)]) continue;
			dld[enm(nw)] = true;
			
			if(co[nw.v]) swap(nw.u, nw.v);
			if(co[nw.v]) {
				if(co[nw.u] != co[nw.v])
					ans += nw.w;
			}
			else {
				co[nw.v] = co[nw.u];
				if(nw.v - m > 0 && !dld[eup(nw.v)])
					q.push(E(nw.v, nw.v - m, v[eup(nw.v)]));
				if(nw.v + m <= nb && !dld[edn(nw.v)])
					q.push(E(nw.v, nw.v + m, v[edn(nw.v)]));
				if((nw.v - 1) % m != 0 && !dld[elt(nw.v)])
					q.push(E(nw.v, nw.v - 1, v[elt(nw.v)]));
				if(nw.v % m != 0 && !dld[ert(nw.v)])
					q.push(E(nw.v, nw.v + 1, v[ert(nw.v)]));
			}
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}




/*#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 500 + 10;
const int K = 50 + 10;

int n, m, t, k;

struct EDGE {
	int v, w, nt;
	bool ad;
} e[2 * 2 * N * N + 2 * K];
int lt[N * N], ep;
inline void AE(int u, int v, int w) {
	++ep;
	e[ep].v = v;
	e[ep].w = w;
	e[ep].nt = lt[u];
	lt[u] = ep;
}
inline int plc(int x, int y) {
	return (x - 1) * m + y;
}

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d%d%d", &n, &m &t);
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j <= m; ++j) {
			int w;
			scanf("%d", &w);
			AE(plc(i, j), plc(i + 1, j), w);
			AE(plc(i + 1, j), plc(i, j) ,w);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < m; ++j) {
			int w;
			scanf("%d", &w);
			AE(plc(i, j), plc(i, j + 1), w);
			AE(plc(i, j + 1), plc(i, j), w);
		}
	}
	
	while(t--) {
		int oldep = ep;
		scanf("%d", &k);
		for(int i = 1; i <= k; ++i) {
			int x, p, c;
			scanf("%d%d%d", &x, &p, &c);
		}
		
		ep = oldep;
	}
	return 0;
}*/
