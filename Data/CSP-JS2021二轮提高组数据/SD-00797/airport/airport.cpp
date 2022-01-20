#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <vector>
#define write(n) (n < 0 ? (putchar('-'), rite(-n)) : rite(n))
using namespace std;
inline int read() {
	int x = 0, b = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			b = 0;
		}
		c = getchar(); 
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ '0');
		c = getchar();
	}
	return b ? x : -x;
}
void rite(int n) {
	if (n > 9) {
		rite(n / 10);
	}
	putchar(n % 10 ^ '0');
} 
struct node {
	int a, b;
	bool operator < (node y) const {
		return a < y.a;
	}
}a[100002], b[100002];
int suma[100002], sumb[100002];
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= m1; ++i) {
		a[i].a = read(), a[i].b = read();
	}
	for (int i = 1; i <= m2; ++i) {
		b[i].a = read(), b[i].b = read();
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >,  greater<pair<int, int> > > key;
	priority_queue<int, vector<int>, greater<int> > tim;
	sort(a + 1, a + m1 + 1);
	sort(b + 1, b + m2 + 1);
	for (int i = 1; i <= m1; ++i) {
		while (!(key.empty()) && a[i].a > key.top().first) {
			tim.push(key.top().second); 
			key.pop();
		}
		if (tim.empty()) {
			++suma[key.size() + 1];
			key.push(make_pair(a[i].b, key.size() + 1));
		} else {
			++suma[tim.top()];
			key.push(make_pair(a[i].b, tim.top()));
			tim.pop();
		}
	}
	while (!key.empty()) {
		key.pop();
	}
	while (!tim.empty()) {
		tim.pop();
	}
	for (int i = 1; i <= m2; ++i) {
		while (!(key.empty()) && b[i].a > key.top().first) {
			tim.push(key.top().second); 
			key.pop();
		}
		if (tim.empty()) {
			++sumb[key.size() + 1];
			key.push(make_pair(b[i].b, key.size() + 1));
		} else {
			++sumb[tim.top()];
			key.push(make_pair(b[i].b, tim.top()));
			tim.pop();
		}
	}
	for (int i = 1; i <= n; ++i) {
		suma[i] += suma[i - 1];
		sumb[i] += sumb[i - 1]; 
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, suma[i] + sumb[n - i]);
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
