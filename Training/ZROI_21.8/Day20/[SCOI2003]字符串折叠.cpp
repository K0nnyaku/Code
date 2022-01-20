#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MAXN = 1e2 + 10;

int F[MAXN][MAXN], Num[MAXN];
int n;
char S[MAXN];

bool Check(int x, int y, int k);

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
    scanf("%s", S+1); n = strlen(S+1);

    memset(F, 0x3f, sizeof F);
    IOR(i, 1, n+1) 
        F[i][i] = 1; 

    IOR(i, 1, 10) Num[i] = 1;
    IOR(i, 10, 100) Num[i] = 2;
    Num[100] = 3;

    IOR(len, 2, n+1) IOR(l, 1, n-len+2) {
        int r = l + len - 1;

        IOR(k, l, r+1) {
            if(Check(l, r, k-l+1)) 
                F[l][r] = min(F[l][r], F[l][k] + 2 + Num[len/(k-l+1)]);            
            F[l][r] = min(F[l][r], F[l][k] + F[k+1][r]);
        } 
    }

    printf("%d", F[1][n]);

    return 0;
} /**/

bool Check(int l, int r, int k) {
    if((r - l + 1) % k) return false;

    IOR(i, l, r+1) 
        if(S[i] != S[(i-l)%k+l]) return false;
    return true;
}