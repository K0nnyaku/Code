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

const int N_ = 1e3 + 3;
const int K_ = 1e1 + 3;
const int INF = 0x3f3f3f3f;

template<typename T, int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	T W[M];
	Edge() { FL(I, 0); FL(Nt, 0); FL(To, 0); FL(W, 0); cnt = 1; }
	void AdN(int u, int v, T w) { 
//		printf("from %d to %d = %d\n", u, v, w);
		Nt[++cnt] = I[u]; To[cnt] = v; W[I[u]=cnt] = w; 
	}
};

Edge<int, N_*N_, N_*N_<<1> I;
int Pos[N_][N_], Far[N_*N_][K_];
int n, k, a, b, c, cnt;
bool Mp[N_*N_], Vq[N_*N_][K_];

void Spfa(int sp);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in",  "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> k >> a >> b >> c;
	int x;
	IR(i, 1, n) IR(v, 1, n) IN >> x, Pos[i][v] = ++cnt, Mp[cnt] = x;

	IR(i, 1, n) IR(v, 1, n) {
		if(i > 1) I.AdN(Pos[i][v], Pos[i-1][v], b);
		if(v > 1) I.AdN(Pos[i][v], Pos[i][v-1], b);

		if(i < n) I.AdN(Pos[i][v], Pos[i+1][v], 0);
		if(v < n) I.AdN(Pos[i][v], Pos[i][v+1], 0);
	}

	Spfa(1);

	int ans = INF;

	IR(i, 0, k) ans = min(ans, Far[cnt][i]);
	cout << ans << "\n";

	return 0;
} /**/

struct Node {
	int x, y;
	Node(int x_ = 0, int y_ = 0) { x = x_; y = y_; }
	friend bool operator<(const Node &x, const Node &y) { return Far[x.x][x.y] < Far[y.x][y.y]; }
};

void Spfa(int sp) {
	FL(Vq, 0); FL(Far, 0x3f); Far[sp][k] = 0;
	deque<Node> Q; Q.push_front(Node(sp, k));
	
	while(Q.size()) {
		int x = Q.front().x, y = Q.front().y; 
		Q.pop_front();

		Vq[x][y] = 0;
		ER(i,v,I,x,I) {
			int vtp = Far[x][y] + I.W[i] + (Mp[v] ? a : ((y==1 && v != cnt) ? a + c : 0));
			int ktp = (Mp[v] || (y==1 && v != cnt)) ? k : y-1;

			if(vtp < Far[v][ktp]) {
				Far[v][ktp] = vtp;
				if(!Vq[v][ktp] && (Vq[v][ktp] = 1)) 
					if(Q.size() && Node(v, ktp) < Q.front()) Q.push_front(Node(v, ktp));
					else									 Q.push_back (Node(v, ktp));
			}
		}
	}
}







