#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define ER(i, v, p, q, k, ...) for(int i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define DG(x) cout << "Debug: " << #x << "=" << x << "\n"
#define ERR   cout << "Fuck\n"

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

const int N_ = 1e6 + 7;

int Nt[N_];
int sln, pln;
char S[N_], P[N_];

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	scanf("%s%s", S+1, P+1);
	sln = strlen(S+1), pln = strlen(P+1);

	IR(i, 2, pln, v=0) {
		while(v && P[v+1] != P[i]) v = Nt[v];
		Nt[i] = (v += P[v+1]==P[i]);
	}

	IR(i, 1, sln, v=0) {
		while(v && P[v+1] != S[i]) v = Nt[v];
		v += P[v+1]==S[i];
		if(v == pln) cout << i-v+1 << "\n";
	}

	IR(i, 1, pln) printf("%d ", Nt[i]);

	return 0;
} /**/













