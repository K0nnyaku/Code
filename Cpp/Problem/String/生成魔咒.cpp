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

const int N_ = 1e5 + 7;

long long ans;
int Fl[N_<<2], En[N_<<1], cnt, las, n;
map<int, int> Ch[N_<<1];

void Extend(int x) {
	int p = las, u;
	En[las = u = ++cnt] = En[p] + 1;
	while(p && !Ch[p][x]) Ch[p][x] = u, p = Fl[p];
	if(!p) Fl[u] = 1;
	else {
		int q = Ch[p][x];
		if(En[q] == En[p] + 1) Fl[u] = q;
		else {
			int v = ++cnt;
			Ch[v] = Ch[q]; 
			Fl[v] = Fl[q]; En[v] = En[p] + 1; Fl[q] = Fl[u] = v;
			while(Ch[p][x] == q) Ch[p][x] = v, p = Fl[p];
		}
	}
	ans += En[u] - En[Fl[u]];
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	cnt = las = 1;
	while(n--) {
		int x; IN >> x;

		Extend(x); 

		cout << ans << "\n";
	}

	return 0;
} /**/









