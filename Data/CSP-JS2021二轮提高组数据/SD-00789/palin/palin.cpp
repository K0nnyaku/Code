#include <cstdio>
#include <iostream>
using namespace std;
int n, l, r, a[101], b[101]; bool flag; char ops[101];
void dfs(int x, char ch) {
	if (flag) return;
	if (x == 2 * n + 1) {
		for (int i = 1; i <= n; ++i)
			if (b[i] != b[n * 2 + 1 - i]) return;
		flag = true;
		for (int i = 1; i <= 2 * n; ++i)
			printf("%c", ops[i]);
		printf("\n");
	}
	ops[x] = ch;
	if (ch == 'L') {
		b[x] = a[l++];
		dfs(x + 1, 'L');
		dfs(x + 1, 'R');
		--l;
	} else {
		b[x] = a[r--];
		dfs(x + 1, 'L');
		dfs(x + 1, 'R');
		++r;
	}
}
int mian() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; ++i) scanf("%d", &a[i]);
	l = 1, r = 2 * n;
	flag = 0;dfs(1, 'L'); dfs(1, 'R');
	if (flag == 0) printf("-1\n");
	return 0;
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) mian();
	fclose(stdin); fclose(stdout);
	return 0;
}
