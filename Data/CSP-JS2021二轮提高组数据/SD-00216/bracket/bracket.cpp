#include<bits/stdc++.h>
using namespace std;
string s;int n,k;
int sit[505];int sitn=0;
int y=0;bool flag;long long sum=0;
char r[5]={'(',')','*'};
void check(int x,int num,string s2)
{
	if(flag==0) return;
	if(x>=n) 
	{
		if(y!=0) flag=0;
		//cout<<114514;
		//cout<<x<<" "<<num<<endl;
		return;
	}
	if(s2[x]=='*') 
	{
		num++;
	}
	if(num>k)
	{
		flag=0;
		return;
	}
	if(s2[x]==')')
	{
		return;
	}
	if(s2[x]=='(')
	{
		check(x+1,0,s2);
	}
	check(x+1,num,s2);
}
void dfs(int x,string s1,int t)
{
	if(x==sitn)
	{
		//cout<<s1<<" ";
		if(s1[0]!='('||s1[n-1]!=')')
		{
			return;
		}
		flag=1;
		y=0;
		for(int i=0;i<=n;i++)
		{
			if(s1[i]=='(') y++;
			if(s1[i]==')') y--;
		}
		//cout<<s1<<" "<<y<<endl;
		if(y)	return;
		check(0,0,s1);
		if(flag)
		{
			//cout<<":"<<s1<<":"<<endl;
			sum++;
			sum=sum%1000000007;
			return; 
		}
	}
	for(int i=t;i<n;i++)
	{
		if(s1[i]=='?')
		{
			for(int j=0;j<3;j++)
			{
				string s2=s1;
				s2[i]=r[j];
				//cout<<s2<<" ";
				dfs(x+1,s2,i+1);
			}
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='?')
		{
			sitn++;
			sit[sitn]=i;
		}
	}
	dfs(0,s,0);
	cout<<sum; 
	return 0;
}
/*
7 3
(*??*??
*/
