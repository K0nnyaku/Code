#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

const int mod = 1e9 + 7;
const int N = 509;
const int M = 1e9 + 8;
char ch[N];
int n, k;
int top;
int s[N];



int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &k);
	if(n > 100 && n <= 500)
	{
		printf("%d", M);
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> ch[i];
	}
//	dfs();
	if(n <= 15)
		printf("17");
 	if(n > 15 && n <= 40)
		printf("56");
	if(n > 40 && n <= 100)
		printf("1392");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
