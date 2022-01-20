#include<bits/stdc++.h>
using namespace std;
int n,k;
string arr;
unsigned long long p=0;
int cz;
int ffind()
{
	int yw=0;
	for(;cz<n;cz++)
	{
		if(arr[cz]=='(')
		{
			cz++;
			if(ffind()==1)
			{
				return 1;
			}
		}
		else if(arr[cz]==')')
		{
			return 0;
		}
		else
		{
			if(yw==1)
			{
				return 1;
			}
			yw=1;
			while(arr[cz]=='*')
			{
				cz++;
			}
			cz--;
		}
	}
	return 0;
}
void f(int s,int zkh,int sl)
{
	if(zkh<0)
	{
		return ;
	}
	if(sl>k)
	{
		return ;
	}
	if(arr[0]=='*')
	{
		return ;
	}
	if(s==n)
	{
		cz=0;
		if(zkh==0 && arr[n-1]!='*')
		{
			p++;
			p%=1000000007;
		}
		return ;
	}
	if(arr[s]=='(')
	{
		zkh++;
		sl=0;
		f(s+1,zkh,sl);
		return ;
	}
	else if(arr[s]==')')
	{
		zkh--;
		sl=0;
		f(s+1,zkh,sl);
		return ;
	}
	else if(arr[s]=='*')
	{
		if(s==0 or s==n-1)
		{
			return ;
		}
		else
		{
			sl++;
			f(s+1,zkh,sl);
		}
		return ;
	}
	arr[s]='*';
	f(s+1,zkh,sl+1);
	arr[s]='(';
	f(s+1,zkh+1,0);
	arr[s]=')';
	f(s+1,zkh-1,0);
	arr[s]='?';
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>arr;
	f(0,0,0);
	cout<<p<<endl;
	return 0;
}
