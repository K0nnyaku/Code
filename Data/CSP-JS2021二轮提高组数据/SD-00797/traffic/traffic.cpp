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
int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
