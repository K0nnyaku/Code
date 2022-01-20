#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int ans=0,tt,s,n,m1,m2,g0,g1,gn[100005][2],gw[100005][2],c[100005],d[100005],min;
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
	{
		cin>>gn[i][0]>>gn[i][1];
		for(int j=0;j<i;j++)
		{
			if(gn[i][0]<gn[j][1])
			{
				g0=gn[i][0],g1=gn[i][1];
				for(int t=i;t>j;t--)
					gn[t][0]=gn[t-1][0],gn[t][1]=gn[t-1][1];
				gn[j][0]=g0,gn[j][1]=g1;
			}	
		}
	}
	for(int i=0;i<m2;i++)
	{
		cin>>gw[i][0]>>gw[i][1];
		for(int j=0;j<i;j++)
		{
			if(gw[i][0]<gw[j][1])
			{
				g0=gw[i][0],g1=gw[i][1];
				for(int t=i;t>j;t--)
					gw[t][0]=gw[t-1][0],gw[t][1]=gw[t-1][1];
				gw[j][0]=g0,gw[j][1]=g1;
			}	
		}
	}
	for(int i=0;i<=n;i++)
	{
		s=n;
		for(int j=0;j<m1;j++)
		{
			if(j<i) c[j]=gn[j][1];
			else
			{
				tt=100000;
				min=c[0];
				for(int t=0;t<i;t++)
				{
					if(gn[j][0]>c[t])
					{
						if(c[t]<=min) 
						{
							tt=t;
							min=c[t];	
						}	
					}
				}
				if(tt!=100000)
					{
						c[tt]=gn[j][1];
						s++;
					}
			}
		}
		for(int j=0;j<m2;j++)
		{
			if(j<n-i) d[j]=gw[j][1];
			else
			{
				tt=100000;
				min=d[0];
				for(int t=0;t<n-i;t++)
				{
					if(gw[j][0]>c[t])
					{ 
						if(d[t]<=min) 
						{
							tt=t;
							min=d[t];	
						}	
					}
				}
				if(tt!=100000)
				{
					d[tt]=gw[j][1];
					s++;
				}
			}
		}
		if(ans<s) ans=s;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
