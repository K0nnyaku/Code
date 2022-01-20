#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const double E = 1e-7;
const int MAXN = 1e5 + 10;
const double INF = 0x3f3f3f3f;
double A[MAXN], Q[MAXN];
int t, n;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(A, 0, sizeof A);
        memset(Q, 0, sizeof Q);
        IOR(i, 0, n) 
            scanf("%lf", &A[i]);

        sort(A, A+n);
        Q[0] = A[0];
        IOR(i, 1, n) 
            Q[i] = A[i] + Q[i-1];

        double ans = -INF;
        IOR(i, 1, n) {    
            double x = (double)Q[i-1] / i;
            x += (double)(Q[n-1] - Q[i-1]) / (n - i);
            ans = max(ans, x);
        }
        printf("%lf\n", ans);
    }

	return 0;
} /**/