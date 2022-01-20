#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int read();

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	return 0;
}

int read() {
	int a = 1, h = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			a = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		h = h * 10 + ch - '0';
		ch = getchar();
	}
	return a * h;
}
