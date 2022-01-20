#include<iostream>
#include<cstdio>
using namespace std;
int n,k,ans=0;
const int mod=1e9+7;
char s[510],c[510];
inline int read()
{
	int w=0,r=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		r=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		w=(w<<1)+(w<<3)+ch-48;
		ch=getchar();
	}
	return w*r;
}
int find()
{
	int ttop=0,k=0;
	while(k<=n)
	{
		k++;
		if(s[k]==')')
		{
			while(1)
			{
				if(c[ttop]=='(')
				{
					ttop--;
					break;
				}
				else
				ttop--;
				if(ttop<=0)
				return 0;
			}
			if(c[ttop]=='*'&&s[k+1]=='*')
			{
				while(1)
				{
					k++;
					if(s[k]==')')
					return 0;
					if(s[k]=='(')
					break;
					if(k>n)
					return 0;
				}
				k=k-1;
			}
			else
			{
				if(s[k+1]=='*')
				{
					int k1=k;
					while(1)
					{
						k1++;
						if(s[k1]==')')
						break;
						if(s[k1]=='(')
						{
							k=k1-1;
							break;
						}
						if(k1>n)
						return 0;
					}
				}
			}
		}
		else
		{
			if(s[k]=='(')
			c[++ttop]=s[k];
			if(s[k]=='*')
			c[++ttop]=s[k];
		}
	}
	if(ttop!=0)
	return 0;
	else
	return 1;
}
void dfs(int i,int x,int p1,int p2,int p3)
{
	if(p3==0)
	{
		if(p1!=p2)
		return ;
		if(find()==1)
		ans=(ans+1)%mod;
		return ; 
	}
	for(int j=i;j<=n;j++)
	{
		int flag=0;
		if(s[j]=='?')
		{
			if(x<k&&min(p1,p2)+p3-1>=max(p1,p2))
			{
				s[j]='*';
				dfs(j+1,x+1,p1,p2,p3-1);
				s[j]='?';
				flag=1;
			}
			if(p1+p3>=p2&&p1+1<=p2+p3-1)
			{
				s[j]='(';
				dfs(j+1,0,p1+1,p2,p3-1);
				s[j]='?';
				flag=1;
			}
			if(p2+p3>=p1&&p2+1<=p1+p3-1)
			{
				s[j]=')';
				dfs(j+1,0,p1,p2+1,p3-1);
				s[j]='?';
				flag=1;
			}
			if(flag==0)
			return ;
		}
		else
		{
			if(s[j]=='*')
			{
				x++;
				if(x>k)
				return ;
			}
			else
			x=0;
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	k=read();
	int p1=0,p2=0,p3=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&s[i]);
		if(s[i]=='(')
		p1++;
		if(s[i]==')')
		p2++;
		if(s[i]=='?')
		p3++; 
	}
	if(s[n]=='?')
	{
		s[n]=')';
		p3--;
		p2++;
	}
	if(s[1]=='?')
	{
		s[1]='(';
		p3--;
		p1++;
	}
	if(s[n]=='('||s[n]=='*'||s[1]==')'||s[1]=='*')
	{
		printf("0");
		return 0;
	}
	dfs(1,0,p1,p2,p3);
	printf("%d",ans%mod);
	return 0;
}
