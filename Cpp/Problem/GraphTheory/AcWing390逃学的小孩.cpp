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

const int N_ = 2e5 + 2;

template<typename T, int N, int M>
struct Edge {
	int Nt[M<<1], To[M<<1], I[N]; int cnt;
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
long long dia;
int n, m, pr, qr;
bool Vv[N_];

void Wkp(int x, long long dis) {
	if(dis > dia) dia = dis, pr = x;
	ER(i,v,I,x,I) if(!Vv[v] && (Vv[v]=1)) 
		Wkp(v, dis+I.W[i]);
}
void Wkq(int x, int vlt, long long wlt, long long dis) {
	if(dis >= dia) dia = dis, qr = x;
	Pr[x] = Node(vlt, wlt);
	ER(i,v,I,x,I) if(!Vv[v] && (Vv[v]=1)) 
		Wkq(v, x, I.W[i], dis+I.W[i]);
}
long long Wkx(int x) {
	long long tmp = 0;
	ER(i,v,I,x,I) if(!Vv[v] && (Vv[v]=1))
		tmp = max(tmp, Wkx(v) + I.W[i]);
	return tmp;
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	Ir(i, 1, n) {
		int u, v; long long w;
		IN >> u >> v >> w;
		I.Ad(u, v, w); I.Ad(v, u, w);
	}

	Vv[1] = 1;  Wkp(1, 0);
	FL(Vv, 0);
	Vv[pr] = 1; Wkq(pr, 0, 0, 0);
	FL(Vv, 0);

	int y = qr;
	do 
		Vv[y] = 1;
	while(y != pr && (y = Pr[y].x));

	int x = qr; long long sum = 0, ans = 0;
	do 
		ans = max(ans, min(sum, dia-sum) + Wkx(x) + dia);
	while(x != pr && (sum += Pr[x].y) && (x = Pr[x].x));

	cout << ans << "\n";

	return 0;
} /**/











