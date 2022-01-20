#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;
template <typename T>
inline void read(T &x)
{
	x = 0;
	T f=1;
	char c=getchar();
	for (; !isdigit(c); c=getchar())
	{
		if (c=='-')
			f *= -1;
		}	
	for (; isdigit(c); c=getchar())
		x = (x<<1) + (x<<3) + c - '0';
	x *= f;
}

const int maxn=6e5;
char ss[maxn];
char ans[maxn];
int t,n;
int a[maxn];
int f[maxn];
bool flag;

void dfs(int nw, int l, int r)
{
	if (nw == n+1)
	{
		if (!flag)
		{
			flag = true;
			for (int i=1; i<=n; i++)
				ans[i] = ss[i];
			return;
		}
		bool ff=false;
		for (int i=1; i<=n; i++)
		{
			if (ans[i] < ss[i])
			{
				ff=true;
				break;
			}
		}
		if (!ff)
		{
			for (int i=1; i<=n; i++)
				ans[i] = ss[i];
		}
		return ;
	}
	
	
	if (!f[a[l]])
	{
		f[a[l]] = nw;
		ss[nw] = 'L';
		dfs(nw+1, l+1, r);
		f[a[l]] = 0;
	 } 
	else if (f[a[l]] + nw == n+1)
	{
		ss[nw] = 'L';
		dfs(nw+1, l+1, r);
	}
	
	if (!f[a[r]])
	{
		f[a[r]] = nw;
		ss[nw] = 'R';
		dfs(nw+1, l, r-1);
		f[a[r]] = 0;
	}
	else if (f[a[r]] + nw == n+1){
		ss[nw] = 'R';
		dfs(nw+1, l, r-1);
	}
	return ;
}


int main ()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(t);
	while (t--)
	{
		flag = false;
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		read(n);
		n *= 2;
		for (int i=1; i<=n; i++)
			read(a[i]);
		dfs(1,1,n);
		if (flag)
		{
			for (int i=1; i<=n; i++)
				printf("%c",ans[i]);
			printf("\n");
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}









