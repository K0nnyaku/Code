#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <vector>
#include <set>

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

const int MAXN = 1e5 + 10;

int n, m1, m2;

struct E {
	int l, r;
	bool operator < (const E &th) const {
		return l < th.l;
	}
} dom[MAXN], itl[MAXN]; 

namespace Task1 {
	int check(int mid) {
		int doms = mid, itls = n - mid;
		
		std::set<int> endings;
		int domans = 0;
		for (int i = 1; i <= m1; ++i) {
			E now = dom[i];
			while (endings.size() && *endings.begin() < now.l) {
				endings.erase(endings.begin());
			}
			if ((int) endings.size() < doms) {
				endings.insert(now.r);
				++domans;
			}
		}
		endings.clear();
		int itlans = 0;
		for (int i = 1; i <= m2; ++i) {
			E now = itl[i];
			while (endings.size() && *endings.begin() < now.l) {
				endings.erase(endings.begin());
			}
			if ((int) endings.size() < itls) {
				endings.insert(now.r);
				++itlans;
			}
		} 
		return domans + itlans;
	}
	
	void _main() {
		int ans = 0;
		for (int t1 = 0; t1 <= n; ++t1) {
			ans = std::max(ans, check(t1));
		}
		printf("%d\n", ans);
	} 
}

namespace TaskAC {
	int ansdom[MAXN];
	int ansitl[MAXN];
	
	void check() {
		
		std::set<std::pair<int, int> > endings;
		std::set<int> empties;
		for (int i = 1; i <= n; ++i) empties.insert(i);
		int domans = 0;
		for (int i = 1; i <= m1; ++i) {
			E now = dom[i];
			while (endings.size() && endings.begin()->first < now.l) {
				empties.insert(endings.begin()->second);
				endings.erase(endings.begin());
			}
			if (empties.empty()) continue;
			endings.insert(std::make_pair(now.r, *empties.begin()));
			for (int x = (int) *empties.begin(); x <= n; ++x) {
				ansdom[x]++;
			}
			empties.erase(empties.begin()); 
		}
		
		
		
		
		
		endings.clear();
		empties.clear();
		for (int i = 1; i <= n; ++i) empties.insert(i);
		int itlans = 0;
		for (int i = 1; i <= m2; ++i) {
			E now = itl[i];
			while (endings.size() && endings.begin()->first < now.l) {
				empties.insert(endings.begin()->second);
				endings.erase(endings.begin());
			}
			if (empties.empty()) continue;
			endings.insert(std::make_pair(now.r, *empties.begin()));
			for (int x = (int) *empties.begin(); x <= n; ++x) {
				ansitl[x]++;
			}
			empties.erase(empties.begin()); 
		}
	}

	void _main() {
		
		check();
	
		int ans = 0;
		for (int i = 0; i <= n; ++i) {
	//		printf("ansdom[%d] = %d\n", i, ansdom[i]);
	//		printf("ansitl[%d] = %d\n", i, ansitl[i]);
			ans = std::max(ans, ansdom[i] + ansitl[n - i]);
		} 
		
		printf("%d\n", ans);
	} 
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout); 
	n = read(); m1 = read(); m2 = read();
	for (int i = 1; i <= m1; ++i) {
		dom[i].l = read(); dom[i].r = read();
	} std::sort(dom + 1, dom + 1 + m1);
	
	for (int i = 1; i <= m2; ++i) {
		itl[i].l = read(); itl[i].r = read();
	} std::sort(itl + 1, itl + 1 + m2);
	
	if (n <= 5000) Task1::_main();
	else TaskAC::_main(); 
	
	return 0;
}


