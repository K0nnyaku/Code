#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>  
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
int n,m1,m2;
int a1[100010],a2[100010],l1[100010],l2[100010],t1[100010],t2[100010];
int maxn=0;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a1[i],&l1[i]);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&a2[i],&l2[i]);
	}
	for(int i=1;i<=m1;i++)
	{
		t1[i]=i;
	}
	for(int j=1;j<=m2;j++)
	{
		t2[j]=j;
	}
	int x;
	for(int i=1;i<=m1;i++)
	{
		for(int j=m1;j>=i;j--)
		{
			if(a1[j]<a1[j-1])
			{
				x=t1[j-1];
				t1[j-1]=t1[j];
				t1[j]=x;
			}
		}
	}
	for(int i=1;i<=m2;i++)
	{
		for(int j=m2;j>=i;j--)
		{
			if(a2[j]<a2[j-1])
			{
				x=t2[j-1];
				t2[j-1]=t2[j];
				t2[j]=x;
			}
		}
	}
	int nei=n,wai=0;
	while(wai!=n+1)
	{
		int ans=0;
		bool Nei[100010],Wai[100010];
		for(int i=0;i<=nei;i++)
		{
			Nei[i]=1;
		}
		for(int i=0;i<=wai;i++)
		{
			Wai[i]=1;
		}
		ans+=n;
		for(int i=nei+1;i<=m1;i++)
		{
			Nei[i]=0;
			for(int j=1;j<=m1;j++)
			{
				if(a1[t1[i]]>=l1[t1[j]]&&Nei[j]==1&&Nei[i]!=1)
				{
					Nei[i]=1;
					Nei[j]=0;
					ans+=1;
				}
			}
		}
		for(int i=wai+1;i<=m2;i++)
		{
			Wai[i]=0;
			for(int j=1;j<=m2;j++)
			{
				if(a2[t2[i]]>=l2[t2[j]]&&Wai[j]==1&&Wai[i]!=1)
				{
					Wai[i]=1;
					Wai[j]=0;
					ans++;
				}
			}
		}
		if(ans>maxn)
		{
			maxn=ans;
		}
		nei--;
		wai++;
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
