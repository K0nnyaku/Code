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

template<int N, int M> 
struct Automaton {
	struct Node { int fail, qt, Ch[M]; };

	Node Tr[N];
	int rt, cnt;

	Automaton() { rt = cnt = 1; }

#define Q(x)    Tr[x].qt
#define F(x)    Tr[x].fail
#define C(x, y) Tr[x].Ch[y]
#define TN      (S[i]-'a')

	void Ins(const string &L, const string &R) {
		int p = rt;
		Ir(i, 0, S.size()) {
			int &ch = C(p, TN);
			p = ch ? ch : ch=++cnt;
		}
		Q(p) = 1; end = p;
	}

	void ItAC(stack<int> &Fn) {
		
		Ir(i, 0, M) C(0, i) = rt;
		queue<int> Q; Q.push(rt);

		while(Q.size()) {
			int p = Q.front(); Q.pop();

			Fn.push(p);

			Ir(i, 0, M) {
				int &ch = C(p, i), f = F(p);
				if(ch) F(ch) = C(f, i), Q.push(ch);
				else     ch  = C(f, i);
			}
		}
	}

	void Match(const string &S, int *A, int v) {
		Ir(i, 0, S.size(), p=rt) p = C(p, TN), A[p] += v % P, A[p] %= P;
	}
	void ItFl(stack<int> &Fn, int *A) {
		while(Fn.size()) {
			int x = Fn.top(); Fn.pop();
			A[F(x)] += A[x], A[F(x)] %= P;	
		}
	}

	Node* operator[](const int &x) { return &Tr[x]; }
};

const int N_ = 200 + 7;
const int L_ = 1e6 + 7;

Automaton<L_, 26> AC;
string S[N_];
stack<int> Fn;
int Qt[L_], Ans[L_], Mp[N_], n;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	cin >> n;
	IR(i, 1, n) cin >> S[i], AC.Ins(S[i], Mp[i]);

	AC.ItAC(Fn);

	IR(i, 1, n) 
		AC.Match(S[i], Qt);

	AC.ItFl(Fn, Qt);

	cout << Qt[1] << "\n";

	return 0;
} /**/














