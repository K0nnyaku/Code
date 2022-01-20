#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int t,n,a[1000005],f[1000005],ans[1000005];
struct node
{
	int c1,c2,vis,cnt;
}e[500005];
void dfs(int now,int ct)
{
	if(ct==n)
	{
		if(ans[1]==0)
		{
			for(int i=1;i<=ct*2;i++)
			{
				ans[i]=f[i];
			}
		}
		else
		{
			int p=0;
			for(int i=1;i<=ct;i++)
			{
				if(ans[i]<f[i])
				{
					p=0;
					break;
				}
				if(ans[i]>f[i])
				{
					p=1;
					break;
				}
			}
			if(p==1)
			{
				for(int i=1;i<=ct*2;i++)
				{
					ans[i]=f[i];
				}			
			}
		}
		return ;
	}
	
	int l=e[now].c1,r=e[now].c2,ll=0,x[5];
	if(l!=1&&e[a[l-1]].vis==0&&e[a[l-1]].cnt<2)
	{
		e[a[l-1]].cnt++;
	}
	if(l!=r-1&&e[a[l+1]].vis==0&&e[a[l+1]].cnt<2)
	{
		e[a[l+1]].cnt++;		
	}
	if(r!=n&&e[a[r+1]].vis==0&&e[a[r+1]].cnt<2)
	{
		e[a[r+1]].cnt++;		
	}
	if(r!=l+2&&r!=l+1&&e[a[r-1]].vis==0&&e[a[r-1]].cnt<2)
	{
		e[a[r-1]].cnt++;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(e[i].vis==0&&e[i].cnt==2)
		{
			f[ct+1]=i;
			f[2*n-ct]=i;
			e[i].vis=1;
			dfs(i,ct+1);
			e[i].vis=0;
		}
	}	
	return ;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);

	int l;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		
		for(int j=1;j<=n*2;j++)
		{
			scanf("%d",&a[j]);
			if(e[a[j]].c1==0)
				e[a[j]].c1=j;
			else
				e[a[j]].c2=j;
		}
		
		f[1]=a[1];
		f[2*n]=a[1];
		e[a[n]].cnt++;
		e[a[1]].vis=1;
		dfs(a[1],1);
		
		for(int j=1;j<=n;j++)
		{
			e[j].cnt=0;
			e[j].vis=0;
		}
		f[1]=a[n];
		f[2*n]=a[n];
		e[a[1]].cnt++;
		e[n].vis=1;
		dfs(a[n],1);
		
		for(int j=1;j<=n;j++)
		{
			e[j].cnt=0;
			e[j].vis=0;
		}
		if(ans[1]==0)
		{
			printf("-1\n");
			continue;
		}
		
		l=1;
		for(int j=1;j<=n*2;j++)
		{
			if(ans[j]==a[l])
			{
				l++;
				printf("L");
			}
			else
				printf("R");
			ans[j]=0;
		}
		printf("\n");
	}
	return 0;
}
