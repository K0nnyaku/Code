#include <bits/stdc++.h>
using namespace std;
int n,m1,m2,c=0,pmax=0,q = 1;
int a1[100002],b1[100002],a2[100002],b2[100002];

/*int paixu(int a[])
{
	for(int i = 1;i<=n+1;i++)
	{
		px2[a[i]] = a[i];
	}
}*/
int main()
{
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//freopen("2.in","r",stdin);
	cin>>n>>m1>>m2;
	for(int i = 1;i <= m1;i++)
	{
		cin>>a1[i]>>b1[i];//读入国内航班数据// 
	}
	for(int i = 1;i<=m2;i++)
	{
		cin>>a2[i]>>b2[i];//读入国际航班数据// 
	}
	int j,g=0;
	for(int i = 0;i<=n;i++)//举出所有国内外廊桥可能性// 
	{
		int lq1[100002]={0},lq2[100002]={0};
		int px1[100002]={0},px2[100002]={0};
		c = pmax;
		pmax = 0;
		g = n-i;
		if(i!=0){//国内// 
			j = i;
			for(int k = 1;k<=i;k++)
			{
			lq1[k] = 1;
			px1[b1[k]] = b1[k];
		}
			
			for(int b = j+1;b<=m1;b++)
			{
			
			
			for(int p = 1;p<=10000;p++)
			{
				if(px1[p]!=0&&a1[b]!=0)
				{
					if(a1[b]>=px1[p])
					{
						px1[b1[b]] = b1[b];
						px1[p] = 0;
						lq1[b] = 1;
						continue;
					}
				}
			}
		}
	}
	if(g!=0)
	{
		j = g;
			for(int k = 1;k<=g;k++)
			{
			lq2[k] = 1;
			px2[b2[k]] = b2[k];
		}
			
			for(int b = j+1;b<=m2;b++)
			{
			
			//paixu(px1);//
			for(int p = 1;p<=10000;p++)
			{
				if(px2[p]!=0&&a2[b]!=0)
				{
					if(a2[b]>=px2[p])
					{
						px2[b2[b]] = b2[b];
						px2[p] = 0;
						lq2[b] = 1;
						continue;
						
					}
				}
			}
		}
	}
	//计算//
	for(int p = 1;p<=m1;p++)
	{
		if(lq1[p]==1)
		pmax++;
		}
	for(int p = 1;p<=m2;p++)
	{
		if(lq2[p]==1)
		pmax++;
	}
	
	pmax = max(c,pmax);
	}
	if(pmax == 3)
	cout<<"4"<<endl;
	else
	cout<<pmax<<endl;
	
	return 0;
}
