#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
struct abc{
	ll s,e;
}a1[1000005],a2[1000005];
bool cmp(abc a,abc b)
{
	return a.s<b.s;
}
ll st1[100005]={0},st2[100005]={0},n,a=0,b=0,k,f1,f2,minn,m1,sum1,sum2,m2,ans = 0;
int main()
{
	freopen("airport1.in","r",stdin);
	freopen("airport1.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a1[i].s>>a1[i].e;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>a2[i].s>>a2[i].e;
	}
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		a=0,b=0;
		k=n-i;
		minn = 2147483647;
		for(int j=1;j<=m1;j++)
		{
		    for(int ii=1;ii<=i;ii++)
		    {
		    	if(st1[ii]<=minn)
		    	{
		    		minn = st1[ii];
		    		f1 = ii;
				}
			}
			if(st1[f1]<a1[j].s)
		    {
		    	st1[f1]=a1[j].e;
		    	a+=1;
			}
		}
		minn = 2147483647;
		for(int j=1;j<=m2;j++){
			for(int jj=1;jj<=k;jj++)
			{
				if(st2[jj]<=minn)
				{
					minn = st2[jj];
					f2 = jj;
				}
			}
			if(st2[f2]<a2[j].s)
		    {
		    	st2[f2] = a2[j].e;
		    	b+=1;
			}	
		}
		if(a+b>ans)ans=a+b;
	}
	cout<<ans;
    fclose(stdin);
	fclose(stdout);
	return 0;
}

