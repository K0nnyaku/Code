//T2±¬ËÑO((3^n)n)£¬Ô¤¼ÆµÃ·Ö15-pts 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
template<class T> inline void read(T &x) {
	x = 0; int f = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar();}
	while (c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c - 48); c = getchar();}
	if (f) x = ~x + 1;
}
template<class T> inline void write(T x) {
	if (x < 0) {putchar('-'); x = ~x + 1;}
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
#define writeS(x) write(x), putchar(' ')
#define writeL(x) write(x), putchar('\n')
int n, k, ans;
char s[505], tmp[505], d[3] = {'*', '(', ')'};
int cnt, a[505];
void check() {
	if (tmp[1] == '*') return;
	if (tmp[n] == '*') return;
	int maxtot = 0, tot = 0;
	for (int i = 1; i <= n; ++i) {
		if (tmp[i] == '*') {
			if (tmp[i - 1] != '*') tot = 1;
			else tot += 1;
		}
		if (tot > maxtot) maxtot = tot;
	}
	if (maxtot > k) return;
	int stk[505]; tot = 0;
	memset(a, 0, sizeof(a)); cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (tmp[i] == '(') {
			stk[++tot] = ++cnt;
			if (tmp[i + 1] == '*') a[cnt] = 1;
		}
		if (tmp[i] == ')') {
			if (tot == 0) return;
			if (a[stk[tot]] == 1 && tmp[i - 1] == '*' && stk[tot] < cnt) return;
			tot--;
		}
	}
	if (tot > 0) return;
	ans++;
//	printf("%s\n", tmp + 1);
}
void dfs(int dep) {
	if (s[dep] != '?') {
		dfs(dep + 1);
		return;
	}
	for (int i = 0; i < 3; ++i) {
		tmp[dep] = d[i];
		if (dep == n) check();
		else dfs(dep + 1);
	}
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n); read(k);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
		tmp[i] = s[i];
	dfs(1);
	write(ans);
	return 0;
}
