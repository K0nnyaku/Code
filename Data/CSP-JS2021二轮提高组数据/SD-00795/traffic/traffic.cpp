#include <cstdio>
#include <iostream>
#define orz cout << "AK IOI" << "\n"

using namespace std;

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
int n, m, T, mp[8][8];
int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	n = read(), m = read(), T = read();
	for(int i = 1; i <= n - 1; i++) 
		for(int j = 1; j <= m; j++) mp[i][j] = read();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

