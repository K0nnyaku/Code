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

const int N_ = 2e3 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;

template<typename T, int N, int M>
struct Edge {
	int I[N], H[N], Nt[M], To[M]; int cnt;
	T W[M], C[M];
	Edge() { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(To, 0); FL(W, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c, T w) {
		Nt[++cnt] = I[u]; To[cnt] = v; C[cnt] = c; W[I[u]=cnt] =  w;
		Nt[++cnt] = I[v]; To[cnt] = u; C[cnt] = 0; W[I[v]=cnt] = -w;
	}
};

Edge<long long, N_<<1, N_*17> I;
long long Far[N_<<1], In[N_<<1], Out[N_<<1];
long long ans;
int og, sk, n, m, go, ks;
bool Vv[N_<<1];

bool Spfa(int og, int sk);
long long Dic(long long fl, int x, int sk);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif

	IN >> n;

	og = 0,    sk = 2*n+1;
	go = sk+1, ks = sk + 2;

	IR(i, 1, n) {
		long long x; IN >> x;
		Out[i] += x; In[i+n] += x; 
		I.AdI(i, i+n, INF-x, 0);
	}

	long long x, y; 
	IN >> x;
	IR(i, 1, n)   I.AdI(og, i, INF, x);
	IN >> x >> y;
	IR(i, 1, n-x) I.AdI(i+n, i+x, INF, y); 
	IN >> x >> y;	
	IR(i, 1, n-x) I.AdI(i+n, i+x, INF, y);

	Ir(i, 1, n) I.AdI(i, i+1, INF, 0);
	IR(i, 1, n) I.AdI(i+n, sk, INF, 0);
	
	I.AdI(sk, og, INF, 0);

	IR(i, 1, 2 * n) {
		if(In[i] > Out[i]) I.AdI(go, i, In[i]-Out[i], 0);
		if(In[i] < Out[i]) I.AdI(i, ks, Out[i]-In[i], 0);
	}

	while(Spfa(go, ks))
		FL(Vv, 0), Dic(INF, go, ks);

	cout << ans << "\n";

	return 0;
} /**/

bool Spfa(int og, int sk) {
	FL(Vv, 0); FL(Far, 0x7f);
	Far[og] = 0;
	deque<int> Q; Q.push_front(og);

	memcpy(I.H, I.I, sizeof I.I);

	while(Q.size()) {
		int tp = Q.front(); Q.pop_front();
		Vv[tp] = 0;

		ER(i,v,I,tp,I) if(I.C[i] && Far[v] > Far[tp]+I.W[i]) {
			Far[v] = Far[tp] + I.W[i];
			if(!Vv[v] && (Vv[v] = 1)) 
				if(Q.size() && Far[Q.front()] > Far[v]) Q.push_front(v);
				else									Q.push_back (v);
		}
	}
	return Far[sk] != INF;
}

long long Dic(long long fl, int x, int sk) {
	if(x == sk) return fl;
	long long res = fl;
	Vv[x] = 1;

	ER(i,v,I,x,H) 
		if(I.C[i] && !Vv[v] && Far[v] == Far[x]+I.W[i]) {
			long long k = Dic(min(res, I.C[i]), v, sk);
		
			I.C[i] -= k; I.C[i^1] += k;
			ans += k * I.W[i];
			I.H[x] = i;  res -= k;

			if(!res) return fl;
			if(!k)   Far[v] = 0;
		}
	Vv[x] = 0;
	return fl - res;
}









