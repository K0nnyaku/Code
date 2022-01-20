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
struct Trie {
	int Ch[N][M], Fa[N], C[N], cnt; 
	Trie() { cnt = 1; }

	void Ins(const string &S) {
		Ir(i, 0, S.size(), p=1) {

			int c = S[i] - 'a', &ch = Ch[p][c];
			if(!ch) 
				ch = ++cnt, Fa[ch] = p, C[ch] = c;
			p = ch;
		}

	}
};

template<int N, int M> 
struct GSAM{
	Trie<N, M> Tr;
	int Ch[N<<1][M], Fl[N<<1], En[N<<1], Pos[N<<1], cnt;

	GSAM() { cnt = 1; }

	void Ins(const string &S) { Tr.Ins(S); }

	int Extend(int c, int last) {
		int p = last, u = ++cnt;
		En[u] = En[p] + 1;
		while(p && !Ch[p][c]) Ch[p][c] = u, p = Fl[p];
		if(!p) Fl[u] = 1;
		else {
			int q = Ch[p][c];
			if(En[q] == En[p] + 1) Fl[u] = q;
			else {
				int v = ++cnt;
				memcpy(Ch[v], Ch[q], sizeof Ch[q]);
				Fl[v] = Fl[q]; En[v] = En[p] + 1; Fl[q] = Fl[u] = v;
				while(Ch[p][c] == q) Ch[p][c] = v, p = Fl[p];
			}
		}
		return u;
	}
	void Init() {
		queue<int> Q; Pos[1] = 1;

		Ir(i, 0, M) if(Tr.Ch[1][i]) Q.push(Tr.Ch[1][i]);
		while(Q.size()) {
			int x = Q.front(); Q.pop();
			Pos[x] = Extend(Tr.C[x], Tr.Fa[x] [Pos]);
			Ir(i, 0, M) if(Tr.Ch[x][i]) Q.push(Tr.Ch[x][i]);
		}
	}

	long long Solve() {
		long long res = 0; 
		IR(i, 2, cnt) 	
			res += En[i] - En[Fl[i]];
		return res;
	}
};

const int S_ = 1e6 + 7;

GSAM<S_, 26> I;
string S; int n;

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/P6139_1.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n; 
	IR(i, 1, n) 
		cin >> S, I.Ins(S);

	I.Init();
	
	cout << I.Solve();

	return 0;
} /**/





