#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
const int MOD=1000000007;
int n,k;
string a;
int len=0;
int micnt[1056];
/*
need to write a find() of duiyingkuohao
*/
int fibra(int x)
{
	int sta=0;
	sta++;
	for(int i=x+1;i<=len;i++)
	{
		if(a[i]=='(') sta++;
		if(a[i]==')') sta--;
		if(sta==0) return i;
	}
	return 0x3f3f3f3f;
}
int dfs(int x)
{
//	cout<<x<<" "<<a<<" "<<endl;
	//check (  )
	int ans=0;
	int maxi=-1;
	for(int i=0;i<=x;i++)
	{
		if(a[i]==a[i-1]&&a[i]=='*')
		{
			micnt[i]=micnt[i-1]+1;
			maxi=max(maxi,micnt[i]);
			if(maxi>k) return 0;
		}
		else if(a[i]=='*') micnt[i]=1;
		if(a[i]=='*')
		{
			if(i==0||i==len-1) return 0;
		}
	}
	if(x==len-1)
	{
		int sta=0;
		for(int i=0;i<=x;i++)
		{
			if(a[i]=='*') continue;
			if(a[i]=='(') sta++;
			if(a[i]==')') 
			{
				if(sta==0)
				{
					return 0;
				}
				sta--;
			}
		}
		if(sta!=0) return 0;
//		for(int i=0;i<len;i++)
//		{
//			if(a[i]=='*'&&a[i+1]=='(')
//			{
//				int pos=fibra(i+1);
//				if(a[+1]=='*') return 0;
//			}
//		}
	
//		cout<<a<<endl;
		return 1;
	}
	bool flag=0;
	if(a[x+1]=='?')
	{
		a[x+1]='(';
		ans=ans+dfs(x+1);
		ans%=MOD;
		a[x+1]=')';
		ans=ans+dfs(x+1);
		ans%=MOD;
		a[x+1]='*';
		ans=ans+dfs(x+1);
		ans%=MOD;
		a[x+1]='?';
		return ans;
	}
	return dfs(x+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
//	cout<<a.length();
	len=a.length();
	if(a[0]=='?')
	{
		int anns=0;
		a[0]='(';
		anns=anns+dfs(0);
		anns%=MOD;
		a[0]=')';
		anns=anns+dfs(0);
		anns%=MOD;
		a[0]='*';
		anns=anns+dfs(0);
		anns%=MOD;
		a[0]='?';
		cout<<anns;
	}
	else cout<<dfs(0)%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??

10 2
???(*??(?)

*/
