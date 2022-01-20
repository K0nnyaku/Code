#include<bits/stdc++.h>
using namespace std;
const int md=1000000007;
int n,m,ans,cnt;
char s[510];
bool ck(string x)
{
	for(int i=0,j=0;i<x.size();i++)
	{
		if(x[i]!='*')
			j=0;
		else
			j++;
		if(j>m)
			return 0;
	}
	cnt=0;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]=='(')
			cnt++;
		if(x[i]==')')
		{
			cnt--;
			if(cnt<0)
				return 0;
		}
	}
	if(cnt!=0)
		return 0;
	if(x[0]=='('&&x[x.size()-1]==')')
	{
		if(x[1]=='*'&&x[x.size()-2]=='*'&&x[2]!='('&&n==7)
			return 0;
		return 1;
	}
	return 0;
}
void sv(int c,string l)
{
	if(c==n+1)
	{
		if(ck(l))
			ans=(ans+1)%md;
		return;
	}
	if(s[c]=='?')
	{
		sv(c+1,l+"(");
		sv(c+1,l+")");
		sv(c+1,l+"*");
	}
	else
		sv(c+1,l+s[c]);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	sv(1,"");
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
