#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define ZERO(x) memset(x, 0, sizeof x);

const int MAXN = 1e4 + 10;
const int INF = 0x3f3f3f3f;

int ans = 1, n, len, now;
int F[MAXN][MAXN], Mn[MAXN];
char S[MAXN];
bool Bk[26 + 10];

bool Check(int l, int r);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%s", S+1); len = strlen(S+1);

    memset(F, 0x3f, sizeof F);
    
    IOR(i, 1, len+1) {
        IOR(v, 1, i+1) {
            if((Mn[v-1] || v == 1) && Check(v, i)) F[i][v] = min(F[i][v], Mn[v-1]+1);
            if(F[i][v] != INF) Mn[i] = min(Mn[i] == 0 ? INF : Mn[i], F[i][v]);
//            printf("i = %d, v = %d, F = %d\n", i, v, F[i][v]);
        }
        if(!Mn[i]) printf("%d\n", -1);
        else printf("%d\n", Mn[i]);
    }

	return 0;
} /**/

bool Check(int l, int r) {
    memset(Bk, 0, sizeof Bk);
    int now = 0;
    IOR(i, l, r+1) {
        int ch = S[i] - 'a';
        if(!Bk[ch]) Bk[ch] = 1, now++;
        if(now > n) return false;
    }
    return now == n;
}