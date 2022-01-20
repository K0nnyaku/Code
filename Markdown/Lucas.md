---
title: Lucas定理 
date: 2021-10-14 21:15:29
tags: [数论, 模板, 组合数, Lucas]
---

### [LG3807[模板]卢卡斯定理/Lucas 定理](https://www.luogu.com.cn/problem/P3807)

### 就，模板

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

const int MAXN = 1e5 + 10;
const int MAXQ = 10 + 10;

long long Fac[MAXN], Ie[MAXN];
long long n, m, p, t, up;

long long C(long long n, long long m);
long long Lucas(long long n, long long m);
long long Qp(long long x, long long e);

void Pre(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif

	IN >> t;
	
	while(t--) {
		IN >> n >> m >> p;
		Pre(p);
		cout << Lucas(n+m, n) << "\n";
	}

	return 0;
} /**/

void Pre(int x) {
	Fac[0] = Ie[0] = 1;
	IOR(i, 1, x+1) 
		Fac[i] = Fac[i-1] * i % p,
		Ie[i] = Qp(Fac[i], p-2);
}

long long Qp(long long x, long long e) {
	long long res = 1;
	x %= p;
	while(e) {
		if(e & 1) res = x * res % p;
		x = x * x % p; e >>= 1;
	}
	return res % p;
}

long long C(long long n, long long m) {
	return Fac[n] * (Ie[m] * Ie[n-m] % p) % p;
}

long long Lucas(long long n, long long m) {
	if(!m) return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}
```







 
 
