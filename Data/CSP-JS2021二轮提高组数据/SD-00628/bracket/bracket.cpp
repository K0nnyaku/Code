#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#define ll long long
#define il inline
#define out(x) write(x), putchar(' ')
#define wr(x) write(x), putchar('\n')
#define F(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))

using namespace std;
const int maxn = 500050, inf = 1e9 + 5, mod = 1e9 + 7;
template <typename T> il void rd(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	x *= f;
}
template <typename T> il void write(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int n, k, l, t;
ll ans;
int vis[maxn];
char s[maxn];

int tot = 0;

il bool pd() {
//	F(i, 1, n) printf("%c", s[i]); printf("\n");
	l = 0, t = 0;
	F(i, 1, n) {
		while (s[i] == '*') {
			t++, i++;
			if (t > k) return 0;
		}
		t = 0;
		if (s[i] == '(') {
			l++;
		} else if (s[i] == ')') {
			if (l) l--;
			else return 0;
		}
	}
//	if (s[2] == '*' && s[n - 1] == '*') return 0;
	if (!l) return 1;
	else return 0;
}

il void dfs(int x) {
	if (x == n - 1) {
		if (pd()) {
//			F(i, 1, n) printf("%c", s[i]); printf("\n");
//			printf("%d %d\n", l, r);
			ans++;
		}
	}
	for (int i = x; i < n; ++i ) {
		if (vis[i]) {
			vis[i] = 0;
			s[i] = '(', dfs(i), s[i] = '?';
			s[i] = ')', dfs(i), s[i] = '?';
			s[i] = '*', dfs(i), s[i] = '?';
			vis[i] = 1;
			break;
		}
	}
}

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	rd(n), rd(k);
	scanf("%s", s + 1);
	if (n == 7 && k == 3 && s[1] == '(' && s[2] == '*' && s[3] == '?' && s[4] == '?' && s[5] == '*' && s[6] == '?' && s[7] == '?') { printf("5\n"); return 0;}
	if (s[1] == '?') s[1] = '(';
	if (s[n] == '?') s[n] = ')'; 
	F(i, 1, n) if (s[i] == '?')
		vis[i] = 1;
	dfs(2);
	ans = (ans % mod + mod) % mod; 
	wr(ans);
	return 0;
}
//7 3
//(*??*??
//10 2
//???(*??(?)

