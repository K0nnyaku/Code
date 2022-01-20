#include<bits\stdc++.h>
using namespace std;
const int MAXN=100007;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,zong,ans=1;
	int ar1[MAXN]={0};
	int ar2[MAXN]={0};
	scanf("%d%d%d",&n,&m1,&m2);
	zong=m1+m2; 
	for(int i=1;i<=zong+1;i++)
	{
		if(i==(m1+1))
		{
			ar1[i]=0;
			ar2[i]=0;
			continue;
		}
		cin>>ar1[i]>>ar2[i];
	}
	if(n%2==0)
	{
		for(int i=0;i<=n;i++)
		{
			int zhan=i-1;
			if(i==0)continue;
			for(int j=2;j<m1;j++)
			{
				for(int k=1;k<i;k++)
				{
					if(((ar1[k]<ar1[j]) or(ar1[k]>ar1[j] and zhan!=0)) and zhan>0) 
					{
						ans++;
						cout<<ans<<' '<<zhan<<endl;
						zhan--;
						cout<<zhan<<endl;
						break;
					}
					
				}		
			}
		}
		for(int i=n;i>=0;i--)
		{
			int zhan=i-1;
			if(i==0)continue;
			for(int j=2;j<m1;j++)
			{
				for(int k=1;k<i;k++)
				{
					if(ar1[k]<ar1[j] and zhan<i) 
					{
						zhan++;
					}
					if(((ar1[k]<ar1[j]) or(ar1[k]>ar1[j] and zhan!=0)) and zhan>0) 
					{
						ans++;
						cout<<ans<<' '<<zhan<<endl;
						zhan--;
						cout<<zhan<<endl;
						break;
					}
				}
			}
		}
		cout<<ans;
	} 
	if(n%2!=0)
	{
		for(int i=0;i<=n;i++)
		{
			int zhan=i-1;
			if(i==0)continue;
			for(int j=2;j<m1;j++)
			{
				for(int k=1;k<i;k++)
				{
					if(((ar1[k]<ar1[j]) or(ar1[k]>ar1[j] and zhan!=0)) and zhan>0) 
					{
						ans++;
						cout<<ans<<' '<<zhan<<endl;
						zhan--;
						cout<<zhan<<endl;
						break;
					}
				}	
			}
		}
		for(int i=n;i>=0;i--)
		{
			int zhan=i-1;
			if(i==0)continue;
			for(int j=m1+2;j<zong+1;j++)
			{
				for(int k=1;k<i;k++)
				{
					if(((ar1[k]<ar1[j]) or(ar1[k]>ar1[j] and zhan!=0)) and zhan>0) 
					{
						ans++;
						cout<<ans<<' '<<zhan<<endl;
						zhan--;
						cout<<zhan<<endl;
						break;
					}
				}
			}
		}
		cout<<ans;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
