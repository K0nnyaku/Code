#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
 
#define N 200097
#define LL long long

using namespace std;
LL n, m1, m2, a[N], b[N], tot1 = 0, tot2 = 0, ans = 0;
struct Qry {
	LL t, id;
	bool operator < (Qry a) const {
		return t < a.t;
	}
} qr1[N], qr2[N];
priority_queue<LL, vector<LL>, greater<LL> > q;

LL calc(LL cnt, LL state) {
	if (cnt == 0) return 0; 
	while (!q.empty()) q.pop();
 	LL res = 0;
	if (state == 1) {
		for (int i = 1; i <= tot1; i++) {
			while (q.size() >= 1 && q.top() < qr1[i].t) q.pop();
			if (q.size() < cnt) q.push(b[qr1[i].id]), res++;
		}
		return res;
	}
	else {
		for (int i = 1; i <= tot2; i++) {
			while (q.size() >= 1 && q.top() < qr2[i].t) q.pop();
			if (q.size() < cnt) q.push(b[qr2[i].id]), res++;
		}
		return res;
	}
}
void sub2() {
	int p = n / 2;
	printf("%lld", calc(p, 1) + calc(n - p, 2));
	return;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++) {
		scanf("%lld%lld", &a[i], &b[i]);
		qr1[++tot1] = (Qry) {a[i], i};
	}
	if (n >= 50000) sub2();
	else {
		sort(qr1 + 1, qr1 + tot1 + 1);
		for (int i = 1; i <= m2; i++) {
			scanf("%lld%lld", &a[i + m1], &b[i + m1]);
			qr2[++tot2] = (Qry) {a[i + m1], i + m1};
		}
		sort(qr2 + 1, qr2 + tot2 + 1);
		for (int i = 0; i <= n; i++) {
			LL ans1 = calc(i, 1);
			LL ans2 = calc(n - i, 2);
			ans = max(ans, ans1 + ans2);
		}
	}
	printf("%lld", ans);
	return 0;
}

