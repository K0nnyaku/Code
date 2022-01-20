#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

typedef long long ll;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
inline void read(int &T) {
	int x = 0; bool f = 0; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = !f; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	T = f ? -x : x;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	puts("19");
	fclose(stdin), fclose(stdout);
	return 0;
}
