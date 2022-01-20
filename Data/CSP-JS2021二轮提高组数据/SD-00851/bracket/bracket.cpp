#include <bits/stdc++.h>
const int maxn = 2e6+5;
const int mod = 1e9+7;

inline int read() {
	int x = 0,w = 1;char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') w = -1;ch = getchar();}
	while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0';ch = getchar();}
	return x * w;
}

int n,k,tot,ans;
int C[2005][2005];

void init() {
//	tot = 1;
//	for(int i = 1;i <= n;i++) tot *= i % mod;
	C[1][1] = 1,C[1][0] = 0,C[0][1] = 0;
	for(int i = 2;i <= n;i++)
		for(int j = 2;j <= k;j++) 
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}

int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	std::string str; std::cin >> str;
	init();
	std::cout << C[n][k];
	return 0;
}
