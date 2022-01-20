#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 505;
int n, k, ans, f, sum[N], a[N];
char s[N];
inline int check(int x){
	int res = 0;
	for (int i = x - 1; ; --i){
		if (s[i] == '*') res ++;
		else break;
	}
	for (int i = x + 1; ; ++i){
		if (s[i] == '*') res ++;
		else break;
	}
	res += 1;
	return res <= k;
}
inline void dfs(int now, int js, string ss){
	
	if (js < 0) return ;
	if (now == n + 1){
		if (js == 0){
			ans ++;
			ans %= mod;	
		}
		return ;
	}
	if (s[now] != '?'){
		if (s[now] == '(') dfs(now + 1, js + 1, ss + "(");
		if (s[now] == ')') dfs(now + 1, js - 1, ss + ")");
		if (s[now] == '*') dfs(now + 1, js, ss + "*");
	}
	else {
		s[now] = '(';
		dfs(now + 1, js + 1, ss + "(");
		s[now] = ')';
		dfs(now + 1, js - 1, ss + ")");
		if (check(now)){
			s[now] = '*';
			dfs(now + 1, js, ss + "*");
			s[now] = '?';
		}
	}
}
int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	if (s[1] == '*' || s[n] == '*'){
		cout << 0 << endl;
		return 0;
	}
	if (s[1] == '?') s[1] = '(';
	if (s[n] == '?') s[n] = ')';
	string s = "(";
	dfs(2, 1, s);
	printf("%d\n", ans);
	return 0;
}

