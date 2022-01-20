---
title: AcWing325 计算机
date: 2021-10-31 11:35:49
tags: [dp, 树形dp, 换根, 二次扫描]
---

### [AcWing325](https://www.acwing.com/problem/content/description/327/)

### F[x][0/1] 和 Pos[x]

### 自下而上: F[x][0/1] 以1为根时的值

### 自上而下: F[x][0/1] 以x为根, 最大和次大值

### Pos[x] 以x为根, x的最大值从哪一个子树更新

``cpp
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

vector<int> P[N_], Qp[N_], Qs[N_];
int Mk[N_], F[N_], Pos[N_];
int n;

int Pre(int x, int last);
void Wk(int x, int last);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif
	

	return 0;
} /**/

int Pre(int x, int last) {
	int mx = 0;
	ER(i, x) {
		if(T(i) == last) continue;

		P[x].push_back( Pre(T(i), x) + V(i) );
		Pos[T(i)] = P[x].size() - 1;

		if(P[x].back() > mx) 
			mx = P[x].back(), Mk[x] = T(i);

		Qp[x].push_back(mx);
	}

	Qs[x].resize(P[x].size());
	SR(i, P[x].size()-1, 0) 
		Qs[x][i] = max(i < P[x].size()-1 ? Qs[x][i+1] : 0, P[x][i]);

	if(!P[x].size()) return 0;
	return mx;
}

void Wk(int x, int last) {
	ER(i, x) {
		if(T(i) == last) continue;

		int p = Pos[T(i)];
		F[T(i)] = Qp[x].size() ? max(p > 0 ?				Qp[x][p-1] : 0, 
									 p < Qs[x].size() - 1 ? Qs[x][p+1] : 0) : 0 + V(i);

		printf("F[%d] = %d\n", T(i), F[T(i)]);
		/*
		printf("-------------------------\n");
		printf("Qp[%d].size() = %d\n", x, Qp[x].size());
		printf("Qs[%d].size() = %d\n", x, Qs[x].size());
		printf("F[%d] = %d\n", T(i), F[T(i)]);
		printf("\n-------------------------\n");
		*/

		if(Mk[x] != T(i)) F[T(i)] = max(F[T(i)], F[x] + V(i));

		Wk(T(i), x);
	}
}
```
