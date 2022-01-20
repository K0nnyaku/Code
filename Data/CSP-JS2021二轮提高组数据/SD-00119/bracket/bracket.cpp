#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
int n,k;
string s;
int dfs(int x,int z,int c)
{
	if(c==n)
	{
		if(z==0&&x==0) return 1;
		return 0;
	}
	int xh=x,zh=z,sum=0;
	for(int i=c+1;i<=n;++i)
	{
		if(s[i]=='*')
		{
			++xh;
			if(xh>k||i==0||i==n) return 0;
		}
		if(s[i]=='(') ++zh,xh=0;
		if(s[i]==')')
		{
			if(zh) --zh,xh=0;
			else return 0;
		}
		if(s[i]=='?')
		{
			if(xh<k&&i!=0&&i!=n) sum+=dfs(xh+1,zh,i);
			sum%=mod;
			sum+=dfs(0,zh+1,i);
			sum%=mod;
			if(zh>0) sum+=dfs(0,zh-1,i);
			sum%=mod;
			return sum;
		}
		if(i==n)
		{
			sum+=dfs(xh,zh,i);
			sum%=mod;
			return sum;
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	--n;
	printf("%d",dfs(0,0,-1));
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
