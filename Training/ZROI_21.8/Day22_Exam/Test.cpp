#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);

#define A(x) G[x].a
#define B(x) G[x].b
#define C(x) G[x].c

const int MAXN = 4e2 + 2;

struct { long long a, b, c; } G[MAXN];
long long F[2][MAXN][MAXN];
int n, a, b, c;

int main() {
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
    
    scanf("%d%d%d", &n, &a, &b);
    c = n - a - b;
    IOR(i, 1, n+1) 
        scanf("%lld%lld%lld", &A(i), &B(i), &C(i));

    bool cur = 0;
    IOR(i, 1, n+1) {
        cur ^= 1; memset(F[cur], 0, sizeof F[cur]);
        IOR(x, 0, min(a+1, i+1)) IOR(y, 0, min(b+1, i+1)) {
            if(x + y > i) break;

            long long u = 0, v = 0, w = 0;
            if(x) u = F[cur^1][x-1][y] + A(i);
            if(y) v = F[cur^1][x][y-1] + B(i);
            if(i - x - y < c) w = max(x ? F[cur^1][x-1][y] : 0, y ? F[cur^1][x][y-1] : 0) + C(i); 
            F[cur][x][y] = max(
                    F[cur][x][y], max( u, max(v, w) ) );
            printf("i = %d, x = %d, y = %d, f = %lld\n",i, x, y, F[cur][x][y]);
        }
        
    }

    printf("%lld", F[cur][a][b]);

    return 0;
}