//airport
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,m1,m2,sum,maxx=-0x3f3f3f3f;
bool vis1[100001],vis2[100001];
struct point1
{
	int start,over,narrow;
}e1[100001];
struct point2
{
	int start,over,narrow;
}e2[100001];
queue<point1> q1;
queue<point2> q2;
inline int cmp1(point1 tx,point1 ty)
{
	return(tx.start<ty.start);
}
inline int cmp2(point2 tx,point2 ty)
{
	return(tx.start<ty.start);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&e1[i].start,&e1[i].over);
		e1[i].narrow=e1[i].over-e1[i].start;
		
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&e2[i].start,&e2[i].over);
		e2[i].narrow=e2[i].start-e2[i].over;
	}
	sort(e1+1,e1+m1+1,cmp1);
	sort(e2+1,e2+m2+1,cmp2);
	int x1=0,x2=n;
	printf("%d",m1+m2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
