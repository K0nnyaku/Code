#include <bits/stdc++.h>
using namespace std;

#define lint long long
#define rep(_, __, ___) for (int _ = __; _ <= ___; ++_) 
const int maxn = 1e5 + 5;

inline lint readInt()
{
	int fx = 1, xx = 0;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			fx = -1;
		ch = getchar();
	}
	while (isdigit(ch))
		xx *= 10, xx += ch - 48, ch = getchar();
	return fx * xx; 
}

int n, m1, m2;
struct node
{
	int arrive, leave;
	bool operator< (const node& x) const { return arrive < x.arrive; }
} a[maxn], b[maxn];
int tmp_fa[maxn], tmp_fb[maxn];
int fa[maxn], fb[maxn];
int cur[maxn], tot;

int main() 
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = readInt(), m1 = readInt(), m2 = readInt();
	rep(i, 1, m1)
		a[i].arrive = readInt(), a[i].leave = readInt();
	rep(i, 1, m2)
		b[i].arrive = readInt(), b[i].leave = readInt();
	sort(a + 1, a + m1 + 1);
	sort(b + 1, b + m2 + 1);
	rep(i, 1, m1)
	{
		int t = 1;
		while (cur[t] >= a[i].arrive && t <= tot)
			++t;
		if (t == tot + 1)
			cur[++tot] = a[i].leave, ++tmp_fa[tot];
		else
			cur[t] = a[i].leave, ++tmp_fa[t];
	}
	rep(i, 1, n)
		fa[i] = fa[i - 1] + tmp_fa[i];
	memset(cur, 0, sizeof(cur));
	tot = 0;
	rep(i, 1, m2)
	{
		int t = 1;
		while (cur[t] >= b[i].arrive && t <= tot)
			++t;
		if (t == tot + 1)
			cur[++tot] = b[i].leave, ++tmp_fb[tot];
		else
			cur[t] = b[i].leave, ++tmp_fb[t];
	}
	rep(i, 1, n)
		fb[i] = fb[i - 1] + tmp_fb[i];
	int ans = 0;
	rep(i, 0, n)
		ans = fa[i] + fb[n - i] > ans ? fa[i] + fb[n - i] : ans;
	printf("%d\n", ans); 
	return 0; 
}
