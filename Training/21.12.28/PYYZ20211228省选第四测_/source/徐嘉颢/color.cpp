#include <bits/stdc++.h>
#define int long long
#define double long double
#define FL(xx, yy, zz) memset(xx, yy, sizeof(int) * zz)
#define Efor(xx, yy) for(int xx = Head[yy]; xx; xx = Next[xx])
#define Lfor(xx, yy, zz, xyz, ...) for(int xx = yy, ##__VA_ARGS__; xx <= zz; xx += xyz)
#define Rfor(xx, yy, zz, xyz, ...) for(int xx = yy, ##__VA_ARGS__; xx >= zz; xx -= xyz)
using namespace std;
const int kN = 1e6 + 16;
int n, Q;
struct Graph {
	int tot, Head[kN], Next[kN], Ver[kN];
	int S[kN], F[kN], C[kN], NewC;
	Graph() {
		tot = 1;
	}
	void Ins(int, int), Solve(int, int), Change(int);
	double Ask(int);
	int DFS(int, int);
} T;

signed main() {
//#ifdef FIO
//    freopen("D:/Code/In.in", "r", stdin);
//    freopen("D:/Code/Out.out", "w", stdout);
//#endif
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> n;
	Lfor (i, 1, n - 1, 1, u, v) cin >> u >> v, T.Ins(u + 1, v + 1), T.Ins(v + 1, u + 1);
	Lfor (i, 1, n, 1) T.C[i] = i;
	T.NewC = n + 100;
	// 节点编号都+1
	T.Solve(1, 0);
//	cout << "~~~\n";
	cin >> Q;
	Lfor (i, 1, Q, 1, u) {
		char c;
		cin >> c >> u; ++u;
//		cout << "u : " << u << "\n";
		if (c == 'q') printf("%.10Lf\n", T.Ask(u));
		else T.Change(u);
	}
    return 0;
}
//	void Ins(int, int), Solve(int, int), Change(int);
//	double Ask(int);
//	int DFS(int, int);

void Graph::Ins(int x, int y) {
	Ver[++tot] = y, Next[tot] = Head[x], Head[x] = tot;
}

void Graph::Solve(int x, int fa) {
	S[x] = 1;
	Efor (e, x) {
		int y = Ver[e];
		if (y == fa) continue;
		F[y] = x, Solve(y, x), S[x] += S[y];
	}
}

void Graph::Change(int x) {
	++NewC;
	while (x) C[x] = NewC, x = F[x];
}

double Graph::Ask(int x) {
	int tmp = x, ans = 0;
	while (F[tmp]) ans += (C[tmp] != C[F[tmp]]), tmp = F[tmp];
	tmp = ans;
//	cout << "tmp : " << tmp << "\n";
	Efor (e, x) {
		int y = Ver[e];
		if (y != F[x]) {
			ans += DFS(y, tmp + (C[x] != C[y]));
		}
	}
//	ans += DFS(x, ans);	
//	cout << "ans : " << ans << "\n";
	double a = 1;
	return a * ans / S[x];
}

int Graph::DFS(int x, int sum) {
	int ans = sum;
	Efor (e, x) {
		int y = Ver[e];
		if (y == F[x]) continue;
//		printf("C[%lld] = %lld\n", y - 1, C[y]);
		ans += DFS(y, sum + (C[x] != C[y]));
	}
//	cout << x - 1 << " : "<< ans << "\n";
	return ans;
}
