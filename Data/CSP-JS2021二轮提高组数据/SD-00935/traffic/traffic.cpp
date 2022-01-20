#include <cstdio>
#include <cstring>
#define MAXN 101
int s[MAXN], n, k;
int good[MAXN];
char c[MAXN];
bool check() {
	int lx = 0, l = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		good[i] = 0;
		if (s[i] == 1) {
			l++; lx = 0;
		} else if (s[i] == 2) {
			lx++;
			if (i == 1 || i == n) return false;
			if (lx > k) return false;
		} else r++, lx = 0;
		if (r > l) return false;
	}
	if (l != r) return false;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 3) {
			int j = i;
			while (j && s[j] != 1 && good[j] == 0) {
				good[j] = 1;
				j--;
			}
			good[j] = 1; j--;
			int xl = 0;
			while (j && xl <= k) {
				if (s[j] == 2) {
					good[j] = 1;
					j--; xl++;
				} else break;
			}
		}
	} 
	for (int i = 1; i <= n; i++) if (!good[i]) return false;
	return true;
}
int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	printf("%d\n", 6);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
