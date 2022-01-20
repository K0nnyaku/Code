#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define FL(x, y) memset(x, y, sizeof x)
#define DG(x) cout << "Debug: " << #x << "=" << x << "\n"
#define ERR   cout << "Fuck\n"
#define MP(x, y)    make_pair(x, y)
#define fi	first
#define se  second

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
}IN;

const int N_ = 1e6 + 7;

template<int N, int M>
struct GSAM {
	bitset<10> Fg[N<<1];
	int Ch[N<<1][M], En[N<<1], Fl[N<<1], Pos[N<<1], cnt;

	GSAM() { cnt = 1; }

	void Ins(const string &S, int pos) {
		Ir(i, 0, S.size(), p=1) {
			int c = S[i]-'a', &ch = Ch[p][c];
			p = ch ? ch : ch = ++cnt;
			Fg[p].set(pos);
		}
	}

	int Extend(int c, int p) {
		int u = Ch[p][c];
		if(En[u]) return u;	

		En[u] = En[p] + 1; p = Fl[p];
		
		while(p && !Ch[p][c]) Ch[p][c] = u, Fg[p] |= Fg[u], p = Fl[p];	

		if(!p) Fl[u] = 1, Fg[p] |= Fg[u];
		else {
			int q = Ch[p][c];
			if(En[q] == En[p] + 1) Fl[u] = q, Fg[p] |= Fg[u];
			else {
				int v = ++cnt;
				Ir(i, 0, M) 
					if(En[Ch[q][i]]) Ch[v][i] = Ch[q][i], Fg[v] |= Fg[Ch[q][i]];
				Fl[v] = Fl[q]; En[v] = En[p] + 1; Fl[u] = Fl[q] = v; 
				while(Ch[p][c] == q) Ch[p][c] = v, Fg[p] |= Fg[v], p = Fl[p];
			}
		}
		return u;
	}

	void Init() {
		queue<pair<int ,int> > Q; 
		Ir(i, 0, M) if(Ch[1][i]) Q.push(MP(i, 1));
		while(Q.size()) {
			auto p = Q.front(); Q.pop();
			int last = Extend(p.fi, p.se);
			Ir(i, 0, M) if(Ch[last][i]) Q.push(MP(i, last));
		}
	}

	int Solve(const string &S, int n) {
		int res = 0, tmp = 0;
		Ir(i, 0, S.size(), p=1) {
			int c = S[i]-'a', ch = Ch[p][c];

			tmp++;
			while(p && !ch) p = Fl[p], ch = Ch[p][c], tmp = En[p];
			if(!p) p = 1, tmp = 0;

			res = max(res, tmp * (Fg[p].count()==n));
			p = ch;
		}
		return res;
	}
};

GSAM<N_, 26> I;
string S;
int n;

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in",  "r", stdin );
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	while(cin >> S) I.Ins(S, n), n++;

	I.Init();

	cout << I.Solve(S, n);

	return 0;
} /**/










