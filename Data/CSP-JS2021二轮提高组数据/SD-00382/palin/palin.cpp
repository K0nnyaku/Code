#include<bits/stdc++.h>
#define N 500005
using namespace std;

char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int res=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		res=(res<<1)+(res<<3)+ch-'0';
		ch=getchar();
	}
	return f?-res:res;
}

int n,a[N*2],ans[N*2],tmp[N*2];
bool flag;
char con[N*2],con_tmp[N*2];

void dfs(int l,int r,int sum)
{
	if(sum==n*2)
	{
		flag=1;
		for(int i=1;i<=n;i++)
		{
			if(tmp[i]!=tmp[n*2-i+1])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			for(int i=1;i<=n*2;i++)
			{
				if(ans[i]>tmp[i]||ans[i]==0)
				{
					for(int i=1;i<=n*2;i++)
					{
						ans[i]=tmp[i];
						con[i]=con_tmp[i];
					}
					break;	
				}
				if(ans[i]<tmp[i]) break;
			}
		}
		return ;
	}
	
	tmp[sum+1]=a[l];
	con_tmp[sum+1]='L';
	dfs(l+1,r,sum+1);
	
	tmp[sum+1]=a[r];
	con_tmp[sum+1]='R';
	dfs(l,r-1,sum+1);
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n*2;i++) ans[i]=0;
		for(int i=1;i<=n*2;i++) a[i]=read();
		dfs(1,n*2,0);
		if(!ans[1])
		{
			puts("-1");
			continue;
		}
		else
		{
			for(int i=1;i<=n*2;i++)
			{
				putchar(con[i]);
			}
			puts("");
		}
	}
}

