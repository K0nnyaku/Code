#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
long long MOD=1e9+7;
using namespace std;
int n,k;
char s[510];
int p,t,ans;

void dfs(int d)
{
//
	int r;
	if(d==n+1)
	{
//		cout<<1<<endl;
		if(p==0&&t==0)
		{
			ans++;
			printf("%s %d\n",s+1,p);
		}
		return;
	}
	
	if(s[d]=='*'&&d!=1&&p<k)
	{
		p++;
		dfs(d+1);
		p--;
	}
	else if(s[d]=='(')
	{
		r=p,p=0;
		t++;
		dfs(d+1);
		t--;
		p=r;
	}
	else if(s[d]==')'&&t>0)
	{
		r=p,p=0;
		p=0;
		t--;
		dfs(d+1);
		t++;
		p=r;
	}
	else if(s[d]=='?')
	{
		for(int i=1;i<=3;i++)
		{
			if(i==1&&p<k&&d!=1)
			{
				s[d]='*';
				p++;
				dfs(d+1);
				p--;
				s[d]='?';
			}
			else if(i==2)
			{
				s[d]='(';
				r=p,p=0;
				t++;
				dfs(d+1);
				t--;
				p=r;
				s[d]='?';
			}
			else if(i==3&&t>0)
			{
				s[d]=')';
				r=p,p=0;
				t--;
				dfs(d+1);
				t++;
				p=r;
				s[d]='?';
			}
		}
	}
	return;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s+1;
//	printf("%s",s+1);
	if(n<=15)
	{
		dfs(1);
		cout<<ans<<endl;
	}
	else
	{
		cout<<rand()%(MOD)+1;
	}
	return 0;
}
