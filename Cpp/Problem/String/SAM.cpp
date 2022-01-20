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

const int N_ = 1e6 + 7;
const int M_ = 26;

int Fl[N_<<1], En[N_<<1], Ch[N_<<1][M_], Qt[N_<<1], Fn[N_<<1], C[N_<<1], len, cnt, las, ans;

void Extend(char c) {
	int ch = c - 'a', p = las, u;

	En[las = u = ++cnt] = En[p] + 1; Qt[u] = 1;
	while(p && !Ch[p][ch]) Ch[p][ch] = u, p = Fl[p];
	if(!p) Fl[u] = 1;
	else {
		int q = Ch[p][ch];
		if(En[q] == En[p] + 1) Fl[u] = q;
		else {
			int v = ++cnt;
			memcpy(Ch[v], Ch[q], sizeof Ch[q]);
			Fl[v] = Fl[q]; En[v] = En[p] + 1; Fl[q] = Fl[u] = v;
			while(Ch[p][ch] == q) Ch[p][ch] = v, p = Fl[p];
		}
	}
}

bool Vv[N_<<1];
void Fd(const string &S) {
	Ir(i, 0, S.size(), p=1) {
		if(!Vv[p] && (Vv[p]=1)) ans++;
		p = Ch[p][S[i]-'a'];
	}
}

string S[N_];
int n;

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) cin >> S[i];

	las = cnt = 1;
	IR(i, 1, n) 
		Ir(v, 0, S[i].size()) Extend(S[i][v]);

	IR(i, 1, n) Fd(S[i]);

	cout << ans << "\n";

	return 0;
} /**/









