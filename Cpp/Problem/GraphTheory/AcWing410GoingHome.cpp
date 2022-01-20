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

const int N_ = 1e2 + 2;
const int E_ = 7e5 + 2;
const int INF = 0x3f3f3f3f;

template<typename T, int N, int M>
struct Edge {
	int Nt[M<<1], To[M<<1], I[M<<1], H[M<<1]; int cnt;
	T W[M<<1], C[M<<1];
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); FL(H, 0); cnt = 1; }
	void AdI(int u, int v, T c, T w) {
		Nt[++cnt] = I[u]; C[cnt] = c; W[cnt] = w;  To[I[u]=cnt] = v;
		Nt[++cnt] = I[v]; C[cnt] = 0; W[cnt] = -w; To[I[v]=cnt] = u;
	}
	void Cl() { FL(Nt, 0); FL(To, 0); FL(I, 0); FL(H, 0); cnt = 1; }
};

int Abs(int x) { return x < 0 ? -x : x; }
struct Node {
	int x, y;
	Node(int x_ = 0, int y_ = 0) { x = x_; y = y_; }
	friend int operator-(const Node &x, const Node &y) {
		return Abs(x.x - y.x) + Abs(x.y - y.y);
	}
};

vector<Node>H, M;
Edge<int, N_*N_, E_> I;
int Far[N_*N_]; 
int n, m, ct, s, t;
bool Vv[N_*N_], Vq[N_*N_];

bool Spfa();
int Dic(int x, int fl);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;

	do {
		I.Cl(); FL(Far, 0); FL(Vv, 0); FL(Vq, 0);
		H.clear(); M.clear();
		ct = 0; 
		IR(i, 1, n) {
			IR(v, 1, m) {
				char ch = getchar();
				if(ch == 'H')	   H.push_back(Node(i, v));
				else if(ch == 'm') M.push_back(Node(i, v));
			}
			getchar();
		}
		/*
		Ir(i, 0, M.size()) 
			printf("M[%d] = %d %d\n", i, M[i].x, M[i].y);
		Ir(i, 0, H.size()) 
			printf("H[%d] = %d %d\n", i, H[i].x, H[i].y);
		*/
//		Ir(i, 0, M.size()) Ir(v, 0, H.size())
//			printf("i = %d, v = %d, H[v]-M[i] = %d\n", 
//					i, v, H[v]-M[i]);
		
		Ir(i, 0, M.size()) Ir(v, 0, H.size())
			I.AdI(i+1, v+M.size()+1, 1, M[i]-H[v]);
	//		printf("i + 1 = %d, v + M.size() + 1 = %d\n", i+1, v + M.size() + 1);

		s = 0, t = M.size() + H.size() + 1;
		Ir(i, 0, M.size()) I.AdI(s, i+1, 1, 0);
		Ir(i, 0, H.size()) I.AdI(i+M.size()+1, t, 1, 0);
		
		while(Spfa()) 
			FL(Vv, 0), Dic(s, INF);

		cout << ct << "\n";

		IN >> n >> m;
	}while(n + m);

	return 0;
} /**/

bool Spfa() {
	FL(Vq, 0);	    Vq[s] = 1;
	FL(Far, 0x3f);  Far[s] = 0;
	deque<int> Q;   Q.push_back(s);
	I.H[s] = I.I[s];

	while(Q.size()) {
		int tp = Q.front(); Q.pop_front();
		Vq[tp] = 0;
		ER(i,v,I,tp,I) if(Far[v] > Far[tp] + I.W[i] && I.C[i]) {
			Far[v] = Far[tp] + I.W[i];
			I.H[v] = I.I[v];
			if(!Vq[v]) 
				if(Q.size() && Far[v] <= Far[Q.front()]) Q.push_front(v);
				else									 Q.push_back(v);
		}
	}
	
	return Far[t] != INF;
}

int Dic(int x, int fl) {
	if(x == t) return fl;
	int res = fl; Vv[x] = 1;
	for(int &i = I.H[x], v = I.To[i]; i; i = I.Nt[i], v = I.To[i]) {
		if(Far[v] == Far[x] + I.W[i] && !Vv[v] && I.C[i]) {
			int k = Dic(v, min(res, I.C[i]));

			I.C[i] -= k; I.C[i^1] += k; 
			res -= k;    ct += k * I.W[i];

			if(!res) return fl;
			if(!k) Far[v] = 0;
		}

	}
	return fl - res;
}









