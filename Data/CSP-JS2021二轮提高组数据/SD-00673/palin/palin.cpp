#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<utility>
#include<cmath>
#define N 100050
using namespace std;
int n,t,a[N],b[N];
bool c[N];
int flag;
int l,r;
void dfs(int num,char st)
{
	if(num>=2*n+1)
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=b[2*n+1-i])
			return ;
		}
		flag=1;
		for(int i=1;i<=n*2;i++)
		{
			if(c[i])
			printf("L");
			else 
			printf("R");
		}
		return ;
	}
		b[num]=a[l];
		l++;
		c[num]=1;
		dfs(num+1,'L');
		l--;
		c[num]=0;
		if(!flag)
		{
			b[num]=a[r];
			r--;
			c[num]=0;
			dfs(num+1,'R');
			r++;
		}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	if(t==1)
	{
		cout<<"-1";
		return 0;
	}
	for(int j=1;j<=t;j++)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		l=1;
		r=2*n;
		dfs(1,'L');
		if(!flag)
		cout<<"-1";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
