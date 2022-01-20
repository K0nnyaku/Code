#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <random>
#include <chrono>

struct event {
	int tm, ty, i;
} e[400005];

int n, m1, m2, cnt;
bool dom[200005];

inline int read() {
	char ch = getchar();
	int n = 0;
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') n = n * 10 + (ch ^ '0'), ch = getchar();
	return n;
}

int func(int x) {
	memset(dom, 0, sizeof(dom));
	int use[2] = { 0, 0 }, ans = 0;
	for (int i = 1; i <= cnt; ++i)
		if (e[i].ty & 2) {
			if (e[i].ty & 1) {
				if (!dom[e[i].i]) --use[1];
			} else if (use[1] == n - x) dom[e[i].i] = 1;
			else ++use[1], ++ans;
		} else {
			if (e[i].ty & 1) {
				if (!dom[e[i].i]) --use[0];
			} else if (use[0] == x) dom[e[i].i] = 1;
			else ++use[0], ++ans;
		}
	return ans;
}

std::mt19937 rnd;
inline int randint(int l, int r) {
	return (int) ((double) rnd() / (1ll << 32) * (r - l + 1)) + l;
}
inline double random() {
	return (double) rnd() / (1ll << 32);
}

inline int do_once() {
	double T = 1.0; int ans = n >> 1, c = func(ans);
	while (T >= 1e-6) {
		int new_a = ans + T * randint(-n, n);
		if (new_a <= 0) new_a = 0;
		if (new_a >= n) new_a = n;
		int new_c = func(new_a);
		if (new_c > c)
			if (random() > 0.1 * T) ans = new_a, c = new_c;
		T *= 0.95;
	}
	return c;
}

int main() {
	auto start = std::chrono::steady_clock::now();
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	rnd.seed(std::chrono::steady_clock::now().time_since_epoch().count());
	n = read(); m1 = read(); m2 = read();
	for (int i = 1; i <= m1; ++i) e[++cnt].tm = read(), e[cnt].ty = 0, e[cnt].i = i, e[++cnt].tm = read(), e[cnt].ty = 1, e[cnt].i = i;
	for (int i = m1 + 1; i <= m1 + m2; ++i) e[++cnt].tm = read(), e[cnt].ty = 2, e[cnt].i = i, e[++cnt].tm = read(), e[cnt].ty = 3, e[cnt].i = i;
	std::sort(e + 1, e + cnt + 1, [](const event &a, const event &b) { return a.tm < b.tm; });
	int ans = 0;
	while (1) {
		int v = do_once();
		if (v > ans) ans = v;
		auto now = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count() > 650) break;
	}
	printf("%d\n", ans);
	return 0;
}
