#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<unordered_map>
using namespace std;
#define int long long
#define pir pair<int,int>
#define fs first
#define sd second 
const int mod=1e9+7,MAXN=505;
int n,k,ans,cntw;
string s;
unordered_map<string,int>mp;
int checkkuo(string s)
{
	int tail=0,st[MAXN];
	memset(st,0,sizeof(st));
	for(int i=0;i<n;i++)
	{
		if(s[i]==')')
		{
			if(!tail)return false;
			else
			{
				int hd=st[tail--],cnt=0;
				for(int j=hd;j<=i;j++)if(s[j]=='*')cnt++;
				if(cnt>k)return false;
				
			}
		}
		else if(s[i]=='(')st[++tail]=i;
	}
	int cnt=0;
	if(tail)return false;
}
void dfs(int now)
{
	if(now>=cntw&&!mp[s])
	{
		int tail=0,st[MAXN];
		memset(st,0,sizeof(st));
		for(int i=0;i<n;i++)
		{
			if(s[i]==')')
			{
				if(!tail)return;
				else
				{
					int hd=st[tail--],cnt=0;
					for(int j=hd;j<=i;j++)if(s[j]=='*')cnt++;
					if(cnt>k)return;
				}
			}
			else if(s[i]=='(')st[++tail]=i;
		}
		int cnts=0;
		if(tail)return;
		for(int i=0;i<n;i++)
		{
			int ye1=0,ye2=0,flag=0;
			if(s[i]=='*')
			{
				for(int j=0;j<=i-1;j++)if(s[j]=='(')
				{
					ye1=1;break;
				}
				for(int j=i+1;j<n;j++)if(s[j]==')')
				{
					ye2=1;break;
				}
				if(ye1&&ye2)
					flag=1;
				if(!flag)return;
			}
		}
		mp[s]=1;
		//cout<<s<<endl;
		ans++;
		ans%=mod;
		return;
	}
	for(int i=0;i<n;i++)
	if(s[i]=='?')
	{
		s[i]='(';
		dfs(now+1);
		s[i]=')';
		dfs(now+1);
		s[i]='*';
		dfs(now+1);
		s[i]='?';
	}
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	getchar();
	getline(cin,s);
	for(int i=0;i<n;i++)if(s[i]=='?')cntw++;
	dfs(0);
	cout<<ans;
	return 0;
}
