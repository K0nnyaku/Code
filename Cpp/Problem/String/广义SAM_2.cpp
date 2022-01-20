#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
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
		if(l == '-') x = -x;
		return *this;
	}
}IN;

template<int N, int M>
struct GSAM {

	int Ch[N<<1][M], Pos[N], Fl[N<<1], En[N<<1], cnt;

	GSAM() { cnt = 1; }

	void Ins(const string &S) {
		Ir(i, 0, S.size(), p=1) {
			int c = S[i]-'a', &ch = Ch[p][c];
			p = ch ? ch : ch = ++cnt;

		}
	}

	int Extend(int c, int last) {
		int u = Ch[last][c];
		if(En[u]) return u;

		En[u] = En[last] + 1; int p = Fl[last];

		while(p && !Ch[p][c]) Ch[p][c] = u, p = Fl[p];


		if(!p) Fl[u] = 1;
		else {
			int q = Ch[p][c];
			if(En[q] == En[p] + 1) Fl[u] = q;
			else {
				int v = ++cnt;
				Ir(i, 0, M) 
					Ch[v][i] = En[Ch[q][i]] ? Ch[q][i] : 0;

				 Fl[v] = Fl[q]; En[v] = En[p] + 1; Fl[u] = Fl[q] = v;

				 while(Ch[p][c] == q) Ch[p][c] = v, p = Fl[p];
			}
		}
		return u;
	}

	void Init() {
		queue<pair<int, int> > Q;	
		Ir(i, 0, M) if(Ch[1][i])
			Q.push(make_pair(i, 1));
		while(Q.size()) {
			auto p = Q.front(); Q.pop();
			int last = Extend(p.first, p.second);	
			Ir(i, 0, M) if(Ch[last][i]) 
				Q.push(make_pair(i, last));
		}
	}

	long long Solve() {
		long long res = 0;
		IR(i, 1, cnt) res += En[i] - En[Fl[i]];
		return res;
	}
};

const int N_ = 1e6 + 7;

GSAM<N_, 26> I;
string S; int n;

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;

	IR(i, 1, n) cin >> S, I.Ins(S);
	I.Init();			
	cout << I.Solve();

	return 0;
} /**/







