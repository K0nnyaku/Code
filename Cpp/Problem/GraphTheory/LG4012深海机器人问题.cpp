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

const int N_ = 15 + 3;
const int M_ = 2 * N_ * N_;
const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;

template<typename T, int N, int M>
struct Edge {
	int I[N], H[N], Nt[M], To[M]; int cnt;
	T C[M], W[M];
	Edge() { FL(I, 0); FL(H, 0); FL(Nt, 0); FL(To, 0); FL(C, 0); FL(W, 0); cnt = 1; }
	
	void AdI(int u, int v, T c, T w) {
#ifdef Debug
		printf("From %d to %d, c = %d, w = %d\n", u, v, c, w);
#endif
		Nt[++cnt] = I[u]; C[cnt] = c; W[cnt] =  w; To[I[u]=cnt] = v;
		Nt[++cnt] = I[v]; C[cnt] = 0; W[cnt] = -w; To[I[v]=cnt] = u;
	}	
};

Edge<int, N_, M_<<1> I;

int Mp[N_][N_], Pos[N_][N_];
int n, m, og, sk, ans, cnt, a, b;
bool Vv[N_], Vq[N_];

void MkP(int x);
bool Spfa();
int Dic(int fl, int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> a >> b;

	IR(i, 1, n) IR(v, 1, m) IN >> Mp[i][v], Pos[i][v] = cnt++;
	Ir(i, 1, n) Ir(v, 1, m) {
		I.AdI(Pos[i][v], Pos[i+1][v], )<++>
	}

	og = 0; sk = cnt+1;
	IR(i, 1, a) {
		int k, x, y; IN >> k >> x >> y;
		I.AdI(og, Pos[x+1][y+1], k, 0);
	}
	IR(i, 1, b) {
		int k, x, y; IN >> k >> x >> y;
		I.AdI(Pos[x+1][y+1], sk, k, 0);
	}





	return 0;
} /**/

bool Spfa() {
	FL(Far, 0xcf); FL(Vq, 0);
	
	memcpy(I.H, I.I, sizeof I.I);
	deque<int> Q; Q.push_front(og);
	
	Far[og] = 0; 
	
	while(Q.size()) {
		int tp = Q.front(); Q.pop_front();
		Vq[tp] = 0;
		
		ER(i,v,I,tp,I) 
			if(I.C[i] && Far[v] < Far[tp] + I.W[i]) {
				Far[v] = Far[tp] + I.W[i];
				if(!Vq[v])
					if(Q.size() && Far[v] > Far[Q.front()]) Q.push_front(v);
					else 									Q.push_back (v);
			}
	}
	return Far[sk] != NINF;
} 

int Dic(int fl, int x) {
	if(x == sk) return fl;
	int res = fl; Vv[x] = 1;
	
	ER(i,v,I,x,H) 
		if(I.C[i] && !Vv[v] && Far[v] == Far[x] + I.W[i]) {
			int k = Dic(min(res, I.C[i]), v);
			
			I.C[i] -= k; I.C[i^1] += k;
			I.H[x] = i;
			ans += k * I.W[i]; res -= k;    
			
			if(!res) return fl;
			if(!k) Far[v] = NINF;
		}
	Vv[x] = 0;
	return fl - res;
}





