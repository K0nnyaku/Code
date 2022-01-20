#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);

const int FAC[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
const int MAXN = 30 + 10;
const int MAXP = 1 << 11;

long long F[2][MAXP][MAXP], Fac[MAXN];
int n, p;

void Pre(long long* x, int y);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &p);
    IOR(i, 2, n+1) 
        Pre(&Fac[i], i);

    bool cur = 0; F[cur][0][0] = 1;
    IOR(i, 2, n+1)  {
		cur ^= 1; memcpy(F[cur], F[cur^1], sizeof F[cur^1]);
		IOR(v, 0, 1 << 10) IOR(k, 0, 1 << 10) {
			if(v & k) continue;
		
       		if(!(Fac[i] & k)) F[cur][v | Fac[i]][k] += F[cur^1][v][k], F[cur][v | Fac[i]][k] %= p; 
       		if(!(Fac[i] & v)) F[cur][v][k | Fac[i]] += F[cur^1][v][k], F[cur][v][k | Fac[i]] %= p;
    	} 
	}

    long long ans = 0;
    IOR(v, 0, 1 << 10) IOR(k, 0, 1 << 10) 
        ans += F[cur][v][k], ans %= p;

    printf("%lld", ans);

	return 0;
} /**/

void Pre(long long* x, int y) {
    IOR(i, 0, 10) 
		while(y != 1 && !(y % FAC[i]))
        	*x |= (1 << i), y /= FAC[i];
}