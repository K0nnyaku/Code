#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int n,m,ans;
int stc[510];
char s[510];
bool check()
{
	int num=0,top=0;
	if(s[1]==')'||s[1]=='*') return 0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='*') num++;
		else num=0;
		if(num>m) return 0;
	}
	if(num) return 0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(') stc[++top]=i;
		if(s[i]==')')
		{
			if(top)
			{
				int pos=stc[top];
				top--;
				bool flag=0;
				for(int x=pos+1;x<=i-1;x++) if(s[x]!='*') flag=1;
				if(flag&&s[pos+1]=='*'&&s[i-1]=='*') return 0; 
			}
			else return 0;
		}
	}
	if(top) return 0;
	return 1;
}
void lbw(int i)
{
	if(i==n+1)
	{
		if(check()) ans++;
		return;
	}
	if(s[i]=='?')
	{
		s[i]='(';
		lbw(i+1);
		s[i]=')';
		lbw(i+1);
		s[i]='*';
		lbw(i+1);
		s[i]='?';
	}
	else lbw(i+1);
} 
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	if(s[1]==')'||s[1]=='*')
	{
		printf("0\n");
		return 0;
	}
	lbw(1);
	printf("%d\n",ans);
	return 0;
}
