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

const int N_ = 1365 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;

template<typename T, int N, int M>
struct Edge {
	int I[N], H[N], Nt[M], To[M]; int cnt;
	T C[M];
	Edge()    { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(To, 0); FL(C, 0); cnt = 1; }
	void Cl() { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(To, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c) {
		Nt[++cnt] = I[u]; To[cnt] = v; C[I[u]=cnt] = c; 
		Nt[++cnt] = I[v]; To[cnt] = u; C[I[v]=cnt] = 0; 
	}
};

Edge<long long, N_, (N_*300)<<1> I;
long long Far[N_], In[N_], Out[N_];
int og, sk, n, m, go, ks;
bool Vv[N_<<1];

bool Pre(int og, int sk);
long long Dic(long long fl, int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	while(~scanf("%d%d", &n,&m)) {
		I.Cl();
		FL(Far, 0); FL(In, 0); FL(Out, 0); FL(Vv, 0);

		og = 0,    sk = n+m+1;
		go = sk+1, ks = sk+2;

		IR(i, 1, m) {
			long long x; IN >> x;
			I.AdI(n+i, sk, INF-x);
			In[sk] += x; Out[n+i] += x;
		}

		IR(i, 1, n) {
			int c; long long d;
			IN >> c >> d;
			I.AdI(og, i, d);

			IR(v, 1, c) {
				int t, l, r; IN >> t >> l >> r;
				Out[i] += l; In[n+t+1] += l;
				I.AdI(i, n+t+1, r-l);
			}
		}

		long long sum = 0;
		IR(i, 0, n+m+1) {
			if(In[i] > Out[i]) I.AdI(go, i, In[i]-Out[i]), sum += In[i]-Out[i];
			if(In[i] < Out[i]) I.AdI(i, ks, Out[i]-In[i]);
		}
		I.AdI(sk, og, INF);

		long long tmp = 0;
		while(Pre(go, ks)) 
			tmp += Dic(INF, go);

		if(tmp != sum) { cout << "-1\n\n";  continue; }
		
		tmp = I.C[I.cnt];
		I.C[I.cnt] = 0, I.C[I.cnt^1] = 0;

		while(Pre(og, sk)) 
			tmp += Dic(INF, og);

		cout << tmp << "\n\n";
	}

	return 0;
} /**/

bool Pre(int og, int sk) {
	FL(Far, 0); Far[og] = 1;
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
	ER(i,v,I,x,H) 
		if(I.C[i] && Far[v] == Far[x]+1) {
			int k = Dic(min(res, I.C[i]), v);
		
			I.C[i] -= k; I.C[i^1] += k;
			I.H[x] = i;  res -= k;

			if(!res) return fl;
			if(!k)   Far[v] = 0;
		}
	return fl - res;
}









