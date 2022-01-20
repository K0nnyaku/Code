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
long long a[505],pos[505],f[505],top=0,n,k,ans=0;
long long qf()
{  long long i,top=0,fl=0;
   long long g[505];
   for(i=1;i<=n;i++)
     if(a[i]==1) g[++top]=i;
       else if(a[i]==2)
       {  f[i]=g[top];
	      top--;}
   return 0;}
long long print(long long t,long long r)
{  for(long long i=t;i<=r;i++)
    if(a[i]==1) cout<<"(";
      else if(a[i]==2) cout<<")";
      else if(a[i]==3) cout<<"*";
   cout<<endl;}
bool check1(long long t,long long r)
{  long long i,sum1=0,sum3=0;
   bool flag=true;
   for(i=t;i<=r;i++)
   {  if(sum1<0||sum3>=k) { flag=false;break;}
      if(a[i]==1){ sum1++;sum3=0;}
        else if(a[i]==2){ sum1--;sum3=0;}
        else if(a[i]==3) sum3++;}
   if(sum1!=0) flag=false;
   if(a[t]==3||a[r]==3) flag=false;
   return flag;}
bool check3(long long t,long long r)
{  long long i;bool flag=true;
   for(i=t;i<=r;i++)
      if(a[i]!=3) return false;
   return true;}
bool check2(long long q[],long long t,long long r)
{  long long i,fp=t,rp=r;
   bool flag=true;
   while(fp<=rp)
   {  while(a[rp]==2&&a[fp]==1&&f[rp]==fp){ fp++;rp--;}
      if(fp>rp) break;
	  if(a[rp]==3&&a[fp]==3&&!check3(fp,rp)) { flag=false;break;}
      else if(a[fp]==3)
      {  long long sum=0;
         while(fp<=rp&&a[fp]==3){  sum++;fp++;}
         if(sum>=k){  flag=false;break;}}
      else if(a[rp]==3)
        {   long long sum=0;
            while(fp<=rp&&a[rp]==3){  sum++;rp--;}
            if(sum>=k){  flag=false;break;}}
        
        else 
        { long long sum=0;
		  for(i=fp;i<=rp;i++)
		  {  if(a[i]==1) sum++;
		      else if(a[i]==2) sum--;
		     if(sum==0) break;}
		  long long j=i+1;
		  while(a[j]==3) j++;
          if(check1(fp,i)&&check1(j,rp)&&check2(a,fp,i)&&check2(a,j,rp)) break;
             else{ flag=false;break;}}}
   return flag;}
long long dfs(long long l)
{  if(l==top+1)
   {  if(check1(1,n))
      {  qf();
	     if(check2(a,1,n)) {ans++;}}
      return 0;}
   for(long long i=1;i<=3;i++)
   {  a[pos[l]]=i;dfs(l+1);a[pos[l]]=0;}
   return 0;}
int main()
{  string s;
   long long i;
   freopen("bracket.in","r",stdin);
   freopen("bracket.out","w",stdout);
   n=duru();k=duru();
   cin>>s;
   for(i=0;i<n;i++)
   {  if(s[i]=='?'){ a[i+1]=0;pos[++top]=i+1;}
       else if(s[i]=='(') a[i+1]=1;
         else if(s[i]==')') a[i+1]=2;
           else if(s[i]=='*') a[i+1]=3;}
   dfs(1);
   cout<<ans<<endl;
   fclose(stdin);
   fclose(stdout);
   return 0;}
     
   
   
   
