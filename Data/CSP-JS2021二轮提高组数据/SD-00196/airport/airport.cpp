#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <bitset>
#include <queue>

#define I inline
#define LL long long
#define CI const int
#define Heriko return
#define Deltana 0
#define Romanno 1
#define mst(a,b) memset(a,b,sizeof(a))

using namespace std;

template<typename J>
I void fr(J &x)
{
	x=0;short f=1;char c(getchar());
	
	while(c<'0' or c>'9')
	{
		if(c=='-') f=-1;
		
		c=getchar();
	}
	
	while(c>='0' and c<='9')
	{
		x=(x<<1)+(x<<3)+(c^=48);
		c=getchar();
	}
	
	x*=f;
}

template<typename J>
I J Hmax(const J &x,const J &y) {Heriko x>y?x:y;}

CI MXX(1e5+5);

int n,m1,m2,ans;

struct Node
{
	int l,r;
	
	I bool operator < (const Node &co) const
	{
		Heriko (l==co.l)?(r<co.r):(l<co.l);
	}
}

a[MXX],b[MXX];

signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	fr(n),fr(m1),fr(m2);
	
	for(int i(1);i<=m1;++i) fr(a[i].l),fr(a[i].r);
	
	for(int i(1);i<=m2;++i) fr(b[i].l),fr(b[i].r);
	
	sort(a+1,a+1+m1);sort(b+1,b+1+m2);
	
	int cnt1(0),cnt2(0),sum1(0),sum2(0);
	
	for(int i(0);i<=n;++i)
	{
		cnt1=cnt2=sum1=sum2=0;
		priority_queue<int> q1,q2;
		
		int j(n-i);
		
		for(int k(1);k<=m1;++k)
		{
			if(!i) break;
			
			while(q1.size() and (-1*q1.top())<a[k].l and cnt1)
			{
				q1.pop();--cnt1;
			}
			
			if(cnt1<i) 
			{
				q1.push(-1*a[k].r);
				++sum1,++cnt1;
			}
		}
		
		for(int k(1);k<=m2;++k)
		{
			if(!j) break;
			
			while(q2.size() and (-1*q2.top())<b[k].l and cnt2)
			{
				q2.pop();--cnt2;
			}
			
			if(cnt2<j) 
			{
				q2.push(-1*b[k].r);
				++sum2,++cnt2;
			}
		}
		
		ans=Hmax(ans,sum1+sum2);
	}
	
	printf("%d\n",ans);
	
	Heriko Deltana;
}
