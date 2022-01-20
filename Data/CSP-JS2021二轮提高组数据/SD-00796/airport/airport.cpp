//T1大模拟O(n(m1+m2))，预计得分40+pts 
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
struct node {
	int start;
	int end;
	bool operator < (const node &rhs) const {
		return start < rhs.start;
	}
} a[100005], b[100005];
int n, m1, m2, ans;
int t1[100005], t2[100005];
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n); read(m1); read(m2);
	for (int i = 1; i <= m1; ++i)
		read(a[i].start), read(a[i].end);
	sort(a + 1, a + m1 + 1);
	for (int i = 1; i <= m2; ++i)
		read(b[i].start), read(b[i].end);
	sort(b + 1, b + m2 + 1);
	for (int k = 0; k <= n; ++k) {
		int tmp = 0;
		memset(t1, 0, sizeof(t1));
		memset(t2, 0, sizeof(t2));
		for (int i = 1; i <= m1; ++i)
			for (int j = 1; j <= k; ++j)
				if (a[i].start > t1[j]) {
					t1[j] = a[i].end;
					tmp++;
					break;
				}
		for (int i = 1; i <= m2; ++i)
			for (int j = 1; j <= n - k; ++j)
				if (b[i].start > t2[j]) {
					t2[j] = b[i].end;
					tmp++;
					break;
				}
		if (tmp > ans) ans = tmp;
	}
	write(ans);
	return 0;
}
