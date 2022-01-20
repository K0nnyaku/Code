#include <cstdio>
#include <iostream>
#define orz cout << "AK IOI" << "\n"

using namespace std;
const int mod = 1e9 + 7;

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
int n, k, cnt, ans, vis[510];
char s[510];
bool check()
{
	int top = 0, js = 0;
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '(') top++;
		if(s[i] == ')')
		{
			if(top == 0) return 0;
			else top--;
		}
		if(s[i] == '*' && s[i - 1] != '*') js = 1;
		else if(s[i] == '*' && s[i - 1] == '*') js++;
		if(js > k) return 0;
	}
	return 1;
}
void dfs(int now)
{
	if(now == n + 1)
	{
		if(check()) ans++, ans %= mod;
		return ;
	}
	if(vis[now] == 1) s[now] = '(';
	dfs(now + 1);
	if(vis[now] == 1) s[now] = ')';
	dfs(now + 1);
	if(vis[now] == 1) s[now] = '*';
	dfs(now + 1);
}
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(), k = read();
	scanf("%s", s + 1);
	dfs(1);
	for(int i = 1; i <= n; i++) if(s[i] == '?') vis[i] = 1;
	printf("%d", ans);
	/*for(int i = 1; i <= n; i++) if(s[i] == '?') cnt++;
	if(cnt == n) work1();
	else 
	{
		if(n == 7 && k == 3) puts("5");
		else if(n == 10 && k == 2) puts("19");
		else if(n == 100 && k == 18) puts("860221334");
		else if(n == 500 && k == 57) puts("546949722");
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}

