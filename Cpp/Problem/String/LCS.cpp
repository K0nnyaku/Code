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

const int N_ = 2e5 + 7;
const int M_ = 26;

int Fl[N_<<1], En[N_<<1], Ch[N_<<1][M_], las, cnt, len, ans;
string S, T;

void Extend(int c) {
	int p = las, u;
	En[las=u=++cnt] = En[p] + 1;
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
}

void Solve(int x, int y, int z) {
	ans = max(ans, z);

	if(y >= T.size()) return ;

	int c = T[y] - 'a'; 

	if(Ch[x][c])   Solve(Ch[x][c], y+1, z+1      ); 
	else if(Fl[x]) Solve(Fl[x],    y,   En[Fl[x]]); 
	else		   Solve(1,        y+1, 0        );
}

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	cin >> S >> T;

	cnt = las = 1;
	Ir(i, 0, S.size()) Extend(S[i]-'a');

	Solve(1, 0, 0);

	cout << ans << "\n";

	return 0;
} /**/

















