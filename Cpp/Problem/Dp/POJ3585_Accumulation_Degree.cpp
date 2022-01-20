//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;

struct Edge {
	int next, to, val;
	Edge(int _next  = 0, int _to = 0, int _val = 0) {
		next = _next; to = _to; val = _val;
	}
}E[MAXN << 1];
int Head[MAXN];
int cnt;
void Add(int from, int to, int val) {
	E[++cnt] = Edge(Head[from], to, val);
	Head[from] = cnt;
}

int T;
int P[MAXN], F[MAXN], Deg[MAXN];

void Init();
void Pre(int x, int last);
void Wk(int x, int last);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\AC.out", "w", stdout);
#endif
	IN >> T;
	while(T--) {
		int n; IN >> n;
		Init();
		IOR(i, 1, n) {
			int u, v, w; IN >> u >> v >> w;
			Add(u, v, w); Add(v, u, w);
			Deg[u]++; Deg[v]++;
		}

		Pre(1, 0);
		F[1] = P[1];
		Wk(1, 0);

		IOR(i, 1, n+1) F[1] = max(F[1], F[i]);

		cout << F[1] << "\n";
	}


	return 0;
} /**/

void Init() {
	memset(F, 0, sizeof F);
	memset(P, 0, sizeof P);
	memset(Head, 0, sizeof Head);
	memset(Deg, 0, sizeof Deg);
	cnt = 0;
	IOR(i, 0, MAXN<<1) E[i] = Edge();
}

void Pre(int x, int last) {
	EOR(i, x) {
		if(T(i) == last) continue;

		Pre(T(i), x);

		if(E[Head[T(i)]].next) 
			P[x] += min(P[T(i)], V(i));
		else 
			P[x] += V(i);
	}
}

void Wk(int x, int last) {
	EOR(i, x) {
		if(T(i) == last) continue;

		if(Deg[x] == 1) 
			F[T(i)] = P[T(i)] + V(i);
		else if(Deg[T(i)] != 1) 
			F[T(i)] = P[T(i)] + min(F[x] - min(P[T(i)], V(i)), V(i));
		else
			F[T(i)] = V(i);

		Wk(T(i), x);
	}
}











