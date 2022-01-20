#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2;
int q1[100005],q2[100005],h1,t1,h2,t2,max1,max2,f1[100005],f2[100005],ans=0;
struct node
{
	int l,r;
}a[100005],b[100005];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int cnt1=n;cnt1>=0;cnt1--)
	{
		int cnt2=n-cnt1,ans1=0,ans2=0;
		h1=t1=h2=t2=0;
		for(int i=1;i<=m1;i++)
		{
			while(h1<t1&&a[i].l>q1[h1+1])h1++;
			if(t1-h1<cnt1)q1[++t1]=a[i].r,ans1++;
		}
		for(int i=1;i<=m2;i++)
		{
			while(h2<t2&&b[i].l>q2[h2+1])h2++;
			if(t2-h2<cnt2)q2[++t2]=b[i].r,ans2++;
		}
		ans=max(ans,ans1+ans2);
	}
	printf("%d\n",ans);
	return 0;
}
