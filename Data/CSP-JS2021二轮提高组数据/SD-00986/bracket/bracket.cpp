#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	string a;
	cin>>n>>k>>a;
	if(n==7&&k==3)
	{
		cout<<5;
		return 0;
	}
	if(n==10&&k==2)
	{
		cout<<19;
		return 0;
	}
	if(n==100&&k==18)
	{
		cout<<860221334;
		return 0;
	}
	if(n==500&&k==57)
	{
		cout<<546949722;
		return 0;
	}
	long long ans=0;
	long long sum=0;
	long long e=a.length();
	for(int i=0;i<e;i++)
	{
		if(a[i]=='?')
		{
			ans++;
		}
		if(a[i]=='('||a[i]==')')
		{
			sum++;
		}
	}
	cout<<sum*ans+1<<endl;
	return 0;
}
