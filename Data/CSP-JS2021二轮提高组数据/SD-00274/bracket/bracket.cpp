#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
char s[550];
int st[510][510],top[510];
bool is_string(char a[])
{
	memset(top,0,sizeof(top));
	memset(st,0,sizeof(st));
	int cnt=1;
	for(int l=1;l<=n;l++)
	{
		if(s[l]=='?') return false;
		if(a[l]=='(')
		{
			cnt++;
		}
		if(a[l]=='*')
		{
			int sum=0;
			while(a[l+1]=='*')
			{
				sum++;
				l++;
			}
			if(sum>=k) return false;
			st[cnt][++top[cnt]]=1;
			
		}
		if(a[l]==')')
		{
			if(cnt==1) return false;
			if(top[cnt]==3&&st[cnt][1]==1&&st[cnt][2]==0&&st[cnt][3]==1) return false;
			cnt--;
			st[cnt][++top[cnt]]=0;
			top[cnt+1]=0;
		}
		if(top[cnt]>3&&st[cnt][top[cnt]-2]==0&&
		    st[cnt][top[cnt]-1]==1&&
		    st[cnt][top[cnt]]==0)
		{
			top[cnt]-=2;
		}
		else
		if(top[cnt]>2&&st[cnt][top[cnt]-1]==0&&st[cnt][top[cnt]]==0)
		top[cnt]-=1;
	}
	if(top[cnt]>3&&st[cnt][top[cnt]-2]==0&&
		    st[cnt][top[cnt]-1]==1&&
		    st[cnt][top[cnt]]==0)
		{
			top[cnt]-=2;
		}
		else
		if(top[cnt]>2&&st[cnt][top[cnt]-1]==0&&st[cnt][top[cnt]]==0)
		top[cnt]-=1;
	if(cnt==1)
	{
		if(top[cnt]==1&&st[cnt][1]==0) return true;
		if(top[cnt]==3&&st[cnt][1]==0&&st[cnt][2]==1&&st[cnt][3]==0) return true;
	}
	return false;
}
void dfs(int x)
{
	if(x>n)
	{
		if(is_string(s))
		{
			ans++;
			for(int i=1;i<=n;i++) cout<<s[i];
			cout<<endl; 
		}
		return;
	}
	if(s[x]=='?')
	{
		s[x]='*';
		dfs(x+1);
		s[x]='(';
		dfs(x+1);
		s[x]=')';
		dfs(x+1);
		s[x]='?';
	}
	else dfs(x+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

