#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
const int mod=1e9+7;
bool check(string s)
{
	int cnt=0;
	queue<char> q;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')	q.push(s[i]);
		if(s[i]=='*')	cnt++;
		if(cnt>k)	return 0;
		if(s[i]=='(')	cnt=0;	
		if(s[i]==')')	q.pop();
	}
	if(!q.empty())	return 0;
	return 1;
}
int ans=0;
char sign[4]={'*','(',')'};
void dfs(int x)
{
	for(int i=1;i<=n;i++)
//	cout<<s[i];
	if(x==n&&check(s))	ans++;
	if(x=='?')
	{
		for(int i=0;i<3;i++)
		{
			//cout<<"..."<<endl;
			s[x]=sign[i];dfs(x+1);s[x]='?';
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	char s[5005];
	for(int i=1;i<=n;i++)
	cin>>s[i];
	int cnt;
	//int len=strlen(s);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?')	cnt++;
	}
	if(cnt==n)	//s´®ÖÐÖ»ÓÐ? 
	{
		cout<<pow(2,n)<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?')
		dfs(i);
	}
	cout<<ans%mod;
	return 0;
}
