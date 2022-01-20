#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MAXN = 9 + 10;
const int MAXP = (1 << 10) + 10;

long long F[2][MAXP][MAXN];
int n, m;

bool Check(int x, int y, int s);

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    scanf("%lld%lld", &n, &m);
    F[0][0][0] = 1;
    
    bool cur = 0;
    IOR(x, 1, n+1) IOR(y, 1, n+1) {
        cur ^= 1; memset(F[cur], 0, sizeof F[cur]);
        IOR(v, 0, 1 << n+1) {
            int tv = (v << 1) % (1 << n+1);
            IOR(k, 0, m+1) {
                F[cur][tv][k] += F[cur^1][v][k];
                if(k < m && Check(x, y, v)) F[cur][tv+1][k+1] += F[cur^1][v][k];
            }
        }
    }

    long long ans = 0;
    IOR(i, 0, 1 << n+1) 
        ans += F[cur][i][m];
    
    printf("%lld", ans);

    return 0;
} /**/

bool Check(int x, int y, int s) {
    if(y > 1 && s & 1) return false;
    if(x > 1 && y > 1 && s >> n && 1) return false;
    if(x > 1 && s >> n-1 & 1) return false;
    if(y < n && x > 1 && s >> n-2 & 1) return false;
    return true;
}
