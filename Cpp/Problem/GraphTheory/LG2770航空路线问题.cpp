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

const int N_ = 2e2 + 5;
const int M_ = 5e3 + N_ + 5; 
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
unordered_map<string, int> Mp;
vector<int> W;
string Nm[N_];
int Far[N_];
int n, m, og, sk, ans, fg;
bool Vv[N_], Vq[N_];

void MkP(int x);
bool Spfa();
int Dic(int fl, int x);

int main() { /**/

#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif

	IN >> n >> m;
	IR(i, 1, n) {
		string S; cin >> S;
		Mp[S] = i; Nm[i] = S;
	}
	
	og = 1; sk = n * 2; 
	IR(i, 1, n) I.AdI(i, i+n, 1+(i==n || i==1), (i!=1 && i!=n));

	IR(i, 1, m) {
		string S, SS; cin >> S >> SS;
		int u = Mp[S], v = Mp[SS];
		if(u > v) swap(u, v);
		I.AdI(u+n, v, 1, 0);
	}

	while(Spfa()) 
		FL(Vv, 0), Dic(INF, og);
		
	FL(Vv, 0);
	MkP(og);
	
	if(fg == 1) { 
		cout << ans + 2 << "\n";
		Ir(i, 0, W.size()) if(W[i] >= 1 && W[i] <= n) 
			cout << Nm[W[i]] << "\n"; 
		cout << Nm[1] << "\n"; 
	}
	else		 cout << "No Solution!\n";
	
} /**/

void MkP(int x) {
	if(x == og) fg++;
	W.push_back(x);
	ER(i,v,I,x,I) {
#ifdef Debug
		printf("x = %d, v = %d, I.C[i] = %d\n", x, v, I.C[i]);
#endif
		if(!I.C[i] && !Vv[v] && (Vv[v] = 1))
			MkP(v);
	}
}

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








