#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
int n,m1,m2,flag1=1,flag2=1,cnt1,cnt2,in=1,out=1,vis1[1000001],vis2[1000001],temp,sum1[1000001],sum2[1000001],ans;
struct node1{
	int arrive,leave,data;
}a1[1000001];
struct node2{
	int arrive,leave,data;
}a2[1000001];
bool cmp1(node1 x,node1 y)
{
	return x.arrive<y.arrive;
}
bool cmp2(node2 x,node2 y)
{
	return x.arrive<y.arrive;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
 	cin>>n>>m1>>m2;
 	for(int i=1;i<=m1;i++)
	cin>>a1[i].arrive>>a1[i].leave;
	for(int i=1;i<=m2;i++)
	cin>>a2[i].arrive>>a2[i].leave;
	sort(a1+1,a1+1+m1,cmp1);
	sort(a2+1,a2+1+m2,cmp2);
	a1[1].data=1;sum1[1]=1;temp=1;
	while(temp<=m1)
	{
		flag1=temp;cnt1=flag1+1;
		if(vis1[flag1]==1)
		{
			temp++;
			continue;
		}
		while(cnt1<=m1)
		{
			if(vis1[cnt1]==0&&a1[cnt1].arrive>a1[flag1].leave)
			{
				a1[cnt1].data=in;
				vis1[cnt1]=1;
				flag1=cnt1;
				sum1[in]++;
			}
			cnt1++;
		}
		sum1[in]=sum1[in]+sum1[in-1];
		vis1[temp]=1;a1[temp].data=in;
		temp++;in++;sum1[in]=1;
	}
	for(int i=in;i<=n;i++)
	sum1[i]=sum1[in-1];
	a2[1].data=1;temp=1;sum2[1]=1;
	while(temp<=m2)
	{
		flag2=temp;cnt2=flag2+1;
		if(vis2[flag2]==1)
		{
			temp++;
			continue;
		}
		while(cnt2<=m2)
		{
			if(vis2[cnt2]==0&&a2[cnt2].arrive>a2[flag2].leave)
			{
				a2[cnt2].data=out;
				vis2[cnt2]=1;
				flag2=cnt2;
				sum2[out]++;
			}
			cnt2++;
		}
		sum2[out]=sum2[out]+sum2[out-1];
		vis2[temp]=1;a2[temp].data=out;
		temp++;out++;sum2[out]=1;
	}
	for(int i=out;i<=n;i++)
	sum2[i]=sum2[out-1];
	for(int i=0;i<=n;i++)
	ans=max(ans,sum1[i]+sum2[n-i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

