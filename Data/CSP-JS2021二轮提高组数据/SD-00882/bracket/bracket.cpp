#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lld;
const int N = 505;
const lld mod = 1e9 + 7;

inline int read() {
	int res = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-')  f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = (res << 3) +  (res << 1) + c - '0';
		c = getchar();
	}
	return res * f;
}

int n, k;
char c[N];
lld f[N][N];
bool as[N][N];

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(), k = read();
	scanf("%s", c + 1);
	
	for (int i = 1; i < n; ++i) {
		if ((c[i] == '(' || c[i] == '?') && (c[i + 1] == ')' || c[i + 1] == '?'))
			f[i][i + 1] = 1;
		if (c[i] == '?' || c[i] == '*')  as[i][i] = 1;
	}
	if (c[n] == '?' || c[n] == '*')  as[n][n] = 1;
		
	for (int len = 1; len < k; ++len)
		for (int i = 1, j; i + len <= n; ++i) {
			j = i + len;
			as[i][j] = ((as[i + 1][j] && (c[i] == '*' || c[i] == '?')) || (as[i][j - 1] && (c[j] == '*' || c[j] == '?')));
		}
	
	for (int len = 2; len < n; ++len)
		for (int i = 1, j; i + len <= n; ++i) {
			j = i + len;
			if ((c[i] == '(' || c[i] == '?') && (c[j] == ')' || c[j] == '?')) {
				f[i][j] = (f[i][j] + f[i + 1][j - 1]) % mod;
				
				if (as[i + 1][j - 1])  f[i][j]++;
				
				for (int l = 1; l <= min(k, j - i - 1); ++l) {
					if (as[i + 1][i + l])
						f[i][j] = (f[i][j] + f[i + l + 1][j - 1]) % mod;
				
					if (as[j - l][j - 1])
						f[i][j] = (f[i][j] + f[i + 1][j - l - 1]) % mod;
				}
				for (int l = i; l <= j; ++l) {
					f[i][j] = (f[i][j] + f[i][l] * f[l + 1][j] % mod) % mod;
					for (int ls = 0; ls < min(k, j - l); ++ls) {
						if (as[l][l + ls])
							f[i][j] = (f[i][j] + f[i][l - 1] * f[l + ls + 1][j] % mod) % mod;
					}
				}
			}
		}
	
	printf("%lld\n", f[1][n]);
	return 0;
}

