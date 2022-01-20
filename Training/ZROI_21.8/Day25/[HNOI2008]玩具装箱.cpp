#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

#define A(x) (Q[x] + x)
#define B(x) (Q[x] + x + s + 1)
#define SLOPE(x, y) ( ((F[y] + B(y) * B(y) - (F[x] + B(x) * B(x))) / (B(y) -B(x))) )

const int MAXN = 5e4 + 10;

double Q[MAXN], F[MAXN];
int Deq[MAXN];
int n, s, l, r;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &s);
    IOR(i, 1, n+1) 
		scanf("%lf", &Q[i]), Q[i] += Q[i-1];
    
    l = r = 1; Deq[1] = 0;
    IOR(i, 1, n+1) {
//		printf("%lf\n", SLOPE(Deq[l], Deq[l+1]));
		while(l < r && SLOPE(Deq[l], Deq[l+1]) < 2 * A(i)) l++;
//		F[i] = F[Deq[l]] + B(Deq[l]) * B(Deq[l]) - 2 * A(i) * B(Deq[l]) + A(i) * A(i);
		int v = Deq[l];
		F[i] = F[v] + (Q[i] - Q[v] + i - v - 1 - s) * (Q[i] - Q[v] + i - v - 1 - s);
		while(l < r && SLOPE(Deq[r-1], Deq[r]) > SLOPE(Deq[r], i)) r--;
		Deq[++r] = i;
    }
    printf("%lld\n", (long long)F[n]);

	return 0;
} /**/