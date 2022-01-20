#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MAXN = 50 + 10;
const int INF = 0x3f3f3f3f;

int Op[MAXN<<2], Num[MAXN<<2], F[2][MAXN<<2][MAXN<<2];
int n, ans = -INF;

int main() {
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    scanf("%d", &n); getchar();
    IOR(i, 1, n+1) {
        char t;
        getchar(); scanf("%c%d", &t, &Num[i]); 
        if(t == 't') Op[i] = 1;
    } 

    IOR(i, n+1, n*2+1) {
        Num[i] = Num[i-n];
        Op[i] = Op[i-n];
    }

    memset(F[0], 0x3f, sizeof F[0]);
    memset(F[1], -0x3f, sizeof F[1]);

    IOR(i, 1, n*2) F[0][i][i] = F[1][i][i] = Num[i];

    IOR(len, 2, n+1) IOR(l, 1, n*2 - len + 2) {
        int r = l + len - 1;
        IOR(k, r, l) 
            if(Op[k])  {
                F[0][l][r] = min(F[0][l][r], F[0][l][k] + F[0][k+1][r]);
                F[1][l][r] = max(F[1][l][r], F[1][l][k] + F[1][k+1][r]);
            }else {
                F[0][l][r] = 
                    min( min(F[0][l][r], min(F[0][l][k] * F[0][k+1][r], F[1][l][k] * F[1][k+1][r]) ), 
                        min(F[0][l][k] * F[1][k+1][r], F[1][l][k] * F[0][k+1][r]) );
                F[1][l][r] = 
                    max( max(F[1][l][r], F[1][l][k] * F[1][k+1][r]), F[0][l][k] * F[0][k+1][r]);
            }
    }

    IOR(i, 1, n+1) 
        ans = max(ans, F[1][i][i+n-1]);

    printf("%d", ans);

    return 0;
}
