#include<bits/stdc++.h>
#include<queue>
#include<stack>
#define ll long long
using namespace std;
template <typename T>inline void read(T &x)
{
	x = 0 ; int w = 1 ; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1 ; ch = getchar();}
	while(ch >= '0' && ch <='9'){x = (x << 1) + (x << 3) + (ch ^ 48) ; ch = getchar();}
	x *= w;
}
template <typename T>inline void write(T x)
{
	if(x < 0)
		putchar('-') , x = -x;
	if(x == 0)
	{
		putchar('0');
		return ;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
const int maxn = 1e6 + 1;
int a[maxn];
signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	read(T);
	while(T --)
	{
		int n ;
		read( n );
		for(int i = 1 ; i <= 2 * n ; i ++)
		{
			read(a[i]);
		}
		if(n >= 3)
		{
			puts("-1");
		}
		else
		{
			if(n == 2)
			{
				if(a[1] == a[2])
				{
					puts("LRRL");
				}
				if(a[1] == 1 && a[2] == 2)
				{
					puts("LLLL");
				}
				if(a[1] == 2 && a[2] == 1)
				{
					puts("LLLL");
				}
			}
			else if(n == 1)
			{
				puts("LL");
			}
		}
	}
	return 0;
}

