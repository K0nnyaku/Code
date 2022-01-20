#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct note
{
	int st;
	int end;
}a1[100005],a2[100005];
struct node
{
	int x;
	int sum;
}b1[100005],b2[100005];
int n,m1,m2,book,tot1=1,tot2=1;
int ans1[100005],ans2[100005];
bool mycmp(note c1,note c2)
{
	return c1.st<c2.st;
}
int main() 
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a1[i].st,&a1[i].end);
	}
	sort(a1+1,a1+m1+1,mycmp);
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&a2[i].st,&a2[i].end);
	}
	sort(a2+1,a2+m2+1,mycmp);
	b1[tot1].x=a1[1].end;
	b2[tot2].x=a2[1].end;
	b1[tot1].sum=1;
	b2[tot2].sum=1;
	for(int i=2;i<=m1;i++)
	{
		book=0;
		for(int j=1;j<=tot1;j++)
		{
			if(a1[i].st>b1[j].x)
			{
				book=1;
				b1[j].sum=b1[j].sum+1;
				b1[j].x=a1[i].end;
				break;
			}
		}
		if(book==0)
		{
			b1[++tot1].x=a1[i].end;
			b1[tot1].sum=1;
		}
	}
	for(int i=2;i<=m2;i++)
	{
		book=0;
		for(int j=1;j<=tot2;j++)
		{
			if(a2[i].st>b2[j].x)
			{
				book=1;
				b2[j].sum=b2[j].sum+1;
				b2[j].x=a2[i].end;
				break;
			}
		}
		if(book==0)
		{
			b2[++tot2].x=a2[i].end;
			b2[tot2].sum=1;
		}
	}
	ans1[0]=0;
	ans2[0]=0;
	for(int i=1;i<=m1;i++)
	{
		ans1[i]=ans1[i-1]+b1[i].sum;
	}
	for(int i=1;i<=m2;i++)
	{
		ans2[i]=ans2[i-1]+b2[i].sum;
	}
	int maxa=0;
	for(int i=0;i<=n;i++)
	{
		maxa=max(maxa,ans1[i]+ans2[n-i]);
	}
	printf("%d",maxa);
	return 0;
}
