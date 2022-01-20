#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define inf 0x3f3f3f3f
#define maxn 1000001
#define ll long long

void read(int &x) {
	char F = getchar();
	int flag = 1; x = 0;
	while(F > '9' || F < '0') {
		if(F == '-') flag = -1;
		F = getchar();
	}
	while(F >= '0' && F <= '9') {
		x *= 10;
		x += F - '0';
		F = getchar();
	}
	x *= flag;
}


int n, m, tt, top = -1, flo[maxn], nex[maxn], fir[maxn], too[maxn], cup[maxn], S, T, Top, Fir[maxn];

void add(int u, int v, int w) {
	//printf("from %d to %d, cup = %d\n", u, v, w);
	top ++;
	flo[top] = 0;
	cup[top] = w;
	too[top] = v;
	nex[top] = fir[u];
	fir[u] = top;
}

int calc(int x, int y) {
	return (x - 1) * m + y;
}

int dep[maxn], q[maxn], h, t, cur[maxn];

bool bfs() {
	memset(dep, -1, sizeof dep);
	h = t = 1; dep[S] = 0; q[t] = S;
	while(h <= t) {
		int now = q[h ++];
		for(int i = fir[now]; ~ i; i = nex[i]) {
			if(cup[i] <= flo[i]) continue;
			int to = too[i];
			if(~ dep[to]) continue;
			dep[to] = dep[now] + 1;
			if(to == T) return 1;
			q[++ t] = to;
		}
	}
	return 0;
}

int dfs(int o, int maxflow) {
	if(o == T || ! maxflow) return maxflow;
	int res = 0;
	for(; ~ cur[o]; cur[o] = nex[cur[o]]) {
		int i = cur[o], to = too[i];
		if(cup[i] <= flo[i]) continue;
		if(dep[to] != dep[o] + 1) continue;
		int flow = dfs(to, min(maxflow, cup[i] - flo[i]));
		flo[i] += flow;
		flo[i ^ 1] -= flow;
		res += flow;
		maxflow -= flow;
		if(! maxflow) return res;
	}
	return res;
}

int dinic() {
	int res = 0;
	while(bfs()) {
		for(int i = S; i <= T; i ++) cur[i] = fir[i];
		res += dfs(S, inf);
		//printf("%d\n", res);
	}
	return res;
}

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	memset(fir, -1, sizeof fir);
	read(n); read(m); read(tt);
	S = 0, T = n * m + (n << 1) + (m << 1) + 1;
	for(int i = 1; i < n; i ++) for(int j = 1; j <= m; j ++) {
		int len; read(len);
		add(calc(i, j), calc(i + 1, j), len);
		add(calc(i + 1, j), calc(i, j), 0);
		add(calc(i + 1, j), calc(i, j), len);
		add(calc(i, j), calc(i + 1, j), 0); 
	}
	for(int i = 1; i <= n; i ++) for(int j = 1; j < m; j ++) {
		int len; read(len);
		add(calc(i, j), calc(i, j + 1), len);
		add(calc(i, j + 1), calc(i, j), 0);
		add(calc(i, j + 1), calc(i, j), len);
		add(calc(i, j), calc(i, j + 1), 0);
	}
	Top = top;
	for(int i = S; i <= T; i ++) Fir[i] = fir[i];
	while(tt --) {
		top = Top;
		for(int i = S; i <= T; i ++) fir[i] = Fir[i];
		int K; read(K);
		while(K --) {
			int x, len, col, poix, poiy;
			read(len); read(x); read(col);
			if(x >= 1 && x <= m) poix = x, poiy = 1;
			if(x > m && x <= m + n) poix = m, poiy = x - n;
			if(x > m + n && x <= (m << 1) + n) poiy = n, poix = ((m << 1) + n + 1) - x;
			if(x > (m << 1) + n && x <= (m << 1) + (n << 1)) poix = 1, poiy = (m << 1) + (n << 1) + 1 - x;
			add(calc(poiy, poix), x + n * m, len);
			add(x + n * m, calc(poiy, poix), 0);
			add(x + n * m, calc(poiy, poix), len);
			add(calc(poiy, poix), x + n * m, 0);
			if(! col) add(S, x + n * m, inf), add(x + n * m, S, 0);
			else add(x + n * m, T, inf), add(T, x + n * m, 0);
			//printf("%d %d\n", poiy, poix);
		}
		memset(flo, 0, sizeof flo);
		printf("%d\n", dinic());
	}
	return 0;
}
