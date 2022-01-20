#include <bits/stdc++.h>
#define int long long
#define Efor(xx, yy) for(int xx = Head[yy]; xx; xx = Next[xx])
#define Lfor(xx, yy, zz, xyz) for(int xx = yy; xx <= zz; xx += xyz)
#define Rfor(xx, yy, zz, xyz) for(int xx = yy; xx >= zz; xx -= xyz)
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
const int kN = 77, INF = ~0ul >> 1;
int n, k, Ans = INF;
int Seq[kN], A[kN];
bool Vis[kN];
int Solve() {
    int sum = 0;
    // Lfor (i, 1, n, 1) cout << Seq[i] << " ";
    // cout << "\n";
    Lfor (i, 1, k, 1) {
        int L = (i - 1) * (n / k) + 1, R = i * (n / k);
        // cout << L << " " << R << "\n";
        sort (Seq + L, Seq + 1 + R);
        bool flag = 1;
        Lfor (j, L + 1, R, 1) {
            if (Seq[j] == Seq[j - 1])   {
                flag = 0; break;
            }
        }
        if (flag) sum += Seq[R] - Seq[L];
        else return INF;
    }
    // cout << "sum : " << sum << "\n";
    return sum;
}
void DFS(int x) {
    // cout << "x : " << x << "\n";
    if (x == n + 1) {
        Ans = min(Ans, Solve());
        return ;
    }
    Lfor (i, 1, n, 1) {
        if (Vis[i]) continue;
        Vis[i] = 1;
        Seq[x] = A[i];
        DFS(x + 1);
        Vis[i] = 0;
    }
}
signed main() {
#ifdef FIO
    freopen("D:/Code/In.in", "r", stdin);
    freopen("D:/Code/Out.out", "w", stdout);
#else
    freopen("num.in", "r", stdin);
    freopen("num.out", "w", stdout);
#endif
    IN >> n >> k;
    Lfor (i, 1, n, 1) IN >> A[i];
    DFS(1);
    cout << Ans;
    return 0;
}