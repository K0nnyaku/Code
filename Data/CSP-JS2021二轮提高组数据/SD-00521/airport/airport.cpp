#include<bits/stdc++.h>
using namespace std;
long long n;//一共n个廊桥
long long m1,m2;//国内航班and国外航班
long long m1in[5005],m1out[5005];//国内航班进出时间 
long long m2in[5005],m2out[5005];//国外航班进出时间
long long vis1[5005],vis2[5005];//机位判断 
long long sum=0,gn=0,gw=0;//临时计数点 
long long ans=0;//实际计数点 
long long maxtime;
void nei(int t1,int n1)
{
	if(n1==0) return;
	for(int j=1;j<=n1;j++)//机位循环 
	{
		for(int i=1;i<=m1;i++)//飞机循环 
		{
			if(vis1[j]==t1)
			{ 
				if(vis1[j]==t1 && m1out[i-1]==t1) continue;
				vis1[j]=0;
				
			}//如果飞机飞出，机位重置 
			if(vis1[j]==0)//如果有机位 
			{
				vis1[j]=m1out[i];
				m1out[i]=t1;
				gn++;
			}
			else continue;
		}
	}
	return ;
}
void wai(int t2,int n2)
{
	if(n2==0) return;
	for(int j=1;j<=n2;j++)//机位循环 
	{
		for(int i=1;i<=m2;i++)//飞机循环 
		{
			if(vis2[j]==t2)
			{ 
				if(vis2[j]==t2 && m2out[i-1]==t2) continue;
				vis2[j]=0;
				gw++;
			}//如果飞机飞出，机位重置 
			if(vis2[j]==0)//如果有机位 
			{
				vis2[j]=m2out[i];
				m2out[i]=t2;
				
			}
			else continue;
		}
	}
	return ;
}
void time(int t,int n1)
{
	if(t==maxtime)
	{
		return;
	}
	else
	{
		
		nei(t,n1);
		wai(t,n-n1);
		time(t+1,n1)	;
	}

}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	cin>>m1in[i]>>m1out[i];
	//国内 
	for(int i=1;i<=m2;i++)
	cin>>m2in[i]>>m2out[i];
	maxtime=max(m1out[m1],m2out[m2]); 
	//国外 
	//到此为止为输入
	for(int i=0;i<=n;i++)//机位循环 
	{
	sum=gn+gw;
	ans=max(ans,sum);
	gn=0;
	gw=0;
	sum=0;
	time(1,i);
	}
	sum=gn+gw;
	ans=max(ans,sum);
	cout<<ans<<endl;
	return 0;
} 

