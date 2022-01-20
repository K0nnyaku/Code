#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
#include <map> 
using namespace std;
const int N=1e5+5,inf=1e9;
#define ll long long
#define db double
#define gc getchar()
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define dep(x,y,z) for(int x=y;x>=z;x++)
int n,m1,m2,vis1[N],vis2[N],f1[N],f2[N],st[5][N],tp[5];
struct nd{int s,t;}ar[N],prt[N];
bool cmp(nd a,nd b){return a.s<b.s;}
inline int in()
{
	int f=0,g=1;char c=gc;
	while(!isdigit(c)) 
		g=g*(c=='-'?-1:1),c=gc;
	while(isdigit(c))
		f=f*10+c-'0',c=gc;
	return f*g;
}  
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=in();m1=in();m2=in();int mx=0,j=1,k=0,ls=0;
	rep(i,1,m1) ar[i].s=in(),ar[i].t=in();
	rep(i,1,m2) prt[i].s=in(),prt[i].t=in();
	sort(ar+1,ar+m1+1,cmp);sort(prt+1,prt+m2+1,cmp);
	rep(i,1,m1) st[0][++tp[k]]=i;
	while(tp[k]>0)
	{
		rep(i,1,tp[k])
		{
			if(ls<ar[st[k][i]].s) f1[j]++,ls=ar[st[k][i]].t;
			else st[k^1][++tp[k^1]]=st[k][i];
		}
		tp[k]=0;k=k^1;j++;ls=0;
	}
	j=1,k=0;ls=0;tp[0]=tp[1]=0;
	rep(i,1,m2) st[0][++tp[k]]=i;
	while(tp[k]>0)
	{
		rep(i,1,tp[k])
		{
			if(ls<prt[st[k][i]].s) f2[j]++,ls=prt[st[k][i]].t;
			else st[k^1][++tp[k^1]]=st[k][i];
		}
		tp[k]=0;k=k^1;j++;ls=0;
	}
	rep(i,1,m1) f1[i]+=f1[i-1];
	rep(i,1,m2) f2[i]+=f2[i-1];
	rep(i,0,n) mx=max(mx,f1[i]+f2[n-i]);
	cout<<mx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
