#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int n,m_1,m_2;//廊桥 国内 国际 
struct node{
	int dd,lk;//抵达 离开 
}a1[maxn],a2[maxn];

struct dy{
	int s,lat;//使用机场数 上一架飞机离开时间 
}f_1[maxn],f_2[maxn];
int ls1,ls2;
int qzh1[maxn],qzh2[maxn];
int ans;
bool cmp(node x,node y)
{
	return x.dd<y.dd;
}
inline int read()
{
	int x=1,y=0;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-')
	  c=getchar();
	if(c=='-')
	{
	  x=-1;
	  c=getchar();
	}
	while(c>='0'&&c<='9')
	{
	  y=(y<<3)+(y<<1)+c-'0';
	  c=getchar();
	}
	return x*y;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m_1=read(),m_2=read();
	for(int i=1;i<=m_1;i++)
	  a1[i].dd=read(),a1[i].lk=read();
	for(int i=1;i<=m_2;i++)
	  a2[i].dd=read(),a2[i].lk=read();
	sort(a1+1,a1+m_1+1,cmp);
	sort(a2+1,a2+m_2+1,cmp);
	f_1[++ls1].s++;
	f_1[ls1].lat=a1[1].lk;
	for(int i=2;i<=m_1;i++)
	{
	  for(int j=1;j<=ls1;j++)
	  {
	  	if(a1[i].dd>f_1[j].lat)
	  	{
	  	  f_1[j].s++;
	  	  f_1[j].lat=a1[i].lk;
	  	  //cout<<j<<endl;
		  break;	
		}
		if(j==ls1)
		{
		  f_1[++ls1].s++;
		  f_1[ls1].lat=a1[i].lk;
		  //cout<<ls1<<endl;
		  break;
		}
	  }
	}
	f_2[++ls2].s++;
	f_2[ls2].lat=a2[1].lk;
	for(int i=2;i<=m_2;i++)
	{
	  for(int j=1;j<=ls2;j++)
	  {
	  	if(a2[i].dd>f_2[j].lat)
	  	{
	  	  f_2[j].s++;
	  	  f_2[j].lat=a2[i].lk;
	  	  //cout<<j<<endl;
		  break;	
		}
		if(j==ls2)
		{
		  f_2[++ls2].s++;
		  f_2[ls2].lat=a2[i].lk;
		  //cout<<ls2<<endl;
		  break;
		}
	  }
	}
	qzh1[1]=f_1[1].s;
	for(int i=2;i<=ls1;i++)
	  qzh1[i]=qzh1[i-1]+f_1[i].s;
	qzh2[1]=f_2[1].s;
	for(int i=2;i<=ls2;i++)
	  qzh2[i]=qzh2[i-1]+f_2[i].s;
	for(int i=0;i<=n;i++)
	  ans=max(ans,qzh1[min(ls1,i)]+qzh2[min(ls2,n-i)]);
	printf("%d",ans);
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
*/
/*
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
