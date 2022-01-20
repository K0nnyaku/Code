---
title: AcWing380 舞动的夜晚
date: 2021-11-11 8:38:03
tags: [Tarjan, SCC, 网络流, 最大流, Dinic, 二分图最大匹配, 二分图最大匹配的必须边和可行边]
---

### [AcWing380](https://www.acwing.com/problem/content/382/)

### 代码:

```cpp
#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q) for(int i = p.Hd[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
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

const int N_ = 1e4 + 2;
const int E_ = 1e5 + 2;
const int INF = 0x3f3f3f3f;

template<typename T, int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], Pos[M << 1], Hd[N]; int cnt;
	T Val[M << 1];
	int I[N];
	Edge() { FL(Nt, 0); FL(To, 0); FL(Hd, 0); FL(Val, 0); FL(I, 0); cnt = 1; }
	void AdI(int u, int v, T w, int pos = 0) { Nt[++cnt] = I[u]; Val[cnt] = w; Pos[cnt] = pos; To[I[u] = cnt] = v; }
};
template<typename T, int N>
struct Stack {
	T A[N];
	int tp, num;
	Stack() { FL(A, 0); tp = num = 0; }
	T Tp() { return A[tp]; }
	void Pp() { num = --tp; }
	void Ph(const T& x) { A[num = ++tp] = x; }
	void Cl() { FL(A, 0); tp = num = 0; }
};

Stack<int, N_<<1 > Sk;
Edge<int, N_<<1, E_<<1> G;
int D[N_<<1], Ms[N_<<1], Fn[N_<<1], Lw[N_<<1];
int n, m, e, s, t, cnt, tot, pos;
bool Vk[N_<<1];

int Dic(int x, int fl);
void Tarjan(int x);
bool Hg();

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m >> e;
	IR(i, 1, e) {
		int u, v; IN >> u >> v;
		G.AdI(u, v+n, 1, i); G.AdI(v+n, u, 0);
	}

	IR(i, 1, n) G.AdI(0, i, 1), G.AdI(i, 0, 0);
	t = n + m + 1;
	IR(i, n+1, n+m) G.AdI(i, t, 1), G.AdI(t, i, 0);

	while(Hg()) 
		tot += Dic(s, INF);

	IR(i, 0, n+m+1) G.Hd[i] = G.I[i]; 

	IR(i, 0, n+m+1) if(!Ms[i]) 
		Tarjan(i), Sk.Cl();

	priority_queue<int> Q;
	IR(i, 1, n) ER(v, k, G, i) 
		if(G.Val[v] && Ms[i] != Ms[k] && G.Pos[v]) 
			Q.push(-G.Pos[v]);

	cout << Q.size() << "\n";
	while(Q.size()) { cout << -Q.top() << " ";  Q.pop(); }
	cout << "\n";

	return 0;
} /**/

bool Hg() {
	FL(D, 0);	   D[s] = 1;
	queue<int> Q;  Q.push(s);
	G.Hd[s] = G.I[s];

	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(int i = G.I[x], v = G.To[i]; i; i = G.Nt[i], v = G.To[i]) 
			if(G.Val[i] && !D[v]) {
				D[v] = D[x] + 1, Q.push(v), G.Hd[v] = G.I[v];
				if(v == t) return 1;
			}
	}
	return 0;
}

int Dic(int x, int fl) {
	if(x == t) return fl;
	int res = fl;
	for(int &i = G.Hd[x], v = G.To[i]; i; i = G.Nt[i], v = G.To[i]) 
		if(G.Val[i] && D[v] == D[x] + 1) {
			int k = Dic(v, min(fl, G.Val[i]));
			G.Val[i] -= k, G.Val[i^1] += k; res -= k;

			if(!res) return fl;
			if(!k) D[v] = 0;
		}
	return fl - res;
}

void Tarjan(int x) {
	Fn[x] = Lw[x] = ++pos;
	Sk.Ph(x); Vk[x] = 1;

	ER(i, v, G, x) if(G.Val[i])
		if(!Fn[v]) Tarjan(v), Lw[x] = min(Lw[x], Lw[v]);
		else if(Vk[v])		  Lw[x] = min(Lw[x], Fn[v]);

	if(Fn[x] == Lw[x] && ++cnt) {
		int y;
		do {
			y = Sk.Tp(); Sk.Pp(); Vk[y] = 0;	
			Ms[y] = cnt;
		} while(y != x);
	}
}
```
