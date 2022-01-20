#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 1000000007

using namespace std;

int read();
void in();
void solve();

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	in();
	solve();
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

void in() {
	n = read();
	k = read();
	cin >> ch;
	if (ch[0] != '(' || ch[n - 1] != ')') {
		cout << 0;
		exit(0);
	}
}

void solve() {
	
}
