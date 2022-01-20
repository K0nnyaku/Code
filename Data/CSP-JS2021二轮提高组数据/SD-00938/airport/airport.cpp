#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=100010;
struct FLY{
	int next;
	int to;
};
FLY a[N],b[N];//国内进出  国外进出
int n,ma,mb;//廊桥个数  国内  国际 
int fa[N],fb[N]; 
bool cmp(FLY x,FLY y)
{
	return x.next<y.next;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&ma,&mb);
	for(int i=1;i<=ma;i++)
		scanf("%d%d",&a[i].next,&a[i].to);
	sort(a+1,a+ma+1,cmp);
	for(int i=1;i<=mb;i++)
		scanf("%d%d",&b[i].next,&b[i].to);
	sort(b+1,b+mb+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		int vis=i-1;
		fa[i]=ma;
		int flag=a[1].to;
		for(int j=2;j<=ma;j++)
		{
			if(a[j].next<flag&&!vis) 
			{
				fa[i]--;
				continue;
			}
			if(a[j].next<flag&&vis)
			{
				vis--;
				if(a[j].to<=flag) sum++;
			}
			if(a[j].next>=flag)
			{
				vis++;
				vis+=sum;
				flag=a[j].to;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int vis=i-1;
		int sum=0;
		fb[i]=mb;
		int flag=b[1].to;
		for(int j=2;j<=mb;j++)
		{
			if(b[j].next<flag&&!vis) 
			{
				fb[i]--;
				continue;
			}
			if(b[j].next<flag&&vis)
			{
				vis--;
				if(b[j].to<=flag) sum++;
			}
			if(b[j].next>=flag)
			{
				vis++;
				vis+=sum;
				flag=b[j].to;
			}
		}
	}
	int ans=-1;
	for(int i=0;i<=n;i++)
	ans=max(ans,fa[i]+fb[n-i]);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


