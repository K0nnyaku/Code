#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[16],tot,b[16],dui[20];
char ch[10000],ch1[20];
int dfs(int x)
{
	if(x<=tot)
	{
		int k1;
		ch[a[x]]='(';
		k1=dfs(x+1);
		ch[a[x]]=')';
		k1+=dfs(x+1);
		ch[a[x]]='*';
		k1+=dfs(x+1);
		return k1;
	}
	int k1=0,t=0,top=0;
	for(int i=0;i<n;i++)
	{
		if(ch[i]=='*')
		{
			++k1;
			if(ch[i-1]!='*')
				ch1[++t]='*';
			if(k1>k)
				return 0;
		}
		else
		{
			k1=0;
			if(ch[i]=='(')
				ch1[++t]='(',b[++top]=t;
			else
				if(!top)
					return 0;
				else
					dui[b[top]]=i,--top,ch1[++t]=')';
		}
	}
	if(top!=0||ch1[1]=='*'||ch1[t]=='*')
		return 0;
	for(int i=1;i<=t;i++)
		if(ch1[i]=='(')
			if(dui[i]-i!=2&&ch1[dui[i]-1]=='*'&&ch1[i+1]=='*')
				return 0;
	return 1;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",ch);
	if(n<=15)
	{
		for(int i=0;i<n;i++)
			if(ch[i]=='?')
				a[++tot]=i;
		int w=dfs(1);
		printf("%d",w);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
