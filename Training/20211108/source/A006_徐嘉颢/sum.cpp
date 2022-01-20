#include <bits/stdc++.h>
#define int long long
#define Efor(xx, yy) for(register int xx = Head[yy]; xx; xx = Next[xx])
#define Lfor(xx, yy, zz, xyz) for(register int xx = yy; xx <= zz; xx += xyz)
#define Rfor(xx, yy, zz, xyz) for(register int xx = yy; xx >= zz; xx -= xyz)
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
const int kN = 1e6 + 16, Mod = 1e9 + 7;
int A[kN];
signed main() {
#ifdef FIO
    freopen("D:/Code/In.in", "r", stdin);
    freopen("D:/Code/Out.out", "w", stdout);
#else
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
#endif
    register int n, Ans = 0;
    IN >> n;
    Lfor (i, 1, n, 1) IN >> A[i];
    Lfor (i, 1, n, 1) {
        Lfor (j, i + 1, n, 1) {
            register int Tmp = A[i] ^ A[j];
            Ans = (Ans + Tmp * Tmp * 2) % Mod;
        }
    }
    cout << Ans;
    cerr << "\n" << clock() << "(ms)";
    return 0;
}