---
title: GSS3-线段树单点修改区间最大子段和
date: 2021-10-7 20:12:01
tags: [数据结构, 线段树, 最大子段和]
---
### [GSS3](https://www.luogu.com.cn/problem/SP1716)

### 每个节点维护前缀最大子段和```lmax```, 后缀最大子段和```rmax```, 最大子段和```max```, 区间和```val```
### PushUp:
```cpp
void Seg::Up() {
	Seg lt = Tr[lc], rt = Tr[rc];
	val = lt.val + rt.val;
	lmax = max(lt.lmax, lt.val + rt.lmax);
	rmax = max(rt.rmax, rt.val + lt.rmax);
	mx = max(max(lt.mx, rt.mx), lt.rmax + rt.lmax);
}
```
### Ask:
```cpp
Seg Seg::Ask(int l, int r, int L, int R) {
	//查询区间完全包含当前节点
	if(L >= l && r >= R) return *this;

	//查询区间完全被包含于当前节点的某一子节点
	if(r <= MID) return Tr[lc].Ask(l, r, L, MID);
	if(l > MID) return Tr[rc].Ask(l, r, MID+1, R);

	//else
	Seg lt, rt, res;

	lt = Tr[lc].Ask(l, r, L, MID);
	rt = Tr[rc].Ask(l, r, MID+1, R);

	res.val = lt.val + rt.val;
	res.lmax = max(lt.lmax, lt.val + rt.lmax);
	res.rmax = max(rt.rmax, rt.val + lt.rmax);
	res.mx = max(max(lt.mx, rt.mx), lt.rmax + rt.lmax);

	return res;
}
```

### All
```cpp
#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
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
#define int long long

#define MID ((L + R) >> 1)
const int MAXN = 5e4 + 10;
const int INF = 0x3f3f3f3f;

struct Seg {
	int lc, rc;
	int lmax, rmax, mx, val;

	void Init(int L, int R);
	void Up();
	void Change(int x, int k, int L, int R);
	int New();
	Seg Ask(int l, int r, int L, int R);

} Tr[MAXN<<2];
int cnt = 1;

int n, q;

signed main() { /**/
#ifdef LOCAL
	freopen("I:/Code/In.in", "r", stdin);
	freopen("I:/Code/WA.out", "w", stdout);
#endif
	IN >> n;
	Tr[1].Init(1, n);

	IN >> q;

	while(q--) {
		int opt, x, y;
		IN >> opt >> x >> y;
	
		if(!opt) Tr[1].Change(x, y, 1, n);
		else printf("%lld\n", Tr[1].Ask(x, y, 1, n).mx);
	}

	return 0;
} /**/

void Seg::Init(int L, int R) {
	if(L == R) {
		IN >> val; 
		lmax = rmax = mx = val;
		return ;
	}

	lc = New(); Tr[lc].Init(L, MID); 
	rc = New(); Tr[rc].Init(MID+1, R);

	Up();
}
 
void Seg::Change(int x, int k, int L, int R) {
	if(L == R) {
		lmax = rmax = mx = val = k;
		return ; 
	}

	if(x <= MID) Tr[lc].Change(x, k, L, MID);
	else Tr[rc].Change(x, k, MID+1, R);
	
	Up();
}

Seg Seg::Ask(int l, int r, int L, int R) {
	if(L >= l && r >= R) return *this;

	if(r <= MID) return Tr[lc].Ask(l, r, L, MID);
	if(l > MID) return Tr[rc].Ask(l, r, MID+1, R);

	Seg lt, rt, res;

	lt = Tr[lc].Ask(l, r, L, MID);
	rt = Tr[rc].Ask(l, r, MID+1, R);

	res.val = lt.val + rt.val;
	res.lmax = max(lt.lmax, lt.val + rt.lmax);
	res.rmax = max(rt.rmax, rt.val + lt.rmax);
	res.mx = max(max(lt.mx, rt.mx), lt.rmax + rt.lmax);

	return res;
}

int Seg::New() {
	return ++cnt; 
}

void Seg::Up() {
	Seg lt = Tr[lc], rt = Tr[rc];
	val = lt.val + rt.val;
	lmax = max(lt.lmax, lt.val + rt.lmax);
	rmax = max(rt.rmax, rt.val + lt.rmax);
	mx = max(max(lt.mx, rt.mx), lt.rmax + rt.lmax);
}
```
