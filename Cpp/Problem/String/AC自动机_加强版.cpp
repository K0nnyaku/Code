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
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	Edge()    { FL(I, 0); FL(Nt, 0); FL(To, 0); cnt = 1; }
	void Cl() { FL(I, 0); FL(Nt, 0); FL(To, 0); cnt = 1; }
	void AdI(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
};

const int N_ = 150 + 7;
const int L_ = 70 + 7;

string S[N_];
pair<int, int> Ans[N_];
int n;

template<int N, int M>
struct Automaton {
	struct Node { int fail, qt, Ch[M]; };

	Node Tr[N];
	Edge<N, N> I;
	int Qt[N];
	int rt, cnt;

	Automaton() { rt = cnt = 1; }

	void Cl() { I.Cl(); FL(Tr, 0); FL(Qt, 0); rt = cnt = 1; }

	int New() { return ++cnt; }

	void Ins(const string &S, int pos) {
		int p = rt; 
		Ir(i, 0, S.size()) {
			int c = S[i] - 'a';
			if(!Tr[p].Ch[c]) 
				Tr[p].Ch[c] = New();
			p = Tr[p].Ch[c];
		}
		Tr[p].qt = pos;
	}

	void Init() {
		Ir(i, 0, 26) Tr[0].Ch[i] = rt;
		queue<int> Q; Q.push(rt);

		while(Q.size()) {
			int p = Q.front(); Q.pop();

			Ir(i, 0, 26) {
				int &ch = Tr[p].Ch[i], fl = Tr[p].fail;
				if(ch) Tr[ch].fail = Tr[fl].Ch[i], Q.push(ch);
				else   ch = Tr[fl].Ch[i];
			}
		}
	}

	void Match(const string &S) {
		Ir(i, 0, S.size(), p=rt) {
			int c = S[i] - 'a';
			p = Tr[p].Ch[c]; Qt[p]++;
		}
	}

	void BuildFailTree() { IR(i, 2, cnt) I.AdI(Tr[i].fail, i); }

	void Fd(int x = 1) {
		ER(i,v,I,x,I)
			Fd(v), Qt[x] += Qt[v];

		Ans[Tr[x].qt].first  = -Qt[x];
		Ans[Tr[x].qt].second = Tr[x].qt;
	}

	Node* operator[](const int &x) { return &Tr[x]; }
};

Automaton<L_*N_, 26> AC;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif

	IN >> n;
	do {
		IR(i, 1, n) 
			cin >> S[i], AC.Ins(S[i], i);

		AC.Init();

		IR(i, 2, AC.cnt) 
			cout << AC[i]->fail << "\n";
		IR(i, 2, AC.cnt)
			Ir(v, 0, 26) 
			cout << AC[i]->Ch[v] << "\n";

		return 0;
		cin >> S[n+1];
		
		AC.Match(S[n+1]);

		AC.BuildFailTree();

		AC.Fd();

		sort(Ans+1, Ans+n+1);

		int mx = Ans[1].first;

		cout << -mx << "\n";

		IR(i, 1, n)
			if(Ans[i].first == mx) 
				cout << S[Ans[i].second] << "\n";
			else break;

		AC.Cl(); FL(Ans, 0); 

		IN >> n;
	}while(n);


	return 0;
} /**/




















