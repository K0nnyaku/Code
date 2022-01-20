#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MAXN = 50 + 10;

int A[MAXN], Val[MAXN];
int Q[MAXN], F[2][MAXN][MAXN];
int n, c;

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    scanf("%d%d", &n, &c);
    IOR(i, 1, n+1) 
        scanf("%d%d", &A[i], &Val[i]);

    memset(F, 0x3f, sizeof F);
    IOR(i, 1, n+1)  
        Q[i] = Q[i-1] + Val[i];
    F[0][c][c] = F[1][c][c] = 0;

    IOR(len, 2, n+1) IOR(l, 1, n-len+2) {
        int r = l + len - 1;
        F[0][l][r] = min(F[0][l+1][r] + (A[l+1] - A[l]) * (Q[l] + Q[n] - Q[r]),
                F[1][l+1][r] + (A[r] - A[l]) * (Q[l] + Q[n] - Q[r]));
        F[1][l][r] = min(F[0][l][r-1] + (A[r] - A[l]) * (Q[l-1] + Q[n] - Q[r-1]),
                F[1][l][r-1] + (A[r] - A[r-1]) * (Q[l-1] + Q[n] - Q[r-1]));
    }

    printf("%d", min(F[1][1][n], F[0][1][n]));

    return 0;
} /**/