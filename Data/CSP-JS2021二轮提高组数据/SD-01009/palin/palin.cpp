#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1000000],b[1000000];
char ans[1000000];
bool d;
void dfs(int m,int i1,int i2)
{
	if(i1==i2)
		d=false;
	if(d)
	{
		if(m<n)
		{
			bool d1=true,d2=true;
			for(int j=0;j<m;j++)
			{
				if(b[j]==a[i1])
					d1=false;
				if(b[j]==a[i2])
					d2=false;
			}
			if(a[i1]<a[i2])
			{
				if(d1)
				{
					ans[m]='L';
					b[m]=a[i1];
					dfs(m+1,i1+1,i2);
				}
				if(d2)
				{
					ans[m]='R';
					b[m]=a[i2];
					dfs(m+1,i1,i2-1);
				}
			}
			else
			{
				if(d2)
				{
					ans[m]='R';
					b[m]=a[i2];
					dfs(m+1,i1,i2-1);
				}
				if(d1)
				{
					ans[m]='L';
					b[m]=a[i1];
					dfs(m+1,i1+1,i2);
				}
			}
		}
		else
		{
			if(b[n*2-1-m]==a[i1])
			{
				ans[m]='L';
				b[m]=a[i1];
				dfs(m+1,i1+1,i2);
			}
			else if(b[n*2-1-m]==a[i2])
			{
				ans[m]='R';
				b[m]=a[i2];
				dfs(m+1,i1,i2-1);
			}
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		d=true;
		for(int j=0;j<n*2;j++)
			cin>>a[j];
		dfs(0,0,n*2-1);
		if(d)
			cout<<-1<<"\n";
		else
		{
			for(int j=0;j<n*2;j++)
				cout<<ans[j];
			cout<<"\n";
		}
	}
	return 0;
}
