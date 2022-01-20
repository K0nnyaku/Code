---
title: GSS4
date: 2021-10-7 6:26:35
tags: [数据结构, 线段树]
---
### [GSS4](https://www.luogu.com.cn/problem/SP2713)

## 每个数最多被开log次
## 记录区间max, >1则暴力修改

```cpp
#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

#define MID ((L + R) >> 1)
#define V(x) (Tr[x].val)
#define M(x) (Tr[x].mx)
const int MAXN = 1e5 + 10;
#define int long long

struct Seg {
	int lc, rc, mx, val;

	void Init(int L, int R);
	void Up();
	void Change(int l, int r, int L, int R);
	int New();
	int Ask(int l, int r, int L, int R);

} Tr[MAXN<<4];
int cnt = 1;

int n, q, Index = 1;

signed main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	while(~scanf("%lld", &n)) {
		if(Index != 1) puts("");
		printf("Case #%lld:\n", Index++);
		Tr[1].Init(1, n);
		scanf("%lld", &q);
		
		while(q--) {
			int opt, x, y; 
			scanf("%lld%lld%lld", &opt, &x, &y);
			if(x > y) swap(x, y);

			if(opt) printf("%lld\n", Tr[1].Ask(x, y, 1, n));
			else Tr[1].Change(x, y, 1, n);
		}
	}
	return 0;
} /**/

void Seg::Init(int L, int R) {
	if(L == R) { 
		scanf("%lld", &val); mx = val; return ; }

	lc = New(); Tr[lc].Init(L, MID);
	rc = New(); Tr[rc].Init(MID+1, R);

	Up();
}

void Seg::Change(int l, int r, int L, int R) {
	if(mx == 1) return ;
	if(L == R) {
		val = sqrt(val); mx = val;
		return ;
	}

	if(l <= MID) Tr[lc].Change(l, r, L, MID);
	if(r > MID) Tr[rc].Change(l, r, MID+1, R);

	Up();
}

void Seg::Up() {
	val = V(lc) + V(rc);
	mx = max(M(lc), M(rc));
}

int Seg::Ask(int l, int r, int L, int R) {
	if(L >= l && r >= R) return val;
	
	int res = 0;
	if(l <= MID) res += Tr[lc].Ask(l, r, L, MID);
	if(r > MID) res += Tr[rc].Ask(l, r, MID+1, R);

	return res;
}

int Seg::New() {
	return ++cnt; }
```
