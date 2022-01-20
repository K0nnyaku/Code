#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define il inline
#define out(x) write(x), putchar(' ')
#define wr(x) write(x), putchar('\n')
#define F(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))

using namespace std;
const int maxn = 500050, inf = 1e9 + 5;
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

int T, n;
int a[maxn * 2];

il void dfs(int l, int r) {
	
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	for ( rd(T); T; --T ) {
		rd(n);
		F(i, 1, 2 * n) rd(a[i]);
		dfs(1, n);
	}
	return 0;
}

