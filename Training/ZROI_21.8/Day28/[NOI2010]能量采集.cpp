#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const int MAXN = 1e6 + 10;

unsigned long long ans;
unsigned long long Mu[MAXN];
unsigned long long n, m;

void Euler_Mu(int);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	cin >> n >> m;
	
	Euler_Mu(100100);

//	IOR(i, 1, min(n, m) + 1) IOR(v, 1, min(n, m) / i + 1) 
//		ans += i * Mu[v] * (n / (i * v)) * (m / (i * v));
	unsigned long long Min = min(n, m);

    for (int d = 1; d <= Min; d++)
        for (int D = 1; D <= Min / d; D++)
            ans += d * Mu[D] * (n / (d * D)) * (m / (d * D));	

	cout << ans * 2 - n * m;

	return 0;
} /**/

int Prime[MAXN], idx = 0;
bool Vis[MAXN];

void Euler_Mu(int n) {
    Mu[1] = 1;
	memset(Vis, 0, sizeof Vis);
	memset(Prime, 0, sizeof Prime);

}
