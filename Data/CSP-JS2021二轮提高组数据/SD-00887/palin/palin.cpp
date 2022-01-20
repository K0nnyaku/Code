#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[1000005],b[500005],nc;
bool c[1000005],v;
void d(int l,int r,int now)
{
	if(now==-1)
	{
		v=true;
		return ;
	}
	if(a[l]==b[now])
	{
		d(l+1,r,now-1);
		if(v)
		{
			c[++nc]=false;
			return ;
		}
	}
	if(a[r]==b[now])
	{
		d(l,r-1,now-1);
		if(v)
			c[++nc]=true;
	}
	return ;
}
void f(int l,int r,int now)
{
	if(now==n)
	{
		d(l,r,now-1);
		return ;
	}
	b[now]=a[l];
	f(l+1,r,now+1);
	if(v)
	{
		c[++nc]=false;
		return ;
	}
	b[now]=a[r];
	f(l,r-1,now+1);
	if(v)
		c[++nc]=true;
	return ;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		v=false;
		nc=0;
		cin>>n;
		for(int j=0;j<n*2;j++)
			cin>>a[j];
		f(0,n*2-1,0);
		if(v)
		{
			for(int j=nc;j>=1;j--)
			{
				if(c[j])
					cout<<'R';
				else
					cout<<'L';
			}
		}
		else
			cout<<-1;
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
