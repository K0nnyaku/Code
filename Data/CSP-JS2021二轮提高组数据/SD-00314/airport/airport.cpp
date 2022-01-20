#include<bits/stdc++.h>
using  namespace std;
const int M=1e5+7;
int  n,m1,m2;
int  a[M];
int  b[M];
int  c[M];
int  d[M];
void  qsort(int  l,int  r)
{
	int  i=l,j=r,mid=(l+r)/2;
	while(i<=j)
	{
		while(a[i]<a[mid])i++;
		while(a[j]>a[mid])j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			i++;
			j--;
		}
	}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
}
void  qqsort(int  l,int  r)
{
	int  i=l,j=r,mid=(l+r)/2;
	while(i<=j)
	{
		while(c[i]<c[mid])i++;
		while(c[j]>c[mid])j--;
		if(i<=j)
		{
			swap(c[i],c[j]);
			swap(d[i],d[j]);
			i++;
			j--;
		}
	}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
}
priority_queue < int > q;
int  main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int  i=1;i<=m1;i++)
	scanf("%d%d",&a[i],&b[i]);
	qsort(1,m1);
	for(int  i=1;i<=m2;i++)
	scanf("%d%d",&c[i],&d[i]);
	qqsort(1,m2);
	int  ans1[n+1],ans2[n+1];
	for(int  i=0;i<=n;i++)
	{
		ans1[i]=0,ans2[i]=0;
	}
    for(int  i=0;i<=n;i++)
    {
    	while(q.size()!=0)q.pop();
    	
    	for(int  j=1;j<=m1;j++)
    	{
    		
    		while(q.size()!=0&&a[j]>=(-q.top()))
    		q.pop();
    		if(q.size()<i)
    		{
    			q.push(-b[j]);
    			ans1[i]++;
			}
		}
	}
	for(int  i=0;i<=n;i++)
    {
    	while(q.size()!=0)q.pop();
    	
    	for(int  j=1;j<=m2;j++)
    	{
    		
    		while(q.size()!=0&&c[j]>=(-q.top()))
    		q.pop();
    		if(q.size()<i)
    		{
    			q.push(-d[j]);
    			ans2[i]++;
			}
		}
	}
	int ans=0;
	for(int  i=0;i<=n;i++)
	ans=max(ans,ans1[i]+ans2[n-i]);
	printf("%d",ans);
	return  0;
}
