---
title: AT_Tokiomarine2020_E
date: 2021-10-17 17:00:28
tags: [数学, 容斥]
---

### [AT_Tokiomarine2020_E](https://atcoder.jp/contests/tokiomarine2020/submissions/26617485)

### 题意
#### 给定$N$个数$A_i$, 在其中选出$1-k$个满足选出的数按位与等于$S$, 按位或等于$T$
#### $0 < K \le N \le 50, 0 < A_i, S, T \le 2^18, A_i \neq A_j$

### 思路

1. #### 筛
	* #### 如果 $(S | T) ^ T \neq 0$ 无解 
	* #### 对于每一个数$x$, 如果$x | T \neq T$或$x & S \neq S$, 则一定不可能作为解的一部分
	* #### 对于筛出的数, 只需考虑$S ^ T$为$1$的位
2. #### 容斥
	* #### 性质: 具有全0或全1位
	* #### 目的: 不具有性质的个数
	* #### 贡献: $g(i) = 1$ 当且仅当 $i = 0$, 否则为 $0$ (鬼知道为什么我的md用不了latex环境)
	* #### 容斥系数: 考虑对于这个特殊的贡献, 容斥系数$f(i) = (-1)^i$
3. #### 求解
	* #### 枚举需要考虑的每一位 "全1或全0" 或 "不考虑"
	* #### 对于每次枚举出状态, 将每一个数分类存储在桶中, 下标,或者说分类依据,为上条前种状态中考虑的位置的对应二进制组成的数
	* #### 对于每一类, 都可以选择$1-k$个, 容斥系数与枚举状态中考虑的数的个数, 即状态变量$i$二进制中$1$的个数相关

### 细节/技巧/注意

* #### 对于一个数x, 遍历仅改变其二进制下原为$1$的位的所有情况
```cpp
	for(int i = x; i; i = (i - 1) & x) 
		something
```
* #### 此题求解中对于考虑到的数$x$按状态$i$中考虑到的每一位分类
```cpp
	A[i] & i	
```
* #### 注意清空桶

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
 
const int MAXN = 60 + 10;
const int MAXV = 1e6 + 10;
 
long long T[MAXN], A[MAXN], C[MAXN][MAXN];
long long Bk[MAXV]; 
long long n, s, k, t, ans, cnt;
 
void Pre();
 
int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> k >> s >> t;
	IOR(i, 0, n) IN >> T[i];
 
	Pre();
 
	if((s | t) ^ t) return cout << 0, 0;
 
	IOR(i, 0, n) 
		if( (s & T[i]) == s && (t | T[i]) == t ) 
			A[cnt++] = T[i];
 
	IOR(i, 1, k+1) 
		ans += C[cnt][i];
 
	int lm = s ^ t; 
	for(int i = lm; i; i = (i - 1) & lm) {
		IOR(v, 0, cnt) Bk[A[v] & i]++;
 
		IOR(v, 0, cnt) {
			IOR(l, 1, k+1) 
				ans += C[Bk[A[v] & i] ][l] * (__builtin_popcount(i) & 1 ? -1 : 1);
			Bk[A[v] & i] = 0;
		}
	}
 
	cout << ans;
 
	return 0;
} /**/
 
void Pre() {
	IOR(i, 0, MAXN) C[i][0] = 1;
 
	IOR(i, 1, MAXN) IOR(v, 1, MAXN)
			C[i][v] = C[i-1][v] + C[i-1][v-1];
}
```

### 做题中的一些问题

* ### 《关于我因为把样例1看成样例2结果调了半个小时试了三种组合数求法这件事》

