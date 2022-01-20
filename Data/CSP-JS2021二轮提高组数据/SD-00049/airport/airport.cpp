#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<vector>
#define N 100010
using namespace std;
int n,m1,m2,cnt1,cnt2;
bool vis[N];
int size1[N],size2[N];
struct ques{
	int l,r;
}q1[N],q2[N];
void read(int &x)
{
	char c;x=0;int f=1;
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	x*=f;
}
int solve1(int x)
{
	int last,tot=1;
	last=q1[x].r;
	vis[x]=1;
	for(int i=x+1;i<=m1;++i)
	{
		if(vis[i])continue;
		if(q1[i].l>last)
		{
			vis[i]=1,tot++,last=q1[i].r;
		}
	}
	return tot;
}
int solve2(int x)
{
	int last,tot=1;
	last=q2[x].r;
	vis[x]=1;
	for(int i=x+1;i<=m2;++i)
	{
		if(vis[i])continue;
		if(q2[i].l>last)
		{
			vis[i]=1,tot++,last=q2[i].r;
		}
	}
	return tot;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n),read(m1),read(m2);
	for(int i=1;i<=m1;++i)
	{
		read(q1[i].l),read(q1[i].r);
	}
	for(int i=1;i<=m1;++i)if(!vis[i])cnt1++,size1[cnt1]+=size1[cnt1-1]+solve1(i);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m2;++i)
	{
		read(q2[i].l),read(q2[i].r);
	}
	for(int i=1;i<=m2;++i)if(!vis[i])cnt2++,size2[cnt2]+=size2[cnt2-1]+solve2(i);
	int res=0;
	for(int i=0;i<=n;++i)
	{
		res=max(res,size1[i]+size2[(n-i)]);
	}
	printf("%d",res);

	return 0;
}
