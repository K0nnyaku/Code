#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100005;

int n,m1,m2,m,sum=0,ans=0;
int na[MAXN][2],in[MAXN][2],r[MAXN][2],so[MAXN],N[MAXN],I[MAXN];
bool flag=0;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d%d%d",&n,&m1,&m2);
	m=max(m1,m2); m=max(n,m);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&r[i][0],&r[i][1]);
		so[i]=r[i][0];
	}
	sort(so+1,so+m1+1);
	for(int i=1;i<=m1;i++)
		for(int j=1;j<=m1;j++)
			if(so[i]==r[j][0])
			{
				na[i][0]=r[j][0];
				na[i][1]=r[j][1];
			}
	memset(r,0,sizeof(r));
	memset(so,0,sizeof(so));
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&r[i][0],&r[i][1]);
		so[i]=r[i][0];
	}
	sort(so+1,so+m2+1);
	for(int i=1;i<=m2;i++)
		for(int j=1;j<=m2;j++)
			if(so[i]==r[j][0])
			{
				in[i][0]=r[j][0];
				in[i][1]=r[j][1];
			}
	N[0]=-1,I[0]=-1;
	
	for(int i=0;i<=n;i++)
	{
		sum=0;
		for(int j=i+1;j<=m;j++) N[j]=-1;
		for(int j=n-i+1;j<=m;j++) I[j]=-1;
		
		if(i>0)
			for(int j=1;j<=m1;j++)
			{
				flag=0;
				
				for(int k=1;k<=i;k++)
					if((N[k]>0) && (na[j][0]>na[N[k]][1]))
						N[k]=0;
				
				for(int k=1;k<=i;k++)
					if((N[k]==0) && (flag==0))
					{
						N[k]=j;
						sum++;
						flag=1;
					}
			}
		
		if(n-i>0)
			for(int j=1;j<=m2;j++)
			{
				flag=0;
				
				for(int k=1;k<=n-i;k++)
					if((I[k]>0) && (in[j][0]>in[I[k]][1]))
						I[k]=0;
				
				for(int k=1;k<=n-i;k++)
					if((I[k]==0) && (flag==0))
					{
						I[k]=j;
						sum++;
						flag=1;
					}
			}
		
		ans=max(sum,ans);
		
		for(int j=1;j<=m;j++)
			N[j]=0,I[j]=0;
	}
	
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

