#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
const int MAXN = 505;
const int MOD = 1e9 + 7;
int n, k;
char s[MAXN];
template <class I> inline void read(I &x){
	x = 0; int f = 1; char ch;
	do { ch = getchar(); if(ch == '-') f = -1; } while(ch < '0' || ch > '9');
	do { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); } while(ch >= '0' && ch <= '9');
	x *= f; return; 
} 
namespace seg{
	inline int lson(int k) { return k << 1; }
	inline int rson(int k) { return k << 1 | 1; };
	 
}
int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n), read(k);
	scanf("%s", s + 1);
	long long ans = 0;
	for(int i = 1; i <= k; ++i) ans = (ans + (n - i + 1) * i % MOD) % MOD;
	for(int i = 1; i <= k; ++i){
		if((n - k + 1) & 1) continue;
		else ans = (ans + (1 << (n - k)) % MOD) % MOD; 
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
