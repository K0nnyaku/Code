#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 510;
const int maxl = 1010;

typedef bitset<maxl + 5> Int;

int n, m, L = 1000;

int wh[maxl + 5];
Int val[maxn + 5];
bitset<maxn + 5> from[maxn + 5];
int tot = 0;

inline void change(int x, const Int &y)
{
	int p = -1;
	REP(i, 0, n) if (val[i].none() && from[i][x]) { p = i; break; }
	if (!~p)
	{
		for (int i = L - 1; i >= 0; --i) if (~wh[i] && from[wh[i]][x])
		{
			p = wh[i], wh[i] = -1;
			break;
		}
	}
	assert(~p);
	REP(i, 0, n) if (i != p && from[i][x]) val[i] ^= val[p], from[i] ^= from[p];
	val[p] ^= y;
	REP(i, 0, L) if (val[p][i])
	{
		if (!~wh[i]) { wh[i] = p; break; }
		val[p] ^= val[wh[i]];
		from[p] ^= from[wh[i]];
	}
}

int main()
{
	freopen("cut.in", "r", stdin);
	freopen("cut.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(wh, -1, sizeof wh);
	REP(i, 0, n) from[i][i] = 1;
	REP(ii, 0, m)
	{
		int x, y;
		static char s[maxl + 5];
		Int w;
		scanf("%d%d%s", &x, &y, s), --x, --y;
		int l = strlen(s);
		REP(i, 0, l) if (s[i] == '1') w[L - l + i] = 1;
		change(x, w), change(y, w);
		Int ans = 0;
		REP(i, 0, L) if (~wh[i] && !ans[i]) ans ^= val[wh[i]];
		bool flag = 0;
		int tmp = 0;
		REP(i, 0, L) if (ans[i] || flag) flag = 1, s[tmp++] = ans[i] + '0';
		if (!tmp) s[tmp++] = '0';
		s[tmp] = 0;
		printf("%s\n", s);
	}
	return 0;
}
