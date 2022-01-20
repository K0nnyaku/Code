#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAXN 100005
using namespace std;
//不开long long见祖宗！！！
//别紧张，放松。 
long long n,m1,m2;
struct plane{
	long long a;
	long long b;
};
plane c1[MAXN],c2[MAXN];
long long gn[MAXN],gj[MAXN];
long long ngn[MAXN],ngj[MAXN];
long long sum,num,p=1,maxx;
bool cmp(plane x,plane y)
{
	if(x.a>y.a) return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	 scanf("%lld%lld",&c1[i].a,&c1[i].b);
	for(int i=1;i<=m2;i++)
	 scanf("%lld%lld",&c2[i].a,&c2[i].b);
	sort(c1+1,c1+m1+1,cmp);
	sort(c2+1,c2+m2+1,cmp);
	while(sum!=n)
	{
		sum++;
		for(int i=p;i<=m1;i++)
		{
			if(c1[i].a>=ngn[sum])
			{
				ngn[sum]=c1[i].b;
				gn[sum]++;
				c1[i].a=0;
				p++;
			}
		}
		gn[sum]+=gn[sum-1];
		sort(c1+1,c1+m1+1,cmp);
	}
	p=1;
	while(num!=n)
	{
		num++;
		for(int i=p;i<=m2;i++)
		{
			if(c2[i].a>=ngj[num])
			{
				ngj[num]=c2[i].b;
				gj[num]++;
				c2[i].a=0;
				p++;
			}
		}
		gj[num]+=gj[num-1];
		sort(c2+1,c2+m2+1,cmp);
	}
	for(int i=0;i<=n;i++)
	{
		maxx=max(maxx,gn[i]+gj[n-i]);
	}
	printf("%lld",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

