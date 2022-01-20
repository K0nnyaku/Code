#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#include<string>
#include<map>
#include<bitset>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
inline unsigned RD() {
  unsigned Rtmp(0);
  char Rch(getchar());
  while ((Rch < '0') || (Rch > '9')) Rch = getchar();
  while ((Rch >= '0') && (Rch <= '9')) Rtmp = (Rtmp << 3) + (Rtmp << 1) + Rch - '0', Rch = getchar();
  return Rtmp;
}
inline int RDsg() {
  int Rtmp(0), Rsig(1);
  char Rch(getchar());
  while (((Rch < '0') || (Rch > '9')) && (Rch ^ '-')) Rch = getchar();
  if(Rch == '-') Rsig = -1, Rch = getchar();
  while ((Rch >= '0') && (Rch <= '9')) Rtmp = (Rtmp << 3) + (Rtmp << 1) + Rch - '0', Rch = getchar();
  return Rtmp * Rsig;
}
unsigned long long Mod(1000000007);
unsigned long long f[505][505], g[505][505][2];
unsigned n, m;
unsigned A, B, C, D;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[505];
signed main() {
  freopen("bracket.in", "r", stdin);
  freopen("bracket.out", "w", stdout);
  n = RD(), m = RD();
  scanf("%s", a + 1);
  for (unsigned i(n); i; --i) g[0][i][0] = f[0][i] = 1;
  for (unsigned Len(2); Len <= n; ++Len) {
    for (unsigned i(n - Len + 1); i; --i) {
      for (unsigned len(1); len < Len && len <= m; ++len) {
        if((a[i + Len - len] == '(') || (a[i + Len - len] == ')')) break;
        g[Len][i][1] += g[Len - len][i][0];
        if(g[Len][i][1] >= Mod) g[Len][i][1] -= Mod;
      }
      if((a[i] == '*') || (a[i] == ')') || (a[i + Len - 1] == '*') || (a[i + Len - 1] == '(')) {
        continue;
      }
      unsigned Tol(min(Len - 2, m));
      f[Len][i] = g[Len - 2][i + 1][0] + g[Len - 2][i + 1][1];
      if(f[Len][i] >= Mod) f[Len][i] -= Mod; 
      for (unsigned len(1); len <= m && len + 2 <= Len; ++len) {
        if((a[i + len] == '(') || (a[i + len] == ')')) break;
        f[Len][i] += g[Len - 2 - len][i + len + 1][0]; 
        if(f[Len][i] >= Mod) f[Len][i] -= Mod; 
      }
      g[Len][i][0] = f[Len][i];
      for (unsigned len(2); len + 2 <= Len; ++len) {
        g[Len][i][0] = (g[Len][i][0] + g[len][i][1] * f[Len - len][i + len]) % Mod;
      }
      for (unsigned len(2); len + 2 <= Len; ++len) {
        g[Len][i][0] = (g[Len][i][0] + g[len][i][0] * f[Len - len][i + len]) % Mod;
      }
//      printf("[%u, %u] %llu %llu %llu\n", i, i + Len - 1, f[Len][i], g[Len][i][0], g[Len][i][1]);
    }
  }
  printf("%llu\n", g[n][1][0]);
	return 0;
}
/*
546949722

4 2 
????
 
7 3
(*??*??

5

10 2
???(*??(?)
*/
