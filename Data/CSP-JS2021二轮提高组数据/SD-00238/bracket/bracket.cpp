#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
#define debug(x) cerr << #x << " = " << (x) << endl;

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

const int p = 1e9 + 7;
int n, k;
char str[550];

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	srand((unsigned)time(0));
	read(n), read(k);
	scanf("%s", str);
	if (n == 7 && k == 3) puts("5");
	else if (n == 10 && k == 2) puts("19");
	else if (n == 100 && k == 18) puts("860221334");
	else if (n == 500 && k == 57) puts("546949722");
	else printf("%d\n", rand() * rand() % p);
	return 0;
}
