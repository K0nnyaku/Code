//吐了 又来 跟字符串过不去是吧 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
const int inf_int = 0x7fffffff;
typedef long long ll;
int n,k;
#define maxn 509
char a[maxn],b[maxn];
int ans=0;
int f[maxn][maxn][maxn*2];
bool check()
{
	int e=0,ok=1,s=0,maxs=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='(')e++;
		else if(a[i]==')')e--;
		if(a[i]=='*')s++;
		else maxs=max(s,maxs),s=0;
		if(e<0)
		{
			break;
		}
	}
	if(e==0&&ok&&maxs<=k)
	{
	
	printf("%s\n",a+1)	;return 1;
	}
	return 0;
}
void dfs(int now)
{
	if(now==n+1)
	{
		if(check())ans++;
		return;
	}
	if(b[now]!='?')
	{
		dfs(now+1);
		return;
	}
	a[now]='(';
	dfs(now+1);
	a[now]=')';
	dfs(now+1);
	a[now]='*';
	dfs(now+1);
	return;
}
		int res=0,mod=1000000007;
int C(int n,int m)
{
	int p=1;
	for(int i=m+1;i<=n;i++)
	{
		p=p*i%mod;
	}
	for(int i=1;i<=n-m;i++)p/=i;
	return p;
}
int Cat(int k)
{
	return C(n,k)*C(n-1,k)%mod;
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	if(n>=100)
	{
		int res=0,mod=1000000007;
		for(int len=1;len<=n;len++)
		{
			res+=(n-len+1)*Cat(len)%mod;
			res%=mod;
		}
		printf("%d\n",res);
		return 0;
	}
	for(int i=1;i<=n;i++)b[i]=a[i];
	dfs(1);
	printf("%d\n",ans/2);
	return 0;
}
/*
4:20 
观察数据范围 像是区间dp 
不大会。先去看看T34的暴力 
4:56你妈 感觉一个都不可做。
5:23剩下时间都看这个。T4不写了 
5:28 5min搞了个T4.
f[i][j][k]表示把[i,j]区间填充完 
多了k个左括号有多少种方法 
f[l][r][a]=f[l][k]+f[k+1][r]
试着把所有星号区间删掉 问号区间挨个变成星号区间 
然后跑区间dp 
问题变成解决第一个 
6:00
不会，准备暴力，25分 
特殊性质可以卡特兰数预处理+枚举星号 
7 3
(*??*??
10 2
???(*??(?)
感觉应该34不看 直接莽2 说不定还有机会。
2感觉没了。 
*/
