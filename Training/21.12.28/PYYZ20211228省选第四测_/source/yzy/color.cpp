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

const int N = 3e5 + 9;
int n, fa[N], col[N], cc, sz[N];
map<int, int> mp;
ll ans, res;
char s[12];
struct G {
  int h[N], tot;
  struct E {
    int t, n;
  } e[N];
  void Add(int f, int t) { e[++tot] = {t, h[f]}, h[f] = tot; }
} g;

void Dfs1(int f) {
  sz[f] = 1;
  nxt (i, f, g) {
    int t = g.e[i].t;
    if (t == fa[f]) continue;
    fa[t] = f, Dfs1(t);
    sz[f] += sz[t];
  }
}

void Dfs2(int f) {
  ++mp[col[f]];
  if (mp[col[f]] == 1) ++res;
  ans += res;
  nxt (i, f, g) {
    int t = g.e[i].t;
    if (t == fa[f]) continue;
    Dfs2(t);
  }
  --mp[col[f]];
  if (mp[col[f]] == 0) --res;
}

signed main() {
  fio("color");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(9);
  cin >> n;
  re (i, n - 1) {
    int x, y;
    cin >> x >> y;
    ++x, ++y;
    g.Add(x, y), g.Add(y, x);
  }
  re (i, n)
    col[i] = i;
  Dfs1(1);
  cc = n;
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> s >> x;
    ++x;
    if (s[0] == 'q') {
      ans = 0;
      mp.clear();
      for (int y = fa[x]; y; y = fa[y]) ++mp[col[y]];
      res = mp.size();
      Dfs2(x);
      cout << 1.l * ans / sz[x] - 1 << '\n';
    } else {
      ++cc;
      while (x) col[x] = cc, x = fa[x];
    }
  }
  return 0;
}