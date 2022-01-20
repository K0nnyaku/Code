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
#include <set> 

namespace chiaro {

const int inf = 2e5 + 7;
const int INF = 0x7fffffff;

template <class T>
inline void read(T &num) {
	num = 0; char c = getchar(), up = c;
	while(!isdigit(c)) up = c, c = getchar();
	while(isdigit(c)) num = (num << 1) + (num << 3) + (c - '0'), c = getchar();
	up == '-' ? num = -num : 0;
}

inline void setting() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
}

int a[inf], b[inf];
int n, n1, n2, m;

namespace baoli {

int ans;
bool vis[inf];
std::pair <int, int> lsh[inf];
int ndx;

inline int getans(int *a, int x) {
	int now = 0, res = 0;
	std::fill(vis + 1, vis + 1 + m, 0);
	for(int i = 1; i <= (m << 1); i++) {
		if(a[i] == 0) continue;
		if(a[i] > 0) {
			if(now < x) {
				vis[a[i]] = 1;
				++now, ++res;
			}
		} else {
			if(vis[-a[i]]) {
				--now;
				vis[-a[i]] = 0;
			}
		}
	}
	return res;
}

inline void solve() {
	for(int i = 1; i <= n1; i++) {
		int x, y; read(x); read(y);
		lsh[++ndx].first = x; lsh[ndx].second = i;
		lsh[++ndx].first = y; lsh[ndx].second = -i;
	}
	std::sort(lsh + 1, lsh + 1 + ndx);
	for(int i = 1; i <= ndx; i++) a[i] = lsh[i].second;
	ndx = 0;
	for(int i = 1; i <= n2; i++) {
		int x, y; read(x); read(y);
		lsh[++ndx].first = x; lsh[ndx].second = i;
		lsh[++ndx].first = y; lsh[ndx].second = -i;
	}
	std::sort(lsh + 1, lsh + 1 + ndx);
	for(int i = 1; i <= ndx; i++) b[i] = lsh[i].second;
	m = std::max (n1, n2);
	for(int i = 0; i <= n; i++) {
		int tmp = getans(a, i) + getans(b, n - i);
		ans = std::max (ans, tmp);
	}
	std::cout << ans << '\n';
	exit(0);
}

}

#define pii std::pair <int, int>
#define mkp std::make_pair
#define bg first
#define ed second

std::set <pii> s;

inline void solvemain () {
	read(n); read(n1); read(n2);
	if(n <= 5000) baoli::solve();
	for(int i = 1; i <= n1; i++) {
		int x, y; read(x); read(y);
		s.insert(mkp(x, y));
	}
	s.insert(mkp(INF, INF));
	for(int i = 1; i <= n; i++) {
		a[i] = a[i - 1];
		std::set <pii> ::iterator x = s.upper_bound(mkp(0, 0));
		while(x->first != INF) {
			++a[i];
			int nxt = x->second;
			s.erase(x);
			x = s.upper_bound(mkp(nxt, 0));
		}
	}
	s.clear();
	for(int i = 1; i <= n2; i++) {
		int x, y; read(x); read(y);
		s.insert(mkp(x, y));
	}
	s.insert(mkp(INF, INF));
	for(int i = 1; i <= n; i++) {
		b[i] = b[i - 1];
		std::set <pii> ::iterator x = s.upper_bound(mkp(0, 0));
		while(x->first != INF) {
			++b[i];
			int nxt = x->second;
			s.erase(x);
			x = s.upper_bound(mkp(nxt, 0));
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		ans = std::max (a[i] + b[n - i], ans);
	}
	std::cout << ans << '\n';
}

}

signed main () {
	chiaro::setting();
	chiaro::solvemain();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

