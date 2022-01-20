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

const int _L = 800 + 10;

set<string> Bk;
string P, S;
int F[_L][_L], Jp[_L][_L], Js[_L][_L];
int t, plen, slen, mx;

void Wk(int x, int y, int res, string Res);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif
	IN >> t;
	while(t--) {
		P.clear(); S.clear();
		cin >> P >> S;
		Bk.clear();
		P = " " + P;
		S = " " + S;
		plen = P.size()-1, slen = S.size()-1;

		IR(i, 1, plen) IR(v, 1, slen) {
			if(P[i] == S[v]) F[i][v] = F[i-1][v-1] + 1;
			else F[i][v] = max(F[i-1][v], F[i][v-1]);
			mx = max(mx, F[i][v]);
		}

		memset(Jp, 0, sizeof Jp);
		memset(Js, 0, sizeof Js);
		SR(i, plen, 1) IR(v, 0, 25) SR(k, i, 1) 
			if(P[k] == 'a' + v) Jp[i][v] = k, k = 0;
		SR(i, slen, 1) IR(v, 0, 25) SR(k, i, 1) 
			if(S[k] == 'a' + v) Js[i][v] = k, k = 0;

		Wk(plen, slen, mx, "");

		for(set<string>::iterator it = Bk.begin(); it != Bk.end(); it++) 
			cout << *it << "\n";
		if(t) cout << "\n";
	}

	return 0;
} /**/

void Wk(int x, int y, int res, string Res) {
	if(!res) {
		Bk.insert(Res); return ;
	}
	if(!x || !y) return ;

	IR(v, 0, 25) {
		int xj = Jp[x][v], yj = Js[y][v];
		char ch = v + 'a';
		if(xj && yj && F[xj][yj] == res) 
			Wk(xj-1, yj-1, res-1, ch+Res);
	}
}











