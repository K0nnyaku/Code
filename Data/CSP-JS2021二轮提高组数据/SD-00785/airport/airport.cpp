#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5+5;
struct plane
{
	int a=0;
	int b=0;
	int cnt=0;
} p1[N],p2[N],np1[N],np2[N];
int n,m1,m2;
bool cmp1(const plane &pa,const plane &pb)
{
	return pa.a<pb.a;
}
bool cmp2(const plane &pa,const plane &pb)
{
	return pa.a<pb.a;
}
void work()
{
	if(n>=m1+m2)
	{
		printf("%d",m1+m2);
		return;
	}
	int last = 1;
	for(int i = 1;i<=m1;i++)
	{
		for(int j = 1;j<=last;j++)
		{
			if(p1[i].a>np1[j].b)
			{
				if(last==1&&i==1)
				{
					np1[j].a=p1[i].a;
				}
				np1[j].b=p1[i].b;
				np1[j].cnt++;
				break;
			}
			else if(j==last)
			{
				np1[++last].b=p1[i].b;
				np1[last].a=p1[i].a;
				np1[last].cnt=1;
				break;
			}
		}
	}
	int last1 = 1;
	for(int i = 1;i<=m2;i++)
	{
		for(int j = 1;j<=last1;j++)
		{
			if(p2[i].a>np2[j].b)
			{
				if(last==1&&i==1)
				{
					np2[j].a=p2[i].a;
				}
				np2[j].b=p2[i].b;
				np2[j].cnt++;
				break;
			}
			else if(j==last1)
			{
				np2[++last1].b=p2[i].b;
				np2[last1].a=p2[i].a;
				np2[last1].cnt=1;
				break;
			}
		}
	}
	sort(np1+1,np1+last+1,cmp2);
	sort(np2+1,np2+last1+1,cmp2);
	int ans = -1;
	int psum;
	for(int i = 0;i<=n;i++)
	{
		psum=0;
		for(int j = 1;j<=n-i;j++)
		{
			psum += np2[j].cnt;
		}
		for(int j = 1;j<=i;j++)
		{
			psum += np1[j].cnt;
		}
		if(psum>ans)
		{
			ans = psum;
			//printf("%d,%d,ans==%d,",i,n-i,ans);
			//printf("%d,%d\n",psum-tmp,tmp);
		}
	}
	printf("%d\n",ans);
}
int main ()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&p1[i].a,&p1[i].b);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&p2[i].a,&p2[i].b);
	}
	sort(p1+1,p1+m1+1,cmp1);
	
	/*for(int i=1;i<=m1;i++)
	{
		printf("%d,%d\n",p1[i].a,p1[i].b);
	}*/
	sort(p2+1,p2+m2+1,cmp1);
	work();
	return 0;
}
