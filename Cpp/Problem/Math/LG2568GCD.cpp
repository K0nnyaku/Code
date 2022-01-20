#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)

struct FastIN 
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x =- x;
		return *this;
	}
}IN;

const int N_ = 1e7 + 2;

long long Phi[N_], Pm[N_], Vv[N_];
long long idx;
void Euler(long long n) {
	Phi[1] = 1;
	IR(i, 2, n) {
		if(!Vv[i]) Pm[idx++] = i, Phi[i] = i - 1, Vv[i] = i;
		Ir(v,0,idx && Pm[v] * i <= n && Pm[v] <= Vv[i]) 
			Vv[i*Pm[v]] = Pm[v], 
			Phi[i*Pm[v]] = Phi[i] * (i % Pm[v] ? Pm[v]-1 : Pm[v]);;
	}
	IR(i, 1, n) Phi[i] += Phi[i-1];
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	long long n, ans = 0; IN >> n;
	Euler(n);
	Ir(i, 0, idx && Pm[i] <= n && n/Pm[i] >= 1) 
		ans += (Phi[n/Pm[i]]<<1) - 1;

	cout << ans;


	return 0;
} /**/






