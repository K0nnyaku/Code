#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans=0;
struct node{
	int x,y;
}gn[100100],gw[100100];
int in1[100100]={0},in2[100100]={0};
int vis1[100100],vis2[100100];
int cmp(node x,node y)
{
	return x.x<y.x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>gn[i].x>>gn[i].y;
	} 
	for(int i=1;i<=m2;i++)
	{
		cin>>gw[i].x>>gw[i].y;
	}
	if(n<=700)
	{
		sort(gn+1,gn+1+m1,cmp);
		sort(gw+1,gw+1+m2,cmp);
		for(int i=0;i<=n;i++)//¹úÄÚÃû¶î 
		{
			memset(in1,0,sizeof(in1));
			memset(in2,0,sizeof(in2));
			int tot1=0,ans1=0;
			for(int j=1;j<=m1;j++)
			{
				tot1=0;
				for(int k=1;k<j;k++)
				{
					if(gn[k].x<gn[j].x&&gn[j].x<gn[k].y&&in1[k]==1)tot1++;		
				}
				if(tot1<i){
			    	in1[j]=1;
			    	ans1++;
				}
			}
			int tot2=0,ans2=0;
			for(int j=1;j<=m2;j++)
			{
				tot2=0;
				for(int k=1;k<j;k++)
				{
					if(gw[k].x<gw[j].x&&gw[j].x<gw[k].y&&in2[k]==1)tot2++; 
				}
				if(tot2<n-i){
					in2[j]=1;
					ans2++;
				}
			}
			ans=max(ans,ans1+ans2);	
		}
		cout<<ans<<endl;
		return 0;
	}
	
	if(n<=5000)
	{
		sort(gn+1,gn+1+m1,cmp);
		sort(gw+1,gw+1+m2,cmp);
		int ans1[100100]={0},ans2[100100]={0};
		for(int i=1;i<=n;i++)
		{
			int ri=0;
			for(int j=1;j<=m1;j++)
			{
				if(gn[j].x>ri&&vis1[j]==0)
				{
					ri=gn[j].y;
					vis1[j]=1;
					ans1[i]++;
				}
			}
			ans1[i]+=ans1[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			int ri=0;
			for(int j=1;j<=m2;j++)
			{
				if(gw[j].x>ri&&vis2[j]==0)
				{
					ri=gn[j].y;
					vis2[j]=1;
					ans2[i]++;
				}
			}
			ans2[i]+=ans2[i-1];
		}
		for(int i=0;i<=n;i++)
		{
			ans=max(ans,ans1[i]+ans2[n-i]);
		}
		cout<<ans;
    }
	fclose(stdin);
	fclose(stdout); 
	return 0;
}/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10


4

*/
