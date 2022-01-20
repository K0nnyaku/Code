#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cmath>

inline void read(int &x) {
	register char ch = 0; register bool w = 0;
	for(; !std::isdigit(ch); w |= ch == '-', ch = getchar());
	for(x = 0; std::isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
}
typedef long long ll;

const int N = 1000005;
const ll mod = 1e9 + 7;

int n, m, ai[N], bi[N];

bool dfs(int dep) {
	if(dep == m) {
		int ci[25] = {0};
		int l = 1, r = m, cnt = 0;
		for(int i = 1; i <= m; ++i) {
			if(bi[i]) ci[++cnt] = ai[r], --r;
			else ci[++cnt] = ai[l], ++l;
		}
		for(int i = 1; i <= n; ++i) if(ci[i] != ci[m + 1 - i]) return 0;
		for(int i = 1; i <= m; ++i) printf("%c", bi[i] ? 'R' : 'L');
		printf("\n");
		return 1;
	}
	bi[dep + 1] = 0;
	if(dfs(dep + 1)) return 1;
	bi[dep + 1] = 1;
	if(dfs(dep + 1)) return 1;
	return 0;
}

void solve() {
	read(n); m = 2 * n;
	for(int i = 1; i <= m; ++i) read(ai[i]), bi[i] = 0;
	if(n <= 10) {
		if(!dfs(0)) printf("-1\n");
		return;
	} else {
		bool flag = 1;
		for(int i = 1; i <= m; ++i) if(ai[i] != ai[m + 1 - i]) {
			flag = 0; break;
		}
		if(flag) {
			for(int i = 1; i <= m; ++i) printf("L");
			printf("\n");
			return;
		} else {
			printf("-1\n"); return;
		}
	}
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T; read(T);
	while(T--) solve();
	fclose(stdin); fclose(stdout);
	return 0;
}
