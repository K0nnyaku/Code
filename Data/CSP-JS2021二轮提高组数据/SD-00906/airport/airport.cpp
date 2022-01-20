#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n, lq1, lq2, m, ans = 0;
struct node {
	int l, r;
	bool operator < (const node a) const {
		return a.r < r;
	}
} arr[N], brr[N];
bool cmp(node a, node b) {
	if (a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}
int q_read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
	return x;
}
void work(int lq) {
	priority_queue<node> q;
	int id = 1, ans1 = 0, ans2 = 0;
	for (int i = 1; i <= m; ++i) {
		while (arr[id].l <= i && q.size() < lq && id <= lq1) {
			q.push(arr[id++]);
			ans1++;
		}
		while (arr[id].l <= i) id++;
		while (!q.empty()) {
			if (q.top().r <= i) q.pop();
			else break;
		}
	}
	while (!q.empty()) q.pop();
	id = 1;
	for (int i = 1; i <= m; ++i) {
		while (brr[id].l <= i && q.size() < (n - lq) && id <= lq2) {
			q.push(brr[id++]);
			ans2++;
		}
		while (brr[id].l <= i) id++;
		while (!q.empty()) {
			if (q.top().r <= i) q.pop();
			else break;
		}
	}
	ans = max(ans, ans1 + ans2);
	return ;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = q_read();
	lq1 = q_read();
	lq2 = q_read();
	for (int i = 1; i <= lq1; ++i) {
		arr[i].l = q_read();
		arr[i].r = q_read();
		m = max(m, arr[i].r);
	}
	for (int i = 1; i <= lq2; ++i) {
		brr[i].l = q_read();
		brr[i].r = q_read();
		m = max(m, arr[i].r);
	}
	sort(arr + 1, arr + lq1 + 1, cmp);
	sort(brr + 1, brr + lq2 + 1, cmp);
	for (int i = 0; i <= n; ++i) {
		work(i);
	}
	cout << ans << endl;
	return 0;
}
