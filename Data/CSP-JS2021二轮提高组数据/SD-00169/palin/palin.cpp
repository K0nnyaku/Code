#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[10005],b[10005],cnt,ans,flag;
char ch[10005];
void init()
{
	memset(b,0,sizeof(b));
	cnt=0;
	flag=0;
	ans=0;
}
void dfs(int x,int l,int r)
{
	if(flag)
	return;
	if(l<0||r<0)
	return;
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
		cout<<ch[i];
		printf("\n");
		flag=1;
		return;
	}
	if(x<=n/2)
	{
		b[x]=a[l];
		ch[x]='L';
		dfs(x+1,l+1,r);
		b[x]=a[r];
		ch[x]='R';
		dfs(x+1,l,r-1);
		return;
	}
	else
	{
		cnt=x;
		b[cnt]=a[l];
		if(b[n-cnt+1]!=b[cnt]&&b[n-cnt+1]>0)
		{
			b[cnt]=a[r];
			if(b[n-cnt+1]!=b[cnt]&&b[n-cnt+1]>0)
			return;
			ch[x]='R';
			dfs(x+1,l,r-1);
			return;
		}
		else
		{
			ch[x]='L';
			dfs(x+1,l+1,r);
			int pos=b[cnt];
			b[cnt]=a[r];
			if(b[n-cnt+1]!=b[cnt]&&b[n-cnt+1]>0)
			{
				b[cnt]=pos;
				return;
			}
			ch[x]='R';
			dfs(x+1,l,r-1);
			return;
		}
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d",&n);
		n*=2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1,1,n);
		if(flag==0)
		printf("-1\n");
	}
	return 0;
}
