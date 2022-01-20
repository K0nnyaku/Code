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
unsigned n, m, a[20005], T;
unsigned Ans[20005], Now[20005];
unsigned Pos[10005];
unsigned L, R;
char Way[20005], AW[20005], Nope(0);
inline void Clr() {
  memset(Ans, 0x3f, sizeof(Ans));
  memset(Pos, 0,sizeof(Pos));
  memset(Now, 0,sizeof(Now));
  memset(AW, 0x3f,sizeof(AW));
  memset(Way, 0,sizeof(Way));
  Nope = 0, L = 1;
  R = m = ((n = RD()) << 1);
}
inline void DFS(unsigned Dep) {
//  if((Way[1] && (!(Way[2] | Way[3] | Way[4] | Way[5]))) && (Way[6] && (!(Way[7] | Way[8] | Way[9] | Way[10])))) {
//    printf("DFS %u\n", Dep);
//    for (unsigned i(1); i < Dep; ++i) printf("%u ", Now[i]);
//    putchar(0x0A);
//    for (unsigned i(1); i < Dep; ++i) printf("%u ", Way[i]);
//    putchar(0x0A);
//  }
  if(Dep > m) {
    Nope = 1;
    char Flg(0);
    for (unsigned i(1); i <= n; ++i) {
      if(AW[i] < Way[i]) break;
      if(AW[i] > Way[i]) {Flg = 1; break;}
    }
    if(Flg) {
      memcpy(Ans, Now, (m + 1) << 2);
      memcpy(AW, Way, m + 1);
    }
    return;
  }
  if(Dep > n) {
    if(m - Dep == Pos[a[L]] - 1) {
      Now[Dep] = a[L], Way[Dep] = 0, ++L;
      DFS(Dep + 1);
      --L;
    }
    if(m - Dep == Pos[a[R]] - 1) {
      Now[Dep] = a[R], Way[Dep] = 1, --R;
      DFS(Dep + 1);
      ++R;
    }
  } else {
    if(!Pos[a[L]]) {
      Now[Dep] = a[L], Way[Dep] = 0, Pos[a[L]] = Dep, ++L;
      DFS(Dep + 1);
      Pos[a[--L]] = 0;
    }
    if(!Pos[a[R]]) {
      Now[Dep] = a[R], Way[Dep] = 1, Pos[a[R]] = Dep, --R;
      DFS(Dep + 1);
      Pos[a[++R]] = 0;
    }
  }
}
signed main() {
  freopen("palin.in", "r", stdin);
  freopen("palin.out", "w", stdout);
  T = RD();
  for (unsigned t(1); t <= T; ++t) {
    Clr();
    for (unsigned i(1); i <= m; ++i) a[i] = RD();
    DFS(1);
    if(Nope) {
      for (unsigned i(1); i <= m; ++i) putchar(AW[i] ? 'R' : 'L');
      putchar(0x0A);
    } else {
      printf("-1\n");
    }
  }
	return 0;
}
/*
RLLLLRLLLLRLLLLLLLLLLRLRLLRRRLLRRLLLLLLL
2
20
10 16 7 13 18 19 14 15 20 9 2 12 17 4 8 1 11 11 8 17 12 5 15 18 3 13 7 16 10 6 19 14 20 9 2 4 1 5 3 6
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
