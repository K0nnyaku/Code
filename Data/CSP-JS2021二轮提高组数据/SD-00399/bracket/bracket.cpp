#include<bits/stdc++.h>

using namespace std;

#define int long long

template<typename _T>
inline void read(_T &x)
{
	x = 0;int f = 1;char s = getchar();
	while(s < '0'||s > '9'){f=1;if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s = getchar();}
	x *= f;
}

int n,k;
char s[23333];
int hf[233][233];
int t[233][233];
int dp[233][233]; // 所有字符串 
int g[233][233]; // 存没有 AB 的字符串 
int f[233][233]; // 存没有 ASB 的字符串 
inline int debug()
{
	return 1;
}

inline bool check(int l,int r)
{
	int flag = 1;
	if(s[l] == '?' || s[l] == '(') flag &=1;
	else flag = 0;
	if(s[r] == '?' || s[r] == ')') flag &= 1;
	else flag = 0;
	return flag;
}

signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n),read(k);
	scanf("%s",s + 1);
	for(int i=1;i <= n;i ++)
	{
		hf[i][i] = (s[i]=='*')||(s[i]=='?');
		for(int j=i+1;j <= n;j ++)
		if(j-i+1 <= k) hf[i][j] = hf[i][j-1] & (s[j]=='*'||s[j]=='?');		
	}

	for(int i=1;i+1 <= n;i ++)
	{
		dp[i][i + 1] = check(i,i+1);// ()
		t[i][i + 1] = f[i][i + 1] = g[i][i + 1] = dp[i][i + 1];
	}
	for(int i=3;i <=n;i ++)
	{
		for(int l=1,r=l+i-1;r <= n;l ++,r ++)
		{
			if(l == 1 && r==n) debug();
			int uop = check(l,r);
			if(uop) dp[l][r] = dp[l+1][r-1];// (A)
			if(uop) dp[l][r] += hf[l + 1][r-1];// (S)
			if(uop)
			for(int k=l+1;k < r-1 ;k ++) // (SA)
			dp[l][r] += hf[l + 1][k] * dp[k + 1][r-1];
			
			if(uop)
			for(int k=r-1;k > l + 1;k -- )// (AS)
			dp[l][r] += dp[l + 1][k-1] * hf[k][r-1];
			
			t[l][r] = g[l][r] = dp[l][r];
			f[l][r] = dp[l][r];
//			printf("%d\n",dp[l][r]);
			for(int k=l + 1;k < r-1;k ++) // AB
			{
				dp[l][r] += g[l][k] * dp[k + 1][r];
				f[l][r] += f[l][k] * f[k + 1][r];
//				dp[l][r] += dp[l][k] * dp[k + 1][r];
			}
			for(int op = 1;op <= k;op ++)
				for(int a1=l+2,a2 = a1 + op-1;a2 < r-1;a1 ++,a2 ++) // ASB
				{
					dp[l][r] += g[l][a1-1] * hf[a1][a2] * dp[a2 + 1][r];
					g[l][r] += g[l][a1-1] * hf[a1][a2] * g[a2 + 1][r];
//					dp[l][r] += dp[l][a1 - 1] * hf[a1][a2] * dp[a2 + 1][r];
				}
//			dp[l][r] += g[l][r] + f[l][r] - t[l][r]-t[l][r];
		}
	}
	
//	for(int i=1;i <= n;i ++)
//	{
//		for(int j=i;j <= n;j ++)
//		{
//			printf("t[%lld][%lld] = %lld ",i,j,t[i][j]);
//			printf("dp[%lld][%lld] = %lld ",i,j,dp[i][j]);
//			printf("g[%lld][%lld] = %lld ",i,j,g[i][j]);
//			printf("f[%lld][%lld] = %lld\n",i,j,f[i][j]);
//		}
//	}
	printf("%lld\n",dp[1][n]);
}
/*
7 3
(*??*??

10 2
???(*??(?)
*/

