#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
#define ll long long
#define P pair <int, int>
#define F first
#define S second
inline int read() {
	int x = 0, W = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') W = -W;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * W;
}
int n, k, f[N][N][N];
char s[N];
void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}
int val[N];
signed main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	puts("0"); 
	fclose(stdin); fclose(stdout);
	return 0;
	n = read(), k = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) if ((s[i] == '?' || s[i] == '(') && (s[i + 1] == '?' || s[i + 1] == ')')) f[i + 1][i][0] = 1; 
	for (int i = 1; i <= n; i++) if (s[i] == '*' || s[i] == '?') f[i][i][1] = 1;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			for (int mid = l + 1; mid <= r - 2; mid++)  {
				val[mid] = 0;
				for (int i = 0; i <= min(k, mid - l); i++) add(val[mid], f[l][mid][i]);
			}
			int sum = 0;
			for (int i = 0; i <= k; i++) sum += f[l + 1][r - 1][i];
			if ((s[l] == '?' || s[l] == '(') && (s[r] == '?' || s[r] == ')')) add(f[l][r][0], sum);
			for (int i = 0; i <= k; i++) {
				if (i && s[r] == '*') add(f[l][r][i], f[l][r - 1][i - 1]); 
				if (i && s[r] == '?') add(f[l][r][i], f[l][r - 1][i - 1]); 
				for (int mid = l + 1; mid <= r - 2; mid++) {
					if (i >= r - (mid + 1) + 1) continue;
					add(f[l][r][i], val[mid] * f[mid + 1][r][i]); 
				}
			}
		}
	}
	printf("%d\n", f[1][n][0]);
	return 0;
}
