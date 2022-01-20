#include<bits/stdc++.h>
using namespace std;
#define IR(x,y,z) for(int x = y; x <= z; x++)
#define Ir(x,y,z) for(int x = y; x < z; x++)
#define SR(x,y,z) for(int x = y; x >= z; x--)
#define Sr(x,y,z) for(int x = y-1; x >= z; x--)
#define ER(i,v,I,x,k) for(int i = I.k[x], v = I.To[i]; i; i = I.Nt[i], v = I.To[i])
#define FL(x, y) memset(x, y, sizeof x)

struct FastIN {
	template<typename T>
	FastIN& operator>>(T &x) {
		char c, l;
		for(c = 0; !isdigit(c); c = getchar()) l = c;
		for(x = 0; isdigit(c);  c = getchar()) x = x * 10 + c - '0';
		if(l == '-') x = -x;
		return *this;
	}
}IN;

const int N_ = 1e2 + 10;
const int M_ = N_ * N_ + 10; 
const long long INF = 0x3f3f3f3f3f3f3f3f;

template<typename T, int N, int M> 
struct Edge {
	int Nt[M_<<1], To[M<<1], I[M<<1], H[M<<1]; int cnt;
	T W[M<<1], C[M<<1];
	Edge()    { FL(Nt, 0); FL(I, 0); FL(H, 0); FL(W, 0); FL(C, 0); cnt = 1; }
	void Cl() { FL(Nt, 0); FL(I, 0); FL(H, 0); FL(W, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c, T w) {
		Nt[++cnt] = I[u]; C[cnt] = c; W[cnt] =  w; To[I[u]=cnt] = v; 
		Nt[++cnt] = I[v]; C[cnt] = 0; W[cnt] = -w; To[I[v]=cnt] = u; 
	} 
};

Edge<long long, N_, M_> I, G;
long long Far[N_];
long long ans; 
int n, m, st, ed;
bool Vd[N_], Vq[N_];

template<typename T, int N, int M>
bool Spfa(Edge<T,N,M> &);
template<typename T, int N, int M>
long long Dic(Edge<T, N, M> &, long long fl, int x);

int main() { /**/
	
	IN >> m >> n; 
	st = 0, ed = n+m+1;
	IR(i, 1, m) {
		long long x; IN >> x;
		I.AdI(st, i, x, 0);
		G.AdI(st, i, x, 0);
	} 
	
	IR(i, 1, n) {
		long long x; IN >> x;
		I.AdI(i+m, ed, x, 0);
		G.AdI(i+m, ed, x, 0);
	}
	
	IR(i, 1, m) IR(v, 1, n) {
		long long x; IN >> x;
		I.AdI(i, v+m, 0x3f3f3f3f, x);
		G.AdI(i, v+m, 0x3f3f3f3f, -x);
	}

	while(Spfa(I)) 
		FL(Vd, 0), Dic(I, 0x3f3f3f3f, st);

	cout << ans << "\n";
	
	ans = 0;
	
	while(Spfa(G)) 
		FL(Vd, 0), Dic(G, 0x3f3f3f3f, st);
	
	cout << -ans << "\n"; 

	return 0;
} /**/

template<typename T, int N, int M>
bool Spfa(Edge<T, N, M> &I) {
	FL(Far, 0x3f); FL(Vq, 0);
	
	memcpy(I.H, I.I, sizeof I.I);
	queue<int> Q; Q.push(st);
	
	Far[st] = 0;
	
	while(Q.size()) {
		int tp = Q.front(); Q.pop();
		
		Vq[tp] = 0;
		
		ER(i,v,I,tp,I) {
			//printf("Try %d to %d\n", tp, v);
			if(I.C[i] && Far[v] > Far[tp] + I.W[i]) {
				//printf("~~~Iteration from %d to %d\n", tp, v);
				Far[v] = Far[tp] + I.W[i];
				if(!Vq[v]) Q.push(v);
			}	
		}
				
	}

	return Far[ed] != INF;
}

template<typename T, int N, int M>
long long Dic(Edge<T,N,M> &I, long long fl, int x) {
	if(x == ed) return fl;
	long long res = fl; 
	Vd[x] = 1;
	
	ER(i,v,I,x,H)
		if(!Vd[v] && I.C[i] && Far[v] == Far[x] + I.W[i]) {
			long long k = Dic(I, min(res, I.C[i]), v);
			
			res -= k; ans += k * I.W[i];	
			I.H[x] = i;
			I.C[i] -= k; I.C[i^1] += k;
			
			if(!res) return fl;
			if(!k) Far[v] = 0;
		}
	Vd[x] = 0;
	return fl - res;
}




