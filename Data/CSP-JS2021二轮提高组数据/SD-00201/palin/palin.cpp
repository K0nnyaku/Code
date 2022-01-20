#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int T;
int n, a[100005];
int b[100005];
string s;
string ans;

bool check() {
	for (int i = 1; i <= n; ++i) {
		if (b[i] != b[2 * n - i + 1]) {
			return false;
		}
	}
	return true;
}

void dfs(int pos, int l, int r) {
	if (pos > 2 * n) {
		if (check()) {
			ans = s;
		}
		return;
	}
	s.push_back('L');
	b[pos] = a[l];
	dfs(pos + 1, l + 1, r);
	if (ans.size()) return;
	s.back() = 'R';
	b[pos] = a[r];
	dfs(pos + 1, l, r - 1);
	s.pop_back();
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	cin >> T;
	while (T --> 0) {
		cin >> n;
		for (int i = 1; i <= 2 * n; ++i) {
			cin >> a[i];
		}
		dfs(1, 1, 2 * n);
		if (ans.size()) {
			cout << ans << endl;
		}
		else {
			cout << -1 << endl;
		}
		s.clear();
		ans.clear();
	}
	return 0;
}

/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/


