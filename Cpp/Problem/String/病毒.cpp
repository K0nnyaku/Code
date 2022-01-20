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

const int N_ = 3e4 + 7;

int Ch[N_][2], Fail[N_], Ed[N_];
int rt, cnt;
#define C(x, y) Ch[x][y]
#define F(x)    Fail[x]
#define TN      S[i]-'0'

string S;
int n;
bool Vv[N_], fg;

void FdLoop(int x) {
	if(fg == 1) return ;

	Ir(i, 0, 2) if(!fg && !Ed[C(x, i)]) {
		if(Vv[C(x, i)]) { fg = 1; return ; }
		Vv[C(x, i)] = 1, FdLoop(C(x, i));
	}

	Vv[x] = 0;
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/P2444_4.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;

	rt = cnt = 1;
	while(n--) {
		cin >> S;
		int p = rt;
		Ir(i, 0, S.size()) {
			int &ch = Ch[p][TN];
			p = ch ? ch : ch=++cnt;
		}
		Ed[p] = 1;
	}

	Ir(i, 0, 2) Ch[0][i] = rt;

	queue<int> Q; Q.push(1);
	while(Q.size()) {
		int p = Q.front(); Q.pop();

		Ir(i, 0, 2) {
			int &ch = Ch[p][i], f = Fail[p];
			if(ch) F(ch) = C(f, i), Q.push(ch);
			else     ch  = C(f, i);
			if(Ed[F(ch)]) Ed[ch] = 1;
		}
	}

	FdLoop(1);

	if(fg) cout << "TAK\n";
	else   cout << "NIE\n";

	return 0;
} /**/













