#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+2;
int n,m1,m2;
struct aircraft{
	int a,b;
}a1[maxn],a2[maxn];
inline bool cmp(aircraft A,aircraft B)
{
	return A.a<B.a;
}
int b1[maxn][2],b2[maxn][2],cnt1,cnt2;
int qb1[maxn],qb2[maxn],ans;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)scanf("%d%d",&a1[i].a,&a1[i].b);
	for(int i=1;i<=m2;++i)scanf("%d%d",&a2[i].a,&a2[i].b);
	sort(a1+1,a1+m1+1,cmp);sort(a2+1,a2+m2+1,cmp);
	if(m1>=1)b1[1][1]=1,b1[1][2]=a1[1].b,++cnt1;
	if(m2>=1)b2[1][1]=1,b2[1][2]=a2[1].b,++cnt2;
	for(int i=2;i<=m1;++i)
	{
		bool flag=0;
		for(int k=1;k<=cnt1;++k)
		{
			if(b1[k][2]<a1[i].a)
			{
				++b1[k][1];
				b1[k][2]=a1[i].b;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			b1[++cnt1][1]=1;
			b1[cnt1][2]=a1[i].b;
		}
	}
	for(int i=2;i<=m2;++i)
	{
		bool flag=0;
		for(int k=1;k<=cnt2;++k)
		{
			if(b2[k][2]<a2[i].a)
			{
				++b2[k][1];
				b2[k][2]=a2[i].b;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			b2[++cnt2][1]=1;
			b2[cnt2][2]=a2[i].b;
		}
	}
	for(int i=1;i<=cnt1;++i)qb1[i]+=qb1[i-1]+b1[i][1];
	for(int i=1;i<=cnt2;++i)qb2[i]+=qb2[i-1]+b2[i][1];
	for(int i=0;i<=cnt1;++i)
	{
		for(int j=0;j<=cnt2;++j)
		{
			if(i+j>n)break;
			ans=max(ans,qb1[i]+qb2[j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
