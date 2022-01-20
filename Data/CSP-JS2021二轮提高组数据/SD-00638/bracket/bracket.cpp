#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k,x,ans;
	int gs=0,yfw=0;
	scanf("%d%d",&n,&k);
	string s;
	cin>>s;
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<=n;i++)
	{
		if(s[i]=='*') gs++;
		if(s[i]=='?') yfw++;
	}
	for(int i=1;i<=k-1;i++)
	{
		for(int j=1;j<=(n-i)/2;j++)
		{
			ans+=i*j;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

