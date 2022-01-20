#include<iostream>
#include<cstdio>
using namespace std;
int a[50010];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n,s,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int f=n;
	while(n>0)
	{
		m=1;
		for(int i=1;i<=f;i++)
			if(a[i]!=-1)
			{
				s=a[i];
				a[i]=-1;
				cout<<i<<' ';
				break;
			}
		for(int i=1;i<=f;i++)
		{
			if(a[i]==1||a[i]==0)
			if(a[i]!=s)
			{
				m++;
				s=a[i];
				cout<<i<<' ';
				a[i]=-1;
			}
		}
		n=n-m;
		cout<<endl;
	}
	return 0;
}
