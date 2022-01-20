#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long duru()
{  long long s=0,i=1;
   char ch;
   ch=getchar();
   while(ch<'0'||ch>'9')
   {  if(ch=='-') i=-1;
	  ch=getchar();}
   while(ch>='0'&&ch<='9')
   {  s=s*10+ch-'0';
	  ch=getchar();}
   return s*i;}
long long a[100010],b[100010],sa[100010],sb[100010];
int main()
{  long long n,m1,m2,i,j,k,x,y,sum1=0,sum2=0,ans=0;
   bool flag;
   freopen("airport.in","r",stdin);
   freopen("airport.out","w",stdout);
   n=duru();m1=duru();m2=duru();
   memset(a,0,sizeof(a));memset(b,0,sizeof(b));
   memset(sa,0,sizeof(sa));memset(sb,0,sizeof(sb));
   for(i=1;i<=m1;i++)
   {  x=duru();y=duru();
      flag=true;
      for(j=1;j<=sum1;j++)
        if(x>a[j]){ a[j]=y;sa[j]++;flag=false;}
      if(flag){  sum1++;sa[sum1]=1;a[sum1]=y;}}
   for(i=1;i<=m2;i++)
   {  cin>>x>>y;
      flag=true;
      for(j=1;j<=sum2;j++)
        if(x>b[j]){ b[j]=y;sb[j]++;flag=false;}
      if(flag){  sum2++;sb[sum2]=1;b[sum2]=y;}}
   k=0;i=1;j=1;
   while(k<n)
   {   if(sa[i]>sb[j]){  k++;ans+=sa[i];i++;}
         else if(sa[i]<=sb[j]){ k++;ans+=sb[j];j++;}}
   printf("%lld\n",ans);
   fclose(stdin);
   fclose(stdout);
   return 0;}
   
    
