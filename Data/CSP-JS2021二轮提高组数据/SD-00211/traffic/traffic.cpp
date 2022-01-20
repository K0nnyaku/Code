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

int n;
// duliu csp
// why it is so hard this year
// fuck ccf
// I'll lose my 1=

__int128 T;

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	T = 19260817;
	std::vector<int> qwq;
	qwq.push_back(1); int ans = 0;
	for(auto v : qwq) ans += v;
	return 0;
}
