#include<iostream>
#include<cstdio>
using namespace std;
int a[1005],n,step[1005],b[1005],f;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=b[n*2-i+1])
			return 0;
	}
	return 1;
}
void dfs(int l,int r,int num)
{
	if(f==1)
		return ;
	if(r<l)
	{
		if(check())
		{
			f=1;
			for(int i=1;i<=n*2;i++)
			{
				if(step[i]==1)
					printf("L");
				else
					printf("R");
			}
			puts("");
		} 
		return ;
	}
	step[num]=1;b[num]=a[l];
	dfs(l+1,r,num+1);
	step[num]=2;b[num]=a[r];
	dfs(l,r-1,num+1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T,i;
	cin>>T;
	while(T--)
	{
		f=0;
		scanf("%d",&n);
		for(i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1,n*2,1);
		if(f==0)
			puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
