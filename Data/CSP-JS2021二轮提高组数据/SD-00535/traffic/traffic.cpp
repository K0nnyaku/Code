#include<cstdio>
#include<cstring>
#define pt putchar(' ')
#define pn putchar('\n')

const int A = 1e4 + 7;
const int B = 1e5 + 7;
const int C = 1e6 + 7;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

void File() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
}
void REFile() {fclose(stdin); fclose(stdout);}

template <typename T> T Pow(T x) {return x * x;}
template <typename T> T Abs(T x) {return x < 0 ? -x : x;}
template <typename T> T Min(T x, T y) {return x < y ? x : y;}
template <typename T> T Max(T x, T y) {return x > y ? x : y;}
template <typename T> void Swap(T&x, T&y) {x ^= y ^= x ^= y;}

int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + (ch ^ 48); ch = getchar();}
	return x * f;
}
void Print(int x) {if(x < 0) x = -x, putchar('-'); if(x > 9) Print(x / 10); putchar(x % 10 ^ 48);}

int T, n, m, kcnt, mp[B], vis[B], ans = INF;
struct edge {int v, w, nxt;} e[B];
int head[B], ecnt;
int a[510][510], b[510][510];

int K(int i, int j) {return (i - 1) * m + j;}
void add_edge(int u, int v, int w) {e[++ecnt] = (edge){v, w, head[u]}; head[u] = ecnt;}
void check() {
	int sum = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			int u = K(i, j); vis[u] = 1;
			for(int k = head[u]; k; k = e[k].nxt)
			{
				int v = e[k].v, w = e[k].w; if(vis[v]) continue;
				if(mp[v] ^ mp[u]) sum += w;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) vis[K(i, j)] = 0;
	ans = Min(ans, sum);
}
void dfs(int x, int y) {
	if(x == n + 1) {check(); return ;}
	mp[K(x, y)] = 0;
	if(y == m + 1) dfs(x + 1, 1);
	else dfs(x, y + 1);
	mp[K(x, y)] = 1;
	if(y == m + 1) dfs(x + 1, 1);
	else dfs(x, y + 1);
}
void build() {
	for(int i = 1; i ^ n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			int x = a[i][j];
			add_edge(K(i, j), K(i + 1, j), x);
			add_edge(K(i + 1, j), K(i, j), x);
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j ^ m; ++j)
		{
			int x = b[i][j];
			add_edge(K(i, j), K(i, j + 1), x);
			add_edge(K(i, j + 1), K(i, j), x);
		}
	}
}
void clear() {
	kcnt = n * m + 2 * m + 2 * n; ecnt = 0;
	memset(head, 0, sizeof head); ans = INF;
}
void Main() {
	n = read(); m = read(); T = read();
	for(int i = 1; i ^ n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			int x = read(); a[i][j] = x;
//			add_edge(K(i, j), K(i + 1, j), x);
//			add_edge(K(i + 1, j), K(i, j), x);
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j ^ m; ++j)
		{
			int x = read(); b[i][j] = x;
//			add_edge(K(i, j), K(i, j + 1), x);
//			add_edge(K(i, j + 1), K(i, j), x);
		}
	}
	for(int i = 1; i <= T; ++i)
	{
		clear(); build();
		int k = read();
		for(int j = 1; j <= k; ++j)
		{
			int x = read(), y = read(), z = read();
			++kcnt; mp[kcnt] = z;
			if(1 <= y && y <= m) add_edge(K(1, y), kcnt, x), add_edge(kcnt, K(1, y), x);
			else if(m + 1 <= y && y <= m + n) add_edge(K(y - m, m), kcnt, x), add_edge(kcnt, K(y - m, m), x);
			else if(m + n + 1 <= y && y <= 2 * m + n) add_edge(K(n, 2 * m - y + n + 1), kcnt, x), add_edge(kcnt, K(n, 2 * m - y + n + 1), x);
			else if(2 * m + n + 1 <= y && y <= 2 * m + 2 * n) add_edge(K(2 * n + 2 * m - y + 1, 1), kcnt, x), add_edge(kcnt, K(2 * n + 2 * m - y + 1, 1), x);
		}
		dfs(1, 1);
		Print(ans); pn;
	}
}

int main() {File(); Main(); REFile(); return 0;}


