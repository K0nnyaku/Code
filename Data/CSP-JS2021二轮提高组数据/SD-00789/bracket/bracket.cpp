#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int mod = 1000000007;
int n, limt; char s[509];
unsigned int dp[501][501][501], dp2[501][501][501];
void mods(int a, int b, int c) {
	dp[a][b][c] %= mod;
}
void modss(int a, int b, int c) {
	dp2[a][b][c] %= mod;
}
bool valid(int x, char ch) {
	if (s[x] == '?' || s[x] == ch) return true;
	return false;
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &limt);
	scanf("%s", s + 1);
	int len, i, j, k;
	for (len = 1; len <= n; ++len) {
		for (i = 1; i + len - 1 <= n; ++i) {
			j = i + len - 1;
			if (len == 1) if (s[i] == '*' || s[i] == '?') dp[i][j][1] = 1;
			if (len == 2) {
				if (limt >= 2) if (s[i] == '*' && s[j] == '*') dp[i][j][2] = 1;
				if (limt >= 2) if (s[i] == '*' && s[j] == '?') dp[i][j][2] = 1;
				if (limt >= 2) if (s[i] == '?' && s[j] == '*') dp[i][j][2] = 1;
				if (s[i] == '(' && s[j] == ')') dp[i][j][0] = 1;
				if (s[i] == '(' && s[j] == '?') dp[i][j][0] = 1;
				if (s[i] == '?' && s[j] == ')') dp[i][j][0] = 1;
				if (limt >= 2) if (s[i] == '?' && s[j] == '?') dp[i][j][0] = 1, dp[i][j][2] = 1;
				if (limt < 2) if (s[i] == '?' && s[j] == '?') dp[i][j][0] = 1;
			}
			if (len < 3) continue;
			if (len <= limt && len - 1 != 0) if (s[i] == '*' || s[i] == '?') dp[i][j][len] = dp[i + 1][j][len - 1];
			if (valid(i, '(') && valid(j, ')')) {
				if (len - 2 <= limt && len - 2 != 0) dp[i][j][0] += dp[i + 1][j - 1][len - 2];
				dp[i][j][0] += dp[i + 1][j - 1][0];
				mods(i, j, 0);
				for (k = i + 1; k + 1 < j; ++k) {
					if (j - k - 1 <= limt && j - k - 1 != 0)
					 dp[i][j][0] += (1ull * dp[i + 1][k][0] * dp[k + 1][j - 1][j - k - 1] % mod);
					if (k - i <= limt && k - i != 0)
					 dp[i][j][0] += (1ull * dp[i + 1][k][k - i] * dp[k + 1][j - 1][0] % mod);
					mods(i, j, 0);
				}
			}
			for (k = i; k + 1 <= j; ++k) {
				if (j - k <= limt && j - k != 0)
				 dp2[i][j][0] += (1ull * dp[i][k][0] * dp[k + 1][j][j - k] % mod);
				modss(i, j, 0);
				dp[i][j][0] += (1ull * dp2[i][k][0] * dp[k + 1][j][0] % mod);
				dp[i][j][0] += (1ull * dp[i][k][0] * dp[k + 1][j][0] % mod);
				mods(i, j, 0);
			}
		}
	}
	printf("%u", dp[1][n][0]);
	fclose(stdin); fclose(stdout);
	return 0;
}
