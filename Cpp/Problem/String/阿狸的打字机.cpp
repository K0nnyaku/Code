#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define ER(i, v, p, q, k, ...) for(int  i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define Er(i, v, p, q, k, ...) for(int &i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define DG(x) cout << "Debug: " << #x << " = " << x << "\n"
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

template<typename T, int N>
struct FenWick {
	T A[N];
	void Cg(int x, T y) { while(x < N) A[x] += y, x += x & -x; }
	T AkP(int x) {
		T res = 0;
		while(x) res += A[x], x -= x & -x;
		return res;
	}
	T AkS(int x, int y) { return AkP(y) - AkP(x-1); }
};

template<int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	Edge() { cnt = 1; }
	void AdI(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
};

const int N_ = 1e6 + 7;

int Mp[N_];
int ct;

template<int N, int M>
struct ACAT {
	int Fail[N], Nxt[N], Ep[N], Fa[N], Ch[N][M], Qt[N];
	bool Ed[N];

	int cnt, rt;

	ACAT() { rt = cnt = 1; }

#define N(x)   Nxt[x]
#define E(x)   Ed[x]
#define F(x)   Fail[x]
#define C(x,y) Ch[x][y]
#define TN     (S[i]-'a')

	void Build(const string &S) {
		Ir(i, 0, S.size(), p=rt) {
			int &ch = C(p, TN), q = p;
			if(S[i] == 'P')			Ed[p] = 1, Mp[++ct] = p;
			else if(S[i] == 'B')    p = Fa[p];
			else                    p = ch ? ch : ch=++cnt, Fa[p] = q;
		}
	}

	void ItAC() {
		Ir(i, 0, M) C(0, i) = rt;
		queue<int> Q; Q.push(rt);

		while(Q.size()) {
			int p = Q.front(); Q.pop();
			Ir(i, 0, M) {
				int &ch = C(p, i), f = F(p);
				if(ch) F(ch) = C(f, i), Ep[ch] = Ep[p]+1, Q.push(ch);
				else     ch  = C(f, i);
			}
		}
	}
};


ACAT<N_, 26> AC;
Edge<N_, N_> I;
FenWick<int, N_> Fk;

string S;
vector<char> T;
vector<int> Qs[N_], Id[N_];

int Qt[N_], Ans[N_], Fn[N_], Nf[N_];
int n, m, fct;

void FdFn(int x) {
	Fn[x] = ++fct; Nf[fct] = x;
	Qt[x] = 1;

	ER(i,v,I,x,I) 
		FdFn(v), Qt[x] += Qt[v];
}

void Solve(int x) {

	Fk.Cg(Fn[x], 1);

	Ir(i, 0, Qs[x].size()) {
		int y = Qs[x][i], id = Id[x][i];
		Ans[id] = Fk.AkS(Fn[y], Fn[y]+Qt[y]-1);
	}

	Ir(i, 0, 26) {
		int ch = AC.Ch[x][i];
		if(AC.Ep[ch] > AC.Ep[x]) Solve(ch);
	}

	Fk.Cg(Fn[x], -1);
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in",  "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	cin >> S;

	/*
	Ir(i, 0, S.size()) 
		if(S[i] == 'P')					 AC.Ins(T, Mp[++ct]);
		else if(S[i] == 'B' && T.size()) T.pop_back();
		else						     T.push_back(S[i]);
		*/

	AC.Build(S);
	
	AC.ItAC();

	IN >> m;
	IR(i, 1, m) {
		int x, y; IN >> x >> y;	
		x = Mp[x];  y = Mp[y];

		Qs[y].push_back(x);
		Id[y].push_back(i);
	}

	IR(i, 2, AC.cnt) 
		I.AdI(AC.Fail[i], i);

	FdFn(1);

	Solve(1);

	IR(i, 1, m) cout << Ans[i] << "\n";

	return 0;
} /**/









