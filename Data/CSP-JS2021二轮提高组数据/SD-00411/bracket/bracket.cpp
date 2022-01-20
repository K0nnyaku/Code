#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int MAXD = 5e2 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline bool chk(char c){ return c == '?' || c == '*';}

char s[MAXN];
int len[MAXN];
int f[MAXN][MAXN], dp[MAXN][MAXN];

int main(void)
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	if(s[1] == '*' || s[n] == '*')
		return printf("0"), 0;
	
	for(int i=1; i<=n; ++i)
	{
		if(chk(s[i])) len[i] = len[i-1] + 1;
		else len[i] = 0;
	}
	
	for(int l=n; l>=1; --l)
		for(int r=l+1; r<=n; ++r)
		{
			if(s[l] != '?' && s[l] != 40) continue;
			if(s[r] != '?' && s[r] != 41) continue;
			
			if(l+1 == r) f[l][r] = 1;
			if(r-l-1 <= d && len[r-1] >= r-l-1) f[l][r] = 1;
			
			add_mod(f[l][r], dp[l+1][r-1]);
			for(int k=1; k<=d && l+k<r && chk(s[l+k]); ++k)
				add_mod(f[l][r], dp[l+k+1][r-1]);
			for(int k=1; k<=d && r-k>l && chk(s[r-k]); ++k)
				add_mod(f[l][r], dp[l+1][r-k-1]);
			
			dp[l][r] = f[l][r];
			static int sum[MAXN];
			sum[l] = sum[l-1] = 0;
			for(int k=l+1; k<r; ++k)
				add_mod(sum[k] = sum[k-1], dp[l][k]);
			
			for(int k=l+1; k<r; ++k)
			{
				int x = min(len[k], min(d, k-l));
				int cur = ((ll)sum[k] - sum[k-x-1] + mod) * f[k+1][r] %mod;
				add_mod(dp[l][r], cur);
			}
		}
	
	printf("%d",dp[1][n]);
	return 0;
}
