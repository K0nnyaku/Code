#include <bits/stdc++.h>
using namespace std;
int a, b;

int read() {
	char ch = getchar();
	int f = 0, h = 1;
	while(!isdigit(ch)) {
		if(ch == '-')
		h = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		f = f * 10 + ch - '0';
		ch = getchar();
	}
	return f * h;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	a = read(); b = read();
	cout << a + b;
	return 0;
}
