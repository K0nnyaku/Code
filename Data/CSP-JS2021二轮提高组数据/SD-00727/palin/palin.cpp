#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <utility>
#include <cmath>
#define MAXN 1000010
using namespace std;
//--------------------------------------------------

//--------------------------------------------------
int n, T, flag = 0;
int tmp[MAXN], res[MAXN], vis[MAXN];
//--------------------------------------------------
int read() {
	int f = 0, x = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
bool check() {
	for (int i = 1; i <= n; ++i)
		if (res[i] != res[(n << 1) - i + 1]) return 0;
	return 1;
}
void dfs(int t, string s) {
//	cout << s << endl;
	if (t == (n << 1) + 1) {
		if (check()) {
			cout << s << endl;
			flag = 1;
		}
		return ;
	}
	int i = 1;
	while (vis[i]) ++i;
	res[t] = tmp[i];
	vis[i] = 1;
	string bes = s + 'L';
	dfs(t + 1, bes);
//	cout << s << endl;
	if (flag) return ;
	vis[i] = 0;
	i = n << 1;
	while (vis[i]) --i;
	res[t] = tmp[i];
	vis[i] = 1;
	bes = s + 'R';
	dfs(t + 1, bes);
//	cout << s << endl;
	if (flag) return ;
	vis[i] = 0;
}
//--------------------------------------------------
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= (n << 1); ++i)
			tmp[i] = read();
		flag = 0;
		memset(vis, 0, sizeof vis);
		dfs(1, "");
		if (!flag) printf("-1\n");
	}
	fclose(stdin); fclose(stdout); 
	return 0;
}
