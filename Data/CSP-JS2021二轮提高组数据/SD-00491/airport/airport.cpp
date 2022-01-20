#include<bits/stdc++.h>
using namespace std;
long long a[1001],b[1001],c[1001],d[1001],e[1001],f[1001],g[1001],h[1001],tail[1001];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i,j,n,m1,m2,k=0,w,z=0,first=1,end=0;
	cin>>n>>m1>>m2;
	for(i=1;i<=m1;i++)
	{
		cin>>a[i]>>b[i];
		e[i]=a[i];g[i]=b[i];
	}
	for(i=1;i<=m2;i++)
	{
		cin>>c[i]>>d[i];
		f[i]=c[i];h[i]=d[i];
	}
	sort(a+1,a+m1+1);
	sort(c+1,c+m2+1);
	for(i=1;i<=m1;i++)
	{
		for(j=1;j<=m1;j++)
		{
			if(e[j]==a[i]) g[j]=b[i];
		}
	}
	for(i=1;i<=m2;i++)
	{
		for(j=1;j<=m2;j++)
		{
			if(f[j]==c[i]) h[j]=d[i];
		}
	}
	int ans1=0,ans2=0;
	for(i=0;i<=n;i++)
	{
		first=1;end=0;
		ans1=0;w=i;k=n-i;
		for(j=1;j<=m1;j++)
		{
			if(a[j]>=tail[first]&&end>=first) 
			{first++;w++;}
			if(w>0)
			{
				ans1++;
				w--;
				end++;
				tail[end]=g[j];
			}
		}
		first=1;end=0;
		for(j=1;j<=m2;j++)
		{
			if(c[j]>=tail[first]&&end>=first) 
			{first++;k++;
			}
			if(k>0)
			{
				ans1++;
				k--;
				end++;
				tail[end]=h[j];
			}
		}
	   if(ans1>=ans2) ans2=ans1;						
	}
	cout<<ans2; 
	return 0;

	
	
}
