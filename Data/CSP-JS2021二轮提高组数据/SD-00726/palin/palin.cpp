#include <cstdio>

#include <iostream>
using namespace std;

#define tp int

#define n2 (n << 1)

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

int n;

int arr[21005];
int fuck[11005];
int turn[10005];

int head = 1, tail = n2;
bool ok = 0;

void dfs(int now, int k)
{
	if(ok)
		return ;
	if(now == n2 + 1)
	{
		ok = 1;
		F(i, 1, n2)
			putchar(turn[i] == 0 ? 'L' : 'R');
		putchar('\n');
		return ;
	}
	
	if(now <= n)
	{
		if(k == 0)
		{
			if(fuck[arr[head]] == 0)
			{
				turn[now] = 0;
				fuck[arr[head ++]] = now;
				dfs(now + 1, 0);
				dfs(now + 1, 1);
				fuck[arr[--head]] = 0;
			}
			else return ;
		}
		else
		{
			if(fuck[arr[tail]] == 0)
			{
				turn[now] = 1;
				fuck[arr[tail --]] = now;
				dfs(now + 1, 0);
				dfs(now + 1, 1);
				fuck[arr[++tail]] = 0;
			}
			else return ;
		}
	}
	else
	{
		if(k == 0)
		{
			if(fuck[arr[head]] == n2 + 1 - now)
			{
				turn[now] = 0;
				head ++;
				dfs(now + 1, 0);
				dfs(now + 1, 1);
				fuck[arr[--head]] = 0;
			}
			else return ;
		}
		else
		{
			if(fuck[arr[tail]] == n2 + 1 - now)
			{
				turn[now] = 1;
				tail --;
				dfs(now + 1, 0);
				dfs(now + 1, 1);
				fuck[arr[++tail]] = 0;
			}
			else return ;
		}
	}
	
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);

	int T = read();
	while(T --)
	{
		n = read();
		ok = 0;
		head = 1, tail = n2;
		F(i, 1, n << 1)
			arr[i] = read();
		dfs(1, 0);
		dfs(1, 1);
		if(!ok)
			puts("-1");
	}
	return 0;
}













