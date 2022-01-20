#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sum[505];
char s[505];
void check()
{
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(s[i]=='*');
	int l=1,r=0,len=0;
	while(l<=n)
	{
		while(r<n&&sum[r+1]-sum[l-1]==r-l+2)r++;
		len=max(len,r-l+1);
		l++;
	}
	if(len>m)return;
	int num=0,last=0,flag=0,flag1=0,flag2=0;
	for(int i=1;i<=n;i++)
	{
		if(flag==1&&last==1&&s[i]=='(')flag1=1;
		if(flag==1&&last==2&&s[i]==')')flag2=1;
		if(s[i]=='(')num++,last=1,flag=0;
		if(s[i]==')')num--,last=2,flag=0;
		if(s[i]=='*')flag=1;
		if(num<0)return;
	}
	if(s[1]!='('||s[n]!=')')return;
	if(flag1==1&&flag2==1)return;
	if(num>0)return;
	ans++;
}
void dfs(int k)
{
	if(k==n+1){check();return;}
	if(s[k]!='?'){dfs(k+1);return;}
	s[k]='(';
	dfs(k+1);
	s[k]=')';
	dfs(k+1);
	s[k]='*';
	dfs(k+1);
	s[k]='?';
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	dfs(1);
	printf("%d",ans);
	return 0;
}
