#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int read() {
	int f = 0, s = 0;
	char ch = getchar();
	while (!isdigit(ch)) f |= ch == '-', ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

const int maxn = 1e6 + 10;
int T, n, a[maxn], flag, b[maxn], vis[maxn];

bool check() {
	int head = 1, back = 2 * n;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1) b[i] = a[head], head++;
		else b[i] = a[back], back--; 
	}
	int id = n;
	for (int i = n + 1; i <= 2 * n; i++) {
		if (a[head] == b[id]) {
			vis[i] = 1;
			head++;
			id--;
		}
		else if (a[back] == b[id]) {
			vis[i] = 2;
			back--;
			id--;
		}
		else return 0;
	}
	return 1;
}

void dfs(int now) {
	if (flag) return ;
	if (now == n + 1) {
		if (check()) {
			for (int i = 1; i <= 2 * n; i++) 
				if (vis[i] == 1) printf("L");
				else printf("R");
			flag = 1;
			return ;
		}
		return ;
	}
	vis[now] = 1;
	dfs(now + 1);
	vis[now] = 2;
	dfs(now + 1);
	vis[now] = 0;
}

signed main () {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
		flag = 0;
		dfs(1);
		if (!flag) printf("-1");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

