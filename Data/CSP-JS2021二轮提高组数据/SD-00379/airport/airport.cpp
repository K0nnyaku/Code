#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,i,j,k,y,b1,b2,b3,ans=0;
int ax=1e8+5,x=0x7f;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int a1[m1+2][2],a2[m2+2][2];
	for(i=1;i<=m1;i++)
		cin>>a1[i][0]>>a1[i][1];
	for(i=1;i<=m2;i++)
		cin>>a2[i][0]>>a2[i][1];
	int c[ax],d1[m1+2],d2[m2+2];
	memset(c,0,sizeof(c));
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
	for(i=0;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			int q=1;
			while(q)
			{
				x=0x7f;
				for(k=1;k<=m1;k++)
				if(a1[k][0]<x&&c[a1[k][0]]==0&&d1[k]==0)
				{
					x=a1[k][0];
					y=k;
				}
				if(x!=0x7f)
				{
					d1[k]++;
					for(k=x;k<=a1[y][1];k++)
						c[k]++;
				}
				else
				{
					b1++;
					q=0;
					memset(c,0,sizeof(c));
				}
			}
		}
		for(j=1;j<=n-i;j++)
		{
			int q=1;
			while(q)
			{
				x=0x7f;
				for(k=1;k<=m2;k++)
				if(a2[k][0]<x&&c[a2[k][0]]==0&&d2[k]==0)
				{
					x=a2[k][0];
					y=k;
				}
				if(x!=0x7f)
				{
					d1[k]++;
					for(k=x;k<=a2[y][1];k++)
						c[k]++;
				}
				else
				{
					b2++;
					q=0;
					memset(c,0,sizeof(c));
				}
			}
		}
		b3=b1+b2;
		if(b3>ans)
			ans=b3;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
