#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m1,m2,ans1=1,ans2=1;
ll c[100001],d[100001];
ll a[100001],b[100001];
ll zou1,zou2;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++)
	{
		a[i]=read();
		zou1=read();
		c[a[i]]=zou1;
	}
	for(int i=1;i<=m2;i++)
	{
		b[i]=read();
		zou2=read();
		d[b[i]]=zou2;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	ll bj1=c[a[1]];
	ll bj2=d[b[1]];
	for(int i=1;i<=m1;i++)
	{
		if(a[i]>bj1)
		{
			ans1++;
			bj1=c[a[i]];
		}
	}
	for(int i=1;i<=m2;i++)
	{
		if(b[i]>bj2)
		{
			ans2++;
			bj2=d[b[i]];
		}
	}
	if(n==1)
	{
		int ans=max(ans1,ans2);
		cout<<ans;
		return 0;
		fclose(stdin);
		fclose(stdout);
	}
	else
	{
		cout<<ans1+ans2+n-1;
		return 0;
		fclose(stdin);
		fclose(stdout);
	}
}

