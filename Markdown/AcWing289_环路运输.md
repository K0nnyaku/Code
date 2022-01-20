---
title: AcWing289 环路运输
date: 2021-11-3 17:17:19
tags: [dp, 环形]
---

### [AcWing289](https://www.acwing.com/problem/content/291/)

### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define Ir(i, st, ed) for(int i = st; i < ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define Sr(i, st, ed) for(int i = st; i > ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

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

const int N_ = 1e6 + 2;
const int INF = 0x3f3f3f3f;

struct Node {
	int val, pos;
	Node(int val_ = 0, int pos_ = 0) {
		val = val_, pos = pos_;
	}
};

int A[N_];
int n, ans;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) IN >> A[i];

	deque<Node> Q;
#define S Q.size()
#define F Q.front()
#define E Q.back()
#define PF Q.pop_front()
#define PE Q.pop_back()
#define I (i % n ? i % n : n)

	ans = -INF;
	IR(i, 1, 2 * n) {
		while(S && F.pos < i - n / 2) PF;

		ans = max(ans, S ? F.val + A[I] + i : 0);

		while(S && E.val <= A[I] - i) PE;	
		
		Q.push_back(Node(A[I] - i, i));
	}

	cout << ans << "\n";

	return 0;
} /**/
```
