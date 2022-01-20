#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int t, n, a[N];
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool palin = true, eq = true;
		for (int i = 1; i <= n << 1; i++) {
			scanf("%d", a + i);
			if (i > n) {
				if (a[i] != a[(n << 1) - i + 1]) {
					palin = false;
				}
				if (a[i] != a[i - n]) {
					eq = false;
				}
			}
		}
		if (palin) {
			for (int i = 1; i <= n << 1; i++) {
				putchar('L');
			}
			putchar('\n');
		} else if (eq) {
			for (int i = 1; i <= n; i++) {
				putchar('L');
			}
			for (int i = 1; i < n; i++) {
				putchar('R');
			}
			putchar('L');
			putchar('\n');
		} else {
			puts("-1");
		}
	}
	return 0;
}
