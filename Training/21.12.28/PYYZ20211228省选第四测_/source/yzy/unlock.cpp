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

const int N = 309;
int n, k, a[N];
bool vis[N];
// dp[i][j]: 前 i 个环选 j 个数的方案个数
lf C[N][N], f[N][N];
vector<int> huan;

void Work() {
  memset(vis, 0, sizeof vis);
  memset(f, 0, sizeof f);
  huan.clear();
  cin >> n >> k;
  re (i, n)
    cin >> a[i];
  re (i, n)
    if (!vis[i]) {
      huan.push_back(0);
      for (int x = i; !vis[x]; vis[x] = 1, ++huan.back(), x = a[x])
        ;
    }
  if ((int)huan.size() > k) return cout << "0.000000000\n", void();
  sort(huan.begin(), huan.end());
  if (k > n - huan[0]) return cout << "1.000000000\n", void();
  f[0][0] = 1;
  re (i, huan.size())
    rep (j, i, k)
      re (x, min(j - i + 1, huan[i - 1]))
        f[i][j] += f[i - 1][j - x] * C[huan[i - 1]][x];
  cout << f[huan.size()][k] / C[n][k] << '\n';
}

signed main() {
  fio("unlock");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(9);
  rep (i, 0, 300) {
    C[i][0] = 1;
    re (j, i)
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
  int T;
  cin >> T;
  while (T--) Work();
}