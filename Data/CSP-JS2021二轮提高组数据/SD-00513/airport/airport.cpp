#include<cstdio>
#include<iostream>
#include<algorithm>
#define ls nw<<1
#define rs ls|1
#define mid (l+r>>1)
using namespace std;
const int N=100005;
int n,m1,m2,ed[N],t[N<<2],din[N],dot[N],ans;
struct pln{int l,r;} in[N],ot[N];
inline int read()
{
	int s=0;char c=getchar();
	while(!isdigit(c))  c=getchar();
	while(isdigit(c))  s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return s;
}
bool cmp(pln a,pln b) {return a.l<b.l;}
void up(int nw) {t[nw]=t[(ed[t[ls]]<=ed[t[rs]])?ls:rs];}
void build(int nw,int l,int r)
{
	if(l==r)  {t[nw]=l;return;}
	build(ls,l,mid);build(rs,mid+1,r);up(nw);
}
void cg(int nw,int l,int r,int x) {if(l!=r) {x<=mid?cg(ls,l,mid,x):cg(rs,mid+1,r,x);up(nw);}}
int qr(int nw,int l,int r,int v)
{
	if(l==r)  return l;
	return ed[t[ls]]<v?qr(ls,l,mid,v):qr(rs,mid+1,r,v);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)  in[i].l=read(),in[i].r=read();
	for(int i=1;i<=m2;i++)  ot[i].l=read(),ot[i].r=read();
	build(1,1,m1);sort(in+1,in+m1+1,cmp);
	for(int i=1,pos;i<=m1;i++)  pos=qr(1,1,m1,in[i].l),din[pos]++,ed[pos]=in[i].r,cg(1,1,m1,pos);
	for(int i=1;i<=m1;i++)  ed[i]=0,din[i]+=din[i-1];
	build(1,1,m2);sort(ot+1,ot+m2+1,cmp);
	for(int i=1,pos;i<=m2;i++)  pos=qr(1,1,m2,ot[i].l),dot[pos]++,ed[pos]=ot[i].r,cg(1,1,m2,pos);
	for(int i=1;i<=m2;i++)  dot[i]+=dot[i-1];
	for(int i=0;i<=n;i++)
		if(ans<din[i]+dot[n-i])  ans=din[i]+dot[n-i];
	printf("%d",ans);return 0;
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
