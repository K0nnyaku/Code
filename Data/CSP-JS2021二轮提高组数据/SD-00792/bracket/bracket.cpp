#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
 
#define P 1000000007
#define LL long long
#define N 521

using namespace std;
LL n, k, g[N][N], op[N], st[N], tp = 0, res = 0, totp = 0, ps[N];
vector<LL> f[N][N];
char ch[N], per[N];
bool p[N];

bool ck() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) p[i] = false, op[i] = 0;
	tp = 0;
	for (int i = 1; i <= n; i++) {
		if (ch[i] == '*') p[i] = true;
		if (ch[i] == '(') cnt++, st[++tp] = i;
		if (ch[i] == ')') cnt--, op[i] = st[tp], op[st[tp]] = i, tp--;
		if (cnt < 0) return false;
	}
	if (cnt > 0) return false;
	for (int i = 1; i <= n; i++) {
		if (p[i]) cnt++;
		else cnt = 0;
		if (cnt > k) return false;
	}
	for (int i = 1; i <= n; i++) 
		if (ch[i] == '(' && (p[op[i] + 1] & p[i - 1])) return false;
	if (ch[1] != '(' || ch[n] != ')') return false;
	return true;
}
void dfs(int l, int r) {
	if (l == r + 1) {
		for (int i = 1; i <= totp; i++) 
			ch[ps[i]] = per[i];
		if (ck()) res++;
		for (int i = 1; i <= totp; i++) 	
			ch[ps[i]] = '?';
		return;
	}
	per[l] = '('; dfs(l + 1, r);
	per[l] = ')'; dfs(l + 1, r);
	per[l] = '*'; dfs(l + 1, r);
	return;
}
LL qf(LL i, LL j, LL kx) {
	if (f[i][j].size() < kx + 1) return 0;
	return f[i][j][kx]; 
}
void sub1() {
	for (int i = 1; i <= n; i++) 
		if (ch[i] == '?') ps[++totp] = i;
	dfs(1, totp);
	printf("%lld", res);
	return;
}
void sub2() {
	f[1][1].push_back(1);
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			int valg = (j < 1) ? 0 : g[i - 1][j - 1]; 
			if (ch[i] == '(') 
				f[i][j].push_back(valg % P), g[i][j] = valg;
			else if (ch[i] == ')') 
				f[i][j].push_back(g[i - 1][j + 1] % P), g[i][j] = g[i - 1][j + 1];
			else if (ch[i] == '*') {
				f[i][j].push_back(0); // f[i][j][0] = 0;
				for (int kx = 1; kx <= min((LL) i, k); kx++) 
					f[i][j].push_back(qf(i - 1, j, kx - 1) % P), g[i][j] = (g[i][j] + f[i][j][kx]) % P;
			}
			else {
				f[i][j].push_back((valg + g[i - 1][j + 1]) % P);
				g[i][j] = f[i][j][0] % P;
				for (int kx = 1; kx <= min((LL) i, k); kx++) 
					f[i][j].push_back(qf(i - 1, j, kx - 1) % P), g[i][j] = (g[i][j] + f[i][j][kx]) % P;	
			}
		}
	}
	printf("%lld", qf(n, 0, 0) % P);
	return;
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	scanf("%s", ch + 1);
	if (n <= 15) sub1();
	else sub2();
	return 0;
}
