#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int N = 1e5 + 10;
int n, m1, m2, ans, f[N], g[N];
struct node
{
	int a, b;
	bool operator < (const node &x) const
	{
		return a < x.a;
	}
}A[N], B[N];
set<node> s;

template<typename T> inline void read(T &s)
{
	s = 0; bool f = false; char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		s = (s << 3) + (s << 1) + (c ^ 48);
		c = getchar();
	}
	if (f) s = ~s + 1;
	return;
}

template<typename T> inline void print(T x)
{
	int s[21], top = 0;
	if (x < 0) putchar('-'), x = ~x + 1;
	while (x) s[++top] = x % 10, x /= 10;
	if (!top) s[++top] = 0;
	while (top) putchar(s[top--] + '0');
	return;
}

void solve(int m, node A[], int f[])
{
	while (!s.empty()) s.erase(s.begin());
	for (int i = 1; i <= m; i++) s.insert(A[i]);
	int cnt = 0;
	while (!s.empty() && cnt < n)
	{
		set<node>::iterator it = s.begin();
		cnt++, f[cnt] = f[cnt - 1];
		while (it != s.end())
		{
			node x; x.a = (*it).b, x.b = (*it).b;
			f[cnt]++; s.erase(it);
			it = lower_bound(s.begin(), s.end(), x);
		}
	}
	for (int i = cnt + 1; i <= n; i++) f[i] = f[cnt];
	return;
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(m1), read(m2);
	for (int i = 1; i <= m1; i++) read(A[i].a), read(A[i].b);
	for (int i = 1; i <= m2; i++) read(B[i].a), read(B[i].b);
	solve(m1, A, f); solve(m2, B, g);
	for (int i = 0; i <= n; i++) ans = max(ans, f[i] + g[n - i]);
	print(ans);
	return 0;
}
