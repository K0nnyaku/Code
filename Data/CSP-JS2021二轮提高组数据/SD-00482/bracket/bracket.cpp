#include <cstdio>

const int Maxn = 5e2 + 5;

int n, k, ans; char s[Maxn], t[Maxn]; int d[Maxn];

int stk[Maxn], tp; bool b[Maxn];
bool check() {
	if(t[1] != '(' || t[n] != ')') return false;
	int cnt = 0, type = 0;
	for(int i = 1; i <= n; ++i) b[i] = 0; tp = 0;
	for(int i = 1; i <= n; ++i) {
		if(t[i] == '(') {
			//if(cnt && type) return false;
			cnt = 0; type = 0;
			stk[++tp] = i;
			b[i] = t[i - 1] == '*';
		}
		if(t[i] == ')') {
			//if(cnt && (!type)) return false;
			cnt = 0; type = 0;
			if(t[i + 1] == '*' && b[stk[tp]]) return false;
			tp--;
		}
		if(t[i] == '*') {
			cnt++; if(cnt == 1) type = (t[i - 1] == ')');
			if(cnt > k) return false;
		}
	}
	return true;
}

void dfs(int u, int p) {
	if(u == n + 1) {
		if(p == 0) {
			if(check()) {
				ans++;
				if(ans >= 1000000007) ans -= 1000000007;
				//puts(t + 1);
			}
		}
		return;
	}
	if(d[u] < p) return;
	if(s[u] == '(' || s[u] == '?') t[u] = '(', dfs(u + 1, p + 1);
	if(s[u] == ')' || s[u] == '?') t[u] = ')', dfs(u + 1, p - 1);
	if(s[u] == '*' || s[u] == '?') t[u] = '*', dfs(u + 1, p);
	return;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	
	scanf("%d%d%s", &n, &k, s + 1);
	for(int i = n; i >= 1; --i) d[i] = (d[i + 1] + (s[i] == '?' || s[i] == ')'));
	dfs(1, 0); printf("%d", ans);
	
	fclose(stdin); fclose(stdout);
	return 0;
} 
