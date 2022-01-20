// XXR YYDS
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

const int L_ = 9 + 2;
const int N_ = 1e9;
const int BK = 1e6;

int S[N_/BK+10] = { /*略*/ }

int Chk(int x) {
	if(x == 1) return false;

	int S[1<<L_]; FL(S, 0);
	int len = 0, sm = 0;

	while(x) S[1<<len++] = x % 10, sm += x % 10, x /= 10;

	if(sm % 2) return false;

	Ir(i, 1, 1<<len) {
		S[i] = S[i&(i-1)] + S[i&-i];
		if(S[i] == sm/2) return true;
	}
	
	return false;
}

int l, r;

int Calc(int x) {
	int res = S[x/BK];
	IR(i,x/BK*BK,x) res += Chk(i);
	return res;
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif

	IN >> l >> r;
	cout << Calc(r) - Calc(l-1) << "\n";

	return 0;
} /**/











