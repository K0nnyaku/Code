#include<iostream>
#include<cstdio>
using namespace std;
int a1[100000],b1[100000],a2[100000],b2[100000];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i,j,k,l,n,m1,m2,s1=0,s2=0,s=0,nei,wai,weishu[100000]={0},z1[100000]={0},z2[100000]={0};
	cin>>n>>m1>>m2;
	for(i=1;i<=m1;i++)
	{
		cin>>a1[i]>>b1[i];//国内 
	}
	for(i=1;i<=m2;i++)
	{
		cin>>a2[i]>>b2[i];//国外 
	}
	for(i=0;i<=n;i++)
	{
		nei=i;
		wai=n-i;//内外廊桥分配
		for(j=1;j<=m1;j++)
		{
			
				for(k=a1[j];k<=b1[j];k++) //国内
				{
					weishu[k]=weishu[k]+1;//标记时间内的数 
				}
				for(k=a1[j];k<=b1[j];k++)
				{
					if(weishu[k]>nei)
					{
						for(l=a1[j];l<=b1[j];l++)
						{
							weishu[l]=weishu[l]-1;
						}
					}	
					break;
				}
				s1=s1+1;//计数
				z1[i]=s1;
				
		}
 
		for(j=1;j<=m2;j++)
		{
			
				for(k=a2[j];k<=b2[j];k++) //国外 
				{
					weishu[k]=weishu[k]+1;//标记时间内的数 
				}
				for(k=a2[j];k<=b2[j];k++)
				{
					if(weishu[k]>wai)
					{
						for(l=a2[j];l<=b2[j];l++)
						{
							weishu[l]=weishu[l]-1;
						}
					}	
					break;
				}
				s2=s2+1;//计数
				z2[i]=s2;
				
		}
	}
	for(i=0;i<=n;i++)
	{
	cout<<z1[i]+z2[i]-2<<" ";
	break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
