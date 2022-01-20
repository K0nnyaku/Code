#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,a1[100001],a2[100001],b1[100001],b2[100001],c[100001]={0},d[100001]={0},c1[100001],d1[100001],ps=0;
int dfs1(int x,int j )
{
	if(x>m1)
	{
		c[j]+=ps;
		ps=0;
		return 0;
	}
	if(a1[x]<c1[1])
	{
		dfs1( x+1,j);
	}
	if(a1[x]>c1[1])
	{
		ps++;
		c1[1]=a2[x];
		for(int k=1;k<=j-1;k++)
	{
		for(int l=1;l<=j-1;l++)
		{
		if(c1[k]>c1[k+1])
		{
			swap(c1[k],c1[k+1]);
			}	
		}
	}
	dfs1(x+1,j);
}
}
int dfs2(int x,int j )
{
	if(x>m2)
	{
		d[j]+=ps;
		ps=0;
		return 0;
	}
	if(b1[x]<d1[1])
	{
		dfs1( x+1,j);
	}
	if(b1[x]>d1[1])
	{
		ps++;
		d1[1]=b2[x];
		for(int k=1;k<=j-1;k++)
	{
		for(int l=1;l<=j-1;l++)
		{
		if(d1[k]>d1[k+1])
		{
			swap(d1[k],d1[k+1]);
			}	
		}
	}
	dfs1(x+1,j);
}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","W",stdout);
	cin>>n>>m1>>m2;
	if(n>=m1+m2)
	{
		cout<<m1+m2<<endl;
		return 0; 
	}
	for(int i=1;i<=m1;i++)
	{
		cin>>a1[i]>>a2[i];
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>b1[i]>>b2[i];
	}
	for(int i=1;i<=m1-1;i++)
	{
		for(int j=1;j<=m1-1;j++)
		{
		if(a1[i]>a1[i+1])
		{
			swap(a1[i],a1[i+1]);
			swap(a2[i],a2[i+1]);
			}	
		}
	}
		for(int i=1;i<=m2-1;i++)
	{
		for(int j=1;j<=m2-1;j++)
		{
		if(b1[i]>b1[i+1])
		{
			swap(b1[i],b1[i+1]);
			swap(b2[i],b2[i+1]);
			}	
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i>=m1)
		{
			c[i]=m1;
		}
		else{
		c[i]+=i;
		for(int j=1;j<=i;j++)
		{
			c1[j]=a2[j];}
		for(int k=1;k<=i-1;k++)
	{
		for(int l=1;l<=i-1;l++)
		{
		if(c1[k]>c1[k+1])
		{
			swap(c1[k],c1[k+1]);
			}	
		}
	dfs1(i+1,i);
		}
		}
	
	}
	for(int i=1;i<=n;i++)
	{
		if(i>=m2)
		{
			d[i]=m2;
		}
		else{
		d[i]+=i;
		for(int j=1;j<=i;j++)
		{
			d1[j]=b2[j];}
		for(int k=1;k<=i-1;k++)
	{
		for(int l=1;l<=i-1;l++)
		{
		if(d1[k]>d1[k+1])
		{
			swap(d1[k],d1[k+1]);
			}	
		}
	dfs2(i+1,i);
		}
		}
	
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(c[i]+d[n-i],ans);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
