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

const int N_ = 9e4 + 7;

long long Fl[N_<<1], Qt[N_<<1], En[N_<<1], Ch[N_<<1][26], cnt, n, t, len, las;
char S[N_];
bool Vv[N_<<1];

void Extend(char c) {
	long long ch = c - 'a', p = las, u;
	
	En[las = u = ++cnt] = En[p] + 1;
	while(p && !Ch[p][ch]) Ch[p][ch] = u, p = Fl[p];
	
	if(!p) Fl[u] = 1;
	else {
		long long q = Ch[p][ch];
		if(En[q] == En[p] + 1) Fl[u] = q;
		else {
			long long v = ++cnt;
			memcpy(Ch[v], Ch[q], sizeof Ch[q]);
			Fl[v] = Fl[q]; En[v] = En[p] + 1; Fl[q] = Fl[u] = v;
			while(Ch[p][ch] == q) Ch[p][ch] = v, p = Fl[p];
		}
	}
}

void FdQt(long long x) {
	Qt[x] = 1;
	Ir(i, 0, 26) {
		int ch = Ch[x][i];
		if(ch) {
			if(!Vv[ch] && (Vv[ch]=1)) FdQt(ch);
			Qt[x] += Qt[ch];
		}
	}
}

void Solve(long long x) {
	long long p = 1;
	while(x) 
		Ir(i, 0, 26) if(Ch[p][i]) 
			if(Qt[Ch[p][i]] < x) x -= Qt[Ch[p][i]];
			else { putchar(i+'a'); p = Ch[p][i]; x--; break; }
	puts("");
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif

	scanf("%s", S+1); len = strlen(S+1);
	
	cnt = las = 1;
	IR(i, 1, len) Extend(S[i]);

	FdQt(1);

	IN >> t;	
	while(t--) { long long x; IN >> x; Solve(x); }

	return 0;
} /**/












