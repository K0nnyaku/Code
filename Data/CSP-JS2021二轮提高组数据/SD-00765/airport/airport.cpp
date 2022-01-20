#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct gq
{
	int at,lt;
}gn[100005],gj[100005];
bool cmp(gq x,gq y){return x.at<y.at;}
int ans_gn[100005],ans_gj[100005];
struct timel
{
	bool flag;
	int t;
}timel_gn[100005],timel_gj[100005];
bool cmpq(timel x,timel y){return x.flag>y.flag;if(x.flag==y.flag)return x.t<y.t;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&gn[i].at,&gn[i].lt);
		timel_gn[i].t=gn[i].lt;
		timel_gn[i].flag=0;
	}
	sort(gn+1,gn+m1+1,cmp);
	sort(timel_gn+1,timel_gn+m1+1,cmpq);
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&gj[i].at,&gj[i].lt);
		timel_gj[i].t=gj[i].lt;
		timel_gj[i].flag=0;
	}
	sort(gj+1,gj+m2+1,cmp);
	sort(timel_gj+1,timel_gj+m2+1,cmpq);
	for(int i=1;i<=m1;i++)
	{
		int tot=1,sum=i;
		for(int j=1;j<=i;j++)timel_gn[j].flag=1;
		for(int j=i+1;j<=m1;j++)
		if(gn[j].at>=timel_gn[tot].t&&timel_gn[tot].flag)sum++;
		else timel_gn[j].flag=0;
		sort(timel_gn+1,timel_gn+1+m1,cmpq);tot++;
		ans_gn[i]=sum;
	}
	for(int i=1;i<=m2;i++)
	{
		int tot=1,sum=i;
		for(int j=1;j<=i;j++)timel_gj[j].flag=1;
		for(int j=i+1;j<=m2;j++)
		if(gj[j].at>=timel_gj[tot].t&&timel_gj[tot].flag)sum++;
		else timel_gj[j].flag=0;
		sort(timel_gj+1,timel_gj+1+m2,cmpq);tot++;
		ans_gj[i]=sum;
	}
	int ans=-1;
	for(int i=0;i<=n;i++)
	ans=max(ans,ans_gn[i]+ans_gj[n-i]);
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
