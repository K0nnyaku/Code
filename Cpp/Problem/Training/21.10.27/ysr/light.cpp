#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x = -x;
		return *this;
	}
} IN;

const int _N = 20 + 10;
const int _L = 20 + 10;

long long Len[_N], F[_N][_L], P[_N];
long long n, idx;

long long Calc();

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#else
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
#endif
	IN >> n; 
	char clo = getchar();
	while(clo != 'Q') {
		int x; IN >> x;
		Len[++idx] = x;
		clo = getchar();
	}

	IR(i, 1, idx) P[i] = i;
	long long ans = 0;
	do {
		ans += Calc();
	}while(next_permutation(P+1, P+idx+1));

	cout << ans << '\n';

	return 0;
} /**/

long long Calc() {
	memset(F, 0, sizeof F);

	IR(i, 0, n) 
		if(i + Len[P[1]] <= n) F[1][i + Len[P[1]]] = 1;

	IR(i, 1, idx-1) IR(v, 0, n) IR(k, 1, n) 
		if(v + Len[P[i+1]] + k <= n) 
			F[i+1][v + Len[P[i+1]] + k] += F[i][v];
		else break;

	/*
	IR(i, 1, idx) 
		printf("%d ", P[i]);
	IR(i, 1, idx) 
		printf("%d ", Len[i]);
	IR(i, 1, idx) {
		cout << "\n-----------------\n";
		IR(v, 1, n) printf("F[%d][%d] = %d\n", i, v, F[i][v]);
		cout << "-----------------\n";
	}
	*/

	long long res = 0;
	IR(i, 1, n) 
		res += F[idx][i];
	
	return res;
}












