#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#define ll long long

inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

const ll maxn=2e5+10;
ll n,m1,m2,tot,maxx1,maxx2,ans;
ll a[maxn],b[maxn<<3];
std::multiset<ll> s;
struct Seg
{
	ll l,r;
	
	inline bool operator < (const Seg &a) const
	{
		return (this->l==a.l) ? (this->r<a.r) : (this->l<a.l);	
	}
} s1[maxn],s2[maxn];

struct Cmp
{
	inline bool operator () (ll x,ll y) const
	{
		return x>y;
	}
};

std::priority_queue<ll,std::vector<ll>,Cmp> q;

inline ll check(ll x)
{
	ll now=1,ret1=0,ret2=0,sum=0;
	for(int j=1;j<=maxx1;j++)
	{
		while(q.size()&&q.top()<=j) sum--,q.pop();
		while(s1[now].l<=j&&now<=m1)
		{
			if(sum!=x) ret1++,sum++,q.push(s1[now].r);
			now++;
		}
	}
	while(q.size()) q.pop();
	now=1,sum=0;
	for(int j=1;j<=maxx2;j++)
	{
		while(sum&&q.top()<=j) sum--,q.pop();
		while(s2[now].l<=j&&now<=m2)
		{
			if(sum!=n-x) ret2++,sum++,q.push(s2[now].r);
			now++;
		}
	}
	
	return ret1+ret2;
}

int main(void)
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
	{
		s1[i].l=read(),s1[i].r=read();
		b[++tot]=s1[i].l,b[++tot]=s1[i].r;
	}
	for(int i=1;i<=m2;i++)
	{
		s2[i].l=read(),s2[i].r=read();
		b[++tot]=s2[i].l,b[++tot]=s2[i].r;
	}
	std::sort(s1+1,s1+m1+1);
	std::sort(s2+1,s2+m2+1);
	std::sort(b+1,b+tot+1);
	for(int i=1;i<=m1;i++)
	{
		s1[i].l=std::lower_bound(b+1,b+tot+1,s1[i].l)-b;
		s1[i].r=std::lower_bound(b+1,b+tot+1,s1[i].r)-b;
	}
	for(int i=1;i<=m2;i++)
	{
		s2[i].l=std::lower_bound(b+1,b+tot+1,s2[i].l)-b;
		s2[i].r=std::lower_bound(b+1,b+tot+1,s2[i].r)-b;
	}
	memset(b,0,sizeof(b));
	for(int i=1;i<=m1;i++) a[i]=s1[i].l,maxx1=std::max(s1[i].r,maxx1);
//	putchar(10);
	for(int i=1;i<=m2;i++) b[i]=s2[i].l,maxx2=std::max(maxx2,s2[i].r);
//	putchar(10);
//	puts("qwq");
	if(n<=5000&&(m1+m2<=5000))
	{
		for(int i=1;i<=n;i++)
		{
			ll now=1,ret1=0,ret2=0,sum=0;
	//		printf("%d\n",i);
			for(int j=1;j<=maxx1;j++)
			{
	//			printf("%d ",j);
	//			ll tmp=0;
	//			if(q.size()) tmp=q.top();
	//			printf("%lld\n",tmp);
				while(q.size()&&q.top()<=j) sum--,q.pop();
				while(s1[now].l<=j&&now<=m1)
				{
					if(sum!=i) ret1++,sum++,q.push(s1[now].r);
					now++;
				}
			}
	//		printf("%lld\n",ret1);
	//		puts("qwq");
			while(q.size()) q.pop();
			now=1,sum=0;
			for(int j=1;j<=maxx2;j++)
			{
				while(sum&&q.top()<=j) sum--,q.pop();
				while(s2[now].l<=j&&now<=m2)
				{
					if(sum!=n-i) ret2++,sum++,q.push(s2[now].r);
					now++;
				}
			}
	//		printf("%lld %lld\n",ret1,ret2);
			ans=std::max(ans,ret1+ret2);
	//		printf("%d %lld\n",i,ret1+ret2);
		}
		printf("%lld\n",ans);
	}
	else
	{
		ll l=0,r=n;
		ll mid1=0,mid2=10;
		while(mid2-mid1>1)
		{
			mid1=(2*l+r)/3;
			mid2=(l+2*r)/3;
//			printf("%lld %lld %lld %lld\n",mid1,mid2,check(mid1),check(mid2));
//			ll sum=std::abs(check(mid1)-check(mid2));
			if(check(mid1)<check(mid2))
			{
	//			if(sum>2) l=mid1;
	//			else l++;
				l=mid1;
			}
			else if(check(mid1)>check(mid2))
			{
	//			if(sum>2) r=mid2;
	//			else r--;
				r=mid2;
			}
			else l=mid1;
		}
		printf("%lld\n",std::max({check(l),check(r),check(mid1),check(mid2)}));
	}
	return 0;
}
