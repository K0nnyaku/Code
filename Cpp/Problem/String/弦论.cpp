#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define ER(i, v, p, q, k, ...) for(int  i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define Er(i, v, p, q, k, ...) for(int &i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define DOG(x) cout << "Debug: " << #x << "=" << x << "\n"
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

const int N_ = 5e5 + 7;

int Fl[N_<<1], En[N_<<1], Ch[N_<<1][26], Fn[N_<<1], Qt[N_<<1], Sm[N_<<1], C[N_<<1];
int cnt, las, len, n, m; 
char S[N_];

void Extend(int c) {
	int p = las, u;
	En[las = u = ++cnt] = En[p] + 1; Qt[u] = 1;
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

void Solve(int x) {
	int p = 1;
	while(x > 0) 
		Ir(i, 0, 26) {
			int ch = Ch[p][i];
			if(Sm[ch] < x) x -= Sm[ch];
			else { putchar(i+'a'); p = ch; x -= Qt[ch]; break; }
		}
}

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	scanf("%s", S+1); len = strlen(S+1);
	IN >> n >> m;
	cnt = las = 1;
	IR(i, 1, len) Extend(S[i]-'a');

	IR(i, 1, cnt) C[En[i]]++;
	IR(i, 1, len) C[i] += C[i-1];
	SR(i, cnt, 1) Fn[C[En[i]]--] = i;
	SR(i, cnt, 1) Qt[Fl[Fn[i]]] += Qt[Fn[i]];

	if(!n) IR(i, 1, cnt) Qt[i] = 1;
	Qt[1] = 0;
	IR(i, 1, cnt) Sm[i] = Qt[i];

	SR(i, cnt, 1) Ir(v, 0, 26) 
		Sm[Fn[i]] += Sm[Ch[Fn[i]][v]];

	if(Sm[1] < m) cout << "-1\n";
	else		  Solve(m);

	return 0;
} /**/




