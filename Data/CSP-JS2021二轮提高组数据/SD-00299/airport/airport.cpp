#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=1e6+1;
struct hb1{
	int l,r;
}h1[M];
struct hb2{
	int l,r;
}h2[M];
int lq1[M],lq2[M],n,m1,m2,ans,maxx;
int comp1(hb1 x,hb1 y)
{
	return x.l<y.l;
}
int comp2(hb2 x,hb2 y)
{
	return x.l<y.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&h1[i].l,&h1[i].r);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&h2[i].l,&h2[i].r);
	sort(h1+1,h1+m1+1,comp1);
	sort(h2+1,h2+m2+1,comp2);
	for(int i=0;i<=n;i++)
	{
		int k=n-i;
		ans=n;
		for(int j=1;j<=i;j++)
		 lq1[j]=h1[j].r;
		 sort(lq1+1,lq1+i+1);
		for(int j=i+1;j<=m1;j++)
		 if(h1[j].l>lq1[1])
		 {
			lq1[1]=h1[j].r;
			ans++;
			sort(lq1+1,lq1+i+1);
		 }//---------
		for(int j=1;j<=k;j++)
		 lq2[j]=h2[j].r;
		 sort(lq2+1,lq2+k+1);
		for(int j=k+1;j<=m2;j++)
		 if(h2[j].l>lq2[1])
		 {
			lq2[1]=h2[j].r;
			ans++;
			sort(lq2+1,lq2+k+1);
		 }
		maxx=max(maxx,ans);
	}
	printf("%d",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
