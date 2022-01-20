#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

const int maxn = 510, mod = 1e9 + 7; 
int n, k, len, top = 0, Ans, t[maxn];
char s[maxn], c[maxn], sta[maxn];

bool check() {
	top = 0;
	int sum = 0;
	for (int i = 1; i <= len; i++) {
		if (c[i] == '(') {
			sta[++top] = '(';
			t[top] = sum;
			sum = 0;
		}
		else if (c[i] == '*') {
			sum++;
			if (sum > k) return 0;
		}
		else if (c[i] == ')') {
			sum = 0;
			if (sta[top] == '(') top--;
			else return 0;
		}
	}
	if (sum) return 0;
	if (top != 0) return 0;
	return 1;
}

void dfs(int now) {
	if (now == len + 1) {
		if (check()) Ans++, Ans %= mod;
		return ;
	}
	if (s[now] == '?') {
		c[now] = '(';
		dfs(now + 1);
		c[now] = ')';
		dfs(now + 1);
		c[now] = '*';
		dfs(now + 1);
	} 
	else {
		c[now] = s[now];
		dfs(now + 1);
	}
}

signed main () {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &k);
	cin >> s + 1;
	len = strlen(s + 1);
	dfs(1);
	cout << Ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
7 3 
(*??*??

*/

