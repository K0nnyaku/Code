#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e6 + 10;
int t, n, a[N], s[N];

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

bool check(int i)
{
	int top = 0, l = 1, r = n << 1;
	for (int j = (n << 1) - 1; j >= 0; j--)
		if (i >> j & 1) s[++top] = a[r], r--;
		else s[++top] = a[l], l++;
	for (int j = 1; j <= n; j++)
		if (s[j] != s[(n << 1) + 1 - j]) return false;
	return true;
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(t);
	while (t--)
	{
		read(n);
		for (int i = 1; i <= n << 1; i++) read(a[i]);
		bool pd = false;
		for (int i = 0; i < 1 << (n << 1); i++)
			if (check(i))
			{
				for (int j = (n << 1) - 1; j >= 0; j--)
					putchar(i >> j & 1 ? 'R' : 'L');
				putchar('\n');
				pd = true; break;
			}
		if (!pd) puts("-1");
	}
	return 0;
}
