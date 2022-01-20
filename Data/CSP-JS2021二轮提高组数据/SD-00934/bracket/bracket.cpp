//感觉有点先拦截导弹 
#include <bits/stdc++.h>
using namespace std;
const int B=600;
int n,k; 
char s[B];
int st[B];
int top;
char a[B];
int b[B];
int cnt;
int ans;
void dfs(int now)
{
	if (now==n)
	{
		if (top!=0) return;
		set<int>se;
		se.insert(0);
		se.insert(0x3f3f3f3f);
		if (a[1]=='*') return;
		if (a[n]=='*') return;
		int last=1;
		for (int i=2;i<=n;i++)
		{
			if (a[i]!='*')
			{
				if (i-last-1>k) return;
				if (a[i]=='(' && a[last]==')') continue;
				if (a[i]==')' && a[last]==')')
				{
					int res=b[last];
					set<int>::iterator it=se.lower_bound(last);
					it--;
					if (res-1!=*it)
					{
						return;
					}
				} 
				last=i;
			}
			else 
			{
				se.insert(i);
			}
		}
		ans++;
	}
	if (s[now+1]!='?')
	{
		int ok=0;
		int res=st[top];
		if (s[now+1]=='(') st[++top]=now+1;
		if (s[now+1]==')' && top!=0) b[now+1]=st[top],top--,ok=1;
		a[now+1]=s[now+1];
		dfs(now+1);
		if (s[now+1]=='(') top--;
		if (s[now+1]==')' && ok==1) st[++top]=res,b[now+1]=0;
	}
	else 
	{
		int res=st[top];
		st[++top]=now+1;
		a[now+1]='(';
		dfs(now+1);
		top--;
		b[now+1]=st[top],top--;
		if (top!=0)
		{
			a[now+1]=')';
			b[now+1]=st[top];top--;
			dfs(now+1);
			st[++top]=res;
		}
		a[now+1]='*';
		dfs(now+1);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s+1;
	dfs(0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3  
(*??*??

*/ 
