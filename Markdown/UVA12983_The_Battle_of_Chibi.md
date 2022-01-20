---
title: UVA12983
date: 2021-10-25 16:18:29
tags: [dp, 数据结构, 树状数组]
---

### [UVA12983](https://vjudge.net/problem/UVA-12983)

### 解
* ### 状态: $F[i][v]$ 以$A_v$结尾, 长度为$i$的LIS种类数
* ### 转移: $F[i][v] = \sum\limits_{1\le k \le v \And A[k] < A[v]}F[i-1][k] $
* ### 边界: $F[1][i] = 1$
* ### 外层枚举$i$, 内层枚举$v$, 树状数组维护离散化后每个数值对应答案的前缀和

### 代码
```cpp
#include<bits/stdc++.h>
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

const int _N = 1e3 + 10;
const int _M = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct FenWick {
	long long Tr[_N];
	void Init();
	void Cg(int x, long long val);
	long long Ask(int l, int r); 
}B;

long long F[_M][_N], A[_N], Q[_N], Pos[_N];
long long t, n, m, idx, cnt;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> t;
	while(t--) {
		IN >> n >> m;
		IOR(i, 1, n+1) IN >> A[i], Q[i] = A[i];

		//离散化
		sort(Q, Q+n+1);
		idx = unique(Q+1, Q+n+1) - Q;
		IOR(i, 1, n+1) Pos[i] = lower_bound(Q+1, Q+idx+1, A[i]) - Q;

		//Dp
		memset(F, 0, sizeof F);
		IOR(i, 1, n+1) F[1][i] = 1;

		IOR(i, 2, m+1) {
			B.Init();
			IOR(v, 1, n+1) {
				F[i][v] += B.Ask(1, Pos[v]-1);
				F[i][v] %= P;

				B.Cg(Pos[v], F[i-1][v]);
			}
		}

		long long ans = 0;
		IOR(i, 1, n+1) 
			ans = (ans + F[m][i] % P) % P;

		printf("Case #%lld: %lld\n", ++cnt, ans);
	}

	return 0;
} /**/

void FenWick::Init() {
	memset(Tr, 0, sizeof Tr);
}

void FenWick::Cg(int x, long long val) {
	while(x <= n) 
		Tr[x] = (Tr[x] + val % P) % P, x += x & -x;
}

long long FenWick::Ask(int l, int r) {
	if(l > r) return 0;

	l--; long long res = 0;
	while(l < r) res = (res % P + Tr[r]) % P, r -= r & -r;
	while(l > r) res = (res % P - Tr[l]) % P, l -= l & -l;

	return res % P;
}
```
