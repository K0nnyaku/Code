#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MAXN = 5e2 + 10;

int A[MAXN], dp[MAXN][MAXN];
int n;

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    scanf("%d", &n);
    IOR(i, 1, n+1) 
        scanf("%d", &A[i]);

    memset(dp, 0x3f, sizeof dp);

    IOR(i, 1, n+1) dp[i][i] = 1;
    IOR(i, 1, n) 
        if(A[i] == A[i+1]) 
            dp[i][i+1] = 1;
        else 
            dp[i][i+1] = 2;

    IOR(len, 3, n+1) IOR(l, 1, n-len+2) {
        int r = l + len - 1;

        if(A[l] == A[r]) dp[l][r] = dp[l+1][r-1];
        else IOR(k, l, r) 
            dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
    }

    printf("%d", dp[1][n]);

    return 0;
} /**/