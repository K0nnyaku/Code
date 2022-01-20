#include <cctype>
#include <cstdio>
#include <iostream>

typedef long long LL;

inline int readInt() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}

const int N = 5e4+3, mod = 1e9+7;

int n, a[N], s[N];

LL ans;

int main() {
  freopen("sum.in", "r", stdin);
  freopen("sum.out", "w", stdout);
  n = readInt();
  for (int i = 1; i <= n; ++i)
  	a[i] = readInt();
  for (int i = 1; i <= n; ++i)
  for (int j = i; j <= n; ++j) {
  	ans += (LL)(a[i] ^ a[j]) * (LL)(a[i] ^ a[j]);
  	ans %= mod;
  }
  ans <<= 1;
  ans %= mod;
  printf("%lld", ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
