#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int read() {
	int x = 0, f = 1; char ch;
	ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int T, n, a[100005], ans[100005], w[100005], b[100005];

bool ansflag;

void make_ans(int l, int r) {
	bool flag = true;
	for(int i = n; i >= 1; i--) {
		flag = true;
		if(b[i] == a[l]) w[n + n - i + 1] = 1, l = l + 1, flag = false;
		else
			if(b[i] == a[r] && ans[n + n - i + 1] == 0) w[n + n - i + 1] = 0, r = r - 1, flag = false;
		if(flag) return;
	}
	for(int i = 1; i <= n * 2; i++) ans[i] = w[i];
	ansflag = true;
}

void dfs(int k, int l, int r) {
	if(k > n) {
		make_ans(l ,r);
		return;
	}
	b[k] = a[l]; w[k] = 1;
	dfs(k + 1, l + 1, r);
	if(ans[k] == 0) {
		b[k] = a[r]; w[k] = 0;
		dfs(k + 1, l, r - 1);
	}
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = read();
	while(T--) {
		n = read();
		for(int i = 1; i <= n * 2; i++) a[i] = read();
		memset(ans, 0, sizeof(ans));
		ansflag = false;
		dfs(1, 1, n * 2);
		if(ansflag) {
			for(int i = 1; i <= 2 * n; i++) {
				if(ans[i] == 1) printf("L");
				else printf("R");
			}
			printf("\n"); 
		}
		else printf("-1\n"); 
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

