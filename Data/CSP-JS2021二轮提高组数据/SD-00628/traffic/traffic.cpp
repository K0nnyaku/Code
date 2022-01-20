#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define il inline
#define out(x) write(x), putchar(' ')
#define wr(x) write(x), putchar('\n')

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

int T, n, m;
int a[maxn * 2];

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	rd(n), rd(m), rd(T);
	
	return 0;
}

