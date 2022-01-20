#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	
	int n,mn,mw;
	cin>>n>>mn>>mw;  
	   // n廊桥的个数、mn国内、mw国际
	
	
	int sk[mn+mw][2];
	for (int i=1;i<=mn+mw;i++)
	{
		cin>>sk[i][1]>>sk[i][2];
	}
     // 输入完毕
   
   
   
    int latest=sk[1][2];
	for (int i=2;i<=mn+mw;i++)
	{
		
		if (latest<sk[i][2])
		{
			latest=sk[i][2];
		}
	}
	int time=latest; 
	
	//时间轴建立
	int bn,bw;
	bn=n+1;
	bw=-1;
	
	int bnm[n+1];
	int bn1;
	int bw1;
	
	for (int i=1;i<=n+1;i++)
	{
		bnm[i]=0;
	}
	
	int bnm1[n+1];
	
	for (int i=1;i<=n+1;i++)
	{
		bnm1[i]=0;
	}
	
	
	
	
	
	int xk[mn+mw];
	for (int i=1;i<=mn+mw;i++)
	{
		xk[i]=0;
	}
	
	for (int i=1;i<=n+1;i++)          //b fen pei fang shi
	{
		bn=bn-1;
		bw=bw+1;
		bn1=bn;
		bw1=bw;
		
	
	
	for (int j=1;j<=time;j++)                //shi jian
		{
			for (int gn=1;gn<=mn;gn++)
			{
				if (sk[gn][1]==j&&bn1!=0)          //进 
				{
					bn1=bn1-1;
					bnm1[i]=++bnm1[i];
				    xk[gn]=1;
				}
				if (sk[gn][2]==j&&xk[gn]==1)                    //chu
				{
					bn1=bn1+1;
					
				}
			}
			for (int gw=mn+1;gw<=(mn+mw);gw++)          
			{
				if (sk[gw][1]==j&&bw1!=0)                 //jin
				{
					bw1=bw1-1;
					bnm[i]=++bnm[i];
					xk[gw]=1;
					
				}
				
				if (sk[gw][2]==j&&xk[gw]==1)                            //chu
				{
					bw1=bw1+1;
					
				}
			}
		
			
		}
		
		
		
	

	  
	
	
	}
	int jg[n+1];
	
	
	for (int i=1;i<=n+1;i++)
	{
		jg[i]=bnm[i]+bnm1[i];
	}
	
	
	int max=0;
	for (int i=1;i<=n+1;i++)
	{
		if (max<jg[i])
		{
			max=jg[i];
		}
	}
	cout<<max;
	
	




	
	return 0;
	}
