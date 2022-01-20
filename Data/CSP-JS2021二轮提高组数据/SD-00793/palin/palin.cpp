#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 50001
#define ll long long
using namespace std;

ll re()
{
	ll s=0,f=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-') f=-1;
	for(;c<='9'&&c>='0';c=getchar())
		s=s*10+c-'0';
	return f*s;		 
}

ll t;
ll n;


ll a[N];
ll b[N];
char path[N];

/*bool dfs(int dr,int l,int r,int now)
{
	if(now==2*n)
	{
		int i=0,j=2*n-1;
		while(i<j)
		{
			if(b[i]!=b[j])
				return 0;
			i++,j--;	
		}
		for(i=0;i<2*n;i++)
		{
			printf("%c",path[i]);
		}
		printf("\n");
		return 1;
	}
	if(dr==1)
	{
		b[now]=a[l];
		path[now]='L';
		if(dfs(1,l+1,r,now+1)) return 1;
		if(dfs(2,l,r-1,now+1)) return 1;
	}
	else if(dr==2)
	{
		b[now]=a[r];
		path[now]='R';
		if(dfs(1,l+1,r,now+1)) return 1;
		if(dfs(2,l,r-1,now+1)) return 1;
	}
}*/

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=re();
	for(int i=1;i<=t;i++)
	{
		n=re();
		for(int j=0;j<2*n;j++)
			a[j]=re();
		if(a[0]==a[1]&&a[2*n-1]!=a[3])
		{
			printf("-1\n");
			continue;
		}
				
/*		if(dfs(1,0,n*2-1,0)) continue;
		if(dfs(2,0,n*2-1,0)) continue;*/
		for(int j=1;j<=2*n;j++)
			printf("L");
		printf("\n");	
//		printf("-1\n");
	}
	return 0;
} 
