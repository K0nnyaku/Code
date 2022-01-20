#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<vector>
#include<bitset>
using namespace std;
#define re register
#define mod 998244353
#define inf 0x7f7f7f7f
#define maxn 200010
inline int read();
inline void wn(int x);
inline void wr(int x);
inline void wi(int x);
int n,a,b;
int ans;
#define P pair<int,int>
set<int>s;
struct node
{
	int l,r;
}c[maxn];
int aa[maxn],bb[maxn];
map<int,int>ll;
map<int,int>rr;
bool cmp(node x,node y)
{
	return x.l<y.l;
}
signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
//	printf("%d M",((sizeof(ll)>>20)));
	n=read(),a=read(),b=read();
	for(re int i=1;i<=a;++i)
		c[i].l=read(),c[i].r=read();
	sort(c+1,c+a+1,cmp);
	for(re int i=1;i<=a;++i)
		ll[c[i].l]=i,rr[c[i].r]=i,s.insert(c[i].l);
	set<int>::iterator it;
	for(re int i=1;i<=n;++i)
	{
		it=s.begin();
		int R=c[ll[(*s.begin())]].r;
		while(it!=s.end())
		{
			s.erase(it);
			it=s.lower_bound(R);
			aa[i]++;
			if(it==s.end())	continue;
			R=c[ll[(*it)]].r;		
		}
	}
//	for(re int i=1;i<=a;++i)	wi(aa[i]);
	s.clear();
	memset(c,0,sizeof c);
	ll.clear();
	rr.clear();
	for(re int i=1;i<=b;++i)
		c[i].l=read(),c[i].r=read();
	sort(c+1,c+b+1,cmp);
	for(re int i=1;i<=b;++i)
		ll[c[i].l]=i,rr[c[i].r]=i,s.insert(c[i].l);
	for(re int i=1;i<=n;++i)
	{
		it=s.begin();
		int R=c[ll[(*s.begin())]].r;
		while(it!=s.end())
		{
			s.erase(it);
			it=s.lower_bound(R);
			bb[i]++;
			if(it==s.end())	continue;
			R=c[ll[(*it)]].r;		
		}
	}
//	for(re int i=1;i<=a;++i)	wi(aa[i]);
	for(re int i=0;i<=n;++i)
		aa[i]+=aa[i-1];
	for(re int i=0;i<=n;++i)
		bb[i]+=bb[i-1];
	for(re int i=0;i<=n;++i)
		ans=max(ans,aa[i]+bb[n-i]);
	wr(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//======================================================
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void wn(int x)
{
	if(x<0)
	{
		putchar('-');
		wn(-x);
		return ;
	}
	if(x>=10)	wn(x/10);
	putchar(x%10+'0');
}
inline void wr(int x)
{
	wn(x);
	putchar('\n');
}
inline void wi(int x)
{
	wn(x);
	putchar(' ');
}
//=======================================
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

