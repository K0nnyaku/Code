#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define N 100050
int n,m1,m2,maxx=0;
struct node{ int x,y; };
node a[N],b[N];
int ans1[N],ans2[N];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1;ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+ch-48;ch=getchar(); }
	return x*f;
}
bool cmp(node a,node b) { return a.x<b.x; }
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++)
		a[i].x=read(),a[i].y=read();
	for(int i=1;i<=m2;i++)
		b[i].x=read(),b[i].y=read();
	sort(a+1,a+1+m1,cmp);sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=n;i++)
	{
		ans1[i]=i;
		priority_queue<int>Q;
		for(int j=1;j<=i;j++) Q.push(-a[j].y);
		for(int j=i+1;j<=m1;j++)
		{
			int lst=-Q.top();
			if(a[j].x<lst) continue;
			ans1[i]++;
			Q.pop();
			Q.push(-a[j].y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans2[i]=i;
		priority_queue<int>H;
		for(int j=1;j<=i;j++) H.push(-b[j].y);
		for(int j=i+1;j<=m2;j++)
		{
			int lst=-H.top();
			if(b[j].x<lst) continue;
			ans2[i]++;
			H.pop();
			H.push(-b[j].y);
		}
	}
	for(int i=0;i<=n;i++) maxx=max(maxx,ans1[i]+ans2[n-i]);
	printf("%d\n",maxx);
	return 0;
}
