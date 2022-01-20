#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define inf 0x3f3f3f3f
#define maxn 200001
#define ll long long

void read(int &x) {
	char F = getchar();
	int flag = 1; x = 0;
	while(F > '9' || F < '0') {
		if(F == '-') flag = -1;
		F = getchar();
	}
	while(F >= '0' && F <= '9') {
		x *= 10;
		x += F - '0';
		F = getchar();
	}
	x *= flag;
}

struct node {
	int l, r, id;
	bool operator < (const node x) const {
		return l < x.l;
	}
	bool operator > (const node x) const {
		return r < x.r;
	}
} a[maxn], b[maxn], a_[maxn], b_[maxn];

int n, m1, m2, cnt1[maxn], cnt2[maxn], ans, sum1[maxn], sum2[maxn];

bool cmp1(node x, node y) {
	return x < y;
}

bool cmp2(node x, node y) {
	return x > y;
}

struct SegmentTree {
	int l, r, dat;
} tree[maxn << 2];

#define l(o) tree[o].l
#define r(o) tree[o].r
#define dat(o) tree[o].dat

void build(int o, int l, int r) {
	l(o) = l; r(o) = r; dat(o) = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build((o << 1) | 1, mid + 1 ,r);
}

void updata(int o) {
	dat(o) = min(dat(o << 1), dat((o << 1) | 1));
}

void add(int o, int k, int x) {
	if(l(o) == r(o)) {
		dat(o) += x;
		return;
	}
	int mid = (l(o) + r(o)) >> 1;
	if(k <= mid) add(o << 1, k, x);
	else add((o << 1) | 1, k, x);
	updata(o); 
}

int find(int o) {
	if(l(o) == r(o)) return l(o);
	if(! dat(o << 1)) return find(o << 1);
	else find((o << 1) | 1);
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n); read(m1); read(m2);
	for(int i = 1; i <= m1; i ++) read(a[i].l), read(a[i].r), a[i].id = i, a_[i] = a[i];
	for(int i = 1; i <= m2; i ++) read(b[i].l), read(b[i].r), b[i].id = i, b_[i] = b[i];
	sort(a + 1, a + 1 + m1, cmp1); sort(b + 1, b + 1 + m2, cmp1);
	sort(a_ + 1, a_ + 1 + m1, cmp2); sort(b_ + 1, b_ + 1 + m2, cmp2);
	build(1, 0, m1);
	int res = 1;
	for(int i = 1; i <= m1; i ++) {
		while(a_[res].r < a[i].l) add(1, cnt1[a_[res].id], -1), res ++;
		cnt1[a[i].id] = find(1); add(1, cnt1[a[i].id], 1);
	}
	build(1, 0, m2);
	res = 1;
	for(int i = 1; i <= m2; i ++) {
		while(b_[res].r < b[i].l) add(1, cnt2[b_[res].id], -1), res ++;
		cnt2[b[i].id] = find(1); add(1, cnt2[b[i].id], 1);
	}
	for(int i = 1; i <= m1; i ++) sum1[cnt1[i]] ++;
	for(int i = 1; i <= m2; i ++) sum2[cnt2[i]] ++;
	for(int i = 1; i <= m1; i ++) sum1[i] += sum1[i - 1];
	for(int i = 1; i <= m2; i ++) sum2[i] += sum2[i - 1];
	ans = max(ans, sum2[n - 1]);
	ans = max(ans, sum1[n - 1]);
	for(int i = 1; i < n; i ++) {
		ans = max(ans, sum1[i - 1] + sum2[n - i - 1]);
	}
	printf("%d\n", ans);
	return 0;
}
