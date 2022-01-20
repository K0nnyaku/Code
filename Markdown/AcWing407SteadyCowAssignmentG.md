---
title: AcWing407 Steady Cow Assignment G
date: 2021-11-16 20:50:12
tags: [图论, 二分图, 二分图匹配, 二分图多重匹配, 最大流, 网络流, Dinic]
---

### [AcWing407](https://www.acwing.com/problem/content/409/)

### 双指针

### 代码
```cpp
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

const int N_ = 1e3 + 2;
const int M_ = 20 + 2;
const int INF = 0x3f3f3f3f;

template<typename T, int N, int M>
struct Edge {
	int Nt[M<<1], To[M<<1], I[N], H[N]; int cnt;
	T C[M<<1];
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); FL(H, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, T c) {
		Nt[++cnt] = I[u]; C[cnt] = c; To[I[u]=cnt] = v;
		Nt[++cnt] = I[v]; C[cnt] = 0; To[I[v]=cnt] = u;
	}
	void Cl() { FL(Nt, 0); FL(To, 0); FL(I, 0); FL(H, 0); FL(C, 0); cnt = 1; }
};

Edge<int, N_+M_, N_*M_> I; 
int Lm[N_], A[N_][M_], Far[N_+M_];
int n, m, s, t;
bool Vq[N_];

int Dic(int x, int fl);
bool Hg();
bool Ck(int l, int r);

int main() { /**/
#ifdef LOCAL
//	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/P2857_4.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) IR(v, 1, m) IN >> A[i][v];
	IR(i, 1, m)				IN >> Lm[i];

	int ans = INF;
	int l = 1, r = 1;
	do {
		bool fg = 0;
		while(!(fg = Ck(l, r)) && r < m) r++;
		if(fg) ans = min(ans, r - l + 1);
	}while(++l <= m);

	cout << ans;

	return 0;
} /**/

bool Hg() {
	queue<int> Q; Q.push(s);
    FL(Far, 0); Far[s] = 1; 
	I.H[s] = I.I[s]; 
	while(Q.size()) {
		int tp = Q.front(); Q.pop();
		ER(i,v,I,tp,I) if(!Far[v] && I.C[i]) {
			Far[v] = Far[tp]+1, I.H[v] = I.I[v], Q.push(v);
			if(v == t) return 1;
		}
	}
	return 0;
}

int Dic(int x, int fl) {
	if(x == t) return fl;
	int res = fl;
	for(int &i = I.H[x], v = I.To[i]; i; i = I.Nt[i], v = I.To[i]) 
		if(I.C[i] && Far[v] == Far[x] + 1) {
			int k = Dic(v, min(res, I.C[i]));
			I.C[i] -= k; I.C[i^1] += k; res -= k;

			if(!res) return fl;
			if(!k) Far[v] = 0;
		}
	return fl - res;
}

bool Ck(int l, int r) {
	I.Cl(); s = 0; t = n + m + 1;
	IR(i, 1, m)				I.AdI(s, i, Lm[i]);

	IR(i, 1, n)				I.AdI(i+m, t, 1);

	IR(i, 1, n) IR(v, l, r) I.AdI(A[i][v], i+m, 1);

	int res = 0;
	while(Hg())
		res += Dic(s, INF);

	return res == n;
}
```
