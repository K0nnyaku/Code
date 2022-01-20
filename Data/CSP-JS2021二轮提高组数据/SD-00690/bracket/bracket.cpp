#include<iostream>
#include<cstdio>
#include<string> 
#include<map>
using namespace std;
const int mod=1000000007;
int ans,n,m;
string s;
map<string,bool> mp;
void init(string str)
{
	if(mp.count(str))
		return;
	if((int)str.length()>n)
		return;
	mp[str]=1;
	init("("+str+")");
	for(auto i:mp)
	{
		init(str+i.first);
		init(i.first+str);
	}
	string tmp;
	for(int i=1;i<=m;++i)
	{
		tmp+="*";
		init("("+tmp+str+")");
		init("("+str+tmp+")");
		for(auto i:mp)
		{
			init(str+tmp+i.first);
			init(i.first+tmp+str);
		}
	}
}
void dfs(int k,string res)
{
	if(k==n)
	{
		if(mp.count(res))
		{
			++ans;
			if(ans>=mod)
				ans-=mod;
		}
		return;
	}
	if(s[k]!='?')
	{
		dfs(k+1,res+s[k]);
		return;
	}
	dfs(k+1,res+"(");
	dfs(k+1,res+")");
	dfs(k+1,res+"*");
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>m>>s;
	init("()");
	string tmp;
	for(int i=1;i<=m;++i)
	{
		tmp+="*";
		init("("+tmp+")");
	}
	dfs(0,string());
	cout<<ans<<endl;
	return 0;
}
