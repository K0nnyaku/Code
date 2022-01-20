#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=1e5+5;
struct www
{
	int l,r;
}a[maxn];
bool cmp(www x,www y)
{
	return x.l<y.l;
}
int ans1[maxn],ans2[maxn];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+1+m1,cmp);
	for(int i=1;i<=n;i++)
	{
		int rf=a[1].r,tot=0; 
		for(int j=1;j<=m1;j++)
		{
			if(a[j].l<rf&&tot<=i)
			{
				tot++;
				rf=max(a[j].r,rf);
				ans1[i]++;
			}
			else if(a[j].l>rf)
			{
				tot=0;
				ans1[i]++;
			}
		}
	}
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+1+m2,cmp);
	for(int i=1;i<=n;i++)
	{
		int rf=a[1].r,tot=0; 
		for(int j=1;j<=m2;j++)
		{
			if(a[j].l<rf&&tot<=i)
			{
				tot++;
				rf=max(a[j].r,rf);
				ans2[i]++;
			}
			else if(a[j].l>rf)
			{
				tot=0;
				ans2[i]++;
			}
		}
	}
	ans1[0]=ans2[0]=0;
	int res=0;
	for(int i=0;i<=n;i++)
		res=max(res,ans1[i]+ans2[n-i]);
	printf("%d\n",res);
	//zhx±£ÓÓ£¬BUGÔ¶Àë 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
