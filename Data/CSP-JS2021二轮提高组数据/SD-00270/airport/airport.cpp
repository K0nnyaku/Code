#include<bits/stdc++.h>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=5005;
int n,m_1,m_2;

struct airg{
	int l,r;
}nei[maxn];

struct airw{
	int l,r;
}wai[maxn];

inline int savn(int t)
{
	int as=0,l,r;
	if (t==0) return as;
	l=nei[1].l,r=nei[1].r;
	t--,as++;
	for (int i=2;i<=m_1;i++)
	{
		if (nei[i].l>r||t>0)
		{
			t--,as++;
			if (nei[i].l<r)
			r=min(nei[i].r,r);
			else r=nei[i].r;
		}
	}
	return as;
} 

inline int savw(int t)
{
	int as=0,l,r;
	if (t==0) return as;
	l=wai[1].l,r=wai[1].r;
	t--,as++;
	for (int i=2;i<=m_1;i++)
	{
		if (wai[i].l>r||t>0)
		{
			t--,as++;
			if (wai[i].l<r)
			r=min(wai[i].r,r);
			else r=wai[i].r;
		}
	}
	return as;
}
// 不知为啥能做对版本 
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m_1,&m_2);
	for (int i=1;i<=m_1;i++) scanf("%d%d",&nei[i].l,&nei[i].r);
	for (int i=1;i<=m_2;i++) scanf("%d%d",&wai[i].l,&wai[i].r); 
	//读入正常
	int ans=0;
	for (int i=0;i<=n;i++)
	ans=max(ans,savn(i)+savn(n-i)); 
	
	printf("%d\n",ans);
	return 0;
} 
