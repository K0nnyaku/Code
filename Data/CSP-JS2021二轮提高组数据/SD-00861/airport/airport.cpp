#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define SIZE 100005
using namespace std;

int n, m1, m2, ans;
struct tingkao {
	int l, r;
}a[SIZE], b[SIZE];
priority_queue <int, vector<int>, greater<int> > q;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

bool cmp(tingkao x, tingkao y) {
	return x.l < y.l;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for(int i = 1; i <= m1; ++i)
		a[i].l = read(), a[i].r = read();
	for(int i = 1; i <= m2; ++i)
		b[i].l = read(), b[i].r = read();
	sort(a + 1, a + m1 + 1, cmp);
	sort(b + 1, b + m2 + 1, cmp);
	for(int i = n; i >= 0; --i) {
		int m = 0, sum1 = 0, sum2 = 0;
		for(int j = 1; j <= m1; ++j) {
			if(q.size() && q.top() < a[j].l) q.pop(), q.push(a[j].r), sum1++;
			else if(m < i) m++, sum1++, q.push(a[j].r);
		}
		while(q.size()) q.pop();
		m = 0;
		for(int j = 1; j <= m2; ++j) {
			if(q.size() && q.top() < b[j].l) q.pop(), q.push(b[j].r), sum2++;
			else if(m < n - i) m++, sum2++, q.push(b[j].r);
		}
		while(q.size()) q.pop();
		ans = max(ans, sum1 + sum2);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
