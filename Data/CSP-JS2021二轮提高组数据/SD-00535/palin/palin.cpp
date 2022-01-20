#include<cstdio>
#include<cstring>

const int A = 1e4 + 7;
const int B = 1e5 + 7;
const int C = 1e6 + 7;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

void File() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
}
void REFile() {fclose(stdin); fclose(stdout);}

template <typename T> T Pow(T x) {return x * x;}
template <typename T> T Abs(T x) {return x < 0 ? -x : x;}
template <typename T> T Min(T x, T y) {return x < y ? x : y;}
template <typename T> T Max(T x, T y) {return x > y ? x : y;}
template <typename T> void Swap(T&x, T&y) {x ^= y ^= x ^= y;}

int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + (ch ^ 48); ch = getchar();}
	return x * f;
}
void Print(int x) {if(x < 0) x = -x, putchar('-'); if(x > 9) Print(x / 10); putchar(x % 10 ^ 48);}

bool flag;
int T, n, a[C], pos[2][C], b[C];
char s[C];

void check(int l, int r) {
	for(int i = n, j = n + 1; i >= 1; --i, ++j)
	{
		if(a[l] == b[i]) s[j] = 'L', ++l;
		else s[j] = 'R', --r;
	}
	printf("%s\n", s + 1);
}
void dfs(int t, int l1, int l2, int r2, int r1) {
	if(t == n + 1) {check(l2, r2); flag = 1; return ;}
	if(l1 == 1 && r1 == 2 * n)
	{
		s[t] = 'L'; b[t] = a[l1]; dfs(t + 1, l1 + 1, pos[1][a[l1]], pos[1][a[l1]], r1);
		if(flag) return ;
		s[t] = 'R'; b[t] = a[r1]; dfs(t + 1, l1, pos[0][a[r1]], pos[0][a[r1]], r1 - 1);
		if(flag) return ;
	}
	else
	{
		if(l1 < l2 && r2 < r1)
		{
			if(a[l1] == a[r2 + 1]) s[t] = 'L', b[t] = a[l1], dfs(t + 1, l1 + 1, l2, r2 + 1, r1);
			if(flag) return ;
			if(a[l1] == a[l2 - 1] && l1 != l2 - 1) s[t] = 'L', b[t] = a[l1], dfs(t + 1, l1 + 1, l2 - 1, r2, r1);
			if(flag) return ;
			if(a[r1] == a[r2 + 1] && r1 != r2 + 1) s[t] = 'R', b[t] = a[r1], dfs(t + 1, l1, l2, r2 + 1, r1 - 1);
			if(flag) return ;
			if(a[r1] == a[l2 - 1]) s[t] = 'R', b[t] = a[r1], dfs(t + 1, l1, l2 - 1, r2, r1 - 1);
			if(flag) return ;
		}
		else if(l1 < l2)
		{
			if(a[l1] == a[l2 - 1] && l1 != l2 - 1) s[t] = 'L', b[t] = a[l1], dfs(t + 1, l1 + 1, l2 - 1, r2, r1);
			if(flag) return ;
			if(a[r1] == a[l2 - 1]) s[t] = 'R', b[t] = a[r1], dfs(t + 1, l1, l2 - 1, r2, r1 - 1);
			if(flag) return ;
		}
		else if(r2 < r1)
		{
			if(a[l1] == a[r2 + 1]) s[t] = 'L', b[t] = a[l1], dfs(t + 1, l1 + 1, l2, r2 + 1, r1);
			if(flag) return ;
			if(a[r1] == a[r2 + 1] && r1 != r2 + 1) s[t] = 'R', b[t] = a[r1], dfs(t + 1, l1, l2, r2 + 1, r1 - 1);
			if(flag) return ;
		}
	}
}
void clear() {
	flag = 0;
	for(int i = 1; i <= n; ++i) pos[0][i] = pos[1][i] = a[i] = b[i] = 0;
}
void work() {
	clear();
	n = read();
	for(int i = 1; i <= 2 * n; ++i)
	{
		int x = read(); a[i] = x;
		if(!pos[0][x]) pos[0][x] = i;
		else pos[1][x] = i;
	}
	dfs(1, 1, 0, 0, n << 1);
	if(!flag) puts("-1");
}
void Main() {
	T = read(); while(T--) work();
}

int main() {File(); Main(); REFile(); return 0;}
/*
1
20
20 9 18 7 13 17 2 11 12 19 3 6 4 1 16 10 8 14 5 14 8 10 16 1 4 6 3 19 12 11 17 13 7 18 9 20 2 15 5 15

*/
