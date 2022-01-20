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

const int N_ = 3e5 + 7;

template<int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	void AdI(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
};

Edge<N_, N_<<1> I;
map<int, long long> Mp[N_];
int Qt[N_], Fa[N_], C[N_], Fn[N_];
int n, cnt;
bool Vv[N_];

void FdFn() {
	queue<int> Q; Q.push(1);
	Vv[1] = 1;
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		Fn[++cnt] = x;
		ER(i,v,I,x,I) if(!Vv[v] && (Vv[v] = 1)) 
			Fa[v] = x, Q.push(v);
	}
}

map<int, long long> Add(const map<int, long long> &x, const map<int, long long> &y, int z) {
	map<int, long long> res;

	if(x.size() < y.size()) {
		res = y;
		for(auto it = x.begin(); it != x.end(); it++) 
			if(it->first != z) res[it->first] += it->second;
			else               res[it->first]  = it->second;
	}
	else {
		res = x;
		for(auto it = y.begin(); it != y.end(); it++) 
			if(it->first != z) res[it->first] += it->second;
	}
	return res;
}

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) IN >> C[i];

	Ir(i, 1, n) {
		int u, v; IN >> u >> v;
		I.AdI(u, v); I.AdI(v, u);
	}

	FdFn();

	IR(i, 1, cnt) Qt[i] = 1;
	SR(i, cnt, 1) Qt[Fa[Fn[i]]] += Qt[Fn[i]];
	
	IR(i, 1, cnt) Mp[i][C[i]] = Qt[i];

	SR(i, cnt, 1) 
		Mp[Fa[Fn[i]]] = Add(Mp[Fa[Fn[i]]], Mp[Fn[i]], C[Fa[Fn[i]]]);	

	IR(i, 1, cnt) {
		int x = Fn[i];

		map<int, long long> Tmp = Mp[Fa[x]];

		Tmp[C[Fa[x]]] = Mp[x][C[Fa[x]]] + Qt[1] - Qt[x];
		Tmp[C[x]] = Qt[1];

		Mp[x] = Tmp;
	}

	IR(i, 1, n) {
		long long tmp = 0;
		for(auto it = Mp[i].begin(); it != Mp[i].end(); it++) 
			tmp += it->second;
		cout << tmp << "\n";
	}


	return 0;
} /**/








