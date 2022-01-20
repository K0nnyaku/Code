#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

typedef long long ll;
const int maxn = 1e6 + 9, inf = 2e9;
const ll INF = 1e18;

int read() {
	int x = 0, f = 0, ch = getchar();
	for (; !isdigit(ch); f = (ch == '-'), ch = getchar()) ;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar()) ;
	return f ? -x : x; 
}

void read(ll &x) {
	int f = 0, ch = getchar();
	for (; !isdigit(ch); f = (ch == '-'), ch = getchar()) ;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar()) ;
	x = f ? -x : x;
}

int n;
int a[maxn], lp, rp, Lp, Rp;

int ans[maxn], top, rans[maxn], top2;

bool solve(int x, int y, int z, int w) {
	lp = x, rp = y, Lp = z, Rp = w;
	for (int i = 1; i <= n - 1; ++i) {
		if (lp < rp && a[lp] == a[rp]) ans[++top] = lp++, rans[++top2] = rp--;
  		else if (lp <= rp && Lp <= Rp && a[lp] == a[Lp]) ans[++top] = lp++, rans[++top2] = Lp++;
 		else if (lp <= rp && Lp <= Rp && a[Rp] == a[rp]) ans[++top] = Rp--, rans[++top2] = rp--;
 		else if (Lp < Rp && a[Rp] == a[Lp]) ans[++top] = Rp--, rans[++top2] = Lp++;
 		else return 0;
	}
	lp = 1, rp = 2 * n;
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == lp) putchar('L'), ++lp;
		else if (ans[i] == rp) putchar('R'), --rp;
	}
	for (int i = n; i >= 1; --i) {
		if (rans[i] == lp) putchar('L'), ++lp;
		else if (rans[i] == rp) putchar('R'), --rp;
	}
	puts("");
	return 1;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= 2 * n; ++i) a[i] = read();
		int pos = 0;
		for (int i = 2; i <= 2 * n; ++i) {
			if (a[i] == a[1]) {
				pos = i;
				break;
			}
		}
		ans[top = 1] = 1;
		rans[top2 = 1] = pos;
		if (solve(2, pos - 1, pos + 1, n * 2)) continue;
		pos = 0;
		for (int i = 1; i <= 2 * n - 1; ++i) {
			if (a[i] == a[2 * n]) {
				pos = i;
				break;
			}
		}
		ans[top = 1] = 2 * n;
		rans[top2 = 1] = pos;
		if (solve(1, pos - 1, pos + 1, 2 * n - 1)) continue;
		puts("-1");
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
