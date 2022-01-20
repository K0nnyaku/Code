#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define tp int

#define F(i, a, b) for(int i = a; i <= b; i++)
#define UF(i, a, b) for(int i = a; i >= b; i--)
#define alledge(i, u) for(int i = head[u]; i; i = edge[i].nxt) 

#define ll long long
#define ull long long

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

void swap(tp &a, tp &b)
{
	tp tmp = a;
	a = b;
	b = tmp;
}

tp read()
{
	tp x = 0, ch = getchar();
	while(!(ch >= '0' && ch <= '9')) ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

void write(tp x)
{
	if(x >= 10)	write(x / 10);
	putchar(x % 10 + '0');
}
void write(tp x, char k)
{
	write(x);
	putchar(k);
} 


int n, k;

int ans;

string str;

string s;

char cha[1000];
int cnt;

int st;

void dfs(int now, int len, char ch)
{
	cha[++cnt] = ch;
	if(now == n - 1)
	{
		if(st != 1)
			{cnt--;	return ;		}
		cha[n] = ')';
		F(i, 3, n - 3)
			if(cha[i - 1] == '*' && cha[i] == '(' && cha[i + 1] == ')' && cha[i + 2] == '*')
			{
				cnt --;
				return ;
			}
		ans ++;
//		F(i, 1, cnt)
//			putchar(cha[i]);
//		putchar(')'); 
//		putchar('\n');
		cnt--;
		return ;
	}
	if(now > n)
		{cnt--;return ;}
	if(st > (n >> 1))
		{cnt--;return ;}
//	cout << now << endl;
	if(len > k)
		{cnt--;return ;}
	if(str[now] == '?')
	{
		//1
		st++;
		dfs(now + 1, 0, '(');
		st--;
		//2
		dfs(now + 1, len + 1, '*');
		//3
		if(st >= 1)
		{
			st--;
			dfs(now + 1, 0, ')');
			st++; 
		}
	}
	else
	{
		if(str[now] == '(')
		{
			st++;
			dfs(now + 1, 0, '(');
			st--; 
		} 
		else if(str[now] == '*')
		{
			if(len + 1 > k)
				{cnt--;return ;}
			dfs(now + 1, len + 1, '*');
		}
		else
		{
			if(st >= 1)
			{
				st --;
				dfs(now + 1, 0, ')');
				st ++;
			}
			else 
				{cnt--;return ;}
		}
	}
	cnt--;
	
}

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	
	n = read(), k = read();
	cin >> str;
	
	st = 1;
	dfs(1, 0, '(');
	
	write(ans);
	
	return 0;
}
