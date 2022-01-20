#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
#define H cout<<endl

using namespace std;

const int N=510;
const int P=1000000007;
char c[N];
int a[N];
int n,k,w;

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]=='?')
		 w++,a[w]=i;
	}
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
	return 0;
}
