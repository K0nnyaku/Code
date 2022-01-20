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

const int N = 505, mod = 1e9 + 7;

int n, K;
char s[N], t[N];

inline bool Check(int l, int r) {
  bool ok = 0;
  for (int i = l; i <= r; i++) {
    
  }
  return true;
}

inline void DFS(int x) {
  if (x > n) {
    if (Check(1, n)) ans++;
    if (ans > mod) ans -= mod;
    return;
  }
  if (s[x] == '?') {
    t[x] = '(';
    DFS(x + 1);
    t[x] = '*';
    DFS(x + 1);
    t[x] = ')';
    DFS(x + 1);
  } else {
    t[x] = s[x];
    DFS(x + 1);
  }
}

int main() {
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  n = read(), K = read();
  scanf("%s", s + 1);
  if (s[1] == '?') s[1] = '(';
  if (s[n] == '?') s[n] = ')';
  printf("0");
  return 0;
}

/*
老规矩, 先看数据范围.
有一个不错的部分分, n <= 100, 有 65 分, 可以先考虑一下, 复杂度应该是 n^4.
看数据范围, 感觉正解是要用 bitset 的样子. (wssb, 方案数怎么可能用 bitset. 
盲猜区间 DP, 好像还蛮简单的? 错觉? 
稍微想想应该能做. 
设状态 f[i][j] 表示区间 (i, j) 合法的方案.
转移的话, 如果 (i, k) 和 (k + 1, j) 都合法,
那 f[i][j] = f[i][k] * f[k + 1][j].
这个还是很好想的, 关键就在于, 中间的一段不合法的怎么搞.
看一下样例吧.
(*??*?? k = 3
长度为 1 的合法串不存在, 长度为 2 的只有 (), 3 的只有 (*).
如果全是 ? 的话, 那么应该可以直接区间 DP, si~
想一下, 这个区间到底能不能合并, 或者说, 怎样合并...
我们好像还需要一维, 来维护 * 的个数.
设 f[i][j][k] 表示在区间 (i, j) 内, 有 k 个 * 的方案数. cao, 好像还不好维护.
我们的 k 好像只需要维护开头的和末尾的, 因为我们保证了中间是合法的, 这样的话, 考虑一下转移.
如果没有 ? 的话, 
日了, 好像不太好想的样子, 看看 C 去.
日了, 只能打个 28 的暴力, 淦! 没有适合我的题qwq.
还剩 1.5h.
淦了, 上了个厕所, 脑子里还是空空的, 不能就此止步啊.
先打个暴力, 保个底. 
怎么 check 一个串是否合法? 
首先, * 的数量超了肯定就不合法了, 
然后, (*()*) 这样的情况, 也就是前面有个 * 然后中间合法, 后面又出来一个 *.
除此之外, 应该没了, 
淦啊, 这暴力贼难打, 而且给的分还这么少, 我真裂开了, 我现在是连怎么判断这个串合不合法都费劲, 
日了, 不写 B 了, 太费劲了, **题, 我**** 
*/
