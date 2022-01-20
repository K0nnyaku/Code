#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int n,a,b; 
struct node1{
	int arrive,leave;
}nat[100001];
struct node2{
	int arrive,leave;
}inter[100001];
int op=0;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=a;i++)
		scanf("%d%d",&nat[i].arrive,&nat[i].leave);
	for(int i=1;i<=b;i++)
		scanf("%d%d",&inter[i].arrive,&inter[i].leave);
for(int i=0;i<=n;i++)
{
	int visc[100001]={0},visin[10001]={0};
	int ans=0;
	int c[100001]={0},in[100001]={0};
	for(int j=1;j<=a;j++)
	{
		if(i==0)	break;
		for(int m=1;m<=i;m++)
		{
			if(visc[j])	break;
			if(nat[j].arrive>=c[m])
			{
				visc[j]=1;
				c[m]=nat[j].leave;
				ans++;
			}
		}
	}
	printf("%d ",ans);
	for(int j=1;j<=b;j++)
	{
		if(n-i==0)	break;
		for(int m=1;m<=n-i;m++)
		{
			if(visin[j])	break;
			if(inter[j].arrive>=in[m])
			{
				visin[j]=1;
				in[m]=inter[j].leave;
				ans++;
			}
		}
	}
	printf("%d ",ans);
	printf("%d\n",ans);
	op=max(op,ans);
}
	printf("%d",op);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
