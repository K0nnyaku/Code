#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,g,f,ans=0,a[100000],b[100000],lk;
bool gj[100000],fj[100000];
struct Edge
{
	int d,z;
};
int cmp(Edge a,Edge b)
{
	return a.d<b.d;	
}
Edge gq[100000],fq[100000];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	                             //输入 
{
		
		scanf("%d%d%d",&n,&g,&f);
		for(int i=1;i<=g;i++)
			{
				scanf("%d%d",&gq[i].d,&gq[i].z);
			}
		for(int i=1;i<=f;i++)
		{
			scanf("%d%d",&fq[i].d,&fq[i].z);
		}
}
/*
{
	printf("%d%d%d",n,g,f);
		for(int i=1;i<=g;i++)
			{
				printf("%d %d\n",gq[i].d,gq[i].z);
			}
		for(int i=1;i<=f;i++)
		{
			scanf("%d %d\n",fq[i].d,fq[i].z);
		}
	
}
*/
{							//国区飞机 
	sort(gq,gq+g,cmp);
		for(int l=1;l<=n;l++)
		{
			a[l]+=a[l-1];
			lk=0;
			for(int j=1;j<=g;j++)
			{
				if(gj[j]==1) 
				{
					continue;	
				}
				if(gq[j].d>lk) 
				{
					lk=gq[j].z;
					gj[j]=1;
					a[l]++;
				}
			}
			if(a[l]==g)
			{
				for(int p=l;p<=g;p++) a[p]=g;
				break;
			}
		}
		
	
}
		
		
		
{							//外国飞机 
		sort(fq,fq+g,cmp);
		for(int l=1;l<=n;l++)
		{
			b[l]+=b[l-1];
			lk=0;
			for(int j=1;j<=f;j++)
			{
				if(fj[j]==1) 
				{
					continue;	
				}
				if(fq[j].d>lk) 
				{
					lk=fq[j].z;
					fj[j]=1;
					b[l]++;
				}
			}
			if(b[l]==f)
			{
				for(int p=l;p<=f;p++) a[p]=f;
				break;
			}
		}
}		
		
{
	int y=0;
	for(int i=1;i<=n;i++)
	{
		y=n-i;
		int sum=a[i]+b[y];
		if(sum>ans)
		ans=sum;
	}
}

		printf("%d",ans);
		return 0;
}
