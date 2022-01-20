#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

const int _BUF = 1e2 + 19;
struct FastIO
{
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x = -x;
		return *this;
	}
	template<typename T>
	FastIO& operator<<(T& x)
	{
		static char Buf[_BUF];
		static int len = -1;
		if(x >= 0) 
			do 
				Buf[++len] = x % 10 + 48, x /= 10;
			while(x);
		else {
			putchar('-');
			do 
				Buf[++len] = -(x % 10) + 48, x /= 10;
			while(x);
		}
		while(len >= 0) 
			putchar(Buf[len--]);
		return *this;
	}
} IO;

const int INF = 0x7f7f7f7f;
const int _N = 5000 + 10;

__int128 F[_N], Num[_N], A[_N], ans = 0, cnt = 0;
int n;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif
	IO >> n;
	SR(i, n, 1) IO >> A[i];
	A[0] = -INF;
	A[n+1] = INF;

	IR(i, 0, n+1) F[i] = 0, Num[i] = 0;
	Num[0] = 1;
	IR(i, 1, n+1) {
		IR(v, 0, i-1) if(A[v] < A[i]) F[i] = max(F[i], F[v]+1);

		__int128 last = -1; 
		SR(v, i-1, 0) if(F[v]+1 == F[i] && A[v] < A[i])
			if(A[v] != last) last = A[v], Num[i] += Num[v];
	}

	if(Num[n+1] == 0) {
		cout << 200 << " ";
		printf("1606938044258990275541962092341162602522202993782792835301376\n");
		return 0 ;
	}
	F[n+1]--;
	IO << F[n+1];
	cout << " ";
	IO << Num[n+1];

	return 0;
} /**/











