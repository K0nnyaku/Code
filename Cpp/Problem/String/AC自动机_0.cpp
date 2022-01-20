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
#define QMX(x,y) (x=max(x,y))
#define QMI(x,y) (x=min(x,y))

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

const int N_ = 150 + 7;
const int L_ = 1e6 + 7;

string S[N_];
int Ans[N_];
int n;

template<int N, int K>
struct Automaton {
	struct Node { int fl, oc, Ch[K]; };
	Node Tr[N];   int rt, cnt;
	
#define F(x)    Tr[x].fl
#define O(x)    Tr[x].oc
#define C(x,y)  Tr[x].Ch[y]

	void Cl() { FL(Tr, 0); rt = 0; cnt = 0; }
	int New() { return ++cnt; }

	void Ins(const string &S, int pos) {
		int p = rt, len = S.size();
		Ir(i, 0, len, v) {
			v = S[i] - 'a';
			if(C(p, v)) p = C(p, v);
			else        C(p, v) = New(), p = cnt;
		}
		O(p) = pos;
	}

	void Init() {
		queue<int> Q;
		Ir(i, 0, 26) if(C(rt,i)) Q.push(C(rt,i));
		while(Q.size()) {
			int x = Q.front(); Q.pop();
			Ir(i, 0, 26) 
				if(C(x,i)) F(C(x,i)) = C(F(x), i), Q.push(C(x,i));
				else        C(x,i) = C(F(x), i);
		}
	}
	int Qy(const string &S) {
		int p = rt, len = S.size(), res = 0;
		Ir(i, 0, len, v) {
			v = S[i] - 'a'; p = C(p, v); 
			for(int k = p; k; k = F(k)) 
				if(O(k)) QMX(res, ++Ans[O(k)]);
		}
		return res;
	}
};

Automaton<L_, 27> AC;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif

	IN >> n;
	do {
		IR(i, 1, n) 
			cin >> S[i], AC.Ins(S[i], i);

		AC.Init();

		string T; cin >> T;

		int mx = AC.Qy(T);

		cout << mx << "\n";

		IR(i, 1, n) 
			if(Ans[i] == mx) cout << S[i] << "\n";

		IN >> n;

		AC.Cl();  FL(Ans, 0);

	} while(n);


	return 0;
} /**/








