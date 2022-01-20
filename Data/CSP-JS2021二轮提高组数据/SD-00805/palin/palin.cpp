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
long long a[500010],b[500010],n;
char ch[500010];
bool vis[500010],stp,op;
bool check(long long q[])
{ long long i;bool flag=true; 
  //for(i=1;i<=2*n;i++) cout<<q[i]<<" ";
  //cout<<endl;
   for(i=1;i<=n;i++)
    if(q[i]!=q[2*n+1-i]){ flag=false;break;}
  return flag;}
long long print(long long q[])
{  long long i,fp,rp;
   fp=1;rp=2*n;
   for(i=1;i<=2*n;i++)
     if(q[i]==a[fp]){  cout<<"L";fp++;}
       else if(q[i]==a[rp]){  cout<<"R";rp--;}
   cout<<endl;
   return 0;}
long long dfs(long long pos,long long sum,long long q[])
{  long long i,j;
   if(stp) return 0;
   if(sum==2*n)
     if(check(q))
       {  print(q);stp=true;op=true;return 0;}
       else return 0; 
   for(i=1;i<=2*n;i++)
     if(!vis[i])
     {  vis[i]=true;q[pos]=a[i];dfs(pos+1,sum+1,q);vis[i]=false;break;}
   for(i=n*2;i>=1;i--)
     if(!vis[i])
     {  vis[i]=true;q[pos]=a[i];dfs(pos+1,sum+1,q);vis[i]=false;break;}
   return 0;}       
int main()
{  long long i,j,t;
   freopen("palin.in","r",stdin);
   freopen("palin.out","w",stdout);
   t=duru();
   for(j=1;j<=t;j++)
   { n=duru();
     stp=false;op=false;
     for(i=1;i<=2*n;i++) a[i]=duru();
     memset(vis,false,sizeof(vis));
     dfs(1,0,b);
	 if(!op) cout<<-1<<endl;}
   fclose(stdin);
   fclose(stdout);
   return 0;}
