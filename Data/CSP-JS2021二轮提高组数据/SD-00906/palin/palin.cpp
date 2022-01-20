#include <bits/stdc++.h>
using namespace std;
#define N 500010
int n;
int arr[N], brr[N], wz[N], ans[N];
bool bo = false;
int q_read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
	return x;
}
void dfs(int l, int r, int id) {
	if (bo) return ;
	if (id > 2 * n) {
		for (int i = 1; i <= 2 * n; ++i) {
			cout << ((brr[i] == 1) ? ("L") : ("R"));
		}
		cout << endl;
		bo = true;
		return ;
	}
	if (!wz[arr[l]]) {
		brr[id] = 1;
		wz[arr[l]] = id;
		dfs(l + 1, r, id + 1);
		wz[arr[l]] = 0;
	} else {
		if (id + wz[arr[l]] == 2 * n + 1) {
			brr[id] = 1;
			dfs(l + 1, r, id + 1);
		}
	}
	if (!wz[arr[r]]) {
		brr[id] = 2;
		wz[arr[r]] = id;
		dfs(l, r - 1, id + 1);
		wz[arr[r]] = 0;
	} else {
		if (id + wz[arr[r]] == 2 * n + 1) {
			brr[id] = 2;
			dfs(l, r - 1, id + 1);
		}
	}
	return ;
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T;
	T = q_read();
	while (T--) {
		n = q_read();
		memset(wz, 0, sizeof(wz));
		bo = false;
		for (int i = 1; i <= 2 * n; ++i) {
			arr[i] = q_read();
		}
		dfs(1, 2 * n, 1);
		if (!bo) puts("-1");
	}
	return 0;
}
