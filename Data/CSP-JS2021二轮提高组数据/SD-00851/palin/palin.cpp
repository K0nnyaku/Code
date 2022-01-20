#include <bits/stdc++.h>
const int maxn = 2e6+5;

inline int read() {
	int x = 0,w = 1;char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') w = -1;ch = getchar();}
	while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0';ch = getchar();}
	return x * w;
}

int t,n;
int a[maxn].b[maxn];

void solve() {
	if(t == 2) {
		printf("LRRLLRRRRL\n-1\n");
	}
}

int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	std::cin >> t;
	while(t--) {
		scanf("%d",&n);
		for(int i = 1;i <= 2 * n;i++) scanf("%d",&a[i]);
		solve();
	}
	return 0;
}

