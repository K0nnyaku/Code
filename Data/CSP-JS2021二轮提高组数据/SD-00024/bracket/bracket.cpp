#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define ll long long
#define db double
#define ls(x) x << 1
#define rs(x) x << 1 | 1
using std::cout;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1; c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}
const int mod = 1e9 + 7;

int n, K, f[510][510], g[510][510], h[510][510], p[510][510], q[510][510], dp[510];
char str[2333];
int que(char a, char b) {
	if (a == '*' || b == '*' || a == ')' || b == '(') return 0;
	return 1;
}
int qk(int x) {
	return x >= mod ? x - mod : x;
}
int main() {
	freopen("bracket.in","r",stdin); 
	freopen("bracket.out","w",stdout);
	n = read(); K = read();
	scanf("%s", str + 1);
	for (int i = 1; i < n; i ++) {
		f[i][i + 1] = que(str[i], str[i + 1]);
		p[i][i + 1] = f[i][i + 1]; q[i][i + 1] = f[i][i + 1];
	}
	for (int len = 3; len <= n; len ++)
		for (int i = 1; i + len - 1 <= n; i ++) {
			int j = i + len - 1, c = que(str[i], str[j]);
			f[i][j] = qk(f[i][j] + 1ll * c * f[i + 1][j - 1] % mod);
			bool flag = 1;
			for (int k = i + 1; k < j; k ++) flag &= (str[k] == '*' || str[k] == '?');
			if (j - i - 1 <= K && flag) f[i][j] += c;
			f[i][j] = qk(f[i][j] + 1ll * c * g[i + 1][j - 1] % mod);
			f[i][j] = qk(f[i][j] + 1ll * c * h[i + 1][j - 1] % mod);
			p[i][j] = f[i][j]; q[i][j] = f[i][j];
			for (int k = i; k < j; k ++) {
				f[i][j] = qk(f[i][j] + 1ll * q[i][k] * g[k + 1][j] % mod);
				f[i][j] = qk(f[i][j] + 1ll * q[i][k] * f[k + 1][j] % mod);
				p[i][j] = qk(p[i][j] + 1ll * q[i][k] * p[k + 1][j] % mod);
			} 
			flag = 1;
			for (int k = i; k < j; k ++) {
				flag &= (str[k] == '*' || str[k] == '?');
				if (k - i + 1 > K || !flag) break;
				g[i][j] = qk(g[i][j] + f[k + 1][j]);
			}
			flag = 1;
			for (int k = j; k > i; k --) {
				flag &= (str[k] == '*' || str[k] == '?');
				if (j - k + 1 > K || !flag) break;
				h[i][j] = qk(h[i][j] + f[i][k - 1]);
			}
		}
	cout << f[1][n] << "\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
