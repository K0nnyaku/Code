#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define M 110

using namespace std;
int T, n, cnt, fl;
int a[M], b[M];
char ans[M], num[M];

int read() {
	int s = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

void init() {
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  cnt = 0, fl = 0;
  for (int i = 1; i <= n; i++) ans[i] = 'R';
}

bool check() {
  int flag = 0;
  for (int i = 1; i <= n; i++)
    if (b[i] != b[2 * n + 1 - i]) return 0;
  for (int i = 1; i <= 2 * n; i++) 
    if ((int)num[i] < (int)ans[i]) {
      flag = 1;
      break;
    }
  fl = 1;
  for (int i = 1; i <= 2 * n; i++)
    ans[i] = num[i];
  return 1;
}

void dfs(int l, int r) {
  if (fl) return;
  if (l == r) {
    num[++cnt] = 'L', b[cnt] = a[l];
    check();
    cnt--;
    return;
  }
  num[++cnt] = 'L', b[cnt] = a[l];
  dfs(l + 1, r);
  cnt--;
  num[++cnt] = 'R', b[cnt] = a[r];
  dfs(l, r - 1);
  cnt--;
}

int main() {
  freopen("palin.in", "r", stdin);
  freopen("palin.out", "w", stdout);
  T = read();
  while (T--) {
    init();
    n = read();
    if (n <= 10) {
      for (int i = 1; i <= 2 * n; i++) a[i] = read();
      
      dfs(1, 2 * n);
      if (!fl) puts("-1");
      else {
        for (int i = 1; i <= 2 * n; i++) cout << ans[i];
        puts("");
      }
    } else puts("-1");
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
