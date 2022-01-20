#include<bits/stdc++.h>
using namespace std;
int n,k; 
int a[78],nu,bj;
int aa[78];
int c[78]; 
int book[78];
int num=0;
void dfs(int x)
{
	if(x>n)
	{
		nu=0;
		for(int i=1;i<x;i++)
		{
			c[++nu]=aa[i];
		}		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			aa[x]=a[i];
			dfs(x+1);
			book[i]=0;
		}
	}
}
int main()
{
	freopen("num.in","w",stdin);
	freopen("num.out","r",stdout);
	cin>>n>>k;
	bj=n/k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<0;
	return 0;
}
