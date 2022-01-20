#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int n,a[500005],b[500005],ans[500005],t,s[500005];
int dfs(int y,int l,int r)
{
	if(l==r)
	{
		b[y]=a[l];
		ans[y]=1;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=b[2*n-i+1])
			{
				b[y]=0;
				ans[y]=0;
				return 0;
			}
		}
		b[y]=0;
		return 1;
	}
//	if(a[l]<=a[r])
//	{
		b[y]=a[l];
		ans[y]=1;
		if(dfs(y+1,l+1,r))
		return 1;
		b[y]=0;
		ans[y]=0;
		
		b[y]=a[r];
		ans[y]=2;
		if(dfs(y+1,l,r-1))
		return 1;
		b[y]=0;
		ans[y]=0;
//	}
//	else
//	{
//		b[y]=a[r];
//		ans[y]=2;
//		if(dfs(y+1,l,r-1))
//		return 1;
//		b[y]=0;
//		ans[y]=0;
//		
//		b[y]=a[l];
//		ans[y]=1;
//		if(dfs(y+1,l+1,r))
//		return 1;
//		b[y]=0;
//		ans[y]=0;
//	}
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int tot=0,sum=0;
		memset(s,0,sizeof(s));
		memset(ans,0,sizeof(ans));
		cin>>n;
		for(int i=1;i<=n*2;i++)
		{
			cin>>a[i];
			if(a[i]==a[i-1])
			{
				sum++;
			}
			if(a[i]==s[tot])
			{
				tot--;
			}
			else
			s[++tot]=a[i];
		}
		if(tot==0&&sum>=2&&n>2)
		{
			cout<<-1<<endl;
			continue;
		}
		else if(tot==0&&sum<2)
		{
			for(int i=1;i<=n*2;i++)
			{
				cout<<"L";
			}
			cout<<endl;
			continue;
		}
		if(dfs(1,1,n*2))
		{
			for(int i=1;i<=2*n;i++)
			{
				if(ans[i]==1)
				cout<<"L";
				else
				cout<<"R";
			}
			cout<<endl;
		}
		else
		cout<<-1<<endl;
	}
	return 0;
}
