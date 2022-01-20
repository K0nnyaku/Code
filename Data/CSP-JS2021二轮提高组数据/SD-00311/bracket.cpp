#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#define int long long
#define MAXN 2000000
#define INF 1e13 + 7
#define MOD 1000000007

using namespace std;

inline int read()
{
	int x = 0, f = 1; char c  = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') { x = x * 10 + (c ^ 48); c = getchar();}
	return f * x;	   
}

char c[1000];
int n, k, ans;

stack<int>q, X;

inline int check(char s[])
{
	
//	cout << s << endl;

	while (!q.empty()) q.pop();
	while (!X.empty()) X.pop();

//	int S = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '*') X.push(i);
		if (s[i] == '(') q.push(i);
		if (s[i] == ')')
		{
			if (q.size() == 0) return 0;
			int ss = q.top(); q.pop();
			if (s[ss - 1] == '*' && s[i + 1] == '*') return 0;
			if (X.empty()) continue;
			int w = X.top(); X.pop();
			while (!X.empty() && X.top() > ss)
			{
				int e = X.top(); X.pop();
				if (w != e + 1) return 0;
				w = e;
			}
			if (q.empty() && !X.empty())
			{
				if (s[i + 1] == '*') return 0;	
				X.pop();
			}
		}
	}

	if (q.empty() && X.empty())
	{
//		cout << s << endl;
//		check(s);
		
		return 1;
	}
	else
		return 0;
}

char cle[10], C[10];

void dfs(int nnow, int l, int num, char s[])
{
	int x = nnow - 1;
	
	
//	cout << s << endl;
	
//	if (x == 9)
//	{
//		cout << 1;
//	}
	
	
	
	if (x == n)
	{
		ans += check(s);
		return;
	}
	
	
	if (c[x] == '*' && num >= k) return;
	if (c[x] == ')' && !l) return;
	if (l > (n + 1) / 2) return;
	
	if (c[x] == ')')
	{
		s[x] = ')';
		dfs(nnow + 1, l - 1, 0, s);
		s[x] = C[5];
	}
	if (c[x] == '*')
	{
		s[x] = '*';
		dfs(nnow + 1, l, num + 1, s);
		s[x] = C[5];
	}
	if (c[x] == '(')
	{
		s[x] = '(';
		dfs(nnow + 1, l + 1, 0, s);
		s[x] = C[5];
	}
	
	
	if (c[x] == '?')
	{
		s[x] = '(';
		dfs(nnow + 1, l + 1, 0, s);
		s[x] = C[5];
		
		if (l)
		{
			s[x] = ')';
			dfs(nnow + 1, l - 1, 0, s);
			s[x] = C[5];
		}
		
		if (num < k)
		{
			s[x] = '*';
			dfs(nnow + 1, l, num + 1, s);
			s[x] = C[5];
		}
	}
}

inline void step_1()
{
	if (c[0] == '(' || c[0] == '?')
	{
		cle[0] = '(';
		dfs(2, 1, 0, cle);
	}
//	if (c[0] == '?')
//	{
//		cle[0] = '*';
//		dfs(1, 0, 1, cle);
//	}
	cout << ans;
}

signed main()
{     
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(), k = read();
	cin >> c;

	if (c[0] == '*' || c[0] == ')')
	{
		cout << 0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}

	if (n <= 15) step_1();
//	else step_2();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??


10 2
???(*??(?)
*/
