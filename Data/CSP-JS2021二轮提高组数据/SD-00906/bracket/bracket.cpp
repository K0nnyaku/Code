#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 0;
int nxt[510];
char ch[510], now[510];
int q_read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
	return x;
}
void dfs(int id) {
	if (id == -1) {
		if (now[1] != '(' || now[n] != ')') return ;
		int l = 0, r = 0, xing = 0;
		for (int i = 1; i <= n; ++i) {
			if (now[i] == '(') {
				xing = 0;
				++l;
			}
			else if (now[i] == ')') {
				++r;
				if (r > l) return ;
				xing = 0;
			} else {
				++xing;
				if (xing > k) return ;
			}
		}
		ans++;
		return ;
	}
	now[id] = '(';
	dfs(nxt[id]);
	now[id] = ')';
	dfs(nxt[id]);
	now[id] = '*';
	dfs(nxt[id]);
	return ;
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = q_read(); k = q_read();
	cin >> ch + 1;
	int pre = 0;
	for (int i = 1; i <= n; ++i) {
		if (ch[i] == '?') {
			nxt[pre] = i;
			pre = i;
		} else {
			now[i] = ch[i];
		}
	}
	nxt[pre] = -1;
	dfs(nxt[0]);
	cout << ans << endl;
	return 0;
}
