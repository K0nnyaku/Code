#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N  100005
using namespace std;
struct BWE
{
	int start,end;
}a[N],b[N];
int aa[N],bb[N],cnt;
bool booka[N],bookb[N];
bool cmp(BWE x,BWE y)
{
	return x.start<y.start;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a[i].start,&a[i].end);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&b[i].start,&b[i].end);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=m1;i++)
		aa[i]=m1;
	for(int i=1;i<=m2;i++)
		bb[i]=m2;
	for(int i=1;i<=n;i++)
	{
		aa[i]=aa[i-1];
		int k=-1;
		for(int j=1;j<=m1;j++)
		{
			//printf("[%d] %d\n",j,booka[j]);
			if(booka[j])
				continue;
			if(a[j].start<k)
				continue;
			booka[j]=true;
			k=a[j].end;
			aa[i]++;
			cnt++;
			//printf("%d %d %d\n",j,k,cnt);
			if(cnt==m1)
				break;
		}
		if(cnt==m1)
			break;
	}
//	for(int i=1;i<=m1;i++)
//		printf("%d\n",aa[i]);
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		bb[i]=bb[i-1];
		int k=-1;
		for(int j=1;j<=m2;j++)
		{
			//printf("[%d] %d\n",j,booka[j]);
			if(bookb[j])
				continue;
			if(b[j].start<k)
				continue;
			bookb[j]=true;
			k=b[j].end;
			bb[i]++;
			cnt++;
			//printf("%d %d %d\n",j,k,cnt);
			if(cnt==m2)
				break;
		}
		if(cnt==m2)
			break;
	}
//	for(int i=1;i<=m2;i++)
//		printf("%d\n",bb[i]);
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,aa[i]+bb[n-i]);
	printf("%d",ans);
	return 0;
}

