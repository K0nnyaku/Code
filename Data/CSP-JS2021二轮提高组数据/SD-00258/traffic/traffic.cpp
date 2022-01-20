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

const int inf = 2e5 + 3;
const int INF = 0x7fffffff;

template <class T>
inline void read(T &num) {
	num = 0; char c = getchar(), up = c;
	while(!isdigit(c)) up = c, c = getchar();
	while(isdigit(c)) num = (num << 1) + (num << 3) + (c - '0'), c = getchar();
	up == '-' ? num = -num : 0;
}

inline void setting() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
}

inline void solvemain () {
	setting();
	int T, n, m; read(T); read(n); read(m);
	while(T--) {
		
	}
}

}

signed main () {
	chiaro::solvemain();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

