#include <cstdio>
#define MAXN 101
int opt[MAXN], a[MAXN], tmp[MAXN];
bool check(int n, int num) {
	int l = 1, r = n;
	for (int i = n; i >= 1; i--) {
		opt[i] = num % 2; num >>= 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!opt[i]) {
			tmp[i] = a[l]; l++;
		} else {
			tmp[i] = a[r]; r--;
		}
	}
	n /= 2;
	for (int i = 1; i <= n; i++) {
		if (tmp[i] != tmp[n * 2 - i + 1]) return false;
	}
	return true;
}
void work() {
	int n; scanf("%d", &n);
	if (n >= 15) {
		printf("-1"); return;
	}
	for (int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
	n *= 2;
	for (int i = 0; i <= (1 << n) - 1; i++) {
		if (check(n, i)) {
			for (int j = 1; j <= n; j++) {
				if (opt[j]) printf("R");
				else printf("L");
			}
			puts("");
			return;
		}
	}
	printf("-1\n");
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
