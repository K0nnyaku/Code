#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  return x * f;
}

const int N = 1e5 + 5;

int n, m1, m2, ans, ans1[N], ans2[N];

struct Node {
  Node *ls, *rs;
  int l, r, v;
  
  inline void Maintain() {
    v = min(ls->v, rs->v);
  }
} SegmentTree[N << 1], *root = SegmentTree, *top = SegmentTree;

inline void Build(Node *&o, int l, int r) {
  o->l = l, o->r = r, o->v = 0;
  if (l == r) return;
  int mid = l + r >> 1;
  o->ls = ++top, o->rs = ++top;
  Build(o->ls, l, mid); Build(o->rs, mid + 1, r);
}

inline void Find1(Node *&o, int x, int k) {
  if (o->l == o->r) {
    ans1[o->l]++;
    o->v = k;
    return;
  }
  if (o->ls->v < x) Find1(o->ls, x, k);
  else if (o->rs->v < x) Find1(o->rs, x, k);
  o->Maintain();
}

inline void Find2(Node *&o, int x, int k) {
  if (o->l == o->r) {
    ans2[o->l]++;
    o->v = k;
    return;
  }
  if (o->ls->v < x) Find2(o->ls, x, k);
  else if (o->rs->v < x) Find2(o->rs, x, k);
  o->Maintain();
}

struct Plane {
  int a, b;
} a1[N], a2[N];

inline bool cmp(Plane a, Plane b) {
  return a.a < b.a;
}

int main() {
  freopen("airport.in", "r", stdin);
  freopen("airport.out", "w", stdout);
  n = read(), m1 = read(), m2 = read();
  Build(root, 1, n);
  for (int i = 1; i <= m1; i++) a1[i].a = read(), a1[i].b = read();
  for (int i = 1; i <= m2; i++) a2[i].a = read(), a2[i].b = read();
  sort(a1 + 1, a1 + m1 + 1, cmp); sort(a2 + 1, a2 + m2 + 1, cmp);
  for (int i = 1; i <= m1; i++) Find1(root, a1[i].a, a1[i].b);
  root = SegmentTree, top = SegmentTree;
  Build(root, 1, n);
  for (int i = 1; i <= m2; i++) Find2(root, a2[i].a, a2[i].b);
  for (int i = 1; i <= n; i++) ans1[i] += ans1[i - 1];
  for (int i = 1; i <= n; i++) ans2[i] += ans2[i - 1];
  for (int i = 0, j = n; i <= n; i++, j--) ans = max(ans, ans1[i] + ans2[j]);
  printf("%d", ans);
  return 0;
}

/*
题意大致明确了, 大概就是给出两组线段, 然后把 n 分成两个数, 分别是这两组线段最厚的地方的线段数量.
然后问能够存下的最多的线段的数量.
n <= 1e5
复杂度感觉是带个log的, 首先我们想一下, 如何分才能使得一段区间内都合法.
看了一下数据范围, 感觉需要离散化, 因为两组飞机是分开的, 所以互不干扰. 
而且我们关注的知识飞机的相对关系, 并不关心具体数字. 
离散化之后, 先差分, 然后前缀和, 求出两组区间内每个时刻被覆盖的次数.
然后可以log的时间内查询出最大值. 
但是这样我们怎么知道哪些飞机不合法呢?
现在有一个想法是, O(n) 的枚举一下廊桥的分配, 然后 log 的时间查询分别的贡献. 
问题就成了如何在 log 的时间内找到一个数对于一个区间的贡献. 
哦, 突然发现这个飞机是先到先得, 也就是说, 我们不用贪心, 这个就是先到先选, 选靠前的.
那么就简单一些了, 画个图去.
好像会了, 我们是可以预处理出每个廊桥对应的贡献的.
我们开一个堆, 维护每个廊桥的最后一架飞机离开的时间.
si~, 这个贪心好像不太对, 如果有两个空的, 我们该怎么选.
这样吧, 想一下, 如果只有一个的话, 那肯定来一个飞机, 能进则进.
如果不能进, 就新开一个给它, 算到贡献里, 然后我们就需要计算两个的贡献了.
两个最多的贡献, 其实好像一样, 也是能进则进, 哦, 我懂了, 其实无脑往前扔就行.
开始写, 思路大概就是维护每一个结尾合法的廊桥, 然后贪心的往前扔就行了. 
好了, 写完了, 现在是 nm 的, 接下来只需要把查询第一个可以放进去的廊桥优化一下就行了. 
哦! 用 lower_bound 啊, 查询小于等于当前值的第一个, 由于保证互不相同, 那 lower_bound 完全可行. 
日了, 这个不保证有序, 时间过去 1h 了, 一定要稳住.
我们是要找到 < a[i].a 的第一个, 分块? 好像行欸! 线段树呢? 好像也行! 还是线段树吧, 我没大写过分块. 
好了, 写完了, 用了将近 1.5h, 但是好歹过了. 开下一题. 
*/
