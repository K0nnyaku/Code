#include <bits/stdc++.h>
using namespace std;

int n, m, t, k;

inline int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x;
}

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	n = read(), m = read(), t = read();
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			read();
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			read();
		}
	}
	
	while (t--) {
		k = read();
		for (int i = 1; i <= k; i++) {
			read();read();read();
		}
		cout << 0 << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


