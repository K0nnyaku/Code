#include<bits/stdc++.h>
using namespace std;
struct h{
	int lai;
	int zou; 
}guohang[150000];
struct k{
	int dao;
	int qu;
}interhang[150000];
int zong;
//yaobao0le no no no
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=0,m_1=0,m_2=0,j=0,zong=0,maxn=-1,hxd=0;
	int guobj=0,interbj=0;//baka
	cin>>n>>m_1>>m_2;
	for(int i=1;i<=m_1;i++)
	{
		cin>>guohang[i].lai>>guohang[i].zou;
	}
	for(int i=1;i<=m_2;i++)
	{
		cin>>interhang[i].dao>>interhang[i].qu;
	}//cin 
	
	for(int i=0;i<=n;i++)//guonei langqiaoshu
	{
	    hxd=i;
		j=n-i;//inter langqiaoshu
		for(int p=1;p<=i;p++)//guonei hangban bianli
		{	
		if(i!=0)//
		{
			for(int c=guohang[1].lai;c<=guohang[m_1].lai;c++)//timebianli
			{
				for(int s=1;s<=m_1;s++)//1
				{
					if(guohang[s].zou==c)
					{
						guobj--;
					}
				}
				//腾出位子，好耶 
			    if(guobj!=i&&guohang[p].lai==c)//2 
			    {
			    	guobj++;
			    	 
			    	zong++;
				}	
			}
		}//
	    }
	
		for(int q=1;q<=j;q++)//guoji hangban
		{
		hxd=i;
		if(j!=0)
		{//
			for(int c=interhang[1].dao;c<=interhang[m_2].dao;c++)//timebianli
			{
				for(int s=1;s<=m_2;s++)//1
				{
					if(interhang[s].qu==c)
					{
						interbj--;
					}
				}
				//腾出位子，好耶 
			    if(interbj!=i&&interhang[q].dao==c)//2 
			    {
			    	interbj++;
			    	
			    	zong++;
				}	
			}
		}// 
		}
		if(zong>maxn)
		{
		maxn=zong;
		zong=0;
	}
	}//一.暴力算各情况总机数 储存于zong 
	
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
	return 0;
} 
