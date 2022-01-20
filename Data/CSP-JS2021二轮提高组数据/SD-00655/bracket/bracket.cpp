#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)

typedef long long ll;

template <typename T>
T read(T &a)
{
	T res = 0, sign = 1;
	char c;
	while((c = getchar()) < '0' || c > '9') if(c == '-') sign = -1;
	while(c <= '9' && c >= '0') res = res * 10 + c - '0', c = getchar();
	a = res * sign;
	return a;
}

const int N = 510;
const ll mod = 1000000007;
ll dp[N][N], ss[N][N];
int n, kk;
char s[N];

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n), read(kk);
	scanf("%s", s+1);
	rep(i,1,n) if(s[i] == '*' || s[i] == '?') ss[i][i] = 1;
	rep(i,2,kk)
	{
		rep(j,1,n-i+1)
		{
			int r = j + i - 1;
			ss[j][r] = ss[j][r-1] * ss[r][r];
			if(i > kk) ss[j][r] = 0;
		}
	}
	rep(i,2,n)
	{
		rep(l,1,n-i+1)
		{
			int r = l + i - 1;
			if(s[l] == '*' || s[r] == '*') { dp[l][r] = 0; continue; }
			if(i == 2) { dp[l][r] = 1; continue; }
			int nl = l+1, nr = r-1;
			ll &js = dp[l][r]; js = 0;
			js = (js + ss[nl][nr]) % mod;
			js = (js + dp[nl][nr]) % mod;
			rep(k,nl,nr) js = (js + dp[l][k] * dp[k+1][r] % mod) % mod;
			rep(k,nl,nr) js = (js + 1ll * ss[nl][k] * dp[k+1][nr] % mod) % mod;
			rep(k,nl,nr) js = (js + 1ll * dp[nl][k] * ss[k+1][nr] % mod) % mod;
			rep(k,nl,nr)
			{
				rep(lj,1,kk)
				{
					js = (js + 1ll * dp[l][k-1] * ss[k][k+lj-1] * dp[k+lj][r] % mod) % mod;
				}
			}
		}
	}
	printf("%d\n", dp[1][n]);
			
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
10 2
???(*??(?)

*/

