#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)

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

const int N_ = 5e3 + 7;
const int M_ = 1e5 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;

template<typename T, int N, int M>
struct Edge {
	int I[N], H[N], To[M], Nt[M]; int cnt;
	T C[M];
	Edge() { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c) {
//		printf("from %d to %d, c = %d\n", u, v, c);
		Nt[++cnt] = I[u]; To[cnt] = v; C[I[u]=cnt] = c;	
		Nt[++cnt] = I[v]; To[cnt] = u; C[I[v]=cnt] = 0;	
	}
	void Add(int u, int v, T c) {
		Nt[++cnt] = I[u]; To[cnt] = v; C[I[u]=cnt] = c;	
	}
};


Edge<long long, N_, M_<<1> I, G;
long long Far[N_], W[N_];
int n, m, og, sk;
bool Vv[N_];

void Spfa();
void MkI(int x);
long long Dic(long long fl, int x);
bool Pre();

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;

	IR(i, 1, m) {
		int u, v; long long w; 
		IN >> u >> v >> w;
		G.Add(u, v, w); 
		G.Add(v, u, w);
	}
	IR(i, 1, n) IN >> W[i];

	og = 1, sk = n * 2;
	Spfa();
	FL(Vv, 0);
	
	W[1] = W[n] = INF;
	MkI(og);
	IR(i, 1, n) I.AdI(i, i+n, W[i]);

	long long ans = 0;
	while(Pre())
		ans += Dic(INF, og);

	cout << ans << "\n";

	return 0;
} /**/

void MkI(int x) {
	ER(i,v,G,x,I) 
		if(Far[v] == Far[x] + G.C[i]) {
			I.AdI(x+n, v, INF);
			if(!Vv[v] && (Vv[v] = 1)) MkI(v);
		}
}

void Spfa() {
	FL(Far, 0x3f); FL(Vv, 0);
	Far[og] = 0;
	deque<int> Q;  Q.push_front(og);
	
	while(Q.size()) {
		int tp = Q.front(); Q.pop_front();
		Vv[tp] = 0;
		ER(i,v,G,tp,I) if(Far[v] > Far[tp]+G.C[i]) {
			Far[v] = Far[tp] + G.C[i];
			if(!Vv[tp]) 
				if(Q.size() && Far[Q.front()] > Far[v]) Q.push_front(v);
				else									Q.push_back (v);
		}
	}
}

bool Pre() {
	FL(Far, 0);  Far[og] = 1;
	queue<int> Q; Q.push(og);

	memcpy(I.H, I.I, sizeof I.I);

	while(Q.size()) {
		int x = Q.front(); Q.pop();
		ER(i,v,I,x,I) if(I.C[i] && !Far[v])
			Far[v] = Far[x] + 1, Q.push(v);
	}

	return Far[sk];
}

long long Dic(long long fl, int x) {
	if(x == sk) return fl;
	long long res = fl; 
	ER(i,v,I,x,H) if(I.C[i] && Far[v] == Far[x]+1) {
		long long k = Dic(min(res, I.C[i]), v);

		I.C[i] -= k; I.C[i^1] += k;
		res -= k;    I.H[x] = i;

		if(!res) return fl;
		if(!k) Far[k] = 0;
	}
	return fl - res;
}









