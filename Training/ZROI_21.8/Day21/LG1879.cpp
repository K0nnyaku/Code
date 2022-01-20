#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MAXN = 12 + 10;
const int MAXP = (1 << 12) + 10;
const int P = 1e9;

int F[MAXN][MAXP], Pr[MAXN];
int n, m, ans;

bool Check(int pos, int x);

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    IOR(i, 1, n+1) IOR(v, 0, m) {
        int x; scanf("%d", &x);
        if(!x) Pr[i] |= (1 << v); 
    }

    F[0][0] = 1;
    IOR(i, 1, n+1) IOR(v, 0, 1 << m) 
        if(Check(i, v)) IOR(k, 0, 1 << m) 
            if(Check(i-1, k) && !(v & k))  F[i][v] += F[i-1][k];

    IOR(i, 0, 1 << m) ans += F[n][i], ans %= P;

    printf("%d", ans);

    return 0;
} /**/

bool Check(int pos, int x) {
    if(Pr[pos] & x) return false;
    return !(x & (x >> 1)) && !(x & (x << 1));
}