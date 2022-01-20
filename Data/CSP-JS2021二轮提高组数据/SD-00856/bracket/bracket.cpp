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

const int maxn = 505;
int n, k;
const int modint = 1e9 + 7;
char s[maxn];
lint ans;
vector<int> p;

int now_layer;
int layer[maxn];
int dot[maxn];

inline bool check()
{
	rep(i, 1, n)
		switch (s[i])
		{
			case '*':
				if (s[i - 1] == '*')
				{
					dot[i] = dot[i - 1] + 1;
					if (dot[i] > k)
						return false;
				}
				else if (s[i - 1] == '(')
				{
					
				}
		}
	return true;
}

void dfs(int x)
{
	if (x == p.size() + 1)
	{
		if (check())
			++ans;
		return;
	}
	s[p[x]] = '(';
	dfs(x + 1);
	s[p[x]] = ')';
	dfs(x + 1);
	s[p[x]] = '(';
	dfs(x + 1);
}

int main() 
{
//	freopen("bracket.in", "r", stdin);
//	freopen("bracket.out", "w", stdout);
	n = readInt(), k = readInt();
	scanf("%s", s + 1);
	p.push_back(0);
	rep(i, 1, n)
		if (s[i] == '?')
			p.push_back(i);
	dfs(1);
	return 0; 
}
