#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <vector>

typedef long long int lli;

int read() {
	int s = 0, x = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') x = -x;
		ch = getchar();
	}
	while (isdigit(ch)) {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * x;
}

lli readll() {
	lli s = 0, x = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') x = -x;
		ch = getchar();
	}
	while (isdigit(ch)) {
		s = s * 10ll + ch - '0';
		ch = getchar();
	}
	return s * x;
}

const int MAXN = 500 + 10;
const int HA = 1e9 + 7;

int n, kk;
char ss[MAXN];

int dp[2][MAXN][MAXN];

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout); 
	scanf("%d %d", &n, &kk);
	scanf("%s", ss + 1);
	
	dp[1][1][0] = (ss[1] == '(' || ss[1] == '?');
	for (int i = 2; i <= n; ++i) {
		int cur = (i & 1);
		for (int j = 0; j <= n; ++j) 
			for (int k = 0; k <= kk; ++k) dp[cur][j][k] = 0;
		for (int j = 0; j <= i; ++j) {
//			if (i == 7 && j == 0) {
//				puts("QAQ"); 
//			}
			if (ss[i] == '(' || ss[i] == '?') {
				if (j) for (int k = 0; k <= kk; ++k) {
					(dp[cur][j][0] += dp[cur ^ 1][j - 1][k]) %= HA;
				}
			}
			if (ss[i] == ')' || ss[i] == '?') {
				for (int k = 0; k <= kk; ++k) {
					(dp[cur][j][0] += dp[cur ^ 1][j + 1][k]) %= HA;
				}
			}
			if (i != n) if (ss[i] == '*' || ss[i] == '?') {
				for (int k = 1; k <= kk; ++k) {
					(dp[cur][j][k] += dp[cur ^ 1][j][k - 1]) %= HA;
				}
			}
		}
//		for (int j = 0; j <= i; ++j) {
//			for (int k = 0; k <= kk; ++k) {
//				printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[cur][j][k]);
//			}
//		}
	}
	printf("%d\n", dp[n & 1][0][0]);
} 

