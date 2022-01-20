//21!9-324@emb
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int S = 1e5 + 5;

int t, n, m1, m2, ans, tot_a, tot_b;
int last_a[S], last_b[S], num_a[S], num_b[S], sum_a[S], sum_b[S];
bool flag;
bool vis[S];

struct data {
	int x, y;
};
data a[S], b[S];

bool operator < (data A, data B) {
	return A.x < B.x;
}

int read();
void in();
void solve();

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	in();
	solve();
	return 0;
}

int read() {
	int a = 1, h = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			a = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		h = h * 10 + ch - '0';
		ch = getchar();
	}
	return a * h;
}

void in() {
	n = read();
	m1 = read();
	m2 = read();
	for (int i = 1; i <= m1; i++) {
		a[i].x = read();
		a[i].y = read();
	}
	sort(a + 1, a + m1 + 1);
	for (int i = 1; i <= m2; i++) {
		b[i].x = read();
		b[i].y = read();
	}
	sort(b + 1, b + m2 + 1);
}

void solve() {
	t = 0;
	for (int i = 1; i <= m1; i++) {
		bool flag = false;
		for (int j = 1; j <= t; j++) {
			if (last_a[j] < a[i].x) {
				last_a[j] = a[i].y;
				num_a[i] = j;
				flag = true;
				break;
			}
		}
		if (!flag) {
			t++;
			num_a[i] = t;
			last_a[t] = a[i].y;
		}
	}
	for (int i = 1; i <= m1; i++) {
		sum_a[num_a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		sum_a[i] += sum_a[i - 1];
	}
	t = 0;
	for (int i = 1; i <= m2; i++) {
		bool flag = false;
		for (int j = 1; j <= t; j++) {
			if (last_b[j] < b[i].x) {
				last_b[j] = b[i].y;
				num_b[i] = j;
				flag = true;
				break;
			}
		}
		if (!flag) {
			t++;
			num_b[i] = t;
			last_b[t] = b[i].y;
		}
	}
	for (int i = 1; i <= m2; i++) {
		sum_b[num_b[i]]++;
	}
	for(int i = 1; i <= n; i++) {
		sum_b[i] += sum_b[i - 1];
	}
	for (int i = 0; i <= n; i++) {
		ans = max(ans, sum_a[i] + sum_b[n - i]);
	}
	printf("%d\n", ans);
}
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
