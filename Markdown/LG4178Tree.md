---
title: LG4178Tree
date: 2021-08-22 9:50:45
tags: [模板, 点分治]
---

### [LG4178](https://www.luogu.com.cn/problem/P4178)

### 点分治流程
* 找出当前树的重心 rt (Cog 函数)
* 求出每个子节点距根的距离 Dep[], 在根的哪一颗子树中 Fa[], (Pre()函数)
* 累加答案(Calc函数)
  * 两种Calc:
  1. 顺次统计每一颗子树, 用线段树或者平衡树维护每一个值的点的个数
  2. 所有点按距离排序, 指针l, r扫描, 每次累加时减去根相同的点
* 删除 rt, 对于 原rt的每个子树执行 1 

### 一些细节:
* Calc2:
  * rt 也包括在"所有点"中 
  * Fa[rt] = rt
  * res += r - l + 1 - Cnt[Fa[A[l].pos]]
  * 执行 Cog时size要取对应的子树的大小
* Vis标记删去(即执行过分治)的点

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

const int MAXN = 4e4 + 10;
const int MAXM = 4e4 + 10;
const int INF = 0x3f3f3f3f;

struct { int to, next, val; } E[MAXN<<1];
int Head[MAXN], idx;
void Add(int pre, int _to, int _val) {
    E[++idx] = { _to, Head[pre], _val }; Head[pre] = idx; }

int Size[MAXN], mxw = INF;
void Cog(int now, int last, int size);

struct Node {
    int pos;
    long long val;
    friend bool operator<(Node x, Node y) { return x.val < y.val; }
}A[MAXN];

long long ans;
int Dep[MAXN], Cnt[MAXN], Fa[MAXN];
bool Vis[MAXN];
int n, rt, cnt, k;

void Wk(int now, int last);
void Pre(int rt, int now, int last, long long dis);
long long Calc(int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IN >> n;
    IOR(i, 0, n-1) {
        int u, v, w; IN >> u >> v >> w;
        Add(u, v, w); Add(v, u, w);
    }
    IN >> k;

    Cog(1, -1, n);
    Wk(rt, -1);

    printf("%lld\n", ans);

	return 0;
} /**/

void Cog(int now, int last, int size) {
    int w = 0;
    Size[now] = 1;
    EOR(i, now) {
        if(T(i) == last || Vis[T(i)]) continue;
        Cog(T(i), now, size);
        Size[now] += Size[T(i)];
        w = max(w, Size[T(i)]);
    }
    w = max(w, size - Size[now]);
    if(w < mxw) rt = now, mxw = w;
}

void Wk(int now, int last) {
    cnt = 0; Vis[now] = 1; 
    memset(Cnt, 0, sizeof Cnt);
    EOR(i, now) {
        if(T(i) == last || Vis[T(i)]) continue;
        Pre(T(i), T(i), now, V(i));
    }

//        printf("--------------\n");
//        printf("!!%d!!\n", rt);
//        IOR(i, 1, n+1) printf("%d ", Fa[i]);
//        printf("\n--------------\n");

    A[cnt++] = { now, 0 }; Dep[now] = 0; Fa[now] = now; Cnt[now]++;
    ans += Calc(now);

    EOR(i, now) {
        if(T(i) == last || Vis[T(i)]) continue;
        mxw = INF;
        Cog(T(i), now, Size[T(i)]);

        Wk(rt, now);
    }
}

void Pre(int rt, int now, int last, long long dis) {
    Dep[now] = dis; Fa[now] = rt;
    EOR(i, now) {
        if(T(i) == last || Vis[T(i)]) continue;
        Pre(rt, T(i), now, dis + V(i));
    }
    A[cnt++] = { now, dis }; Cnt[Fa[now]]++;
}

long long Calc(int x) {
    long long res = 0;
    int l = 0, r = cnt-1;

    sort(A, A+cnt);
//    printf("\n--------------\n");
//    printf("%d\n", x);
//    IOR(i, 0, cnt) printf("%d ", A[i].pos); 
//    printf("\n--------------\n");

    while(l < r) {
        while(A[r].val + A[l].val > k && l < r) r--, Cnt[Fa[A[r+1].pos]]--;
        res += (r - l - Cnt[Fa[A[l].pos]] + 1);
        l++; Cnt[Fa[A[l-1].pos]]--;
    }
    return res;
}
```