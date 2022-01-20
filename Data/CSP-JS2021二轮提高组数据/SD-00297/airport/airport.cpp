#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}

const int MAXN = 100005;
int n, mgn, mgw;
pair<int, int> gn[MAXN], gw[MAXN];

inline int solve(int gnlq, int gwlq) {
	int res = 0, curtime = 0;
	__gnu_pbds::priority_queue<int, greater<int>, __gnu_pbds::pairing_heap_tag> q;
	if (gnlq) {
		q.push(gn[1].second);
		++res;
		for (int i = 2; i <= mgn; ++i) {
			curtime = gn[i].first;
			while (q.size() && q.top() < curtime)
				q.pop();
			if (q.size() < gnlq) {
				q.push(gn[i].second);
				++res;
			}
		}
	}
	q.clear();
	curtime = 0;
	if (gwlq) {
		q.push(gw[1].second);
		++res;
		for (int i = 2; i <= mgw; ++i) {
			curtime = gw[i].first;
			while (q.size() && q.top() < curtime)
				q.pop();
			if (q.size() < gwlq) {
				q.push(gw[i].second);
				++res;
			}
		}
	}
	return res;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), mgn = read(), mgw = read();
	for (int i = 1; i <= mgn; ++i) {
		gn[i].first = read();
		gn[i].second = read();
	}
	for (int i = 1; i <= mgw; ++i) {
		gw[i].first = read();
		gw[i].second = read();
	}
	sort(gn + 1, gn + mgn + 1);
	sort(gw + 1, gw + mgw + 1);
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		ans = max(ans, solve(i, n - i));
	printf("%d\n", ans);
	return 0; 
}
/*
模拟 40pts。 
O(n)枚举分配方案，对于每个 m，O(1) 找位置。
考虑优先队列维护最先空闲的廊桥，我们可以O(1)找位置。 

考虑换个方式，对于每个m，看最多同时在堆里面的数目。
知道这个数目，找一个均衡点。 
*/
