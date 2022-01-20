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

const ll kMaxN = 1000005;

ll n, a[kMaxN], b[kMaxN], c[kMaxN], t[kMaxN], cnt[2], flag;

void calc() {
	if (flag) return;
	ll l = 1, r = n * 2, tot = 0;
	rep(i, 1, (n << 1)) {
		if (!t[i]) {
			c[i] = 1;
			b[++tot] = a[l++];
		} else {
			c[i] = 2;
			b[++tot] = a[r--];
		}
	}
	rep(i, 1, n) {
		if (b[i] != b[n * 2 - i + 1]) return;
	}
	flag = 1;
}

void dfs(ll x) {
	if (flag) return;
	if (x > (n << 1)) {
		calc();
		return;
	}
	if (a[cnt[0]] <= a[cnt[1]]) {
		t[x] = 0, ++cnt[0];
		dfs(x + 1);
		t[x] = 1, --cnt[0], --cnt[1];
		dfs(x + 1);
		++cnt[1];
	} else {
		t[x] = 1, --cnt[1];
		dfs(x + 1);
		t[x] = 0, ++cnt[1], ++cnt[0];
		dfs(x + 1);
		--cnt[0];
	}
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	ll T; read(T);
	while (T--) {
		flag = 0;
		read(n);
		rep(i, 1, (n << 1)) {
			read(a[i]);
		}
		cnt[0] = 1, cnt[1] = (n << 1);
		dfs(1);
		if (flag) {
			rep(i, 1, (n << 1)) {
				if (c[i] == 1) putchar('L');
				else putchar('R');
			}
			putchar('\n');
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
