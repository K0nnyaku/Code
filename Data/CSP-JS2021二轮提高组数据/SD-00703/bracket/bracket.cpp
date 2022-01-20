#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s;
int n,k,ans,mod=1e9+7;
void searches(int num)
{
	if(num<s.length()-1)
	{
		if(s[num]!='?')
		{
			searches(num+1);
		}
		else
		{
			s[num]='(';
			searches(num+1);
			s[num]=')';
			searches(num+1);
			s[num]='*';
			searches(num+1);
		}
	}
	else
	{
		int n1=0,n2=0,n3=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='*')n1++;
			if(s[i]=='(')n2++;
			if(s[i]==')')n3++;
		}
		if(n1<=k&&n2==n3)
		{
			ans++;ans%=mod;
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	searches(0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
