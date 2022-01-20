#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MB = 1 << 21;
struct FastIN {
    char Buf[MB + 100], *p, *e;
    int GetChar() {
        if(p == e) p = Buf, e = Buf + fread(Buf, 1, MB, stdin);
        return p == e ? EOF : *p++;
    }
    template<typename T>
    FastIN& operator>>(T& x) {
        char c, l;
        for(c = 0; !isdigit(c); c = GetChar()) l = c;
        for(x = 0; isdigit(c); c = GetChar()) x = x * 10 + c - '0';
        if(l == '-') x = -x;
        return *this;
    }
}IN;

const int MAXN = 3e2 + 10;
const int MAXV = 1e6 + 10;

vector<int> Fac[MAXN][MAXN];
unordered_map<int, bool> Bk[MAXN][MAXN];
int Mp[MAXN][MAXN], F[MAXN][MAXN][1000];
int r, s, n, idx, ans;

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
    IN >> r >> s >> n;
    IOR(i, 1, r + 1) IOR(v, 1, s + 1) 
        IN >> Mp[i][v];

    F[r][s][n / Mp[r][s]] = 1; Fac[r][s].push_back(n / Mp[r][s]); Bk[r][s][n / Mp[r][s]] = 1;
    LOR(i, r, 0) LOR(v, s, 0) {
        int len = Fac[i][v].size();
        IOR(k, 0, len) {
            int x = Fac[i][v][k], y;
//            printf("i = %d, v = %d, k = %d, x = %d\n", 
//                i, v, k, x);
            if(i > 1) {
                if(x % Mp[i-1][v]) y = x / Mp[i-1][v] + 1;
                else y = x / Mp[i-1][v];

                F[i-1][v][y] += F[i][v][x];
                if(!Bk[i-1][v][y])
                    Fac[i-1][v].push_back(y),
                    Bk[i-1][v][y] = 1;
            }
            if(v > 1) {
                if(x % Mp[i][v-1]) y = x / Mp[i][v-1] + 1;
                else y = x / Mp[i][v-1]; 

                F[i][v-1][y] += F[i][v][x];
                if(!Bk[i][v-1][y]) 
                    Fac[i][v-1].push_back(y),
                    Bk[i][v-1][y] = 1;
            } 
        }
    }

    ans += F[1][1][0] + F[1][1][1];
    printf("%d", ans);

    return 0;
} /**/