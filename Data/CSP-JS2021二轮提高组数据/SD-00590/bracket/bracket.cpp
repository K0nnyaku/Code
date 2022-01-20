#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define inf 0x3f3f3f3f
#define maxn 501
#define ll long long

void read(int &x) {
	char F = getchar();
	int flag = 1; x = 0;
	while(F > '9' || F < '0') {
		if(F == '-') flag = -1;
		F = getchar();
	}
	while(F >= '0' && F <= '9') {
		x *= 10;
		x += F - '0';
		F = getchar();
	}
	x *= flag;
}

int n, k, s[maxn], sta[maxn], top;
ll ans;

void init() {
	char F = getchar();
	while(F != '(' && F != ')' && F != '*' && F != '?') F = getchar();
	while(F == '(' || F == ')' || F == '*' || F == '?') {
		if(F == '(') s[++ s[0]] = 1;
		if(F == ')') s[++ s[0]] = 2;
		if(F == '*') s[++ s[0]] = 3;
		if(F == '?') s[++ s[0]] = 0;
		F = getchar();
	}
}

void paint() {
	for(int i = 1; i <= n; i ++) {
		if(s[i] == 1) printf("(");
		if(s[i] == 2) printf(")");
		if(s[i] == 3) printf("*");
	}
	puts("");
}

bool check() {
	if(s[1] == 3) return 0;
	if(s[n] == 3) return 0;
	for(int i = 1; i <= n; i ++) {
		bool res = 1;
		if(i - k < 1) continue;
		for(int j = i - k; j <= i; j ++) if(s[j] != 3) res = 0;
		if(res) return 0;
	}
	top = 0;
	for(int i = 1; i <= n; i ++) {
		if(s[i] == 1) sta[++ top] = i;
		if(s[i] == 2) {
			if(! top) return 0;
			int l = sta[top --], r = i;
			bool res = 1;
			for(int j = l + 1; j < r; j ++) if(s[j] != 3) res = 0;
			if(l + 1 == r || res || s[l + 1] != 3 || s[r - 1] != 3) continue;
			return 0;
		}
	}
	if(top) return 0;
	//paint();
	return 1;
}

void dfs(int o, int cnt1, int cnt2) {
	if(cnt1 < cnt2) return;
	if(o == n + 1) {
		if(check()) ans ++;
		return;
	}
	if(s[o] == 1) dfs(o + 1, cnt1 + 1, cnt2);
	if(s[o] == 2) dfs(o + 1, cnt1, cnt2 + 1);
	if(s[o] == 3) dfs(o + 1, cnt1, cnt2);
	if(! s[o]) {
		s[o] = 1; dfs(o + 1, cnt1 + 1, cnt2);
		s[o] = 2; dfs(o + 1, cnt1, cnt2 + 1);
		if(o != 1 && o != n) s[o] = 3; dfs(o + 1, cnt1, cnt2);
		s[o] = 0; 
	}
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n); read(k); init();
	//printf("%d\n", n);
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
/*100 18
?*?????)?????*????????*??(*???????*????????????*???*?????*?????*??????*****??*??????????*???????????
*/
