#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read()
{
	ll x =0 , f =0;
	char ch = getchar();
	while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Wr(ll x)
{
	if(x < 0 ) putchar('-'), x = -x;
	if(x > 9) Wr(x / 10);
	putchar(x % 10 + 48);
}

void W(ll x, char ch)
{
	Wr(x);
	putchar(ch);
}

const int N = 1e6 + 4;
int T, n, nn;
int a[N], b[N], top;
bool ans[N], oknow; // 0->L 1->R
deque<int> q;

void Clear()
{
	top = 0;
	q.clear();
	oknow = 0;
}

void dfs(ll k)
{
	if(k == nn)
	{
      for(int i = 1; i <= n; ++i)
         if(b[i] != b[nn - i + 1]) return;
      
      oknow = 1;
      for(int i = 1; i <= nn; ++i)
         putchar((ans[i] == 0) ? 'L' : 'R');
      putchar('\n');
		return;
	}

	int x = q.front(), y = q.back();
	q.pop_front();
	ans[k + 1] = 0;
	b[k + 1] = x;
	dfs(k + 1);
	if(oknow)
		return;
	q.push_front(x);

	q.pop_back();
	ans[k + 1] = 1;
	b[k + 1] = y;
	dfs(k + 1);
	if(oknow)
		return;
   q.push_back(y);
   
	return;
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);

	T = read();
	while(T--)
	{
		n = read();
		nn = n * 2;
		if(n > 100)
      {
         for(int i = 1; i <= nn; ++i)
            putchar('L');
         putchar('\n');
         continue;
      }
		for(int i = 1; i <= nn; ++i)
			a[i] = read(), q.push_back(a[i]);

		int x = q.front();
		int y = q.back();

		q.pop_front();
		ans[1] = 0;
		b[1] = x;
		dfs(1);
		q.push_front(x);

		if(oknow)
		{
			Clear();
			continue;
		}

		q.pop_back();
		ans[1] = 1;
		b[1] = y;
		dfs(1);
		q.push_back(y);

		if(oknow == 0)
			puts("-1");
		Clear();
	}

	return 0;
}







