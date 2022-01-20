#include<iostream>
#include<cstdio>
using namespace std;
string s,ans1;
int b[100000],f=0,ans[1000000],n,a[1000009];
void check()
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(b[i]!=b[n-i+1])
		{
			return ;
		} 
	}
	if(f==0)
	{
		for(i=1;i<=2*n;i++)
		{
			ans[i]=b[i];
		}
		ans1=s;
	}
	else
	{
		for(i=1;i<=2*n;i++)
		{
			if(ans[i]<b[i])
			{
				return ;
			}
		}
		for(i=1;i<=2*n;i++)
		{
			ans[i]=b[i];
		}
		ans1=s;
	} 
	f=1;
	return ;
} 
void dfs(int t,int l,int r)
{
	if(t>2*n)
	{
		int i;
		check();
		return ;
	}
	string s1=s;
	s+='L';
	b[t]=a[l];
	dfs(t+1,l+1,r);
	s=s1;
	s+='R';
	b[t]=a[r];
	dfs(t+1,l,r-1);
	return ;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		f=0;
		ans1="";
		dfs(1,1,2*n);
		if(f==0)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<ans1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
