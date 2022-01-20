#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
const int N=1e2+5;
char ch[N];
int n,k,flagg;
ll ans[N][N];
int read()
{
	int x=0,f=1;
	char cc=getchar();
	while(!isdigit(cc))
	{
		if(cc=='-')f=-f;
		cc=getchar();
	}
	while(isdigit(cc))
	{
		x=x*10+cc-'0';
		cc=getchar();
	}
	return x*f;
}
ll dfs(int l,int r)
{
	ll sum=0;
	if(ans[l][r])return ans[l][r];
	if(r-l+1<2)return ans[l][r]=0;
	if(ch[l]!='('&&ch[l]!='?')return ans[l][r]=0;
	if(ch[r]!=')'&&ch[r]!='?')return ans[l][r]=0;
	if(r-l-1<=k)
	{
		int flag=0;
		for(int i=l+1;i<=r-1;i++)
		{
			if(ch[i]!='*'&&ch[i]!='?')
			{
				flag=1;break;
			}
		}
		if(!flag)sum++;
	}
	
	//2
	for(int i=l+1;i<=r-2;i++)
	{
		for(int j=i+1;j<=min(i+k+1,r-1);j++)
		{
			int flag=0;
			for(int h=i+1;h<=j-1;h++)
			{
				if(ch[h]!='*'&&ch[h]!='?')
				{
					flag=1;break;
				}
			}
			if(ch[i]!=')'&&ch[i]!='?')
			flag=1;
			if(ch[j]!='('&&ch[j]!='?')
			flag=1;
			if(!flag)
			sum+=dfs(l,i)*dfs(j,r)%mod;
			sum%=mod;
		}
	}
	//3
	sum+=dfs(l+1,r-1)%mod;
	sum%=mod;
	//(SA)
	for(int i=l+2;i<=min(l+k+1,r-2);i++)
	{
		int flag=0;
		for(int h=l+1;h<=i-1;h++)
		{
			if(ch[h]!='*'&&ch[h]!='?')
			{
				flag=1;break;
			}
		}
		if(!flag)
		sum+=dfs(i,r-1);
		sum%=mod;
	}
	//(AS)
	for(int i=max(l+2,r-k-1);i<=r-2;i++)
	{
		int flag=0;
		for(int h=i+1;h<=r-1;h++)
		{
			if(ch[h]!='*'&&ch[h]!='?')
			{
				flag=1;break;
			}
		}
		if(!flag)
		sum+=dfs(l+1,i);
		sum%=mod;
	}
	return ans[l][r]=sum%mod;
} 
void init()
{
	cin>>n>>k;
	scanf(" %s",ch+1);
	if(ch[n]!=')'&&ch[n]!='?')
	{
		flagg=1;return;
	}
}
void solve1()
{
	printf("0");
}
void solve2()
{
	cout<<dfs(1,n)<<endl;
	
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	init();
	if(flagg==1)
	{
		solve1();
	}
	else
	{
		solve2();
	}
	
	
	return 0;
}
/*
7 3
(*??*??

5 3
??*??
10 2
???(*??(?)

7 2
???(*??

*/
