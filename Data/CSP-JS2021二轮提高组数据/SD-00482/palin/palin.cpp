#include <bits/stdc++.h>

typedef long long LL; 

int n;

namespace subtask2 {
	const int Mxn = 5e5 + 5;
	const LL Mod = 998244353, bs = 114514;
	int ra[Mxn], rb[Mxn];
	LL hsha[Mxn], hshb[Mxn], pw[Mxn];
	
	void RMain() {
		for(int i = 1; i <= 2 * n; ++i) scanf("%d", &ra[i]), rb[2 * n - i + 1] = ra[i];
		n <<= 1; pw[0] = 1;
		for(int i = 1; i <= n; ++i)
			hsha[i] = (hsha[i - 1] * bs % Mod + ra[i]) % Mod,
			hshb[i] = (hshb[i - 1] * bs % Mod + rb[i]) % Mod,
			pw[i] = pw[i - 1] * bs % Mod;
		if(hsha[n] == hshb[n]) {
			for(int i = 1; i <= n; ++i) printf("L");
			printf("\n"); return;
		}
		for(int i = n - 2; i >= 2; --i) {
			LL resa = (hshb[n] + Mod - hshb[n - i] * pw[i] % Mod) % Mod,
				 resb = (hsha[n] + Mod - hsha[i] * pw[n - i] % Mod) % Mod;
			if(hsha[i] == resa && hshb[n - i] == resb) {
				for(int j = 1; j <= (i >> 1); ++j) printf("L");
				for(int j = (i >> 1) + 1; j <= (n >> 1); ++j) printf("R");
				for(int j = (i >> 1) + 1; j <= (n >> 1); ++j) printf("R");
				for(int j = 1; j <= (i >> 1); ++j) printf("L");
				printf("\n");
				return;
			}
		}
		printf("-1\n");
	}
}

const int Maxn = 2e3 + 5;
int a[Maxn], b[Maxn];

void Main() {
	scanf("%d", &n);
	if(n > 1000) {
		subtask2::RMain();
		return;
	}
	for(int i = 1; i <= n * 2; ++i) scanf("%d", &a[i]);
	for(int S = 0; S < (1 << (n * 2)); ++S) {
		bool flag = 1; int l = 1, r = 2 * n;
		for(int i = n * 2; i >= 1; --i) {
			if((S >> (i - 1)) & 1) b[i] = a[r--];
			else b[i] = a[l++];
		}
		for(int i = 1; i <= n; ++i) if(b[i] != b[2 * n - i + 1]) {
			flag = 0; break;
		}
		if(flag) {
			for(int i = n * 2; i >= 1; --i) {
				if((S >> (i - 1)) & 1) printf("R");
				else printf("L");
			}
			printf("\n");
			return;
		}
	}
	printf("-1\n");
	return;
}

int main() {
	
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	int T; scanf("%d", &T);
	while(T--) Main();
	
	fclose(stdin); fclose(stdout);
	
	return 0;
}
