#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define i64 long long
#define il inline
#define out(x) write(x), putchar(' ')
#define wr(x) write(x), putchar('\n')
#define F(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))

using namespace std;
const int maxn = 500050, inf = 1e9 + 5;
template <typename T> il void rd(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	x *= f;
}
template <typename T> il void write(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int n, m1, m2, ans = -inf;

//struct SegTree{
//	int l, r, val;
//} tr[maxn];
//il void build(int rt, int l, int r) {
//	
//}
struct plane1{
	int l, r;
} p1[maxn];
il bool cmp1(plane1 x, plane1 y) { return x.l < y.l; }
struct plane2{
	int l, r;
} p2[maxn];
il bool cmp2(plane2 x, plane2 y) { return x.l < y.l; }

struct node{
	int rr, ll;
	il bool operator < (const node &b) {
		return rr < b.rr;
	}
};
il void slove(int k1) { // 国内有 k1 个廊桥 
	int k2 = (n - k1), tot = 0; // 国际有 k2 个廊桥  
	queue < node > q1, q2;
	if (k1) {
		q1.push((node){p1[1].l, p1[1].r}); k1--;
		for (int i = 2; i <= m1; ++i ) {
			node q, t; q = q1.front();
			if (q1.size() && q.rr < p1[i].l) {
				q1.pop(); k1++;
				q = q1.front();
			}
			if (k1 && q.rr < p1[i].l) {
				t.ll = p1[i].l, t.rr = p1[i].r;
				q1.push(t);
				tot++, k1--;
			} else {
				if (k1) {
					t.ll = p1[i].l, t.rr = p1[i].r;
					q1.push(t);
					tot++, k1--;
				}
			}
		}
	}
//	out(tot);
	if (k2) {
		q2.push((node){p2[1].l, p2[1].r}); k2--;
		for (int i = 2; i <= m2; ++i ) {
			node q, t; q = q2.front();
			if (q2.size() && q.rr < p2[i].l) {
				q2.pop(); k2++;
				q = q2.front();
			}
			if (k2 && q.rr < p2[i].l) {
				t.ll = p2[i].l, t.rr = p2[i].r;
				q2.push(t);
				tot++;
				k2--;
			} else {
				if (k2) {
					t.ll = p2[i].l, t.rr = p2[i].r;
					q2.push(t);
					tot++;
					k2--;
				}
			}
		}
	} 
//	wr(tot);
	ans = max(ans, tot);
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	rd(n), rd(m1), rd(m2);
	F(i, 1, m1) rd(p1[i].l), rd(p1[i].r);
	F(i, 1, m2) rd(p2[i].l), rd(p2[i].r);
	sort(p1 + 1, p1 + 1 + m1, cmp1);
	sort(p2 + 1, p2 + 1 + m2, cmp2);
//	F(i, 1, m1) out(p1[i].l), out(p1[i].r); printf("\n");
//	F(i, 1, m2) out(p2[i].l), out(p2[i].r); printf("\n");
	for (int i = 0; i <= n; ++i )
		slove(i);
	wr(ans);
	return 0;
}
//3 5 4 
//1 5
//3 8
//6 10
//9 14
//13 18
//2 11
//4 15
//7 17
//12 16

//2 4 6
//20 30
//40 50
//21 22
//41 42
//1 19
//2 18
//3 4
//5 6
//7 8
//9 10

