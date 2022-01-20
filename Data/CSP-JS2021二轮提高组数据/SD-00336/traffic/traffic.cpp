#include <bits/stdc++.h>

#define ll long long
#define reg register
#define gc getchar()

using namespace std;

const int maxm = 100000 + 3;

inline ll read()
{
	ll f = 0, x = 0;
	char ch = gc;
	while (!isdigit(ch))
		f |= (ch == '-'), ch = gc;
	while (isdigit(ch))
		x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc;
	return f ? -x : x;
}

int main(void)
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
