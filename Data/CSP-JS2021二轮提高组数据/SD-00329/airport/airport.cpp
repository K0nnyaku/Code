#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define iv inline void
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define per(i, a, b) for (ll i = (b); i >= (a); ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll; 

template <typename T>
iv read(T &read_num) {
	read_num = 0;
	ll read_f = 1;
	char read_ch = getchar();
	while (read_ch < '0' || read_ch > '9') {
		if (read_ch == '-') read_f = -1;
		read_ch = getchar();
	}
	while (read_ch >= '0' && read_ch <= '9') {
		read_num = (read_num << 1) + (read_num << 3) + (read_ch ^ 48);
		read_ch = getchar();
	}
	read_num *= read_f;
}

const ll kMaxN = 100005;
const ll kMaxMM = 400005;
struct jgt {
	ll a, b, id;
};

ll n, m1, m2, tot, b1[kMaxMM];
jgt a1[kMaxN], a2[kMaxN];
pll v1[kMaxMM], v2[kMaxMM];
ll a[kMaxN], b[kMaxN];
bool vis1[kMaxN], vis2[kMaxN];

bool cmp1(const jgt &x, const jgt &y) {
	if (x.a == y.a) return x.b < y.b;
	return x.a < y.a;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(m1), read(m2);
	rep(i, 1, m1) {
		read(a1[i].a), read(a1[i].b);
		a1[i].id = 1;
		b1[++tot] = a1[i].a, b1[++tot] = a1[i].b;
	}
	rep(i, 1, m2) {
		read(a2[i].a), read(a2[i].b);
		a2[i].id = 2;
		b1[++tot] = a2[i].a, b1[++tot] = a2[i].b;
	}
	sort(b1 + 1, b1 + m1 + m1 + m2 + m2 + 1);
	rep(i, 1, m1) {
		a1[i].a = lower_bound(b1 + 1, b1 + m1 + m1 + m2 + m2 + 1, a1[i].a) - b1;
		a1[i].b = lower_bound(b1 + 1, b1 + m1 + m1 + m2 + m2 + 1, a1[i].b) - b1;
	}
	rep(i, 1, m2) {
		a2[i].a = lower_bound(b1 + 1, b1 + m1 + m1 + m2 + m2 + 1, a2[i].a) - b1;
		a2[i].b = lower_bound(b1 + 1, b1 + m1 + m1 + m2 + m2 + 1, a2[i].b) - b1;
	}
	sort(a1 + 1, a1 + m1 + 1, cmp1);
	sort(a2 + 1, a2 + m2 + 1, cmp1);
	rep(i, 1, m1) {
		v1[a1[i].a] = make_pair(i, 1);
		v1[a1[i].b] = make_pair(i, 0);
	}
	rep(i, 1, m2) {
		v2[a2[i].a] = make_pair(i, 1);
		v2[a2[i].b] = make_pair(i, 0);
	}
	ll ans = 1000000000;
	rep(i, 0, n) {
		ll numa = i, numb = n - i, cnta = 0, cntb = 0, tmpans = 0;
		rep(j, 1, m1 + m1 + m2 + m2) {
			if (v1[j].fi != 0) {
				if (v1[j].se == 1) {
					if (cnta < numa) ++cnta;
					else vis1[v1[j].fi] = 1, tmpans++;
				} else {
					if (!vis1[v1[j].fi]) cnta--;
					else vis1[v1[j].fi] = 0;
				}
			}
			if (v2[j].fi != 0) {
				if (v2[j].se == 1) {
					if (cntb < numb) ++cntb;
					else vis2[v2[j].fi] = 1, tmpans++;
				} else {
					if (!vis2[v2[j].fi]) cntb--;
					else vis2[v2[j].fi] = 0;
				}
			}
		}
		ans = min(ans, tmpans);
	}
	printf("%lld\n", m1 + m2 - ans);
	return 0;
}
