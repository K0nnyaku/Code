#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
int n, m1, m2, lcnt, lisan[N * 4], d1[N], d2[N], len, e1[N], e2[N];
struct plane {
	int l, r;
} a1[N], a2[N];
bool cmp(plane a, plane b) {
	return a.l < b.l;
}
int scan() {
	int x = 0; char ch = getchar(); bool neg = 0;
	for (; ch < '0' || '9' < ch; ch = getchar()) neg = (ch == '-');
	for (; '0' <= ch && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	return neg ? -x : x;
}
int tre[N * 4];
void add(int x, int k) {
	for (; x <= len; x += (x & -x)) tre[x] += k;
}
void add(int l, int r, int k) {
	add(l, k); add(r + 1, -k);
}
int sum(int x) {
	int res = 0;
	for (; x; x -= (x & -x)) res += tre[x];
	return res;
}
void addd1(int x, int k) {
	for (; x <= n; x += (x & -x)) d1[x] += k;
}
void addd1(int l, int r, int k) {
	addd1(l, k); addd1(r + 1, -k);
}
int summ(int x) {
	int res = 0;
	for (; x; x -= (x & -x)) res += d1[x];
	return res;
}
void addd2(int x, int k) {
	for (; x <= n; x += (x & -x)) d2[x] += k;
}
void addd2(int l, int r, int k) {
	addd2(l, k); addd2(r + 1, -k);
}
int summm(int x) {
	int res = 0;
	for (; x; x -= (x & -x)) res += d2[x];
	return res;
}
struct eventt {
	int dat, who; bool what;
	eventt(){
	}
	eventt(int _d, int _w, int _wh) {
		dat = _d, who = _w, what = _wh;
	}
} ev1[N], ev2[N];
bool cmpp(eventt a, eventt b) {
	return a.dat < b.dat;
}
int evcnt = 0, evvcnt = 0;
void solve() {
	int iswho;
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= evcnt; ++i) {
			iswho = ev1[i].who;
			if (ev1[i].what == 0) {
				if (sum(a1[iswho].l) >= j) continue;
				add(a1[iswho].l, a1[iswho].r, 1); ++e1[j];
			}
			else add(a1[iswho].l, a1[iswho].r, -1);
		}
		memset(tre, 0, sizeof(tre));
	}
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= evvcnt; ++i) {
			iswho = ev2[i].who;
			if (ev2[i].what == 0) {
				if (sum(a2[iswho].l) >= j) continue;
				add(a2[iswho].l, a2[iswho].r, 1); ++e2[j];
			}
			else add(a2[iswho].l, a2[iswho].r, -1);
		}
		memset(tre, 0, sizeof(tre));
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		ans = max(ans, e1[i] + e2[n - i]);
		//printf("%d- %d, %d- %d\n", i, e1[i], n - i, e2[n - i]);
	printf("%d", ans);
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = scan(); m1 = scan(); m2 = scan();
	for (int i = 1; i <= m1; ++i) {
		a1[i].l = scan(); a1[i].r = scan();
		lisan[++lcnt] = a1[i].l, lisan[++lcnt] = a1[i].r;
	}
	for (int i = 1; i <= m2; ++i) {
		a2[i].l = scan(); a2[i].r = scan();
		lisan[++lcnt] = a2[i].l; lisan[++lcnt] = a2[i].r;
	}
	sort(lisan + 1, lisan + lcnt + 1);
	len = unique(lisan + 1, lisan + lcnt + 1) - lisan - 1;
	for (int i = 1; i <= m1; ++i) {
		a1[i].l = lower_bound(lisan + 1, lisan + len + 1, a1[i].l) - lisan;
		a1[i].r = lower_bound(lisan + 1, lisan + len + 1, a1[i].r) - lisan;
	}
	for (int i = 1; i <= m2; ++i) {
		a2[i].l = lower_bound(lisan + 1, lisan + len + 1, a2[i].l) - lisan;
		a2[i].r = lower_bound(lisan + 1, lisan + len + 1, a2[i].r) - lisan;
	}
	sort(a1 + 1, a1 + m1 + 1, cmp);
	sort(a2 + 1, a2 + m2 + 1, cmp);
	for (int i = 1; i <= m1; ++i) {
		ev1[++evcnt] = eventt(a1[i].l, i, 0);
		ev1[++evcnt] = eventt(a1[i].r, i, 1);
	}
	for (int i = 1; i <= m2; ++i) {
		ev2[++evvcnt] = eventt(a2[i].l, i, 0);
		ev2[++evvcnt] = eventt(a2[i].r, i, 1);
	}
	sort(ev1 + 1, ev1 + evcnt + 1, cmpp);
	sort(ev2 + 1, ev2 + evvcnt + 1, cmpp);
	int iswho;
	if (n <= 5000 && m1 + m2 <= 5000) {
		solve(); return 0;
	}
	for (int i = 1; i <= evcnt; ++i) {
		iswho = ev1[i].who;
		if (ev1[i].what == 0) {
			add(a1[iswho].l, a1[iswho].r, 1);
			addd1(sum(a1[iswho].l), n, 1);
			//printf("national [%d, %d] comes.\n", a1[iswho].l, a1[iswho].r);
			//for (int i = 0; i <= n; ++i) printf("%d ", summ(i));
			//puts("");
		}
		else add(a1[iswho].l, a1[iswho].r, -1);
		//printf("national [%d, %d] leaves.\n", a1[iswho].l, a1[iswho].r);
		//printf("BITREE: ");
		//for (int i = 1; i <= len; ++i) printf("%d ", sum(i)); puts(""); puts("");
	}
	memset(tre, 0, sizeof(tre));
	//printf("BITREE: ");
	//	for (int i = 1; i <= len; ++i) printf("%d ", sum(i)); puts(""); puts("");
	for (int i = 1; i <= evvcnt; ++i) {
		iswho = ev2[i].who;
		if (ev2[i].what == 0) {
			add(a2[iswho].l, a2[iswho].r, 1);
			addd2(sum(a2[iswho].l), n, 1); //printf("----> CLEAR %d\n", sum(a2[iswho].l));
			//printf("international [%d, %d] comes.\n", a2[iswho].l, a2[iswho].r);
			//for (int i = 0; i <= n; ++i) printf("%d ", summm(i));
			//puts("");
		}
		else add(a2[iswho].l, a2[iswho].r, -1);
		//printf("international [%d, %d] leaves.\n", a2[iswho].l, a2[iswho].r);
		//printf("BITREE: ");
		//for (int i = 1; i <= len; ++i) printf("%d ", sum(i)); puts(""); puts("");
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) e1[i] = summ(i);
	for (int i = 0; i <= n; ++i) e2[i] = summm(i);
	for (int i = 0; i <= n; ++i)
		ans = max(ans, e1[i] + e2[n - i]);
		//printf("%d- %d, %d- %d\n", i, e1[i], n - i, e2[n - i]);
	printf("%d", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
