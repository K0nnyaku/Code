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

const int MAXN = 5e5 + 10;

int n;
int aa[MAXN * 2];

int bb[MAXN * 2];
int cc[MAXN * 2];

int ansstat = -1;

bool check(int stat) {
	int ptrl = 1, ptrr = n * 2;
	int ansptrl = 1, ansptrr = n * 2;
	memset(bb, 0, sizeof bb);
	for (int i = 0; i < n * 2; ++i) {
		if (stat & (1 << i)) bb[i + 1] = aa[ptrl++];
		else bb[i + 1] = aa[ptrr--];
	}
	
	for (int i = 1; i <= n; ++i) if (bb[i] != bb[n * 2 - i + 1]) return false;
	

	if (ansstat != -1) {
		for (int i = 0; i < n * 2; ++i) {
			int bi = !((stat >> i) & 1);
			int ci = !((ansstat >> i) & 1);
			if (bi < ci) break;
			if (bi > ci) return false; 
		}
	}
//	for (int i = 1; i <= n * 2; ++i) printf("%d", bb[i]);
//	puts("");
	ansstat = stat;
	return true;
}

int _main() {
	n = read();
	for (int i = 1; i <= n * 2; ++i) aa[i] = read();
	for (int i = 0; i <= (1 << (n * 2)) - 1; ++i) {
		check(i);
	}
	if (ansstat == -1) printf("-1\n");
	else {
		for (int i = 0; i < n * 2; ++i) {
			if (ansstat & (1 << i)) printf("L");
			else printf("R");
		} puts("");
	} ansstat = -1;
	return 0;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T = read();
	while (T --> 0) {
		_main();
	}
}




