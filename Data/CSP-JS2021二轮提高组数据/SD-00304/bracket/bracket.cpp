#include<bits/stdc++.h>
#include<stack>
using namespace std;
string s;int n,k;bool fil[501];
char fi[3]={'(',')','*'};
int ans=0;
bool brac();
bool checkK()
{
	bool ifu[501];
	memset(ifu,false,sizeof(ifu));
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='(') 
		{
			for(int j=i;j<n;j++) 
			{
				if(s[j]==')'&&!ifu[j]) 
				{
					ifu[j]=1;
					if((j-i-1)>k) return false;
				}
			}
		}
	}
	
	return true;
}
bool check()
{
	string s1=s;
	if(!brac()) return false;
	if(!checkK()) return false;
	if(s1[0]=='*'||s1[n-1]=='*')return false;
	for(int i=n-1;i>=0;i--)
	{
		if(s1[i]=='(') 
		{
			for(int j=i;j<n;j++) 
			{
				if(s1[j]==')') 
				{
					s1[i]='*',s1[j]='*';
					if(s1[i-1]=='*'&&s1[j+1]=='*') return false;
				}
			}
		}
	}
	return true;
}
bool brac()
{
	stack<char> lef;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(') lef.push('(');
		if(s[i]==')')
		{
			if(lef.empty()) return false;
			lef.pop();
		}
	 } 
	 if(!lef.empty())return false;
	 return true;
} 
void dfs(int bt)
{
	if(bt==n)
	{ 
		if(check()){ ans++;}
		return;
	}
	if(fil[bt])
	{
		for(int i=0;i<3;i++){
			s[bt]=fi[i];
			dfs(bt+1);
		}
	 } 
	 else dfs(bt+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='?') fil[i]=true;
	}
	//s="(*****)";
	//if(check()) cout<<"ok";
	dfs(0);
	cout<<ans;
}
