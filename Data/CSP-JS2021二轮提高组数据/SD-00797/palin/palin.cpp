#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#define write(n) (n < 0 ? (putchar('-'), rite(-n)) : rite(n))
using namespace std;
inline int read() {
	int x = 0, b = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			b = 0;
		}
		c = getchar(); 
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ '0');
		c = getchar();
	}
	return b ? x : -x;
}
void rite(int n) {
	if (n > 9) {
		rite(n / 10);
	}
	putchar(n % 10 ^ '0');
} 
int a[1000002], n, ans[1000002], bo, head, tail, tot, the[100002];
inline bool check() {
	for (int i = 1; i <= n; ++i) {
		if (a[i] != a[n - i + 1]) return false;
	}
	return true;
}
void DFS() {
	if (head < tail) {
		if(check()) {
			bo = 1;
		}
	}
	ans[++tot] = a[head];
	++head;
	DFS();
	--head;
	if(bo == 1) {the[tot] = 1;return;}
	ans[tot] = a[tail];
	--tail;
	DFS();
	++tail;
	if(bo == 1) {
		the[tot] = 2;
		return;
	}
} 
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T = read();
	while (T--) {
		head = 1;
		n = read();
		tail = n;
		bo = 0;
		tot = 0;
		for (int i = 1; i <= n << 1; ++i) {
			a[i] = read();
		}
		DFS();
		if (bo) {
			for (int i = 1; i <= n << 1; ++i) {
				putchar(the[i] == 1 ? 'L' : 'R');
			}
			putchar('\n');
		}
		else {
			puts("-1");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
