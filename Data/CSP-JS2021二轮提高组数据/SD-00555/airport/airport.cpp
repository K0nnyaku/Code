//20pts 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
int n,m1,m2;
int bridge[100010];
int ans1[100100],ans2[100100],ans=0;
bool vis[100100];
struct node
{
	int l,r;
}in[100010],out[100010];
bool cmp(const node &A,const node &B)
{
	return A.l<B.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&in[i].l,&in[i].r);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&out[i].l,&out[i].r);
	}
	sort(in+1,in+1+m1,cmp);
	sort(out+1,out+1+m2,cmp);
	int cnt=0,end=-1;
	for(int i=1;i<=n;i++)
	{
		end=-1;
		for(int j=1;j<=m1;j++)
		{
			if(!vis[j]&&in[j].l>end)
			{
				cnt++;
				vis[j]=1;
				end=in[j].r;
			}
		}
		ans1[i]=cnt;
	}
	cnt=0,end=-1;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		end=-1;
		for(int j=1;j<=m2;j++)
		{
			if(!vis[j]&&out[j].l>end)
			{
				cnt++;
				vis[j]=1;
				end=out[j].r;
			}
		}
		ans2[i]=cnt;
	}
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,ans1[i]+ans2[n-i]);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
