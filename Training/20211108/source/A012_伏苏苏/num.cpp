#include <algorithm>
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

const int N = 73;

int n, k, a[N], num[N], maxn[N], minn[N], hg;
bool v[N][N];

LL ans=1e9+7;

void dfs(int c) {
  if(c == n) {
  	LL s = 0;
  	for (int i = 1; i <= k; ++i) s += maxn[i] - minn[i];
	ans = std::min(ans, s);
	return;
  }
  for (int i = 1; i <= k; ++i) if(num[i] < hg && !v[i][a[c + 1]]) {
  	++num[i];
  	maxn[i] = a[c + 1];
  	if(num[i] == 1) minn[i] = maxn[i];
  	v[i][a[c + 1]] = 1;
  	dfs(c + 1);
  	--num[i];
  	v[i][a[c + 1]] = 0;
    }
}

int main() {
  freopen("num.in", "r", stdin);
  freopen("num.out", "w", stdout);
  n = readInt(), k = readInt();
  for (int i = 1; i <= n; ++i) a[i] = readInt();
  std::sort(a + 1, a + n + 1);
  hg = n / k;
  dfs(0);
  printf("%lld", ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
