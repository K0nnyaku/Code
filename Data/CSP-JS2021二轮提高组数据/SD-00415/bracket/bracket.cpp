#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
int n,k,top,sta[505],z[505];
long long ans;
char s[505];
bool work(int l,int r)
{
	if(l+1==r)
		return true;
	int a=0,p1=0,p2=0;
	for(int i=l+1;i<=r-1;i++)
	{
		if(z[i]>0)
		{
			p1=i;
			break;
		}
		a++;
		if(a>k)
			return false;
	}
	if(p1==0)
		return true;
	a=0;
	for(int i=r-1;i>=l+1;i--)
	{
		a++;
		if(a>k)
			return false;
		if(z[i]>0)
		{
			p2=i;
			break;
		}
	}
	if(p1>l+1&&p2<r-1)
		return false;
	while(z[p1]!=p2)
	{
		int p3=0;
		for(int i=p1;i<=r;i++)
			if(s[i]=='('&&p1!=i)
			{
				p3=i;
				break;
			}
		if(p3-z[p1]-1>k)
			return false;
		if(!work(p1,z[p1]))
			return false;
		p1=p3;
	}
	return work(p1,p2);
}
bool check()
{
	top=0;
	int p1=0,p2=0;
	memset(z,0,sizeof(z));
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
		{
			if(p1==0)
				p1=i;
			sta[++top]=i;
		}
		else if(s[i]==')')
		{
			p2=i;
			if(top<=0)
				return false;
			z[sta[top]]=i;
			z[i]=sta[top];
			top--;
		}
	}
	if(top>0)
		return false;
	if(p1>1||p2<n)
		return false;
	while(z[p1]!=p2)
	{
		int p3=0;
		for(int i=p1;i<=n;i++)
			if(s[i]=='('&&p1!=i)
			{
				p3=i;
				break;
			}
		if(p3-z[p1]-1>k)
			return false;
		if(!work(p1,z[p1]))
			return false;
		p1=p3;
	}
	return work(p1,p2);
}
void dfs(int k)
{
	if(k==n+1)
	{
		if(check())
			ans++;
		return;
	}
	if(s[k]!='?')
		dfs(k+1);
	else
	{
		s[k]='(';
		dfs(k+1);
		s[k]=')';
		dfs(k+1);
		s[k]='*';
		dfs(k+1);
		s[k]='?';
	} 
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s+1;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
