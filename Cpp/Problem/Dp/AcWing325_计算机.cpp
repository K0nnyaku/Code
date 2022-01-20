#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x = -x;
		return *this;
	}
} IN;
const int N_ = 1e4 + 2;

struct Edge {
	int next, to, val; } E[N_ << 1];
int Head[N_];
int cnt;
void Add(int from, int to, int val) {
	E[++cnt] = { Head[from], to, val };
	Head[from] = cnt;
}
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)
#define V(i) E[i].val
#define T(i) E[i].to

int F[N_][2], Pos[N_];
int n;

int Pre(int x, int last);
void Wk(int x, int last);
void Init();

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif
	while(scanf("%d", &n) != EOF) {
		Init();

		IR(i, 2, n) {
			int u, w; IN >> u >> w;
			Add(u, i, w); Add(i, u, w);
		}

		Pre(1, 0);
		Wk(1, 0);

		IR(i, 1, n) 
			printf("%d\n", F[i][0]);
	}


	return 0;
} /**/

int Pre(int x, int last) {
	int mx = 0, mxx = 0;
	ER(i, x) if(T(i) != last) {
		int tmp = Pre(T(i), x) + V(i);

		if(tmp >= mx) 
			mxx = mx, mx = tmp, Pos[x] = T(i);
		else if(tmp > mxx) mxx = tmp;
	}

	F[x][0] = mx, F[x][1] = mxx;
	return mx;
}

void Wk(int x, int last) {
	ER(i, x) if(T(i) != last) {
		if(T(i) != Pos[x]) 
			if(F[x][0] + V(i) >= F[T(i)][0])
				F[T(i)][0] = F[x][0] + V(i),
				F[T(i)][1] = F[T(i)][0],
				Pos[T(i)] = x; 
			else
				F[T(i)][1] = max(F[T(i)][1], F[x][0] + V(i));
		else 
			if(F[x][1] + V(i) >= F[T(i)][0]) 
				F[T(i)][0] = F[x][1] + V(i),
				F[T(i)][1] = F[T(i)][0],
				Pos[T(i)] = x;
			else
				F[T(i)][1] = max(F[T(i)][1], F[x][1] + V(i));
		Wk(T(i), x);
	}
}

void Init() {
	memset(F, 0, sizeof F);
	memset(E, 0, sizeof E);
	memset(Head, 0, sizeof Head);
	memset(Pos, 0, sizeof Pos);
	cnt = 0;
}

























