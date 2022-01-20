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
const int maxn=1e6+5,maxm=5*1e5+5;
int a[maxn];
int cz[maxn],czs;//²Ù×÷ 
int bj[maxm];
int T,n;
int bl(int l,int r,int re)//Ã¶¾Ù×ó Ã¶¾ÙÓÒ
{
	czs++;
	if(l==r)
	{
	  for(int i=1;i<=2*n-1;i++)
	  {
	  	if(cz[i]==1)
	  	  printf("L");
	  	else
	  	  printf("R");
	  }
	  printf("L\n");
	  return 1;
	}
	if((bj[a[l]]>0&&bj[a[l]]!=czs)&&(bj[a[r]]>0&&bj[a[r]]!=czs))
	{
	  czs--;
	  return 0;
	}
	if(bj[a[l]]>0&&bj[a[l]]!=czs)
	{
	  cz[czs]=2;
	  if(bj[a[r]]==0)
	  {
	    bj[a[r]]=2*n+1-czs;
	    re=bl(l,r-1,0);
	    bj[a[r]]=0;
	  }
	  else
	    re=bl(l,r-1,0);
	  czs--;
	  return re;
	}
	if(bj[a[r]]>0&&bj[a[r]]!=czs)
	{
	  cz[czs]=1;
	  if(bj[a[l]]==0)
	  {
	    bj[a[l]]=2*n+1-czs;
	    re=bl(l+1,r,0);
	    bj[a[l]]=0;
	  }
	  else
	    re=bl(l+1,r,0);
	  czs--;
	  return re;
	}
	cz[czs]=1;
	bj[a[l]]=2*n+1-czs;
	re=bl(l+1,r,0);
	bj[a[l]]=0;
	if(re==1)
	  return re;
	cz[czs]=2;
	bj[a[r]]=2*n+1-czs;
	re=bl(l,r-1,0);
	bj[a[r]]=0;
	czs--;
	return re;
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
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
	  czs=0;
	  memset(cz,0,sizeof(cz));
	  memset(bj,0,sizeof(bj));
	  n=read();
	  for(int i=1;i<=2*n;i++)
	  {
	  	a[i]=read();
	  }
	  int mm=bl(1,2*n,0);
	  if(mm==0)
	    printf("-1\n"); 
	}
	return 0;
}

