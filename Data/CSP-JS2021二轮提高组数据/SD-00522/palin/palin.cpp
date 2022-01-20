#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
const int N=2e4+1;
int m,n;
bool flag;
int a[N];
int b[N];
int minn[N];
string mins;
bool check(int head,int tail)
{
	for(int i=1;i<=n/2;i++)
	{
		if(head>=tail)
		{
			break;
		}
		if(b[head]!=b[tail])
		{
			return false;
		}
		head++;
		tail--;
	}
	return true;
}
bool getmin()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]<minn[i])
		{
			return true;
		}
		else
		{
			if(b[i]==minn[i])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}
void dfs(int head,int tail,string s,int pos)
{
	if(head>=tail)
	{
		if(check(1,n))
		{
			if(getmin())
			{
				mins=s;
			}
		}
		return;
	}
	if(a[head]>a[tail])
	{
		b[pos]=a[tail];
		dfs(head,tail-1,s+'R',pos+1);
		b[pos]=a[head];
		dfs(head+1,tail,s+'L',pos+1);
	}
	else
	{
		b[pos]=a[head];
		dfs(head+1,tail,s+'L',pos+1);
		b[pos]=a[tail];
		dfs(head,tail-1,s+'R',pos+1);
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>n;
		n*=2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1,n,"\0",1);
		if(!flag)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<mins;
		}
		flag=0;
		memset(a,0,sizeof(a));
		memset(minn,1e9,sizeof(minn));
		memset(b,0,sizeof(b));
	}
	return 0;
}
/*
2 5 4 1 2 4 5 3 1 2 3 5 3 3 2 1 2 1 3

*/
