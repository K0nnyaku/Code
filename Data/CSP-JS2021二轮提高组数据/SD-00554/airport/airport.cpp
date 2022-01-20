#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(int &x){
	x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	x = x * f;
	return x;
}

const int N = 2e5 + 10;

int n, m1, m2;
int mx;
int tot1, tot2;
struct Q{
	int x, y;
	bool operator < (const Q &a) const{
		return x < a.x;
	}
}qqq[N];
int a[N], b[N];
int x[N], now;
int pos, val, ql, qr;
int aip1[N], aip2[N];
int sum1[N], sum2[N];
int ydd[N];

namespace seg{
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	struct tree{
		int mn;
	}t[N << 2];
	void pushup(int x){
		t[x].mn = min(t[ls(x)].mn, t[rs(x)].mn);
	}
	void build(int x, int l, int r){
		t[x].mn = 1e9;
		if(l == r) return;
		int mid = l + r >> 1;
		build(ls(x), l, mid);
		build(rs(x), mid + 1, r);
	}
	void modify(int x, int l, int r){
		if(l == r){
			t[x].mn = val;
			return;
		}
		int mid = l + r >> 1;
		if(pos <= mid) modify(ls(x), l, mid);
		else modify(rs(x), mid + 1, r);
		pushup(x);
	}
	int query(int x, int l, int r){
		if(ql <= l && r <= qr) return t[x].mn;
		int ans = 1e9;
		int mid = l + r >> 1;
		if(ql <= mid) ans = min(ans, query(ls(x), l, mid));
		if(mid < qr) ans = min(ans, query(rs(x), mid + 1, r));
		return ans; 
	}
}

using namespace seg;

void init(int n){
	memset(x, 0, sizeof x);
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	now = 0;
	for(int i = 1; i <= n * 2; i++) qqq[i].x = qqq[i].y = 0;
	build(1, 1, 2 * n);
	memset(ydd, 0, sizeof ydd);
}

signed main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n);read(m1);read(m2);
	init(m1);
	for(int i = 1; i <= m1; i++) {
		read(a[i]), read(b[i]);
		x[++now] = a[i];
		x[++now] = b[i];
	}
	sort(x + 1, x + 1 + m1 + m1);
	for(int i = 1; i <= m1; i++){
		qqq[i].x = lower_bound(x + 1, x + 1 + m1 + m1, a[i]) - x;
		qqq[i].y = lower_bound(x + 1, x + 1 + m1 + m1, b[i]) - x;
	}
	sort(qqq + 1, qqq + 1 + m1);
	for(int i = 1; i <= m1; i++){
		ql = 1, qr = qqq[i].x;
		int nod = query(1, 1, 2 * m1);
//		if(nod == 1e9) aip1[++tot1] = 1;
//		else aip1[nod]++;
		if(nod == 1e9) nod = ++tot1;
		aip1[nod]++;
		pos = qqq[i].y;
		val = nod;
		modify(1, 1, 2 * m1);
		pos = ydd[nod];
		val = 1e9;
		if(pos != 0) modify(1, 1, 2 * m1);
		ydd[nod] = qqq[i].y;
	}
	init(m2);
	for(int i = 1; i <= m2; i++) {
		read(a[i]), read(b[i]);
		x[++now] = a[i];
		x[++now] = b[i];
	}
	sort(x + 1, x + 1 + m2 + m2);
	for(int i = 1; i <= m2; i++){
		qqq[i].x = lower_bound(x + 1, x + 1 + m2 + m2, a[i]) - x;
		qqq[i].y = lower_bound(x + 1, x + 1 + m2 + m2, b[i]) - x;
	}
	sort(qqq + 1, qqq + 1 + m2);
	for(int i = 1; i <= m2; i++){
		ql = 1, qr = qqq[i].x;
		int nod = query(1, 1, 2 * m2);
		if(nod == 1e9) nod = ++tot2;
		aip2[nod]++;
		pos = qqq[i].y;
		val = nod;
		modify(1, 1, 2 * m2);
		pos = ydd[nod];
		ydd[nod] = qqq[i].y;
		val = 1e9;
		if(pos) modify(1, 1, 2 * m2);
	}
	for(int i = 1; i <= n; i++){
		sum1[i] = sum1[i - 1] + aip1[i];
		sum2[i] = sum2[i - 1] + aip2[i];
	}
	for(int i = 0; i <= n; i++){
		mx = max(mx, sum1[i] + sum2[n - i]);
	}
	printf("%lld", mx); 
	return 0;
}
/*
t1的思路：
读进来先离散化一下。然后建权值线段树
复杂度nlogn
问题：不会删点
刚发现一个好兴致：互不相同
那就可以做了
考虑到可以用priority_queue
但是我不会比大小
然后也可以用

upd: 4:00 就2.5h了
大样例还没过
现在很害怕
决定检查一下代码，清空
大样例输出多很多，检查！
发现问题了，果然是清空
妈的改了还是没过

我草，我还打个锤子
直接退役

上了个厕所冷静了一下，一回来就看见自己写的 if(!pos)
我：这人傻逼吧
改了就过样例了。
真不错
*/
