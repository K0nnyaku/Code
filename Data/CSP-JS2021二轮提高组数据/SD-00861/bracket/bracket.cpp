#include <iostream>
#include <cstdio>
#include <cstring> 
#include <vector>
using namespace std;

int n, k, ans;
char s[505];
bool vis[505][505];

bool check(int l, int r) {
	if(vis[l][r]) return 1;
	int sum = 0;
	bool book = 0;
	vector <int> v;
	for(int i = l; i <= r; ++i) {
		if(!v.size() && s[i] == '*') sum++;
		if(sum > k) return 0;
		if(s[i] == '(') v.push_back(i);
		if(s[i] == ')') {
			if(!v.size()) return 0;
			if(!check(v.back() + 1, i - 1)) return 0;
			vis[v.back() + 1][i - 1] = 1;
			sum = 0;
			book = 1;
			v.pop_back();
		}
	}
	if(v.size() || (s[l] == '*' && s[r] == '*' && book == 1)) return 0;
	return 1;
}

void dfs(int x) {
	if(x == n + 1) {
		memset(vis,0,sizeof(vis));
		if(s[1] != '(' || s[n] != ')') return;
		if(check(1,n)) ans = (ans + 1) % 1000000007;
		return;
	}
	if(s[x] != '?') dfs(x + 1);
	else {
		s[x] = ')';
		dfs(x + 1);
		s[x] = '(';
		dfs(x + 1);
		s[x] = '*';
		dfs(x + 1);
		s[x] = '?';
	}
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d",&n,&k);
	scanf("%s", s + 1);
	dfs(1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
