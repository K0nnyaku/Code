/*
Author: smyslenny
Title:
Date:2021.10.23
Main idea:先敲暴力，也就是枚举两种机场怎么分配廊桥
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <map>
#include <vector>

#define ll long long
#define INF 0x3f3f3f3f
#define orz cout<<"LKP AK IOI"

using namespace std;
const int M=1e5+5;
int n,m_1,m_2,Ans=-INF;

int read()
{
	int x=0,y=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') y=0;c=getchar();}
	while(isdigit(c)) { x=x*10+(c^48);c=getchar();}
	return y?x:-x;
}
struct node{
	int s,e;
}guonei[M],guowai[M];
bool cmp(node a,node b)
{
	return a.s<b.s;
}
int sz_1[M],sz_2[M];
void solve(int x)
{
	memset(sz_1,0,sizeof(sz_1));
	memset(sz_2,0,sizeof(sz_2)); 
	int y=n-x,js_1=0,js_2=0,l=1,r=1;
	if(x)
	{
		sz_1[l]=1,js_1=1;
		for(int i=2;i<=m_1;i++)
		{
			while(l<=r && guonei[sz_1[l]].e<guonei[i].s) l++;
			if(r-l+1<x) sz_1[++r]=i,js_1++;
		}
	}
	if(y)
	{
		l=1,r=1,sz_2[l]=1,js_2=1;
		for(int i=2;i<=m_2;i++)
		{
			while(l<=r && guowai[sz_2[l]].e<guowai[i].s) l++;
			if(r-l+1<y) sz_2[++r]=i,js_2++;
		}
	}
	Ans=max(Ans,js_1+js_2);
//	printf("%d %d %d\n",x,y,js_1+js_2);
	return; 
}
		
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	n=read(),m_1=read(),m_2=read(); 
	for(int i=1;i<=m_1;i++)
		guonei[i].s=read(),guonei[i].e=read();
	for(int i=1;i<=m_2;i++)
		guowai[i].s=read(),guowai[i].e=read();
	sort(guonei+1,guonei+1+m_1,cmp);
	sort(guowai+1,guowai+1+m_2,cmp);
	for(int i=0;i<=n;i++)
		solve(i);
	printf("%d\n",Ans);
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


