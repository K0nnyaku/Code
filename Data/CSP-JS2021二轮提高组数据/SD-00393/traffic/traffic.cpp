#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	long long n,l,r,ans=-1000,a,b;
	cin>>n>>l>>r;
	for(int i=l;i<=r;i++)
	{
		b=i%n;
		ans=max(ans,b);
	}
	cout<<ans;
	return 0;
}
