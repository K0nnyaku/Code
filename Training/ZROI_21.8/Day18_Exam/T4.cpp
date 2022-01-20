#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define ZERO(x) memset(x, 0, sizeof x);

const int MAXN = 1e3 + 10;
const int MAXM = 10 + 10;
const int INF = 0x3f3f3f3f;

int A[MAXN][MAXM];
int n, m, ans = INF, sum;

void Solve(int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    IOR(i, 0, n-1) {
        char S[MAXM]; scanf("%s", S);
        IOR(v, 0, m) A[i][v] = S[v] - '0';
    }

    for(int i = 0; i < (1 << m); i++) 
        Solve(i);

    printf("%d %d", ans, sum);

	return 0;
} /**/

void Solve(int x) {
    int res = 0;
    IOR(i, 0, n-1) {
        int temp = 0;
        IOR(v, 0, m) if(((x >> v) & 1) == A[i][v]) temp++;
        res = max(res, temp);
    }

    if(ans > res) ans = res, sum = 1;
    else if(res == ans) sum++;
}