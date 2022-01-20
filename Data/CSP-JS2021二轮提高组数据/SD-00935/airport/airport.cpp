#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
int n, m1, m2;
struct PLA{
	int x, y;
} pla[MAXN];
bool cmp(PLA a, PLA b) {return a.x < b.x;}
struct Sub1{		
	int f1[MAXN], f2[MAXN];
	struct Tree {
		int sum[MAXN * 4], lazy[MAXN * 4], size[MAXN * 4];
		void build(int node, int l, int r) {
			if (l == r) {size[node] = 1; return;}
			int mid = (l + r) >> 1;
			build(node * 2, l, mid); build(node * 2 + 1, mid + 1, r);
			size[node] = size[node * 2] + size[node * 2 + 1];
		}
		void add(int node, int k) {sum[node] += k * size[node], lazy[node] += k;}
		void push_down(int node) {add(node * 2, lazy[node]), add(node * 2 + 1, lazy[node]); lazy[node] = 0;}
		void add_number(int node, int l, int r, int x, int y) {
			if (l >= x && r <= y) {
				add(node, 1); return;
			}
			int mid = (l + r) >> 1; push_down(node);
			if (x <= mid) add_number(node * 2, l, mid, x, y);
			if (y > mid) add_number(node * 2 + 1, mid + 1, r, x, y);
		}
		int query(int node, int l, int r, int k) {
			if (l == r) {return sum[node];}
			int mid = (l + r) >> 1; push_down(node);
			if (k <= mid) return query(node * 2, l, mid, k);
			return query(node * 2 + 1, mid + 1, r, k);
		}
		void clear() {
			memset(sum, 0, sizeof(sum)); memset(lazy, 0, sizeof(lazy)); memset(size, 0, sizeof(size));
		}
	} tree;
	int inx(int num) {
		tree.clear(); int ans = 0;
		tree.build(1, 1, 100000);
		for (int i = 1; i <= m1; i++) {
			if (tree.query(1, 1, 100000, pla[i].x) < num) {
				ans++;
				tree.add_number(1, 1, 100000, pla[i].x, pla[i].y);
			}
		}
		return ans;
	}
	int iny(int num) {
		tree.clear(); int ans = 0;
		tree.build(1, 1, 100000);
		for (int i = 1; i <= m2; i++) {
			if (tree.query(1, 1, 100000, pla[i].x) < num) {
				ans++;
				tree.add_number(1, 1, 100000, pla[i].x, pla[i].y);
			}
		}
		return ans;
	}
	int maxx(int a, int b) {if (a > b) return a; return b;}
	void work1() {
		std::sort(pla + 1, pla + 1 + m1, cmp);
		for (int i = 0; i <= n; i++) {
			f1[i] = inx(i);
		}
	}
	void work2() {
		std::sort(pla + 1, pla + 1 + m2, cmp);
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			f2[i] = iny(i), ans = maxx(ans, f2[i] + f1[n - i]);
		}
		printf("%d\n", ans);
	}
} sub1;
int f1[MAXN], f2[MAXN];
struct node{
	int pos, dis;
	bool operator < (const node &x) const {
		return x.dis < dis;
	} 
};
std::priority_queue<node> q;
int cnt[MAXN];
int minn(int a, int b) {if (a < b) return a; return b;}
int maxx(int a, int b) {if (a > b) return a; return b;}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2); int mx = 0;
	for (int i = 1; i <= m1; i++) {
		scanf("%d%d", &pla[i].x, &pla[i].y);
		mx = maxx(mx, maxx(pla[i].x, pla[i].y));
	}
	std::sort(pla + 1, pla + 1 + m1, cmp);
	for (int i = 1; i <= m1; i++) {
		f1[i] = f1[i - 1] + 1;
		while (!q.empty()) {
			if (q.top().dis <= pla[i].x) {
				f1[i] = minn(f1[i], f1[q.top().pos]);
				q.pop();
			} else break;
		}
		while (cnt[f1[i]] > pla[i].x) f1[i]++;
		cnt[f1[i]] = maxx(cnt[f1[i]], pla[i].y); 
		q.push((node){i, pla[i].y});
	}
	if (mx <= 10000 && n <= 100 && m1 + m2 <= 300) sub1.work1();
	std::sort(f1 + 1, f1 + 1 + m1);
	while (!q.empty()) q.pop();
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= m2; i++) {
		scanf("%d%d", &pla[i].x, &pla[i].y);
		mx = maxx(mx, maxx(pla[i].x, pla[i].y));
	}
	if (mx <= 10000 && n <= 100 && m1 + m2 <= 300) {
		sub1.work2();
		return 0;
	}
	std::sort(pla + 1, pla + 1 + m2, cmp);
	for (int i = 1; i <= m2; i++) {
		f2[i] = f2[i - 1] + 1;
		while (!q.empty()) {
			if (q.top().dis <= pla[i].x) {
				f2[i] = minn(f2[i], f2[q.top().pos]);
				q.pop();
			} else break;
		}
		while (cnt[f2[i]] > pla[i].x) f2[i]++;
		cnt[f2[i]] = maxx(cnt[f2[i]], pla[i].y); 
		q.push((node){i, pla[i].y});
	}
	std::sort(f1 + 1, f1 + m1 + 1); std::sort(f2 + 1, f2 + m2 + 1);
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int x = i, y = n - i;
		int inx = std::upper_bound(f1 + 1, f1 + 1 + m1, x) - f1 - 1;
		int iny = std::upper_bound(f2 + 1, f2 + 1 + m2, y) - f2 - 1;
		ans = maxx(ans, inx + iny);
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
