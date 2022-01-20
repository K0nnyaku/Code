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

const int N_ = 1e5 + 7;
const int M_ = 1e5 + 7;

long long W[N_];
int n, m, r, P;

template<int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	Edge() { FL(I, 0); FL(Nt, 0); FL(To, 0); cnt = 1; }
	void Add(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
};

template<typename T, int N>
struct FenWickSS {
	struct FenWickPS {
		T A[N];	
		FenWickPS() { FL(A, 0); }
		T AkP(int x) {
			T res = 0;
			while(x) res += A[x], x -= x & -x, res %= P;
			return res % P;
		}
		T AkS(int l, int r) { return ( AkP(r) - AkP(l-1) )% P; }
		void CgP(int x, T y) { while(x < N) A[x] += y, x += x & -x, y %= P; }
	};

	FenWickPS S, C;
	T Sm[N];

	FenWickSS() { FL(Sm, 0); }
	
	T AkS(int l, int r) {
		return ( (Sm[r] % P + (r+1) * S.AkP(r) % P - C.AkP(r) % P + P) % P
						- (Sm[l-1] % P + l * S.AkP(l-1) % P - C.AkP(l-1) % P + P) % P) % P;
	}
	void CgS(int l, int r, T v) {
		S.CgP(l, v);   S.CgP(r+1, -v);
		C.CgP(l, v*l); C.CgP(r+1, -(r+1)*v);
	}
	T& operator[](const int &x) { return Sm[x]; }
};

template<typename T, int N, int M>
struct LNCT {
	Edge<N, M> I;	
	FenWickSS<T, N> Fk;

	int Am[N], Sn[N], As[N], Ep[N], Fn[N], Mp[N], Tp[N];
	int pos, rt;

	LNCT(int rt_ = 1) { FL(Am, 0); FL(Sn, 0); FL(As, 0); FL(Ep, 0); FL(Fn, 0); FL(Mp, 0); FL(Tp, 0); pos = 0; rt = rt_; }
	
	void FdAm(int x, int y) {
		Am[x] = 1; As[x] = y;
		Ep[x] = Ep[y]+1;

		ER(i,v,I,x,I) if(v != y) {
			FdAm(v, x); Am[x] += Am[v];
			if(Am[v] > Am[Sn[x]]) Sn[x] = v;
		}
	}
	void FdTp(int x, int tp) {
		Tp[x] = tp; Fn[x] = ++pos; Mp[pos] = x;
		
		if(Sn[x]) FdTp(Sn[x], tp);

		ER(i,v,I,x,I) if(v != As[x] && v != Sn[x]) FdTp(v, v);
	}
	void Pre(int rt_, long long *W, int n) { 
		rt = rt_; FdAm(rt, 0); FdTp(rt, rt); 
		IR(i, 1, n) Fk.CgS(Fn[i], Fn[i], W[Mp[Fn[i]]]);
	}

	void CgRd(int x, int y, T z) {
		while(Tp[x] != Tp[y]) {
			if(Ep[Tp[x]] < Ep[Tp[y]])	 swap(x, y);
			Fk.CgS(Fn[Tp[x]], Fn[x], z); x = As[Tp[x]];
		}
		if(Ep[x] < Ep[y]) swap(x, y);
		Fk.CgS(Fn[y], Fn[x], z);
	}
	void CgSn(int x, T z) { Fk.CgS(Fn[x], Fn[x]+Am[x]-1, z); }

	T AkRd(int x, int y) {
		T res = 0;
		while(Tp[x] != Tp[y]) {
			if(Ep[Tp[x]] < Ep[Tp[y]]) swap(x, y);
			res += Fk.AkS(Fn[Tp[x]], Fn[x]); res %= P;
			x = As[Tp[x]];
		}
		if(Ep[x] < Ep[y]) swap(x, y);
		res += Fk.AkS(Fn[y], Fn[x]);

		return res % P;
	}
	T AkSn(int x) { return Fk.AkS(Fn[x], Fn[x]+Am[x]-1); }
};

LNCT<long long, N_, M_<<1> T;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> r >> P;

	IR(i, 1, n) IN >> W[i];
	Ir(i, 1, n) {
		int u, v; IN >> u >> v;
		T.I.Add(u, v); T.I.Add(v, u);
	}
	T.Pre(r, W, n);

	while(m--) {
		int opt, x, y; long long z; 
		IN >> opt;

		switch(opt) {
			case 1: IN >> x >> y >> z; 
					T.CgRd(x, y, z);              break;

			case 2: IN >> x >> y;      
					cout << T.AkRd(x, y) << "\n"; break;

			case 3: IN >> x >> y;
					T.CgSn(x, y);				  break;

			case 4: IN >> x; 
					cout << T.AkSn(x)	 << "\n"; break; 
		}
	}


	return 0;
} /**/









