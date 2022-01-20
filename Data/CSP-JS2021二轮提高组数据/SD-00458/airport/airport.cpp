#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int ans[1000001];
int n,cn,abr;
struct sjg
{
	int lai,qu;
}fj1[1000001],fj2[1000001];
int go[1000001],go2[10000001]; 
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>cn>>abr;
	for(int i=1;i<=cn;i++) 
	{
		cin>>fj1[i].lai>>fj1[i].qu;
	}
	for(int i=1;i<=abr;i++) 
	{
		cin>>fj2[i].lai>>fj2[i].qu;
	}
	if(n>=cn+abr)
	{
		cout<<cn+abr;
		return 0;
	}
	for(int i=1;i<=cn;i++)
	{
		for(int j=i+1;j<=cn;j++)
		{
			if(fj1[i].lai>fj1[j].lai)
			{
				swap(fj1[i].lai,fj1[j].lai);
				swap(fj1[i].qu,fj1[j].qu);
			}
		}
	}
	for(int i=1;i<=abr;i++)
	{
		for(int j=i+1;j<=abr;j++)
		{
			if(fj2[i].lai>fj2[j].lai)
			{
				swap(fj2[i].lai,fj2[j].lai);
				swap(fj2[i].qu,fj2[j].qu);
			}
		}
	}/////////////////////////////////////////////////////////
	for(int nei=0;nei<=n;nei++)//国内栈桥数量 
	{
		int wai=n-nei;//国外栈桥数量 
		int zhanqiao=0,zhanqiao2=0;
		int cnt1=0,cnt2=0;
		memset(go,0,sizeof(go));
		memset(go2,0,sizeof(go2));
		for(int j=1;j<=cn;j++)//这个飞机 
		{
		
			//go[j]=fj1[j].qu;//前面有cnt-1个飞机离开时间 
			for(int i=1;i<=cnt1;i++)
			{
				if(go[i]<fj1[j].lai)//现在时间是这次飞机来的时间，前面的飞机该走的飞走 
				{
					zhanqiao--; //走了，少一个栈桥 
					go[i]=100000002;
				}
				
			}
			zhanqiao++;//需要再来一个 
			if(zhanqiao<=nei)
			{
                ans[nei+1]++;
                go[++cnt1]=fj1[j].qu;//这个飞机停在桥上 
			}
			else zhanqiao--;
		} 
	
	for(int j=1;j<=abr;j++)//每个飞机 
	{
		//go2[j]=fj2[j].qu;
		for(int i=1;i<=cnt2;i++)
		{
			
			if(go2[i]<fj2[j].lai)//现在时间是这次飞机来的时间，前面的飞机该走的飞走 
			{
				zhanqiao2--; 
				go2[i]=100000002;//走了 
			}
				
		} 
		zhanqiao2++;//需要再来一个 
		if(zhanqiao2<=wai)
			{
				ans[nei+1]++;go2[++cnt2]=fj2[j].qu;
			}
			else zhanqiao2--;
		
	}

	}
	sort(ans+1,ans+1+n+1);
	cout<<ans[n+1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
