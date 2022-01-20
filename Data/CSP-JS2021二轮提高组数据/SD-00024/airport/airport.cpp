#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define ll long long
#define db double
#define ls(x) x << 1
#define rs(x) x << 1 | 1
using std::cout; 

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1; c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0'; c = getchar();
	}
	return f * x;
}

const int N = 800010;
int n, lenx, leny, tpx[N], tpy[N], nowx, nowy;
int tx[N], ty[N], posx[N], posy[N], tgx[N], tgy[N];

struct node {
	int tl, tr;
}a[N], b[N];

bool cmp(node x, node y) {
	return x.tl < y.tl;
}
void upx(int p) {
	tx[p] = std::min(tx[ls(p)], tx[rs(p)]);
	if (tx[p] == tx[ls(p)]) posx[p] = posx[ls(p)];
	else posx[p] = posx[rs(p)];
}
void upy(int p) {
	ty[p] = std::max(ty[ls(p)], ty[rs(p)]);
	if (ty[p] == ty[ls(p)]) posy[p] = posy[ls(p)];
	else posy[p] = posy[rs(p)];
}
void chx(int p, int c) {
	tx[p] += c; tgx[p] += c;
}
void chy(int p, int c) {
	ty[p] += c; tgy[p] += c;
}
void pdx(int p) {
	if (tgx[p]) {
		chx(ls(p), tgx[p]); chx(rs(p), tgx[p]);
		tgx[p] = 0;
	}
}
void pdy(int p) {
	if (tgy[p]) {
		chy(ls(p), tgy[p]); chy(rs(p), tgy[p]);
		tgy[p] = 0;
	}
}
void bdx(int p, int l, int r) {
	if (l == r) {
		tx[p] = 0; posx[p] = l;
		return;
	}
	int mid = (l + r) >> 1;
	bdx(ls(p), l, mid); bdx(rs(p), mid + 1, r);
	upx(p);
}
void bdy(int p, int l, int r) {
	if (l == r) {
		ty[p] = 0; posy[p] = l;
		return;
	}
	int mid = (l + r) >> 1;
	bdy(ls(p), l, mid); bdy(rs(p), mid + 1, r);
	upy(p);
}

void upd(int p, int L, int R, int l, int r, int c, int op) {
	if (l <= L && R <= r) {
		if (!op) chx(p, c);
		else chy(p, c);
		return;
	}
	if (!op) pdx(p);
	else pdy(p);
	int mid = (L + R) >> 1;
	if (l <= mid) upd(ls(p), L, mid, l, r, c, op);
	if (r > mid) upd(rs(p), mid + 1, R, l, r, c, op);
	if (!op) upx(p);
	else upy(p);
}
int que(int p, int l, int r, int pos) {
	if (l == r) return ty[p];
	pdy(p);
	int mid = (l + r) >> 1;
	if (pos <= mid) return que(ls(p), l, mid, pos);
	return que(rs(p), mid + 1, r, pos);
}
int sol(int lim) {
	while (tx[1] < lim) {
		int loc = posx[1], l = 1, r = lenx;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (a[mid].tl >= loc) r = mid;
			else l = mid + 1;
		}
		nowx ++; 
		upd(1, 1, lenx, a[l].tl, a[l].tr, 1, 0);
		upd(1, 1, lenx, a[l].tl, a[l].tl, 233333, 0);
	}
	while (ty[1] > n - lim) {
		int loc = posy[1], l = 1, r = leny;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (b[mid].tl >= loc) r = mid;
			else l = mid + 1;
		}
		nowy --; 
		upd(1, 1, leny, b[l].tl, b[l].tl, -233333, 1);
		upd(1, 1, leny, b[l].tl, b[l].tr, -1, 1);
	}
	return nowx + nowy;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = read(); lenx = read(); leny = read();
	for (int i = 1; i <= lenx; i ++) {
		a[i].tl = read(); a[i].tr = read();
		tpx[i] = a[i].tl;
	}
	for (int i = 1; i <= leny; i ++) {
		b[i].tl = read(); b[i].tr = read();
		tpy[i] = b[i].tl;
	}
	
	std::sort(tpx + 1, tpx + lenx + 1);
	std::sort(tpy + 1, tpy + leny + 1);
	std::sort(a + 1, a + lenx + 1, cmp);
	std::sort(b + 1, b + leny + 1, cmp);
	
	bdx(1, 1, lenx); bdy(1, 1, leny);
	for (int i = 1; i <= lenx; i ++) {
		a[i].tl = std::lower_bound(tpx + 1, tpx + lenx + 1, a[i].tl) - tpx;
		a[i].tr = std::lower_bound(tpx + 1, tpx + lenx + 1, a[i].tr) - tpx; a[i].tr --;
	}
	for (int i = 1; i <= leny; i ++) {
		b[i].tl = std::lower_bound(tpy + 1, tpy + leny + 1, b[i].tl) - tpy;
		b[i].tr = std::lower_bound(tpy + 1, tpy + leny + 1, b[i].tr) - tpy; b[i].tr --;
		if (que(1, 1, leny, b[i].tl) < n) 
			upd(1, 1, leny, b[i].tl, b[i].tr, 1, 1), nowy ++;
	}
	int ans = nowy;
	for (int i = 0; i <= n; i ++) ans = std::max(ans, sol(i));
	cout << ans << "\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
