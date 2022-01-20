#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

typedef long long ll;
const int maxn = 2e5 + 9, inf = 2e9;
const ll INF = 1e18;

int read() {
	int x = 0, f = 0, ch = getchar();
	for (; !isdigit(ch); f = (ch == '-'), ch = getchar()) ;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar()) ;
	return f ? -x : x; 
}

void read(ll &x) {
	int f = 0, ch = getchar();
	for (; !isdigit(ch); f = (ch == '-'), ch = getchar()) ;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar()) ;
	x = f ? -x : x;
}

int main() {
//	freopen("traffic.in", "r", stdin);
//	freopen("traffic.out", "w", stdout);
	__int128 qwq = 0;
	qwq = qwq + 114514;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
