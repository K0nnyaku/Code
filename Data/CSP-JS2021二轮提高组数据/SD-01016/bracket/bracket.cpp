#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define M 510

using namespace std;
int n, k, ans; char ch;
int top, sta[M], ec[M], num[M], hou[M];

int read() {
	int s = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

void dfs(int x, int xing) {
  if (top > hou[x]) return;
  if (xing == k + 1) return;
  if (x == n + 1) {
    if (!top) ans++;
    return;
  }
  if (ec[x] == 3) {
    for (int i = 0; i <= 2; i++) 
      if (i == 0) {
        num[x] == i;
        dfs(x + 1, xing + 1);
      } else if (i == 1) {
        sta[++top] = x;
        num[x] = i;
        dfs(x + 1, 0);
        top--;
      } else if (i == 2) {
        int tp = sta[top--];
        if (top < 0) {
          top = 0;
          continue;
        }
        if (num[tp - 1] == 0 && ec[x + 1] == 0) {
          sta[++top] = tp;
          continue;
        }
        num[x] = i;
        dfs(x + 1, 0);
        sta[++top] = tp;
      }
  } else {
    num[x] = ec[x];
    if (ec[x] == 0) dfs(x + 1, xing + 1);
    if (ec[x] == 1) {
      sta[++top] = x;
      dfs(x + 1, 0);
      top--;
    }
    if (ec[x] == 2) {
      int tp = sta[top--];
      if (top < 0) {
        top = 0;
        return;
      }
      if (num[tp - 1] == 0 && ec[x + 1] == 0) {
        sta[++top] = tp;
        return;
      }
      num[x] = 2;
      dfs(x + 1, 0);
      sta[++top] = tp;
    }
  }
}

int main() {
  freopen("bracket.in", "r", stdin);
  freopen("bracket.out", "w", stdout);
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    if (ch == '*') ec[i] = 0;
    if (ch == '(') ec[i] = 1;
    if (ch == ')') ec[i] = 2;
    if (ch == '?') ec[i] = 3;
  }
  for (int i = n; i >= 1; i--) {
    if (ec[i] == 3) hou[i] = 1;
    hou[i] += hou[i + 1];
  }
  num[0] = num[n + 1] = 114514;
  
  dfs(1, 0);
  cout << ans;
  fclose(stdin), fclose(stdout);
  return 0;
}
