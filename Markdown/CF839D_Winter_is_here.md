---
title: CF839D Winter is here
date: 2021-10-16 6:39:29
tags: [数论, gcd]
---

### [CF839D](https://www.luogu.com.cn/problem/CF839D)

### 从大到小考虑每个数及其倍数的子序列长度和
### 过程中去重

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

const int MAXV = 1e6 + 10;
const int P = 1e9 + 7;

long long ans;
long long Len[MAXV], Sum[MAXV];
long long n;

long long Qp(long long x, long long e);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
//	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n; 
	int x;
	IOR(i, 0, n) IN >> x, Sum[x]++; 

	long long tmp = 0;
	LOR(i, MAXV-1, 1) {
//		if(!Sum[i]) continue;
		tmp = 0;

		for(int v = i; v < MAXV; v += i) {
//			tmp = (tmp % P + Sum[v] % P) % P;
			tmp = (tmp + Sum[v]);
		}

		if(!tmp) continue;
		tmp = tmp * Qp(2, tmp - 1) % P;
		Len[i] = tmp;
	
		for(int v = i+i; v < MAXV; v += i)
			Len[i] = (Len[i] - Len[v] + P) % P;

		ans = (ans + Len[i] * i % P) % P;
	}

	cout << ans << "\n";


	return 0;
} /**/

/*
long long Qp(long long x, long long e) {
	long long res = 1;
	x %= P;
	while(e) {
		if(e & 1) res = res * x % P;	
		x = x * x % P;  e >>= 1;
	}
	cerr << "Qp:" << res << "\n";
	return res % P;
}
*/
long long Qp(long long x, long long e) {
	long long res = 1;
	x %= P;
	while(e) {
		if(e & 1) res = res * x % P;
		x = x * x % P; e >>= 1;
	}
	return res % P;
}
```
 
