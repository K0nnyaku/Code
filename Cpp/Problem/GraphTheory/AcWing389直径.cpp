#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)

struct FastIN {
	template<typename T>
	FastIN& operator>>(T& x) {
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x =- x;
		return *this;
	}
}IN;

const int N_ = 2e5 + 2;

template<typename T, int N, int M>
struct Edge {
	int Nt[M<<1], To[M<<1], I[N<<1]; int cnt;
	T W[M<<1];
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
	void Ad(int u, int v, T w) { Nt[++cnt] = I[u]; W[cnt] = w; To[I[u]=cnt] = v; }
};

struct Node {
	int x; long long y; 
	Node(int x_ = 0, long long y_ = 0) { x = x_; y = y_; }
};

Edge<long long, N_, N_> I;
Node Pr[N_];
long long Sm[N_];
long long dia;
int Lk[N_];
int n, ans, pt, qt, cnt;
bool Vv[N_];

void Pre(int x, long long dis);
void Wk(int x, int vlt, int wlt, long long dis);
long long Ck(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	Ir(i, 1, n) {
		int u, v; long long w;
		IN >> u >> v >> w;
		I.Ad(u, v, w); I.Ad(v, u, w);
	}

	Vv[1] = 1;  Pre(1, 0);
	FL(Vv, 0); 
	Vv[pt] = 1; Wk (pt, 0, 0, 0);
	FL(Vv, 0);

	long long sum = 0;
	int x = qt, mid = 0;
	do {
		sum += Pr[x].y;		  Vv[x] = 1;
		Lk[++cnt] = x;	Sm[cnt+1] = sum;
		if(Sm[cnt] >= dia / 2 && !mid) mid = cnt - (Sm[cnt] != dia / 2);
	} while(x != pt && (x = Pr[x].x));

	/*
	printf("pt = %d, qt = %d\n", pt, qt);
	IR(i, 1, cnt) 
		printf("Lk[%d] = %d, Sm[%d] = %lld\n", i, Lk[i], i, Sm[i]);
	cout << "cnt = " << cnt << "\n";
	cout << "mid = " << mid << "\n";
	*/

	int r = cnt, l = 1;
	cout << r - l << "\n";
	IR(i, mid, cnt) 
		if(Ck(Lk[i]) + max(Sm[i], Sm[cnt] - Sm[i]) == dia) { r = i; break; }
	Sr(i, mid, 1) 
		if(Ck(Lk[i]) + max(Sm[i], Sm[cnt] - Sm[i]) == dia) { l = i; break; }

//	cout << dia << "\n";
//	cout << r - l << "\n";

	cout << r - l << "\n";

	return 0;
} /**/

void Pre(int x, long long dis) {
	if(dis > dia) pt = x, dia = dis;
	ER(i,v,I,x,I) if(!Vv[v] && (Vv[v]=1)) 
		Pre(v, dis+I.W[i]);
}

void Wk(int x, int vlt, int wlt, long long dis) {
	if(dis > dia) qt = x, dia = dis;
	Pr[x] = Node(vlt, wlt);
	ER(i,v,I,x,I) if(!Vv[v] && (Vv[v]=1)) 
		Wk(v, x, I.W[i], dis+I.W[i]);	
}

long long Ck(int x) {
	long long tmp = 0;
	ER(i,v,I,x,I) if(!Vv[v] && (Vv[v]=1)) 
		tmp = max(tmp, Ck(v) + I.W[i]);	
	return tmp;
}









