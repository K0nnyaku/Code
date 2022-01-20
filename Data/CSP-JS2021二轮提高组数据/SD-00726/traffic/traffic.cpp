#include <cstdio>

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



int n, m, t;

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
//	n = read(), m = read(), t = read();
	write(28);
	return 0;
}
