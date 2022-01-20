#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <functional>
#include <cctype>
#include <queue>
#include <utility>

namespace chiaro {

const int inf = 5e5 + 7;
const int INF = 0x7fffffff;

template <class T>
inline void read(T &num) {
	num = 0; char c = getchar(), up = c;
	while(!isdigit(c)) up = c, c = getchar();
	while(isdigit(c)) num = (num << 1) + (num << 3) + (c - '0'), c = getchar();
	up == '-' ? num = -num : 0;
}

inline void setting() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
}

int n;
int a[inf];
bool ans[inf];
bool flag;
int now[inf];

inline void print() {
	for(int i = 1; i <= (n << 1); i++) {
		printf("%c", "LR"[ans[i]]);
	}
	puts("");
}

inline bool check() {
	for(int i = 1; i <= n; i++) {
		if(now[i] ^ now[(n << 1) - i + 1]) return 0;
	}
	print();
	flag = 1;
	return 1;
}

void dfs(int x, int l, int r) {
	if(x > (n << 1)) {
		check();
		return;
	}
	ans[x] = 0;
	now[x] = a[l];
	dfs(x + 1, l + 1, r);
	if(flag) return;
	ans[x] = 1;
	now[x] = a[r];
	dfs(x + 1, l, r - 1);
}

inline void solve() {
	flag = 0;
	read(n);
	for(int i = 1; i <= (n << 1); i++) read(a[i]);
	dfs(1, 1, n << 1);
	if(!flag) puts("-1");
}

inline void solvemain () {
	setting();
	int T; read(T);
	while(T--) {
		solve();
	}
}

}

signed main () {
	chiaro::solvemain();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

