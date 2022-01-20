#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
#include <set>

using namespace std;

int n, m1, m2;
pair<int, int> a[100005], b[100005];

namespace Sub1 {
	struct SEG {
		int l, r;
		SEG() {}
		SEG(int l, int r) : l(l), r(r) {}
		SEG(pair<int, int> x) : l(x.first), r(x.second) {}
		bool operator < (const SEG& o) const {
			return l < o.l;
		}
	};
	set<SEG> st[205];
	int find(int x, int siz, pair<int, int> t) {
		for (int i = x; i <= x + siz - 1; ++i) {
			if (st[i].empty()) return i;
			set<SEG>::iterator it = st[i].upper_bound(SEG(t));
			if (it == st[i].end()) {
				--it;
				if (it->r < t.first) return i;
			}
			else {
				if (it->l > t.second) {
					--it;
					if (it->r < t.first) {
						return i;
					}
				}
			}
		}
		return 0;
	}
	int calc(int k) {
		int ans = 0;
		for (int i = 0; i <= n; ++i) {
			if (st[i].size()) {
				st[i].clear();
			}
		}
		for (int i = 1; i <= m1; ++i) {
			int x = find(1, k, a[i]);
			if (x) {
				++ans;
				st[x].insert(SEG(a[i]));
			}
		}
		for (int i = 1; i <= m2; ++i) {
			int x = find(k + 1, n - k, b[i]);
			if (x) {
				++ans;
				st[x].insert(SEG(b[i]));
			}
		}
		return ans;
	}
	int solve() {
		int ans = 0;
		sort(a + 1, a + m1 + 1);
		sort(b + 1, b + m2 + 1);
		for (int i = 0; i <= n; ++i) {
			int t = calc(i);
			if (t > ans) ans = t;
		}
		return ans;
	}
}

namespace Sub2 {
	
	struct DAT {
		struct SEG {
			int l, r;
			SEG() {}
			SEG(int l, int r) : l(l), r(r) {}
			SEG(pair<int, int> x) : l(x.first), r(x.second) {}
			bool operator < (const SEG& o) const {
				return l < o.l;
			}
		};
		set<SEG> st[200005];
		int find(pair<int, int> t) {
			for (int i = 1; i <= n; ++i) {
				if (st[i].empty()) return i;
				set<SEG>::iterator it = st[i].upper_bound(SEG(t));
				if (it == st[i].end()) {
					--it;
					if (it->r < t.first) return i;
				}
				else {
					if (it->l > t.second) {
						--it;
						if (it->r < t.first) {
							return i;
						}
					}
				}
			}
			return 0;
		}
		void insert(pair<int, int> p) {
			int x = find(p);
			if (x) {
				st[x].insert(SEG(p));
			}
		}
	};
	
	DAT d[2];
	
	int solve() {
		int ans = 0;
		sort(a + 1, a + m1 + 1);
		sort(b + 1, b + m2 + 1);
		for (int i = 1; i <= m1; ++i) {
			d[0].insert(a[i]);
		}
		for (int i = 1; i <= m2; ++i) {
			d[1].insert(b[i]);
		}
		for (int i = 0; i <= n; ++i) {
			ans += d[0].st[i].size();
		}
		for (int i = 0, t = ans; i < n; ++i) {
			t = t - d[0].st[n - i].size() + d[1].st[i + 1].size();
			if (t > ans) ans = t;
		}
		return ans;
	}
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= m1; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 1; i <= m2; ++i) {
		cin >> b[i].first >> b[i].second;
	}
	if (n <= 100) {
		cout << Sub1::solve() << endl;
	} 
	else {
		cout << Sub2::solve() << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


