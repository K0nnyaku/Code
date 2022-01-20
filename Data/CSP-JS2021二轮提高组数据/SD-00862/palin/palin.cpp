#include <bits/stdc++.h>
using namespace std;
int t = 0;
int n = 0;
int a[1000005] = { 0 };
int main() {
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			cin >> a[i];
		}
		for (int i = 2; i < 2 * n; i++) {
			if (a[i] == a[i - 2]) {
				cout << -1;
			}
		}
		
	}
	return 0;
}
