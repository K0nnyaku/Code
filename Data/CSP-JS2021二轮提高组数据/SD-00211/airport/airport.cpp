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

const int N = 200005;
const ll mod = 1e9 + 7;

int n, m1, m2, result;
int a1[N], b1[N], a2[N], b2[N], ans1[N], ans2[N];
std::set<std::pair<int, int> > S1, S2;

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(m1), read(m2);
	for(int i = 1; i <= m1; ++i) {
		read(a1[i]), read(b1[i]);
		S1.insert(std::make_pair(a1[i], i));
	}
	for(int i = 1; i <= m2; ++i) {
		read(a2[i]), read(b2[i]);
		S2.insert(std::make_pair(a2[i], i));
	}
	for(int i = 1; i <= n; ++i) {
		int tmp1 = ans1[i - 1];
		if(S1.size()) {
			std::set<std::pair<int, int> >::iterator u1 = S1.begin();
			while(u1 != S1.end()) {
				int now = u1->second;
				++tmp1;
//				printf("db %d\n", now);
				S1.erase(u1); if(S1.empty()) break;
				u1 = S1.upper_bound(std::make_pair(b1[now], 0));
			}
		}
		int tmp2 = ans2[i - 1];
		if(S2.size()) {
			std::set<std::pair<int, int> >::iterator u2 = S2.begin();
			while(u2 != S2.end()) {
				int now = u2->second;
				++tmp2;
//				printf("db2 %d\n", now);
				S2.erase(u2); if(S2.empty()) break;
				u2 = S2.upper_bound(std::make_pair(b2[now], 0));
			}
		}
		ans1[i] = tmp1, ans2[i] = tmp2;
//		printf("db %d %d %d\n", i, ans1[i], ans2[i]);
	}
	for(int i = 0; i <= n; ++i) {
		result = std::max(result, ans1[i] + ans2[n - i]);
	}
	printf("%d\n", result);
	fclose(stdin); fclose(stdout);
	return 0;
}
