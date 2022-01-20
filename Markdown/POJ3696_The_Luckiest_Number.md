---
title: POJ_The_Luckiest_Number
date: 2021-09-05 16:00:00
tags: [数论, 同余]
---

[POJ_The_Luckiest_Number](http://poj.org/problem?id=3696)

### 考虑用8构成的数可以表示为$8(10^x - 1)/9$ 的形式, 问题转化为求最小的$x$ 满足$L | 8(10^x - 1) / 9$
### 设$d = gcd(L, 8)$ 
### $L | (10^x - 1) / 9 \Leftrightarrow \frac{9L}{d} | 10^x - 1 \Leftrightarrow 10^x \equiv 1 \pmod{\frac{9L}{d}}$  

### 引理: $\forall a,n\in N^*,\; gcd(a, n) = 1$, 满足$a^x \equiv 1 \pmod{n}$的最小正整数$x_0$ 是 $\phi(n)$的约数 
### 证明: 反证法, 设$x_0$不能整除$\phi(n)$ 
### 设$\phi(n) = qx_0 + r \;(0 < r < x_0)$, 因为$a^x_0 \equiv 1 \pmod{n}$, 所以$a^{qx_0} \equiv 1 \pmod{n}$, 因为欧拉定理, 有$a^r \equiv 1 \pmod{n}$, $0 < r < x_0$ 与$x_0$最小矛盾      
### 所以, 枚举$\phi(9L/9)$的约数求解
### $O(\sqrt{L}\log{L})$ 

```cpp
#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const int MB=1<<21;
struct FastIN
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;


unsigned long long Qp(unsigned long long x, unsigned long long e, unsigned long long mod);
unsigned long long Gcd(unsigned long long x, unsigned long long y);
unsigned long long Phi(unsigned long long x);
unsigned long long Mul(unsigned long long x, unsigned long long y, unsigned long long mod);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif

    unsigned long long x, idx = 1;
    IN >> x;

    while(x) {
        unsigned long long mod = 9 * x / Gcd(x, 8), phi = Phi(mod), sq = sqrt(phi);

       if(Gcd(mod, 10) != 1) {
            printf("Case %llu: %d\n", idx++, 0);
            IN >> x;
            continue;
        }

        priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long> > Fac;
        for(unsigned long long i = 1; i <= sq; i++)
            if(!(phi % i)) Fac.push(i), Fac.push(phi / i);
        
        while(Fac.size()) {
            unsigned long long t = Fac.top(); Fac.pop();
            if(Qp(10, t, mod) == 1) {
                printf("Case %llu: %llu\n", idx++, t);
                break;
            }
        }
            
        IN >> x;
    }

	return 0;
} /**/

unsigned long long Phi(unsigned long long x) {
    unsigned long long res = x, sq = sqrt(x) + 1;
    IOR(i, 2, sq)
        if(!(x % i)) {
            res = res / i * (i - 1);
            while(!(x % i)) x /= i;
        }
    if(x > 1) res = res / x * (x - 1);

    return res;
}

unsigned long long Gcd(unsigned long long x, unsigned long long y) {
    return y ? Gcd(y, x % y) : x; }

unsigned long long Qp(unsigned long long x, unsigned long long e, unsigned long long mod) {
    if(!e) return 1;
    unsigned long long res = Qp(x, e / 2, mod) % mod;
    return e % 2 ? Mul(Mul(res, res, mod), x, mod) : Mul(res, res, mod);
}

unsigned long long Mul(unsigned long long x, unsigned long long y, unsigned long long mod) {
    if(y == 1) return x;
//    if(y == 0) return 0;

    unsigned long long res = Mul(x, y / 2, mod) % mod;
    return y % 2 ? (res * 2 + x) % mod : res * 2 % mod;
}
```