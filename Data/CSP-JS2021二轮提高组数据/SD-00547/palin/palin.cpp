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

const int N = 1e6 + 5;

int n, a[N], b[N], num[N], ans[N], ok, l, r;

inline void DFS(int x) {
  if (ok) return;
  if (x > n << 1) {
    ok = 1;
    return;
  }
  int flag = 1;
  ans[x] = 0; //L
  b[x] = a[l++];
  num[b[x]]++;
  if (x <= n) {
    if (num[b[x]] == 2) flag = 0;
  } else {
    if (b[x] != b[2 * n - x + 1]) flag = 0; 
  }
  if (flag) DFS(x + 1);
  if (ok) return;
  l--;
  num[b[x]]--;
  flag = 1;
  ans[x] = 1; //R
  b[x] = a[r--];
  num[b[x]]++;
  if (x <= n) {
    if (num[b[x]] == 2) flag = 0;
  } else {
    if (b[x] != b[2 * n - x + 1]) flag = 0; 
  }
  if (flag) DFS(x + 1);
  if (ok) return;
  r++;
  num[b[x]]--;
}

inline void Solve() {
  memset(num, 0, sizeof(int) * (n + 1));
  n = read(), l = 1, r = n << 1, ok = 0;
  for (int i = 1; i <= n << 1; i++) a[i] = read();
  DFS(1);
  if (!ok) printf("-1");
  else for (int i = 1; i <= n << 1; i++) printf("%c", ans[i] ? 'R' : 'L');
  printf("\n");
}

int main() {
  freopen("palin.in", "r", stdin);
  freopen("palin.out", "w", stdout);
  int T = read();
  while (T--) Solve();
  return 0;
}

/*
感觉是一道贪心, 数据范围也比较大.
老办法, 先看一下无解.
先看构造吧, 我们可以从中间入手, 因为长度一定是偶数, 那么第 n 个和第 n + 1 个一定是连续选的且相同的.
这俩的位置关系要么是一段长度为 n + 1 的段的两头, 要么是一端的两个.
先打个暴力吧, 40pts 的搜索.
欸? 我们想一下, 是不是前两个和后两个一定挨着或者倒着, 意思是, 第一个和第二个的种类就那么几个,
无非就是前俩, 后面俩, 还有两头, 而这两个对应的, 则也一定是挨着的, 所以我们就可以找到前俩和后俩该咋选.
拿样例举个例子. 
还剩最后 1h, 看 B 看的我头疼, 看 C 吧.
欸! 好像有想法, 还是上面说的, 我们就可以分段, 分而治之了, 拿样例举例子.
4 1 2 4 5 3 1 2 3 5
我们先找长度为 6 的两头一样的, 2 和 5 都是, 先看 2,
那么就分成了两段, 分别是 4 1 3 5 和 4 5 3 1, 我们需要用某种顺序使得这两段一样.
日了, 加个jianzhi, 应该能快不少, 没时间了, 快点打了. 
漂亮! 大样例过了! nice! 好了没时间了, 检查一下去了. 
*/ 
