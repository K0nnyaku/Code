#include<bits/stdc++.h>
using namespace std;
int T,a[2005],ans[2005],len[2005],flag,n;
void dfs(int l,int r,int num)
{
	if(l<r)
	{
		flag=1;
		return;
	}
	if(num<=n-1)
	{
		len[num+1]=a[l];
		ans[num+1]=1;
		dfs(l+1,r,num+1);
		if(flag==1)return;
		ans[num+1]=0;
		len[num+1]=0;
		ans[num+1]=2;
		len[num+1]=a[r];
		dfs(l,r-1,num+1);
		if(flag==1)return;
		ans[num+1]=0;
		len[num+1]=0;
	}
	else
	{
		if(a[l]==len[2*n-num])
		{
			len[num+1]=a[l];
			ans[num+1]=1;
			dfs(l+1,r,num+1);
			if(flag==1)return;
			ans[num+1]=0;
			len[num+1]=0;
		}
		if(a[r]==len[2*n-num])
		{
			ans[num+1]=2;
			len[num+1]=a[r];
			dfs(l,r-1,num+1);
			if(flag==1)return;
			ans[num+1]=0;
			len[num+1]=0;
		}
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		flag=0;
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		memset(len,0,sizeof(len));
		scanf("%d",&n);
		for(int j=1;j<=2*n;j++)scanf("%d",&a[j]);
		dfs(1,2*n,0);
		if(flag==1)
		{
			for(int j=1;j<=2*n;j++)
			{
				if(ans[j]==1)printf("L");
				else if(ans[j]==2)printf("R");
			}
		}
		else printf("-1");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
