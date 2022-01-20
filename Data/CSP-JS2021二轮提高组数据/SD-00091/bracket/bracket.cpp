#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long ll;
int n,k,l,st[16],top=0;
ll ans=0;
string se;
const ll mod=1000000007;
void dfs(int now)
{
	if(now==l)
	{
		int ok=1;
		for(int i=0;i<l;i++)
		{
			if(se[i]=='(')
			{
				st[++top]=i;
			}
			else if(se[i]==')')
			{
				int sl=0,bj=0;
				for(int j=i;j>=st[top];j--)
				{
					if(se[j]=='*'&&!bj) sl++;
					if(se[j]==')') bj=1;
					if(se[j]=='(') bj=0;
				}
				if(sl>k)
				{
					ok=0;break;
				}
				top--;
			}
		}
		if(top) ok=0;
		ans+=ok;
		return;
	}
	if(se[now]!='?') dfs(now+1);
	else
	{
		se[now]='(';dfs(now+1);
		se[now]=')';dfs(now+1);
		se[now]='*';dfs(now+1);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>se;
	l=se.size();
	dfs(0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
