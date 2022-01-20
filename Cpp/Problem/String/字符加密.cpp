#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define ER(i, v, p, q, k, ...) for(int  i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define Er(i, v, p, q, k, ...) for(int &i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
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

const int N_ = 1e5 + 7;

int Rk[N_<<2], Sa[N_<<2], Tmp[N_<<2], e, len;
char S[N_<<1];

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	scanf("%s", S+1); len = strlen(S+1);
	IR(i, 1, len) S[i+len] = S[i];

	len <<= 1;
	IR(i, 1, len) Rk[i] = S[i], Sa[i] = i;

	for(e = 1; e < len; e <<= 1) {
		sort(Sa+1, Sa+len + 1, [](int x, int y) {
				return Rk[x] == Rk[y] ? Rk[x+e] < Rk[y+e] : Rk[x] < Rk[y]; });

		memcpy(Tmp, Rk, sizeof Rk);

		IR(i, 1, len, p=0) 
			p += Tmp[Sa[i]] != Tmp[Sa[i-1]] || Tmp[Sa[i]+e] != Tmp[Sa[i-1]+e],
			Rk[i] = p;
	}

	IR(i, 1, len) 
		if(Sa[i] <= len / 2) cout << S[Sa[i]+len/2] << "\n";

	return 0;
} /**/











