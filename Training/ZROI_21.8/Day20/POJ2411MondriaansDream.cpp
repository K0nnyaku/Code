#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MAXN = 11 + 10;
const int MAXP = (1 << 11) + 10;

long long F[MAXN][MAXP];
int n, m;
bool True[MAXP];

bool Check(int x, int y);

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
    
    while(scanf("%d%d", &n, &m) && n) {
        memset(True, 0, sizeof True);
        IOR(i, 0, 1 << m) {
            bool cnt = 0, flag = 0;
            IOR(v, 0, m) 
                if((i >> v) & 1) cnt = 0;
                else cnt ^= 1, flag = 1;
            True[i] = (cnt ^ 1) && flag;
            printf("i = %d, True = %d\n", i, True[i]);
        }

        memset(F, 0, sizeof F); F[0][0] = 1;
        IOR(i, 1, n+1) IOR(v, 0, 1<<m) IOR(k, 0, 1<<m) 
            if(Check(v, k)) F[i][v] += F[i-1][k];
        printf("%lld\n", F[n][0]);
    }

    return 0;
} /**/

bool Check(int x, int y) {
    if(x & y) return false;
    return True[x | y];
}