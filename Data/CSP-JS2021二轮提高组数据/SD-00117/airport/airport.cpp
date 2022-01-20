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
inline unsigned Rand(unsigned L, unsigned R) {
  return L + (rand() * rand() % (R - L + 1));
}
struct Bri {
  unsigned Fr, To, Bel;
  inline const char operator< (const Bri &x) const {return Fr < x.Fr;}
}P[100005];
priority_queue<unsigned> Br;
vector<unsigned> Dec[200005];
unsigned a[200005], n, m1, m2;
unsigned A, B, C, D;
unsigned Sum1[100005], Sum2[100005];
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Calc(unsigned m, unsigned *Sum) {
  Cnt = 0;
  for (unsigned i(1); i <= m; ++i) {
    P[i].Fr = a[++Cnt] = RD();
    P[i].To = a[++Cnt] = RD();
  }
  sort(a + 1, a + Cnt + 1);
  sort(P + 1, P + m + 1);
  Cnt = unique(a + 1, a + Cnt + 1) - a;
  for (unsigned i(1); i <= m; ++i) {
    P[i].Fr = lower_bound(a + 1, a + Cnt, P[i].Fr) - a;
    P[i].To = lower_bound(a + 1, a + Cnt, P[i].To) - a;
  }
//  for (unsigned i(1); i <= m; ++i) printf("%u [%u, %u]\n", i, P[i].Fr, P[i].To);
  for (unsigned i(1); i <= m; ++i) Br.push(m + 1 - i);
  for (unsigned i(1), j(1); i <= Cnt; ++i) {
    while(P[j].Fr == i) {
      P[j].Bel = m - Br.top() + 1;
      Dec[P[j].To].push_back(Br.top());
      Br.pop(), ++j;
    }
    for (auto k:Dec[i]) {
      Br.push(k);
    }
  }
//  for (unsigned i(1); i <= m1; ++i) {
//    printf("%u Bel %u\n", i, P[i].Bel);
//  }
  for (unsigned i(1); i <= m; ++i) ++Sum[P[i].Bel];
  for (unsigned i(1); i <= n; ++i) Sum[i] += Sum[i - 1];
  memset(P, 0, (m + 2) * sizeof(Bri));
  for (unsigned i(1); i <= Cnt; ++i) Dec[i].clear();
  while(Br.size()) Br.pop();
}
signed main() {
  freopen("airport.in", "r", stdin);
  freopen("airport.out", "w", stdout);
  n = RD(), m1 = RD(), m2 = RD();
  Calc(m1, Sum1);
  Calc(m2, Sum2);
  for (unsigned i(0); i <= n; ++i) {
    Ans = max(Ans, Sum1[i] + Sum2[n - i]);
  }
  printf("%u\n", Ans);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

7

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

4
*/
