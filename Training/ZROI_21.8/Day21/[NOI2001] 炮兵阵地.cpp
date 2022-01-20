#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MAXN = 1e2 + 10;
const int MAXM = 10 + 10;
const int MAXP = 1 << 10;
const int INF = 0x3f3f3f3f;

int F[3][MAXP][MAXP], Pr[MAXN], S[MAXP];
int n, m, idx;

int Count(int x);
bool Vaild(int pos, int x);

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    IOR(i, 1, n+1) {
        getchar();
        IOR(v, 0, m) {
            char ch;
            cin >> ch;
            if(ch == 'H') Pr[i] |= (1 << v);
        }
    }

    IOR(i, 0, 1 << m) 
        if( !(i & i >> 1) && !(i & i >> 2) && !(i & i << 1) && !(i & i << 2) ) 
            S[idx++] = i;

    memset(F, -0x3f, sizeof F);
    F[0][0][0] = 1;
    IOR(i, 0, idx) 
        if(Vaild(1, S[i])) F[1][S[i]][0] = Count(S[i]);
    IOR(i, 0, idx) IOR(v, 0, idx)
        if(Vaild(2, S[i]) && Vaild(1, S[v])) 
            F[2][S[i]][S[v]] = max(F[2][S[i]][S[v]], F[1][S[v]][0] + Count(S[i]));

    IOR(i, 3, n+1) IOR(v, 0, idx) IOR(k, 0, idx) 
        if(!(S[v] & S[k]) && Vaild(i, S[v]) && Vaild(i-1, S[k])) 
            IOR(q, 0, idx) 
            if(!(S[v] & S[q]) && !(S[k] & S[q]) && Vaild(i-2, S[q])) 
                F[i % 3][S[v]][S[k]] = max(F[i % 3][S[v]][S[k]], F[(i - 1) % 3][S[k]][S[q]] + Count(S[v]));

    int ans = -INF;
    IOR(i, 0, idx) IOR(v, 0, idx) 
        ans = max(ans, F[n%3][S[i]][S[v]]);
    printf("%d", ans);

    return 0;
} /**/

int Count(int x) {
    int res = 0;
    for(int i = 0; 1 << i <= x; i++)
        res += ((x >> i) & 1); 
    return res;
}

bool Vaild(int pos, int x) {
    return !(x & Pr[pos]);
}