#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define Ir(i, st, ed) for(int i = st; i < ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define Sr(i, st, ed) for(int i = st; i > ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

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

const int N_ = 1e6 + 2;

struct Edge {
	int next, to; long long val;
	Edge(int next_ = 0, int to_ = 0, long long val_ = 0) {
		next = next_, to = to_, val = val_;
	}
} E[N_ << 1];
int Head[N_];
int cnt = 1;
void Add(int from, int to, long long val) {
	E[++cnt] = Edge(Head[from], to, val);
	Head[from] = cnt;
}
#define T(i) E[i].to
#define V(i) E[i].val

struct Node {
	int pos; long long val;
	Node(int pos_ = 0, long long val_ = 0) {
		pos = pos_, val = val_;
	}
};
vector<Node> Lp[N_], Dist[N_];
long long P[N_], Dia[N_]; 
int n, bk;
bool Vis[N_];
bool flag;

void Flp(int x, int last);
long long Fdia(int x, int last);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) { 
		int v, w; IN >> v >> w;
		Add(i, v, w); Add(v, i, w);
	}

	IR(i, 1, n) if(!Vis[i])
		Flp(i, 0), bk++, flag = 0;

	memset(Vis, 0, sizeof Vis);
	Ir(i, 0, bk) Ir(v, 0, Lp[i].size()) 
		Vis[Lp[i][v].pos] = 1;

	Ir(i, 0, bk) Ir(v, 0, Lp[i].size())
		Fdia(Lp[i][v].pos, 0);

	Ir(i, 0, bk) {
		vector<int> T;
		Ir( v, 0, 2 * Lp[i].size() ) 
			T.push_back(last + v > 0 ? Lp[i][ (v-1) % Lp[i].size() ].val : 0);	

		deque<Node> Q;
		Ir( v, 0, 2 * Lp[i].size()) {
			while()<++>

		}
	}

	/*
	Ir(i, 0, bk) {
		cout << "\n============================\n";

		Ir(v, 0, Lp[i].size())
			printf("Lp[%d][%d].pos = %d, val = %lld, Dia = %lld\n", 
					i, v, Lp[i][v].pos, Lp[i][v].val, Dia[Lp[i][v].pos]);

		cout << "\n============================\n";
	}
	*/

	return 0;
} /**/

long long Fdia(int x, int last) {
	ER(i, x) if(T(i) != last && !Vis[T(i)]) {
		long long tmp = Fdia(T(i), x) + V(i);
		Dia[x] = max(Dia[x], tmp + P[x]);
		P[x] = max(P[x], tmp);
	}
	return P[x];
}

void Flp(int x, int last) {
	if(!flag) Lp[bk].push_back(Node(x, V(last)));
	printf("last = %d, V(last) = %d, flag = %d\n", 
			last, V(last), flag);
	Vis[x] = 1;

	ER(i, x) 
		if(!Vis[T(i)])			Flp(T(i), i);
		else if( (i^1) != last) flag = 1, Lp[bk][0] = Node(x,  V(i));

	if(!flag) Lp[bk].pop_back();
}














