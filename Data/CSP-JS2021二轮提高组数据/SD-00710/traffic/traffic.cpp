#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <vector>

typedef long long int lli;

int read() {
	int s = 0, x = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') x = -x;
		ch = getchar();
	}
	while (isdigit(ch)) {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * x;
}

lli readll() {
	lli s = 0, x = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') x = -x;
		ch = getchar();
	}
	while (isdigit(ch)) {
		s = s * 10ll + ch - '0';
		ch = getchar();
	}
	return s * x;
}

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout); 
	return 0;
}

