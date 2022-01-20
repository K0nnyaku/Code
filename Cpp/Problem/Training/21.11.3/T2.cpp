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

const int N_ = 3e5 + 10;

struct Node {
	int pos, clo;
	Node(int pos_ = 0, int clo_ = 0) {
		pos = pos_, clo = clo_;
	}
} B[N_], L[N_];
int n, m, c;


int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("", "r", stdin);
	freopen("", "w", stdout);
#endif
	IN >> n >> m >> c;
	IR(i, 1, m) {
		int u, v; IN >> u >> v;
		B[i] = Node(u, v);
	}


	return 0;
} /**/










