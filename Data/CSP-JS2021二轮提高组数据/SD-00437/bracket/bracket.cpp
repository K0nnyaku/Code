#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<vector>
#include<bitset>
using namespace std;
#define re register
#define mod 1000000007
#define inf 0x7f7f7f7f
#define maxn 550
#define int long long
inline int read();
inline void wn(int x);
inline void wr(int x);
inline void wi(int x);
int n,k;
string a;
int dp[maxn][maxn];
/*

int dfs(int l,int r)
{
//	wi(l),wr(r);
	if(l>r)	return dp[l][r]=0;
	if(l==r)	return dp[l][r]=1;
	if(r==l+1)
	{
		if(a[l]=='*'||a[r]=='*'||a[l]==')'||a[r]=='(')	return dp[l][r]=0;
		return dp[l][r]=1;
	}
	if(a[l]=='*'||a[r]=='*')	return dp[l][r]=0;	
	if(dp[l][r]!=-1)	return dp[l][r];
	dp[l][r]=0;
	for(re int i=l+1;i<r;++i)
	{
		if(a[i]!='?'&&a[i]!='*')	continue;
		for(re int j=1;j<=k;++j)
		{
			if(a[i+j-1]!='?'&&a[i+j-1]!='*')	break;
			dp[l][r]+=dfs(l,i-1)*dfs(i+j,r);
		}
	}
	return dp[l][r]+dfs(l+1,r-1);
}


6 2
(*??()

*/
int f[maxn];
int dfs(int l,int r)
{
//	wi(l),wr(r);	
//	if(dp[l][r]!=-1)	return dp[l][r];
	if(l>=r)	
	{
		dp[l][r]=0;
		return 0;
	}
	if(r==l+1)
	{
		if(a[l]=='*'||a[r]=='*'||a[l]==')'||a[r]=='(')	
		{
			dp[l][r]=0;
			return 0;
		}
		dp[l][r]=1;
		return 1;
	}
	if(a[l]=='*'||a[r]=='*'||a[l]==')'||a[r]=='(')
	{
		dp[l][r]=0;
		return 0;	
	}
	if((a[l]!=')')&&(a[l]!='*')&&(a[r]!='(')&&(a[r]!='*')&&(f[r-1]-f[l]==0)&&(r-l-1<=k))
		dp[l][r]=1;
	else 
		dp[l][r]=0;
//	if(l==1&&r==6)	wr(dp[l][r]);
	dp[l][r]+=dfs(l+1,r-1);//1
	dp[l][r]%=mod;
//	for(re int i=1;i<=k;++i)
//	{
//		if(a[l+i]!='*'&&a[l+i]!='?')	break;
//		if(l+i>=r-1)	break;///?????????????????????????
//		
//		dp[l][r]+=dfs(l+i+1,r-1);	
//	}
	for(re int i=l+1;;++i)
	{
		if(i-l>k)	break;
		if(i>r-3)	break;
		if(f[i]-f[l]!=0)	break;
		dp[l][r]+=dfs(i+1,r-1);
		dp[l][r]%=mod;
	}///////2
//		if(l==1&&r==6)	wr(dp[l][r]);
	for(re int i=r-1;;--i)
	{
		if(r-i>k)	break;
		if(i<l+3)	break;
		if(f[r-1]-f[i-1]!=0)	break;
		dp[l][r]+=dfs(l+1,i-1);
		dp[l][r]%=mod;
	}///////3
//			if(l==1&&r==6)	wr(dp[l][r]);
//	for(re int i=1;i<=k;++i)
//	{
//		if(a[r-i]!='*'&&a[r-i]!='?')	break;
//		if(r-i<=l+1)	break;///?????????????????????????
//		
//		dp[l][r]+=dfs(l+1,r-i-1);	
//	}
	for(re int i=l+1;i<r-1;++i)
		dp[l][r]+=dfs(l,i)*dfs(i+1,r)%mod,dp[l][r]%=mod;;///////4
//	if(l==1&&r==6)	wr(dp[l][r]);
	for(re int i=l+2;i<=r-2;++i)
	{
		for(re int j=i;j-i+1<=k;++j)
		{
			if(j>r-2)	break;
			if(f[j]-f[i-1]!=0)	break;
			dp[l][r]+=dfs(l,i-1)*dfs(j+1,r)%mod;
			dp[l][r]%=mod;
		}
	}////////5
//		if(l==1&&r==6)	wr(dp[l][r]);
//	for(re int i=l+2;i<=r-2;++i)
//	{
//		for(re int j=1;j<=k;++j)
//		{
//			if(a[i+j-1]!='*'&&a[i+j-1]!='?')	break;
//			if(i+j-1>=r-1)	break;////???????????????????????
//			
//			dp[l][r]+=dfs(l,i-1)*dfs(i+j,r);
//		}
//	}
	return dp[l][r]%mod;
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
//	printf("%d M",((sizeof(edge)>>20)));
	n=read(),k=read();
	memset(dp,-1,sizeof dp);
	cin>>a;
	a=' '+a;
	if(n==1)
	{
		wr(0);
		return 0;
	}
	if(a[1]==')')
	{
		wn(0);
		return 0;
	}
	if(a[n]=='(')
	{
		wn(0);
		return 0;
	}
	a[1]='(';
	a[n]=')';
	bool p=true;
	for(re int i=1;i<=n;++i)
	{
		if(a[i]!='?')	
		{
			p=false;
			break;
		}
	}
	for(re int i=1;i<=n;++i)
	{
		if(a[i]=='('||a[i]==')')	f[i]=1;
		f[i]+=f[i-1];
	}

		wr(dfs(1,n)%mod);


	fclose(stdin);
	fclose(stdout);
	return 0;
}
//======================================================
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void wn(int x)
{
	if(x<0)
	{
		putchar('-');
		wn(-x);
		return ;
	}
	if(x>=10)	wn(x/10);
	putchar(x%10+'0');
}
inline void wr(int x)
{
	wn(x);
	putchar('\n');
}
inline void wi(int x)
{
	wn(x);
	putchar(' ');
}
/*

6 2
???(*?

*/

