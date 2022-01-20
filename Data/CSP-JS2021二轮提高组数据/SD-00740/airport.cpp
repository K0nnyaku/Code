#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;
int n,m1,m2;
int sum1=0,sum2=0;
int a1[maxn],b1[maxn];
int a2[maxn],b2[maxn];
int maxx=0,sumAll=0;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&a1[i],&b1[i]);
	for(int i=1;i<=m2;i++) scanf("%d%d",&a2[i],&b2[i]);
	for(int n1=0;n1<=n;n1++)
	{
		int n2=n-n1;
		while(sum1<n1) sum1++;
		for(int i=n1+1;i<=m1;i++)
		{
			for(int j=1;j<=m1;j++)
			{
				if(a1[i]>=b1[j])
				{
					sum1++;
					b1[j]=b1[i];
				}
			}
			a1[i]=-1;
			b1[i]=maxn-1;
		}
		if(sum1>m1) sum1=m1;
		if(n1==0) sum1=0;
		while(sum2<n2) sum2++;
		for(int i=n2+1;i<=m2;i++)
		{
			for(int j=1;j<=m2;j++)
			{
				if(a2[i]>=b2[j])
				{
					sum2++;
					b2[j]=b2[i];
				}
			}
			a2[i]=-1;
			b2[i]=maxn-1;
		}
		if(sum2>m2) sum2=m2;
		if(n2==0) sum2=0;
		sumAll=sum1+sum2;
		if(sumAll>maxx) maxx=sumAll;
	}
	printf("%d",maxx+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
