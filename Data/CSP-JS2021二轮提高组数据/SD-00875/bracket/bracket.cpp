#include <stdio.h>
#include <string.h>

int n, K;
char str[505];

long long dp[2][505][505][2][2], ans;

long long do_dp() {
	memset(dp[0], 0, sizeof(dp[0]));
	dp[0][0][0][0][0] = 1;
	int now = 1, pre = 0;
	for (int i = 1; i <= n; ++i, now ^= 1, pre ^= 1) {
		memset(dp[now], 0, sizeof(dp[0]));
		if (str[i] == '(') {
			for (int j = 1; j <= i; ++j) {
				for (int k = 0; k <= K; ++k)
					dp[now][j][0][0][0] += dp[pre][j - 1][k][0][0] + dp[pre][j - 1][k][1][0];
				dp[now][j][0][0][0] %= 1000000007;
			}
		} else if (str[i] == ')') {
			for (int j = 0; j < i; ++j) {
				for (int k = 0; k <= K; ++k)
					dp[now][j][0][1][0] += dp[pre][j + 1][k][0][0] + dp[pre][j + 1][k][1][0] + dp[pre][j + 1][k][1][1];
				dp[now][j][0][1][0] %= 1000000007;
			}
		} else if (str[i] == '*') {
			for (int j = 0; j < i; ++j) {
				for (int k = 1; k <= K; ++k)
					dp[now][j][k][1][0] = dp[pre][j][k - 1][1][0];
				for (int k = 1; k <= K; ++k)
					dp[now][j][k][1][1] = dp[pre][j][k - 1][0][0] + dp[pre][j][k - 1][1][1];
			}
		} else {
			for (int j = 1; j <= i; ++j) {
				for (int k = 0; k <= K; ++k)
					dp[now][j][0][0][0] += dp[pre][j - 1][k][0][0] + dp[pre][j - 1][k][1][0];
				dp[now][j][0][0][0] %= 1000000007;
			}
			for (int j = 0; j < i; ++j) {
				for (int k = 0; k <= K; ++k)
					dp[now][j][0][1][0] += dp[pre][j + 1][k][0][0] + dp[pre][j + 1][k][1][0] + dp[pre][j + 1][k][1][1];
				dp[now][j][0][1][0] %= 1000000007;
			}
			for (int j = 0; j < i; ++j) {
				for (int k = 1; k <= K; ++k)
					dp[now][j][k][1][0] = dp[pre][j][k - 1][1][0];
				for (int k = 1; k <= K; ++k)
					dp[now][j][k][1][1] = dp[pre][j][k - 1][0][0] + dp[pre][j][k - 1][1][1];
			}
		}
	}
	return dp[pre][0][0][1][0];
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d %s", &n, &K, str + 1);
	ans = do_dp();
	for (int i = 1, j = n; i < j; ++i, --j)
		str[i] ^= str[j], str[j] ^= str[i], str[i] ^= str[j];
	for (int i = 1; i <= n; ++i)
		if (str[i] == '(') str[i] = ')';
		else if (str[i] == ')') str[i] = '(';
	ans += do_dp();
	int now = 1, pre = 0;
	memset(dp[0], 0, sizeof(dp[0]));
	dp[0][0][0][0][0] = 1;
	for (int i = 1; i <= n; ++i, now ^= 1, pre ^= 1) {
		memset(dp[now], 0, sizeof(dp[0]));
		if (str[i] == '(') {
			for (int j = 1; j <= i; ++j) {
				for (int k = 0; k <= K; ++k)
					dp[now][j][0][0][0] += dp[pre][j - 1][k][0][0] + dp[pre][j - 1][k][1][0];
				dp[now][j][0][0][0] %= 1000000007;
			}
		} else if (str[i] == ')') {
			for (int j = 0; j < i; ++j) {
				for (int k = 1; k <= K; ++k)
					dp[now][j][0][1][0] += dp[pre][j + 1][k][1][1];
				dp[now][j][0][1][0] += dp[pre][j + 1][0][0][0] + dp[pre][j + 1][0][1][0];
				dp[now][j][0][1][0] %= 1000000007;
			}
		} else if (str[i] == '*') {
			for (int j = 0; j < i; ++j) {
				for (int k = 1; k <= K; ++k)
					dp[now][j][k][1][0] = dp[pre][j][k - 1][1][0];
				for (int k = 1; k <= K; ++k)
					dp[now][j][k][1][1] = dp[pre][j][k - 1][0][0] + dp[pre][j][k - 1][1][1];
			}
		} else {
			for (int j = 1; j <= i; ++j) {
				for (int k = 0; k <= K; ++k)
					dp[now][j][0][0][0] += dp[pre][j - 1][k][0][0] + dp[pre][j - 1][k][1][0];
				dp[now][j][0][0][0] %= 1000000007;
			}
			for (int j = 0; j < i; ++j) {
				for (int k = 1; k <= K; ++k)
					dp[now][j][0][1][0] += dp[pre][j + 1][k][1][1];
				dp[now][j][0][1][0] += dp[pre][j + 1][0][0][0] + dp[pre][j + 1][0][1][0];
				dp[now][j][0][1][0] %= 1000000007;
			}
			for (int j = 0; j < i; ++j) {
				for (int k = 1; k <= K; ++k)
					dp[now][j][k][1][0] = dp[pre][j][k - 1][1][0];
				for (int k = 1; k <= K; ++k)
					dp[now][j][k][1][1] = dp[pre][j][k - 1][0][0] + dp[pre][j][k - 1][1][1];
			}
		}
	}
	ans -= dp[pre][0][0][1][0];
	printf("%lld\n", (ans % 1000000007 + 1000000007) % 1000000007);
	return 0;
}
