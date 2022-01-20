#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e1+1;
int n,m,dp[1<<21],a[N],head,tail,res[N];
int read()
{
	int x=0,f=1;
	char cc=getchar();
	while(!isdigit(cc))
	{
		if(cc=='-')f=-f;
		cc=getchar();
	}
	while(isdigit(cc))
	{
		x=x*10+cc-'0';
		cc=getchar();
	}
	return x*f;
}
void init()
{
	cin>>n;n*=2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
}
void solve()
{
	for(int i=0;i<=(1<<n)-1;i++)
	{
		head=1,tail=n;
		for(int j=n-1;j>=0;j--)
		{
			int x=(1<<j)&i;
			if(!x)
			{
				res[n-j]=a[head];
				head++;
			}
			if(x)
			{
				res[n-j]=a[tail];
				tail--;
			}
		}
		int flag=0;
		for(int j=1;j<=n;j++)
		{
			if(res[j]!=res[n-j+1])flag=1;
		}
		if(!flag)
		{
			for(int j=n-1;j>=0;j--)
			{
				int x=(1<<j)&i;
				if(!x)
				{
					printf("L");
				}
				if(x)
				{
					printf("R");
				}
			}
			printf("\n");
			return;
		}
	}
	printf("-1\n");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		init();
		solve();
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
LRRLLRRRRL
©\1
*/
