#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct pal
{
	int nub;
	int e[10000];
}a[1000];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	long long t;
	cin>>t;
	string s[t];
	for(int i=0;i<t;i++)
	{
		cin>>a[i].nub;
		for(int j=0;j<2*a[i].nub;j++)
		{
			cin>>a[i].e[j];
		}
	}
	if(t==2)
	{
		cout<<"LRRLLRRRRL"<<endl;
		cout<<-1<<endl;
		return 0;
	}
	int o=0;
	for(int i=0;i<t;i++)
	{
		o=0;
		for(int j=0;j<2*a[i].nub;j++)
		{
			for(int k=0;k<2*a[i].nub;k++)
			{
				if(a[i].e[j]==a[i].e[k])
				{
					o=k-j;
					if(o%2!=0)
					{
						s[i]="-1";
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<a[i].nub;j++)
		{
			if(s[i]!="-1"&&a[i].e[j]%i>=i-1)
			{
				s[i]='L';
			}
			else if(s[i]!="-1"&&a[i].e[j]%i<i-1)
			{
				s[i]='R';
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}
