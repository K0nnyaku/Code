#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 5;

inline int read() {
	int res = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-')  f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = (res << 3) +  (res << 1) + c - '0';
		c = getchar();
	}
	return res * f;
}

int n, m1, m2;
int ans;

struct node {
	int l, r;
}g1[N], g2[N];
bool cmp(node x, node y) {
	return x.l < y.l;
}

priority_queue <int> q;
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= m1; ++i)  g1[i].l = read(), g1[i].r = read();
	for (int i = 1; i <= m2; ++i)  g2[i].l = read(), g2[i].r = read(); 
	sort(g1 + 1, g1 + 1 + m1, cmp);
	sort(g2 + 1, g2 + 1 + m2, cmp);
	
	for (int i = 0; i <= n; ++i) {
		int rem = i, tmp = 0;
		for (int j = 1; j <= m1; ++j) {
			while (!q.empty() && g1[j].l > -q.top()) {
				q.pop();
				rem++;
			}
			if (rem) {
				++tmp;
				rem--;
				q.push(-g1[j].r);
			}
		} 
		while (!q.empty())  q.pop();
		
		rem = n - i;
		for (int j = 1; j <= m2; ++j) {
			while (!q.empty() && g2[j].l > -q.top()) {
				q.pop();
				rem++;
			}
			if (rem) {
				++tmp;
				rem--;
				q.push(-g2[j].r);
			}
		} 
		while (!q.empty())  q.pop();
		ans = max(ans, tmp);
	}
	
	printf("%d\n", ans);
	return 0;
}

