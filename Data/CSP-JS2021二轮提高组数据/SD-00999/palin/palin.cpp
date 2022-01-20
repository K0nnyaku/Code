#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;
#define ll long long
const int numm = 1e6+5;
const int infss = 2147483647;
int n,m;
int t;
int a[numm];
int stepss[numm],b[numm];
int Steps[numm];
inline bool check ()
{
	for(int i = 1;i<=n;i++)
	if(b[i]!=b[2*n-i+1]) return false ;
//	for(int i = 1;i<=2*n;i++)
//	printf("%d ",b[i]);
//	printf("\n");
	return true;
}
inline void moves ()
{
//	cout<<res[1];
	for(int i = 1;i<=2*n;i++)
	{
	if(Steps[i]<stepss[i]) return ;
	if(stepss[i]<Steps[i]) break;
    } 
//	cout<<2;
	for(int i = 1;i<=2*n;i++)
	Steps[i] = stepss[i]; 
//	for(int i = 1;i<=n;i++)
//	printf("%d ",res[i]);
//	cout<<'\n';
}
void dfs(int l,int r,int step)
{
	if(l == r)
	{
		b[step] = a[l];
		stepss[step] = 1;
//		for(int i = 1;i<=2*n;i++)
//			printf("%d ",b[i]);
//	    printf("\n");
//		if(check())
//		for(int i = 1;i<=2*n;i++)
//		   printf("%d ",b[i]);
//	    printf("\n");
	   if(check())
		moves();
		return ;
	}
	b[step] = a[l];
	stepss[step] = 1;
	dfs(l+1,r,step+1);
	b[step] = a[r];
	stepss[step] = 2;
	dfs(l,r-1,step+1);
} 
int main()
{
   freopen("palin.in","r",stdin);
   freopen("palin.out","w",stdout);
   scanf("%d",&t);
   while( t -- )
   {
//   	for(int i = 1;i<=2*n;i++) res[i] = infss;
      memset(Steps,0x3f3f3f,sizeof(Steps));
   	scanf("%d",&n);
   	for(int i = 1;i<=n*2;i++)
   	scanf("%d",&a[i]);
   	dfs(1,2*n,1);
   	if(Steps[1]!=1&&Steps[1]!=2)
   	{
   		printf("-1\n");
		continue ;
	}
   	for(int i = 1;i<=2*n;i++)
   	if(Steps[i] == 1) printf("L");
     else printf("R");
     printf("\n");
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3*/
