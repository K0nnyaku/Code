//T3±¬ËÑO((2^n)n)£¬Ô¤¼ÆµÃ·Ö28+pts 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
template<class T> inline void read(T &x) {
	x = 0; int f = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar();}
	while (c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c - 48); c = getchar();}
	if (f) x = ~x + 1;
}
template<class T> inline void write(T x) {
	if (x < 0) {putchar('-'); x = ~x + 1;}
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
#define writeS(x) write(x), putchar(' ')
#define writeL(x) write(x), putchar('\n')
int n, a[1000005], b[1000005], c[1000005];
char tmp[1000005], ans[1000005];
bool flag;
bool ckrev() {
	for (int i = 1, j = 2 * n; i <= j; ++i, --j)
		if (b[i] != b[j]) return false;
	return true;
}
bool ckmin() {
	for (int i = 1; i <= 2 * n; ++i) {
		if (tmp[i] < ans[i]) return true;
		if (tmp[i] > ans[i]) return false;
	}
}
void check() {
	int l = 1, r = 2 * n;
	for (int i = 1; i <= 2 * n; ++i) {
		if (tmp[i] == 'L') b[i] = a[l++];
		if (tmp[i] == 'R') b[i] = a[r--];
	}
	if (ckrev()) {
		if (flag == 0) {
			flag = 1;
			for (int i = 1; i <= 2 * n; ++i) {
				ans[i] = tmp[i];
				c[i] = b[i];
			}
		} else {
			if (ckmin()) {
				for (int i = 1; i <= 2 * n; ++i) {
					ans[i] = tmp[i];
					c[i] = b[i];
				}
			}
		}
	}
}
void dfs(int dep) {
	if (dep == 2 * n + 1) {
		check();
		return;
	}
	tmp[dep] = 'L';
	dfs(dep + 1);
	tmp[dep] = 'R';
	dfs(dep + 1);
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T;
	read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= 2 * n; ++i)
			read(a[i]);
		flag = 0;
		memset(ans, '\0', sizeof(ans));
		dfs(1);
		if (!flag) writeL(-1);
		else printf("%s\n", ans + 1);
	}
	return 0;
}
