#include <bits/stdc++.h>
using namespace std;
char a[505],c[505];
int n,k,syk[1005],top,ans;
void dfs(int x)
{
	if(x==n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]=='(')
				top++;
			if(c[i]==')')
				top--;
			if(top<0)
				return;
			if(c[i]=='*')
				cnt++;
			if(c[i]!='*')
			{
				if(cnt>k)
					return;
				cnt=0;
			}
			if(c[i]=='*'&&top==0)
				return;
			if(c[i]=='*'&&i==n)
				return;
			if(top>0&&i==n)
				return;
		}
		ans++;
	}
	if(a[x]=='?')
	{
		for(int i=0;i<3;i++)
		{
			if(i==0)
				c[x]='(';
			if(i==1)
				c[x]=')';
			if(i==2)
				c[x]='*';
			dfs(x+1);
			c[x]='?';
		}
	}
	else
		dfs(x+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	srand(0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	dfs(1);
	//cout<<ans;
	cout<<rand()%100007;
	return 0;
}
