#include<iostream>
#include<cstdio>
#pragma GCC optimize(2)
using namespace std;
int a[1000100];
int b[1000100];
int s[1001000];
int n;
bool dfs(int x,int hh,int tt)
{
	if(x==2*n+1)
	{
		for(int i=1;i<=2*n;i++)
		{
			if(s[i])
				cout<<"R ";
			else
				cout<<"L ";
		}
		cout<<endl;
		return 1;
	}
	if(x>n)
	{
		if(a[hh]!=b[2*n-x+1]&&a[tt]!=b[2*n-x+1])
			return 0;
		if(a[hh]==b[2*n-x+1])
		{
			s[x]=0;
			b[x]=a[hh];
			bool flag=dfs(x+1,hh+1,tt);
			if(flag)	return 1;
		}
		if(a[tt]==b[2*n-x+1])
		{
			s[x]=1;
			b[x]=a[tt];
			bool flag=dfs(x+1,hh,tt-1);
			if(flag)	return 1;
		}
	}
	else 
	{
		s[x]=0;
		b[x]=a[hh];
		bool flag=dfs(x+1,hh+1,tt);
		if(flag)	return 1;
		s[x]=1;
		b[x]=a[tt];
		flag=dfs(x+1,hh,tt-1);
		if(flag)	return 1;
	}
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n*2;i++)
			cin>>a[i];
		bool flag=dfs(1,1,2*n);
		if(!flag)	cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


