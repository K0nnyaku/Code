#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

struct pl {
	int k, a, b;
};
pl a[10002];

int p[2][10002]; 
int n, m1, m2, m;

bool cmp(pl x, pl y) {
	return x.a < y.a;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	cin >> n >> m1 >> m2;
	m = m1 + m2;
	for (int i = 0; i < m1; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = { 0, x, y };
	}
	for (int i = 0; i < m2; i++) {
		int x, y;
		cin >> x >> y;
		a[m1 + i] = { 1, x, y };
	}
	sort(a, a + m, cmp);
	
	int maxn = 0;
	for (int i = 0; i <= n; i++) {
		int cnt = 0;
		memset(p, 0, sizeof(p));
		for (int j = 0; j < m; j++) {
			pl h = a[j];
			int t;
			t = (h.k == 0) ? i : (n - i);
			for (int k = 0; k < t; k++) {
				if (p[h.k][k] <= h.a) {
					p[h.k][k] = h.b;
					cnt++;
					break;
				}
			}
		}
		if (cnt > maxn) {
			maxn = cnt;
		}
	}
	cout << maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
