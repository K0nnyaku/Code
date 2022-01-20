//21!9-324@emb
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int S = 1e6 + 5;

int T, n;
int b[S], a[S];
char r[S];

int read();
void in();
bool solve(int k, int head, int tail);

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		memset(a, 0, sizeof(a));
		in();
	}
	return 0;
}

void in() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++) {
		scanf("%d", &b[i]);
	}
	if (!solve(1, 1, 2 * n)) {
		cout << "-1";
	}
	cout << endl;
}

bool solve(int k, int head, int tail) {
	if (k == (2 * n) + 1) {
		for (int i = 1; i <= 2 * n; i++) {
			cout << r[i];
		}
		return true;
	}
	if (k > n + 1 && a[k - 1] != a[2 * n - k + 2]) {
		return false;
	}
	for (int i = 0; i <= 1; i++) {
		if (i == 0) {
			a[k] = b[head];
			r[k] = 'L';
			if (solve(k + 1, head + 1, tail)) {
				return true;
			}
		}
		else {
			a[k] = b[tail];
			r[k] = 'R';
			if (solve(k + 1, head, tail - 1)) {
				return true;
			}
		}
	}
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
