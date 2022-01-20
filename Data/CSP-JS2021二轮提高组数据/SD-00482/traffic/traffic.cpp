#include <cstdio>
#include <queue>
#include <cstring>

typedef long long LL;

const int Maxn = 5e2 + 5;

const int N = Maxn * Maxn + 4 * Maxn;
const int M = N * 8;
const LL Inf = 1e15;

int n, m, T;

int fy(int x, int y) {
	return (x - 1) * m + y;
}
int lnk(int x) {
	if(1 <= x && x <= m) return fy(1, x);
	if(m < x && x <= m + n) return fy(x - m, m);
	if(m + n < x && x <= 2 * m + n) return fy(n, m - (x - m - n) + 1);
	if(x > 2 * m + n) return fy(n + 1 - (x - 2 * m - n), 1);
}

int ver[M], nxt[M], hd[N], cur[N], ecnt = 1; LL cap[M], ncap[M];
void add(int u, int v, LL w) {
	ecnt++; ver[ecnt] = v; nxt[ecnt] = hd[u]; ncap[ecnt] = w; hd[u] = ecnt;
}
void addedge(int u, int v, LL w) {
	add(u, v, w); add(v, u, 0);
}

int s, t, d[N];

bool bfs() {
	memset(d, 0, sizeof d);
	std::queue<int> q; q.push(s); d[s] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = hd[u]; i; i = nxt[i]) {
			int v = ver[i];
			if(d[v] || cap[i] == 0) continue;
			d[v] = d[u] + 1; q.push(v);
		}
	}
	return d[t] != 0;
}

LL dfs(int u, LL fl) {
	if(u == t) return fl;
	LL rst = fl, k;
	for(int &i = cur[u]; i && rst; i = nxt[i]) {
		int v = ver[i];
		if(d[v] != d[u] + 1 || cap[i] == 0) continue;
		k = dfs(v, std::min(fl, cap[i]));
		if(!k) d[v] = 0;
		rst -= k, cap[i] -= k, cap[i ^ 1] += k;
		if(!rst) break;
	}
	return fl - rst;
}

LL dinic() {
	LL res = 0, fl = 0;
	while(bfs()) {
		memcpy(cur, hd, sizeof cur);
		while(res = dfs(s, Inf)) fl += res;
	}
	return fl;
}

int x, y; LL z; int q;

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &T);
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%lld", &z); x = i, y = j;
			addedge(fy(x, y), fy(x + 1, y), z);
			addedge(fy(x + 1, y), fy(x, y), z);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < m; ++j) {
			scanf("%lld", &z); x = i, y = j;
			addedge(fy(x, y), fy(x, y + 1), z);
			addedge(fy(x, y + 1), fy(x, y), z);
		}
	}
	while(T--) {
		scanf("%d", &q); int X, Y; LL Z;
		scanf("%lld%d%d%lld%d%d", &z, &x, &y, &Z, &X, &Y);
		if(y == Y) {
			printf("0\n");
			continue;
		}
		//printf("%d %d!\n", lnk(x), lnk(X));
		addedge(s = n * m + x, lnk(x), z);
		addedge(lnk(X), t = n * m + X, Z);
		memcpy(cap, ncap, sizeof cap);
		printf("%lld\n", dinic());
		ncap[ecnt - 3] = ncap[ecnt - 2] = ncap[ecnt - 1] = ncap[ecnt] = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
2 3 2
9 4 7
3 8
10 5
2
19 3 1
17 9 0
2
19 3 1
17 9 0
*/
