#include<cstdio>

const int N = 505;
int n, k;
char s[N];
int pre[N], sum[N], vis[N];

bool dfs(i) {
	s[i] = '*';
	for(int j = i + 1; j <= n; ++j) {
		if(s[j] == '?') dfs(j);
	}
	++ans;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d %s", &n, &k, s + 1);
	for(int i = 1; i <= n; ++i) {
		int tmp = 0, flg = 1;
		if(s[i] == '*') sum[i] = sum[i - 1] + 1;
		if(s[i] == '(') {
			pre[i] = tmp;
			tmp = i;
		}
		if(s[i] == ')') {
			int p = tmp;
			while(vis[p]) p = pre[p];
			pre[i] = p;
			vis[p] = 1;
		} 
	}
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '?') {
			dfs(i);
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
