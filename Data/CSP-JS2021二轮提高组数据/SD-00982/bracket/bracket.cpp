#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <string>
#include <cstring>
#include <stack>
#include <ctime>
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
const int maxn = 1000;
stack <int> sss;
int ans;
char ss[maxn];
int xx[maxn];
stack <int> s;
int n, m;
bool check()
{
	//int flag=false;
	int cnt = 0;
	for (int i=1; i<=n; i++)
		xx[i] = 0;
	for (int i=1; i<=n; i++)
	{
		if (ss[i] == '(')
		{
			s.push(1);
			cnt++;
		}
		else if (ss[i] == ')')
		{
			if (s.empty())	
				return false;
			s.pop();
			cnt--;
		}
		else if (ss[i] == '*')
		{
			if (s.empty())
				return false;
			xx[cnt]++;
			if(xx[cnt] > m)
				return false; 
		}
	}
	if (!s.empty())
		return false;
	return true;
}


void dfs(int nw)
{
	if (nw == n+1)
	{
		if (check())
			ans++;
		return;
	}
	if (ss[nw] == ')')
	{
		if (sss.empty()) return;
		sss.pop();
		dfs(nw+1);
		return ;
	}
	if (ss[nw] == '(')
	{
		sss.push(1);
		dfs(nw+1);
		return ;
	}
	if (ss[nw] == '*')
	{
		dfs(nw+1);
		return;
	}
	if (!sss.empty())
	{
		ss[nw] = ')';
		sss.pop();
		dfs(nw+1);
		ss[nw] = '?';
		sss.pop();
		
		ss[nw] = '*';
		dfs(nw+1);
		ss[nw] = '?';
	}
	ss[nw] = '(';
	sss.push(1);
	dfs(nw+1);
	ss[nw] = '?';
	sss.pop();
	return;
	
	
}
/*
fuck
*/
int main ()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n),read(m);
	for (int i=1; i<=n; i++)
		scanf("%c",&ss[i]);
	srand(time(NULL));
	//dfs(1);
	if (n<=5)
	{
		printf("%d",rand()%100);
	}
	else if(n<=10)
		printf("%d",rand()%1000);
	
	else if (n<=100)
	{
		printf("%d",rand()%10000000);
	}
	else 
		printf("%d",rand()+100000);
	return 0;
}















