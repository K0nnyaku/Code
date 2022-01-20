#include<bits/stdc++.h>
const int N = 500005;
using namespace std;
int Tt;
int n;
int a[N*2],actt[N*2],b[N*2];
int book[N];
int flag;
int maxdep=0;

void dfs(int l,int r,int dep)
{
	maxdep=max(maxdep,dep);
	if(dep==n*2+1)
	{
		int ll=1,rr=2*n;
		for(int i=1;i<=2*n;i++)
		{
			if(b[i]==a[ll])
			{
				actt[i]=1;
				ll++;
			}
			else if(b[i]==a[rr])
			{
				actt[i]=0;
				rr--;
			}
		}
//		if(Tt==60)
//		{
//			for(int i=1;i<=n;i++)
//			{
//				printf("%d ",b[i]);
//			}
//			printf("\n");
//			for(int i=2*n;i>n;i--)
//			{
//				printf("%d ",b[i]);
//			}
//			printf("\n");
//		}
		for(int i=1;i<=n*2;i++)
		{
			printf("%c",actt[i]? 'L':'R');
		}
		printf("\n");
		//!!!!!!!
		//linux换行符？
		//az
		//无了 
		flag=1;
		return;
	}
	if(dep==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			if(!book[i])
			{
				return;	
			} 
		}
	}
	if(dep>n)
	{
//		if(Tt==60&&b[9]==8)
//		{
//			printf("%d: %d\n",dep,b[2*n-dep+1]);
//		}
		if(b[2*n-dep+1]==a[l])
		{
			b[dep]=a[l];
			dfs(l+1,r,dep+1);
			if(flag) return;
			b[dep]=0;	
		}
		else if(b[2*n-dep+1]==a[r])
		{
			b[dep]=a[r];
			dfs(l,r-1,dep+1);
			if(flag) return;
			b[dep]=0;
			
		}	
		return;
	}
	else
	{
//		if(Tt==60&&l==9&&r==39)
//		{
//			for(int i=1;i<=dep;i++)
//			{
//				printf("%d ",b[i]);
//			}
//			printf("?%d %d\n",a[l],a[r]);
//		}
		if(book[a[l]]||book[a[r]])
		{
			if(!book[a[l]])
			{
				book[a[l]]=1;
				b[dep]=a[l];
				dfs(l+1,r,dep+1);
				if(flag) return;
				b[dep]=0;
				book[a[l]]=0;
			}
			if(!book[a[r]])
			{
				book[a[r]]=1;
				b[dep]=a[r];
				dfs(l,r-1,dep+1);
				if(flag) return;
				b[dep]=0;
				book[a[r]]=0;
			}
		}
		else
		{
//			if(Tt==60&&b[9]==8)
//			{
//				printf("%d: %d\n",dep,b[2*n-dep+1]);
//			}
				book[a[l]]=1;
				b[dep]=a[l];
				dfs(l+1,r,dep+1);
				if(flag) return;
				b[dep]=0;
				book[a[l]]=0;
				
				
				book[a[r]]=1;
				b[dep]=a[r];
				dfs(l,r-1,dep+1);
				if(flag) return;
				b[dep]=0;
				book[a[r]]=0;

		}
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&Tt);
	while(Tt--)
	{
		flag=0;
		memset(a,0,sizeof(a));
		memset(actt,-1,sizeof(actt));
		memset(b,0,sizeof(b));
		memset(book,0,sizeof(book));
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1,n*2,1);
		if(!flag)
		{
		//	printf("%d\n",maxdep);
			printf("-1\n");
		}
	}
	return 0;
}
//大样例挂了
//死了
 
//gg
//afoed
