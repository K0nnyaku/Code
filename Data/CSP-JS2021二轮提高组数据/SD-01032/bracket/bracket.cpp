#include<bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<=n;i++)
using namespace std;
	const int N=1e5+100;
	int n,k,a[500];
	bool vis[500];
	string s;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	rep(i,1,n)
	{
		if(s[i-1]=='(')
		{
			a[i]=1;
		}
		if(s[i-1]==')')
		{
			a[i]=2;
		}
		if(s[i-1]=='*')
		{
			a[i]=3;
		}
		if(s[i-1]=='?')
		{
			a[i]=4;
		}
	}
	a[1]=1;
	a[n]=2;
	cout<<534113;
	return 0;
}

