---
title: TreeII
date: 2022-1-2 19:41:21
tags: [数据结构, LCT, 模板]
---

### [LG1501](https://www.luogu.com.cn/problem/P1501)

### 注意Q(0) 设为0

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

const int N_ = 1e5 + 7;
const int P = 51061;

template<typename T, int N>
struct LCT {
	struct Node { 
		T vl, sm, Tg[3]; int qt, fa, Ch[2]; 
		Node(int qt_ = 1) {
			qt = qt_; 
			vl = sm = fa = Tg[0] = Tg[1] = Tg[2] = Ch[0] = Ch[1];
		}
	};
	Node Tr[N];
	LCT() { Tr[0].qt = 0; }

#define C(x, y) Tr[x].Ch[y]
#define T(x, y) Tr[x].Tg[y]
#define Q(x)    Tr[x].qt
#define V(x)    Tr[x].vl
#define S(x)    Tr[x].sm
#define F(x)    Tr[x].fa

#define W(x)   (x == C(F(x), 1))
#define Is(x)  (C(F(x),0) != x && C(F(x),1) != x)

	void Rv(int x) { swap(C(x,0), C(x,1)); T(x,2) ^= 1; }
	void Cn(int x, int y, int p) { F(x) = y; C(y, p) = x; }

	void UpV(int x) {
		S(x) = (S(C(x,0)) % P + S(C(x,1)) % P + V(x) % P) % P;
		Q(x) = (Q(C(x,0)) % P + Q(C(x,1)) % P + 1) % P;
	}
	void UpS(int x) {
		if(T(x, 2)) {
			if(C(x,0)) Rv(C(x,0));
			if(C(x,1)) Rv(C(x,1));
			T(x,2) = 0;
		}
	}
	void UpM(int x, T v) {
		v %= P;
		V(x) *= v;   V(x) %= P;   
		S(x) *= v;   S(x) %= P;
		T(x,0) *= v; T(x,0) %= P;
		T(x,1) *= v; T(x,1) %= P;
	}
	void UpA(int x, T v) { 
		v %= P;
		V(x) += v;			  V(x) %= P;
		S(x) += Q(x) % P * v; S(x) %= P;
		T(x,1) += v;		  T(x,1) %= P;
	}
	void UpT(int x) {
		UpM(C(x,0), T(x,0)); UpM(C(x,1), T(x,0));
		UpA(C(x,0), T(x,1)); UpA(C(x,1), T(x,1));
		UpS(x);
		T(x,0) = 1; T(x,1) = 0; 
	}
	void Sp(int x) { if(!Is(x)) Sp(F(x)); UpT(x); }

	void Rot(int x) {
		int u = F(x), v = F(u), p = W(x), q = W(u);
		if(!Is(u)) Cn(x, v, q); else F(x) = v;
		Cn(C(x,p^1), u, p); Cn(u, x, p^1);
		UpV(x); UpV(u);
	}
	void Sy(int x) {
		Sp(x);
		for(int y; y = F(x), !Is(x); Rot(x))
			if(!Is(y)) Rot(W(x) == W(y) ? y : x);
		UpV(x);
	}
	
	void Acc(int x) {
		for(int y = 0; x; x = F(y=x)) 
			Sy(x), C(x, 1) = y, UpV(x);
	}

	void CgRt(int x) { Acc(x); Sy(x); Rv(x); }

	void  Split(int x, int y) { CgRt(x); Acc(y); Sy(y); }

	void Cut(int x, int y) {
		Split(x, y);
		if(F(x)==y && !C(x,1)) F(x) = C(y,0) = 0, UpV(y); 
	}
	void Lk(int x, int y) {
		Split(x, y);
		if(!F(x)) F(x) = y;
	}

	Node* operator[](const int &x) { return &Tr[x]; }
};

LCT<long long, N_> Tr;
int n, q;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/P1501_1.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> q;
	IR(i, 1, n) Tr[i]->vl = Tr[i]->sm = 1;
	Ir(i, 1, n) { int u, v; IN >> u >> v; Tr.Lk(u, v); }

	while(q--) {
		int u, v, p, q;
		char opt = getchar(); ;
		switch(opt) {
			case '+': 
				IN >> u >> v >> p; 
				Tr.Split(u, v); Tr.UpA(v, p); break;
			case '-':
				IN >> u >> v >> p >> q; 
				Tr.Cut(u, v); Tr.Lk(p, q); break;
			case '*':
				IN >> u >> v >> p;
				Tr.Split(u, v); Tr.UpM(v, p); break;
			case '/':
				IN >> u >> v;
				Tr.Split(u, v); cout << Tr[v]->sm << "\n"; break;
		}
	}

	return 0;
} /**/
```
