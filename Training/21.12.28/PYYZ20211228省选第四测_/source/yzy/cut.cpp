#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;

// #define int ll
#define rep(i, f, t) for (int i = (f), ed##i = (t); i <= ed##i; ++i)
#define re(i, t) rep (i, 1, t)
#define per(i, t, f) for (int i = (t), ed##i = (f); i >= ed##i; --i)
#define ste(i, f, t, s) for (int i = (f), ed##i = (t); i <= ed##i; i += s)
#define each(i, x) for (auto &&i : (x))
#define nxt(i, f, g) for (int i = g.h[f]; i; i = g.e[i].n)
#define dbg(x) (cerr << "(dbg) " << #x " = " << (x) << '\n')
#define umod(x) ((x) >= mo && ((x) -= mo))
#define dmod(x) ((x) < 0 && ((x) += mo))
#define up(x, y) (((x) < (y)) && ((x) = (y)))
#define down(x, y) (((x) > (y)) && ((x) = (y)))
#define y1 y1__
#define fio(x) (freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout))

const int N = 1e3 + 9;
int n, m, L;
typedef bitset<N> BS;
BS p[N], a[N], ans, tmp;

struct Q {
  int x, y;
  string s;
} q[N];

void Ins(bitset<N> x) {
  bool b = 0;
  per (i, L - 1, 0) {
    if (x[i]) b = 1;
    if (!b) continue;
    if (p[i].none()) {
      p[i] = x;
      break;
    }
    x ^= p[i];
  }
}

int Cmp() {
  per (i, L - 1, 0) {
    if (tmp[i] && !ans[i]) return 1;
    if (!tmp[i] && ans[i]) return 0;
  }
  return 0;
}
void Out() {
  ans.reset();
  per (i, L - 1, 0) {
    tmp = ans ^ p[i];
    if (Cmp()) ans = tmp;
  }
  int fl = 0;
  per (i, L - 1, 0) {
    if (!ans[i] && fl)
      cout << '0';
    else if (ans[i])
      cout << '1', fl = 1;
  }
  if (!fl) cout << '0';
  cout << '\n';
}

signed main() {
  fio("cut");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  re (i, m)
    cin >> q[i].x >> q[i].y >> q[i].s, up(L, (int)q[i].s.size());
  re (i, m) {
    // cerr << i << '\n';
    a[q[i].x] ^= BS(q[i].s);
    a[q[i].y] ^= BS(q[i].s);
    rep (i, 0, L - 1)
      p[i].reset();
    ans.reset();
    re (i, n)
      Ins(a[i]);
    Out();
  }
  return 0;
}