---
title: Acwing401
date: 2021-11-16 14:49:01
tags: [图论, Tarjan, SCC, 拓扑排序, 缩点]
---

### [AcWing401](https://www.acwing.com/problem/content/description/403/)

### 对于缩点后的DAG, 考虑若拓扑排序的过程中同时有复数点入队, 他们互不可达

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
const int M_ = 6e3 + 2;

template<int N, int M>
struct Edge {
	int Nt[M<<1], To[M<<1], I[N]; int cnt;
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
	void Ad(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
	void Cl() { FL(Nt, 0); FL(To, 0); FL(I, 0); cnt = 1; }
};

template<typename T, int N>
struct Stack {
	T A[N]; int num, tp;
	Stack() { FL(A, 0); num = tp = 0; }
	T Tp() { return A[tp]; }
	int Num() { return num; }
	void Pp() { num = --tp; }
	void Ph(const T&x) { A[num=++tp] = x; }
	void Cl() { FL(A, 0); num = tp = 0; }
};

Stack<int, N_> Sk;
Edge<N_, M_> I, S;
vector<int> Scc[N_];
int Fn[N_], Lw[N_], Msc[N_], In[N_];
int n, m, t, cnt, pos;
bool Vsk[N_];

void Tarjan(int x);
bool Topo(int s);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> t;
	while(t--) {
		I.Cl();  S.Cl(); Sk.Cl();
		FL(Fn, 0); FL(Lw, 0); FL(Msc, 0);
		FL(Vsk, 0);
		pos = 1; cnt = 0;

		IN >> n >> m;
		IR(i, 1, m) {
			int u, v; IN >> u >> v;
			I.Ad(u, v);
		}

		int flag = 0;
		IR(i, 1, n) if(!Fn[i]) 
			if(flag) { flag = 2; cout << "No\n"; break; }
			else flag = 1, Tarjan(i);
			
		if(flag == 2) continue; 

		IR(i,1,n) ER(k,v,I,i,I) 
			if(Msc[i] != Msc[v]) S.Ad(Msc[i], Msc[v]), In[Msc[v]]++;

		flag = 0; int tmp = 0;
		IR(i, 1, cnt) if(!In[i])
			if(flag) { flag = 2; cout << "No\n"; break; }
			else flag = 1, tmp = i;

		if(flag == 2) continue;

		if(Topo(tmp)) 
			cout << "No\n";
		else 
			cout << "Yes\n";
	}

	return 0;
} /**/

void Tarjan(int x) {
	Sk.Ph(x); Vsk[x] = 1;
	Lw[x] = Fn[x] = ++pos;

	ER(i,v,I,x,I) 
		if(!Fn[v]) Tarjan(v), Lw[x] = min(Lw[x], Lw[v]);
		else if(Vsk[v])		  Lw[x] = min(Lw[x], Fn[v]);

	if(Fn[x] == Lw[x]) {
		int y = Sk.Tp(); ++cnt;
		do {
			Scc[cnt].push_back(y); Msc[y] = cnt;	
			Sk.Pp();			   Vsk[y] = 0;
		}while(y != x && (y = Sk.Tp()));
	}
}

bool Topo(int s) {
	int x = s;
	Ir(i,1,cnt) {
		int flag = 0;
		ER(i,v,S,x,I) {
			In[v]--; 
			if(!In[v]) x = v, flag++;
			if(flag > 1) return true;
		}
	}
	IR(i, 1, cnt) if(In[i]) return true;
	return false;
}
```
