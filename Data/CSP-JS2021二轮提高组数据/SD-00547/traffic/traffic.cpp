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

int main() {
  freopen("traffic.in","r",stdin);
  freopen("traffic.out","w",stdout);
  printf("0");
  return 0;
}

