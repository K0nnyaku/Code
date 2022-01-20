#include <bits/stdc++.h>
using namespace std;

#define lint long long
#define rep(_, __, ___) for (int _ = __; _ <= ___; ++_) 

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

int main() 
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	return 0; 
}
