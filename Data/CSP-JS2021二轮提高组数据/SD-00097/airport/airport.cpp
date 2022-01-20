#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;
const int N = 100005;
inline int re()
{
	int x=0,y=1;char c=getchar();
	while(c>'9'||c<'0')
	{if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9')
	x=x*10+(c^48),c=getchar();
	return x*y;
}
int s[N],x[N];
int n,mn,mw;
int ans,anss;
int ny,yw;
int sum,summ;
int um,umm;
int ww;
void dn(int mi)
{
	if(mi>um)
	{
		ans=max(ans,sum);
	}
	if(s[mi]==-1)
	ny++;
	if(s[mi]>0)
	{
		
		if(yn)
		{
			int y=s[mi];
			ny--;
			s[s[mi]]=-1;
			sum++;
			dn(++mi);
			mi--;
			sum--;
			s[s[mi]]=y;
			n=ny++;
		}dn(++mi);
		mi--;
	}
	return;
}
void dw(int mi)
{
	if(mi>umm)
	{
		anss=max(anss,summ);
	}
	if(x[mi]==-1)
	yw++;
	if(x[mi]>0)
	{
		
		if(yn)
		{
			int y=x[mi];
			yw--;
			x[x[mi]]=-1;
			summ++;
			dw(++mi);
			mi--;
			summ--;
			x[x[mi]]=y;
			yw++;
		}dw(++mi);
		mi--;
	}
	return;
}
signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	n=re();mn=re();mw=re();
	for(int i=1;i<=mn;i++)
	{
		int j=re(),c=re();
		s[j]=c;
		um=max(um,c);
	}
	for(int i=1;i<=mw;i++)
	{
		int j=re(),c=re();
		x[j]=c;
		umm=max(umm,c);
	}
	for(int i=1;i<=100;i++)
	{
		ny=i;yw=100-i;
	dn(1);
	dw(1);
	ww=max(ww,ans+anss);
	}
	cout<<ww;
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
