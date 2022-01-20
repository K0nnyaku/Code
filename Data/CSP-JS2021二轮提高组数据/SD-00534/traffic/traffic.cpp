#include <bits/stdc++.h>

const int N = 505 * 505, M = 2e6 + 50, K = 505;

int head[N], cur[N], ver[M], nxt[M], d[N], cnt = 1;
int n, m, q, s, t, x1[K][K], x2[K][K];
long long edge[M], aaaedge[M], maxflow, aaamaxflow;
int aaahead[N], aaaver[M], aaanxt[M], aaacnt;

inline void add(int u, int v, int w, int W = 0) {
	nxt[++cnt] = head[u], ver[cnt] = v, edge[cnt] = w, head[u] = cnt;
	nxt[++cnt] = head[v], ver[cnt] = u, edge[cnt] = W, head[v] = cnt;	
}

inline bool bfs(int s) {
	memcpy(cur, head, sizeof head);	
	memset(d, 0, sizeof d);
	std::queue<int> que;
	que.emplace(s);
	d[s] = 1;
	while (!que.empty()) {
		int x = que.front(); que.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i], w = edge[i];
			if (w && !d[y]) {
				d[y] = d[x] + 1;
				if (y == t) return true;
				que.emplace(y);
			}
		}
	}
	return false;
}

long long dinic(int x, long long flow = 1e18) {
	if (x == t) return flow;
	long long rest = flow;
	for (int &i = cur[x]; i; i = nxt[i])
		if (edge[i] && d[ver[i]] == d[x] + 1) {
			int k = dinic(ver[i], std::min(edge[i], rest));
			edge[i] -= k, rest -= k, edge[i ^ 1] += k;
			if (!k) d[ver[i]] = 0;
			if (!rest) break;	
		}
	return flow - rest;	
}

void update() {
	long long flow;
	while (bfs(s))
		while (flow = dinic(s))
			maxflow += flow;	
}

template <int T>
struct fast_io {
	char p[T], *p1, *p2, q[T], *q1, *q2;
	fast_io() {
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}
	inline char gc() {
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char ch) {
		if (q1 == q2) {
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = ch;
	}
	~fast_io() {
		fwrite(q, 1, q1 - q, stdout);
	}
};

fast_io<1024768> io;

inline long long read() {
	long long r = 0, neg = 1;
	char ch;
	do {
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

void write(long long x) {
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	io.pc(48 + x % 10);
}

inline void output(long long x, char ch = ' ') {
	write(x);
	io.pc(ch);
}

const int inf = 1e8;
int num, x3[N], p[N], tt[N];

inline int id(int i, int j) {
	assert(1 <= i && i <= n);
	assert(1 <= j && j <= m);
	return (i - 1) * m + j;	
}

void build_graph() {
	memset(head, 0, sizeof head);
	cnt = 1;
	for (int i = 1; i <= n * m; ++i) {
		add(s, i, inf);
		add(i, t, inf);	
	}
	for (int i = 1; i < n; ++i)
		for (int j = 1; j <= m; ++j)
			add(id(i, j), id(i + 1, j), x1[i][j], x1[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m; ++j)
			add(id(i, j), id(i, j + 1), x2[i][j], x2[i][j]);
}

void save_graph() {
	aaacnt = cnt;
	aaamaxflow = maxflow;
	memcpy(aaahead, head, sizeof head);
	memcpy(aaanxt, nxt, sizeof nxt);
	memcpy(aaaedge, edge, sizeof edge);
	memcpy(aaaver, ver, sizeof ver);	
}

void load_graph() {
	cnt = aaacnt;
	maxflow = aaamaxflow;
	memcpy(head, aaahead, sizeof aaahead);	
	memcpy(nxt, aaanxt, sizeof aaanxt);
	memcpy(edge, aaaedge, sizeof aaaedge);
	memcpy(ver, aaaver, sizeof aaaver);
}

void expand_graph() {
	for (int i = 1; i <= num; ++i) {
		int w = x3[i], yid = p[i], col = tt[i], o = -1;
		if (1 <= yid && yid <= m) {
			o = id(1, yid);	
		}
		else if (m + 1 <= yid && yid <= m + n) {
			o = id(yid - m, m);
		}
		else if (n + m + 1 <= yid && yid <= m + m + n) {
			o = id(n, m - (yid - n - m) + 1);	
		}
		else if (m + m + n + 1 <= yid && yid <= m + m + n + n) {
			o = id(n - (yid - m - m - n) + 1, 1);
		}
		else throw;
		if (col) add(s, o, w);
		else add(o, t, w);
	}
}

long long solve() {	
	load_graph();
	expand_graph();
	long long flow, dummy = 1ll * n * m * inf;
	while (bfs(s))
		while (flow = dinic(s))
			maxflow += flow;
	return maxflow - dummy;	
}

struct Qingyu_Timer
{
	int _;
	Qingyu_Timer() { _ = clock(); }
	~Qingyu_Timer() {
		fprintf(stderr, "Time used = %.6f seconds", (clock() - _) * 1.0 / CLOCKS_PER_SEC);	
	}
} qwqwqwq;

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	n = read(), m = read(), q = read();
	s = n * m + 1, t = s + 1;
	for (int i = 1; i < n; ++i)
		for (int j = 1; j <= m; ++j)
			x1[i][j] = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m; ++j)
			x2[i][j] = read();
	build_graph();
	update();
	save_graph();
	while (q--) {
		num = read();
		for (int i = 1; i <= num; ++i) {
			x3[i] = read(), p[i] = read(), tt[i] = read();	
		}
		output(solve(), '\n');
	}
	return 0;
}
