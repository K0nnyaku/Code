#include<bits/stdc++.h>
using namespace std;
long long n,m1,m2;
long long a[101000]={0},ai=1,b[101000]={0},bi=1;
long long ad[101000]={0},az=-1,bd[101000]={0},bz=-1;
long long ans=0;
int main()
{
	long long q,p;
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
	{
		cin>>q>>p;
		ai=1;
		while(q<ad[ai])
		{
			ai++;
		}
		az=max(az,ai);
		ad[ai]=p;
		a[ai]++;
	}
	for(int i=0;i<m2;i++)
	{
		cin>>q>>p;
		bi=1;
		while(q<bd[bi])
		{
			bi++;
		}
		bz=max(bz,bi);
		bd[bi]=p;
		b[bi]++;
	}
	if(az>n)
	{
		az=n;
	}
	if(bz>n)
	{
		bz=n;
		b[bz+1]=0;
	}
	for(int i=1;i<=az;i++)
	{
		a[i]+=a[i-1];
	}
	for(int i=bz;i>0;i--)
	{
		b[i]+=b[i+1];
	}
	ans=b[1];
	for(int i=1;i<=az;i++)
	{
		if(bz-i+1<0)
		{
			break;
		}
		ans=max(ans,a[i]+b[1]-b[bz-i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
