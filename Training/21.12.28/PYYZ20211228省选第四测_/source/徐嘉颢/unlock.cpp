#include <bits/stdc++.h>
#define int long long
#define double long double
#define FL(xx, yy, zz) memset(xx, yy, sizeof(int) * zz)
#define Efor(xx, yy) for(int xx = Head[yy]; xx; xx = Next[xx])
#define Lfor(xx, yy, zz, xyz, ...) for(int xx = yy, ##__VA_ARGS__; xx <= zz; xx += xyz)
#define Rfor(xx, yy, zz, xyz, ...) for(int xx = yy, ##__VA_ARGS__; xx >= zz; xx -= xyz)
using namespace std;
struct FastIN
{
	char buf[(1 << 21) + 100], *p, *e;
	int getChar()
	{
		if (p == e) p = buf, e = buf + fread(buf, 1, (1 << 21), stdin);
		return p == e ? EOF : *p++;
	}
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for (c = 0; !isdigit(c); c = getChar()) l = c;
		for (x = 0; isdigit(c); c = getChar()) x = x * 10 - '0' + c;
		if (l == '-') x = -x;
		return *this;
	}
} IN;
const int kN = 1e6 + 16;
int t, n, k, Sec, Cnt;
int A[kN], T[kN], Tmp[kN];
void Work();
signed main() {
//#ifdef FIO
//    freopen("D:/Code/In.in", "r", stdin);
//    freopen("D:/Code/Out.out", "w", stdout);
//#endif
	freopen("unlock.in", "r", stdin);
	freopen("unlock.out", "w", stdout);
	IN >> t;
	while (t --> 0) Work();
    return 0;
}
void DFS(int, int);
void Work() {
	IN >> n >> k;
	Lfor (i, 1, n, 1) IN >> A[i];
	DFS(1, 0);	
	double a = 1;
//	cout << Sec << " : " << Cnt << "\n";
	printf("%.9Lf\n", a * Sec / Cnt);
	Sec = Cnt = 0;
	FL(T, 0, n + 100);
}
bool Check();
void DFS(int x, int last) {
	if (x == k + 1) {
		if (Check()) Sec++;
		Cnt++; return;
	}
	Lfor (i, last + 1, n, 1) {
		T[i] = 1;
		DFS(x + 1, i);
		T[i] = 0;
	}
}
bool Vis[kN];
bool Check() {
	queue <int> Q; // Q 中保存能打开的箱子
	int tot = 0, cnt = 0;
	FL(Vis, 0, n + 100);
	Lfor (i, 1, n, 1) if (T[i]) Q.push(i), Vis[i] = 1;
	while (Q.size()) {
		int x = Q.front(); Q.pop();
		tot++;
		if (!Vis[A[x]]) {
			// A[x] 还没有入队，即未打开
			Q.push(A[x]);
			Vis[A[x]] = 1;
		}
	}
//	cout << ": " << tot << "\n";
	return (tot == n);
}








