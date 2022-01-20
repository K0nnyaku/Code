#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<cstdlib>
#define ll long long
using namespace std;
ll n,a[2008007],b[2008007],c[2008007];
int main()
{
	freopen("conv.in","r",stdin);
	freopen("conv.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=0;i<n;i++)
	scanf("%lld",&a[i]);
	for(ll j=0;j<n;j++)
	scanf("%lld",&b[j]);
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		c[i]=max(c[i],a[j]+b[(i-j+n)%n]);
	}
	for(ll i=0;i<n;i++)
	printf("%lld ",c[i]);
	return 0;
}
