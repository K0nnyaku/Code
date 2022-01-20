#include<iostream> 
#include<cstdio>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;//n是廊桥总数，m是国内航班数量，k是国际航班数量 
	int ans[n+1];//记录每一种分配方案可以通过的飞机数量。 
	int a[m+1][2],b[k+1][2];//用于输入每个航班的情况 
	int mtot=0,ktot=n;//mtot是国内廊桥个数，初始为0，mtot是国际廊桥个数，初始为n，就是先把廊桥分给国际区 
	for(int i=1;i<=m;i++) 
	{
		cin>>a[i][1]>>a[i][2];//输入国内航班情况 
	}
	for(int i=1;i<=k;i++) 
	{
		cin>>b[i][1]>>b[i][2];//输入国际航班情况 
	}
	for(int i=1;i<=n;i++)//循环i次，把所有情况全算一遍 
	{
	    for(int i=1;i<=m;i++) //判断国内航班 
	    {
		    if(mtot==0)//如果不分配廊桥 
		    {
			    mtot++;//下一种情况 
			    continue;
		    }
		    if(mtot>=m) //如果廊桥数量大于等于飞机数量 
		    {
			    ans[i]+=m;
			    mtot++; 
			    continue;
		    }
		    for(int j=1;j<=m;j++)
		    {
			    if(j>mtot)
			    {
			        for(int l=1;l<=mtot;l++)
			        {
			    	    if(a[l][2]<=a[j][1])//如果到达时间大于离开时间2
			    	    {
			    	        ans[i]++;
			    		    continue; 
			    	    }
			        }
			   }
			   if(j<=mtot)
			   {
				    ans[i]++;
				    continue;
			   }
		    }
	    }
		mtot++;	
	}
	for(int i=1;i<=n;i++)//循环i次，把所有情况全算一遍 
	{
	    for(int i=1;i<=k;i++) //判断国际航班 
	    {
		    if(ktot==0)//如果不分配廊桥 
		    {
			    ktot++;//下一种情况 
			    continue; 
		    }
		    if(ktot>=k) //如果廊桥数量大于等于飞机数量 
		    {
			    ans[i]+=k;
			    ktot++; 
			    continue;
		    }
		    for(int j=1;j<=k;j++)
		    {
			    if(j>ktot)
			    {
			        for(int l=1;l<=ktot;l++)
			        {
			    	    if(b[l][2]<=b[j][1])//如果到达时间大于离开时间
			    	    {
			    	        ans[i]++;
			    		    continue; 
			    	    }
			        }
			   }
			   if(j<=ktot)
			   {
				    ans[i]++;
				    continue;
			   }
		    }
	    }
		ktot++;	
	}
	for(int i=1;i<n+1;i++)
	{
		if(ans[i]>=ans[i+1])
		{
			int temp=0;
			temp=ans[i];
			ans[i]=ans[i+1];
			ans[i+1]=temp;
		}
	}
	cout<<ans[n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
