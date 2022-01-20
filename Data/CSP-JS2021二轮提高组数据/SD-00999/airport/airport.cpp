#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
const int numm = 1e6+5;
const int infss = 2147483647;
struct QWQ
{
	int l,r;
	inline bool operator<(const QWQ&x)const {
	  return l<x.l;
	}
}a[numm],b[numm];
int n,m;
int cases1,cases2;
int f1[numm],f2[numm];
int fas[numm];
int vis[numm];
int fs[numm],fy[numm];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int anss;
int main()
{
   freopen("airport.in","r",stdin);
   freopen("airport.out","w",stdout);
     scanf("%d%d%d",&n,&cases1,&cases2);
     for(int i = 1;i<=cases1;i++)
      scanf("%d%d",&a[i].l,&a[i].r);
      for(int i = 1;i<=cases2;i++)
      scanf("%d%d",&b[i].l,&b[i].r);
      sort(a+1,a+1+cases1);sort(b+1,b+1+cases2);
      for(int i = 1;i<=cases1;i++)
      {
      	int ans = i,res = 0;
      	if(!vis[i]) q.push(make_pair(a[i].l,i));
      	for(int j = 2;j<=cases1;j++)
      	{
      		if(vis[j]) continue ;
      		if(a[j].l>a[ans].r)
			  {
			  	ans = j ;
			  	res ++ ;
			  	vis[j] = 1;
			   } 
		}
		f1[i] = ++res ;
	  }
//	  for(int i = 1;i<=cases1;i++)
//	  printf("i::%d %d\n",i,f1[i]);
      for(int i = 1;i<=n;i++)
      {
      	if(q.empty()){fs[i] = fs[i-1];continue ;}
      	fs[i] = fs[i-1] + f1[q.top().second];
      	q.pop();
	  }
//	  for(int i = 1;i<=n;i++) printf("i::%d %d \n",i,fs[i]);
       while(!q.empty()) q.pop();
       memset(vis,0,sizeof(vis));
       for(int i = 1;i<=cases2;i++)
       {
       	   int ans = i,res = 0;
       	   if(!vis[i]) q.push(make_pair(b[i].l,i));
       	   for(int j = 2;j<=cases2;j++)
       	    {
       	   	    if(vis[j]) continue ;
       	   	    if(b[j].l>b[ans].r)
       	   	    {
       	   	    	ans = j;
				    res ++;
				    vis[j] = 1;
				}
			}
			f2[i] = ++res;
	   }
	   for(int i = 1;i<=n;i++)
	   {
	   	if(q.empty()) {fy[i] = fy[i-1];continue ;}
	   	fy[i] = fy[i-1] + f2[q.top().second];
	   	q.pop();
 	   }
 	   for(int i = 0;i<=n;i++)
 	     anss = max(anss,fs[i]+fy[n-i]);
 	     printf("%d",anss);
     fclose(stdin);
     fclose(stdout);
   return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14 
13 18
2 11 
4 15
7 17
12 16

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10


*/
