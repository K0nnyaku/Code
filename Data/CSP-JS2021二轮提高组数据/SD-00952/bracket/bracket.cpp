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
int n , k ;
string s;
int ans = 0 ;
inline bool check()
{
	for(int i = 0 ; i < s.size() ; i ++)
	{
		
	}
}
inline void dfs(int now , int rest)
{
	if(rest == 0)
	{
		if(check())
		{
			ans ++;
		}
		return ;
	}
	for(int i = now ; i < s.size() ; i ++)
	{
		if(s[i] == '?')
		{
			s[i] = '(';
			now ++ ;
			rest --;
			dfs(now , rest);
			now -- ;
			rest ++;
			s[i] = ')';
			now ++ ;
			rest --;
			dfs(now , rest);
			now -- ;
			rest ++;
			s[i] = '*';
			now ++ ;
			rest --;
			dfs(now , rest);
			now -- ;
			rest ++;
		}
	}
}
signed main()
{
	freopen("bracket.out","w",stdout);
	cout << rand();
	return 0;
}

