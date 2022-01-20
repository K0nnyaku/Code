#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>

#define N 2000979
using namespace std;
int T, n, a[N], b[N], tot = 0;
char ch[N], ans[N];
bool fg = false;

void dfs(int l, int r, int p, int q) {
	if (tot > n && (b[tot] != b[2 * n - tot + 1])) return; 
	if (l == r + 1) {
		if (!fg) {
			for (int i = 1; i <= 2 * n; i++) 
				ans[i] = ch[i];
			fg = true;
		}
		else {
			bool pd = false;
			for (int i = 1; i <= 2 * n; i++) {
				if (ans[i] > ch[i]) {pd = true; break;}
				if (ans[i] < ch[i]) {pd = false; break;}
			} 
			if (pd) {for (int i = 1; i <= 2 * n; i++) ans[i] = ch[i]; return;}
		}
		return;
	}
	b[++tot] = a[p]; ch[tot] = 'L';
	dfs(l + 1, r, p + 1, q);
	b[tot] = a[q]; ch[tot] = 'R';
	dfs(l + 1, r, p, q - 1);
	b[tot] = 0; tot--;
	return;
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		tot = 0;
		scanf("%d", &n); fg = false;
		for (int i = 1; i <= 2 * n; i++)
			scanf("%d", &a[i]);
		dfs(1, 2 * n, 1, 2 * n);
		if (fg) {
			for (int i = 1; i <= n * 2; i++) 
				printf("%c", ans[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}

