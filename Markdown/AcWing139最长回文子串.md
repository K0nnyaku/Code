---
title: AcWing139 最长回文子串
date: 2021-11-19 8:58:12
tags: [字符串, Hash, 回文]
---

### [AcWing139](https://www.acwing.com/problem/content/141/)

### 代码
```cpp
#include<bits/stdc++.h>
using namespace std;
#define IR(x,y,z) for(int x = y; x <= z; x++)
#define Ir(x,y,z) for(int x = y; x < z; x++)
#define SR(x,y,z) for(int x = y; x >= z; x--)
#define Sr(x,y,z) for(int x = y-1; x >= z; x--)
#define FL(x, y) memset(x, 0, sizeof x)

struct FastIN {
	template<typename T>
	FastIN& operator>>(T &x) {
		char c, l;
		for(c = 0; !isdigit(c); c = getchar()) l = c;
		for(x = 0; isdigit(c);  c = getchar()) x = x * 10 + c - '0';
		if(l == '-') x = -x;
		return *this;
	}
}IN;

const int N_ = 2e6 + 20;
unsigned long long E[N_];

struct HashS {
	unsigned long long F[N_];
	
	unsigned long long P;
	HashS(unsigned long long P_ = 13331) { FL(F, 0); FL(E, 0); E[0] = 1; P = P_; }
	void Init(char *S, int len) {
		Ir(i, 1, N_)  E[i] = E[i-1] * P;	
		IR(i, 1, len) F[i] = F[i-1] * P + S[i] - 26;
	}

	unsigned long long Ask(int l, int r) {
		return F[r] - F[l-1] * E[r - l + 1];
	}
	void Cl(unsigned long long P_ = 13331) { FL(F, 0); FL(E, 0); E[0] = 1; P = P_; }
	unsigned long long &operator[](int x) { return F[x]; }
} I, G;

int idx;
char S[N_];

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	while(1) {
		int len = 0;

		char ch;
		S[++len] = '$';
		ch = getchar();
		while(ch >= 'a' && ch <= 'z') {
			S[++len] = ch, S[++len] = '$';
			ch = getchar();
		}

		if(ch == 'E') return 0;

		I.Init(S, len);
		reverse(S+1, S+1+len);
		G.Init(S, len);

		int ans = 0;
		IR(i, 1, len) {
			if(i - ans < 1 || i + ans > len) break;
			while(i-ans-1 >= 1 && i+ans+1 <= len 
			      && I.Ask(i-ans-1, i) == G.Ask(len-i-ans, len-i+1)) ans++;
		}
		printf("Case %d: %d\n", ++idx, ans);

		FL(S, 0);
		I.Cl(); G.Cl();
	}

	return 0;
} /**/
```
