#include <cstdio>
#include <iostream>
#define orz cout << "AK IOI" << "\n"

using namespace std;
const int maxn = 5e5 + 10;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
void print(int X)
{
	if(X < 0) X = ~(X - 1), putchar('-');
	if(X > 9) print(X / 10);
	putchar(X % 10 ^ '0');
	return ;
}
int Max(int a, int b){
	return a > b ? a : b;
}
int Min(int a, int b){
	return a < b ? a : b;
}
int T, n, a[maxn * 2];
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = read();
	while(T--)
	{
		n = read();
		int cnt = 0;
		for(int i = 1; i <= 2 * n; i++) a[i] = read();
		for(int i = 1; i <= n; i++)
			if(a[i] == a[2 * n - i + 1]) cnt++;
		if(cnt == n) {for(int i = 1; i <= 2 * n; i++) printf("L"); puts("");}
		else puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

