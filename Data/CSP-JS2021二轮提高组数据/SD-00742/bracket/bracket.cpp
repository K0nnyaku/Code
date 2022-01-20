#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 510;
const int mod = 1e9 + 7; 
int n, k;
int ans;
char s[N];

bool check()
{
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(s[i] == '(') sum1 ++;
		if(s[i] == ')') sum2 ++;
		if(s[i] == '*') sum3 ++;
		if(sum2 > sum1) return false;
		if(sum3 > sum1 * k || (sum3 > 0 && sum1 == 0)) return false;
	}
	if(sum1 != sum2) return false;
	if(s[1] != '(' || s[n] != ')') return false;
	return true;
}

void dfs(int cnt)
{
	if(cnt == n){
		if(check()) ans = (ans + 1) % mod; 
		return ;
	}
	if(s[cnt + 1] == '?'){
		s[cnt + 1] = '*';
		dfs(cnt + 1);
		s[cnt + 1] = '(';
		dfs(cnt + 1);
		s[cnt + 1] = ')';
		dfs(cnt + 1);
		s[cnt + 1] = '?';
		return ;
	} 
	dfs(cnt + 1);
	return ;
}

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++){
		scanf("%s", &s[i]);
	}
	dfs(0);
	printf("%d\n", ans - 2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

