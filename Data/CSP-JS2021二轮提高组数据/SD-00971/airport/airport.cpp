#include<cstdio>
#include<iostream>
using namespace std;
int m,m1,m2;
int n[100005][5],w[100005][5];
int l1[100005],l2[100005];
void sort1()
{
	for(int i=1;i<=m1;i++)
       for(int j=i+1;j<=m1;j++)
          if(n[i][1]>n[j][1])
          {
          	int t;
          	t=n[j][1];n[j][1]=n[i][1];n[i][1]=t;
          	t=n[j][2];n[j][2]=n[i][2];n[i][2]=t;
		  }
	return;
}
void sort2()
{
	for(int i=1;i<=m1;i++)
       for(int j=i+1;j<=m1;j++)
          if(w[i][1]>w[j][1])
          {
          	int t;
          	t=w[j][1];w[j][1]=w[i][1];w[i][1]=t;
          	t=w[j][2];w[j][2]=w[i][2];w[i][2]=t;
		  }
	return;
}
int na(int x)
{
    int ans=x;
	for(int i=1;i<=x;i++) 
	{
		l1[i]=n[i][2];
		if(l1[i]>l1[i-1])
		{
			int t=l1[i-1];l1[i-1]=l1[i];l1[i]=t;
		}
	}
	for(int i=x;i<=m1;i++)
	   if(n[i][1]>l1[x])
	   {
	   	ans++;l1[x]=n[i][2];
	   	for(int i=1;i<=x;i++) 
		   if(l1[x]>l1[i])
		   {
			   int t=l1[i];l1[i]=l1[x];l1[x]=t;
		   } 
	   }
	return ans;   
}
int inna(int x)
{
    int ans=x;
	for(int i=1;i<=x;i++) 
	{
		l2[i]=w[i][2];
		if(l2[i]>l2[i-1])
		{
			int t=l2[i-1];l2[i-1]=l2[i];l2[i]=t;
		}
	}
	for(int i=x;i<=m2;i++)
	   if(w[i][1]>l2[x])
	   {
	   	ans++;l2[x]=w[i][2];
	   	for(int i=1;i<=x;i++) 
		   if(l2[x]>l2[i])
		   {
			   int t=l2[i];l2[i]=l2[x];l2[x]=t;
		   } 
	   }
	return ans;   
}
int main()
{
   freopen("airport.in","r",stdin);
   freopen("airport.out","w",stdout);
   l1[0]=1e9;l2[0]=1e9;
   scanf("%d %d %d",&m,&m1,&m2);
   for(int i=1;i<=m1;i++) scanf("%d %d",&n[i][1],&n[i][2]);
   for(int i=1;i<=m2;i++) scanf("%d %d",&w[i][1],&w[i][2]);
   int ans=0;sort1();sort2();
   for(int i=0;i<=m;i++) ans=max(ans,na(i)+inna(m-i));
   printf("%d",ans);  
   fclose(stdin);
   fclose(stdout);
   return 0;
}

