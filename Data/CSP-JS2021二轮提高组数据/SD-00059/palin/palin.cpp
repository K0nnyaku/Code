#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10000001];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			cout<<"L";
		}
		for(int i=1;i<=n;i++)
		{
			cout<<"R";
		}
	}
}
