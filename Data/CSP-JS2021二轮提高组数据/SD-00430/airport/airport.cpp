#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define SIZE 1000000
int n,mm1,mm2,nei[SIZE]={0},wai[SIZE]={0},aa[SIZE]={0},ans=0,maxxx=0;
void work1(int i,int j)
{
	if(j==i) return;
	for(j=j-1;j>i;j--)
	if(aa[j]>aa[j-1]) swap(aa[j],aa[j-1]);
	return;
}
int work(int k)
{
	int ana=0;
	for(int i=1;i<=n;i++) aa[i]=0;
	if(k>0)
	for(int i=1;i<=maxxx;i++)
	if(nei[i]>0)
	{
		for(int j=1;j<=k;j++)
		{
			if(aa[j]<i){aa[j]=nei[i];work1(1,j);ana++;break;}
		}
	}
	if(k<n)
	for(int i=1;i<=maxxx;i++)
	if(wai[i]>0)
	{
		for(int j=k+1;j<=n;j++)
		{
			if(aa[j]<i){aa[j]=wai[i];work1(k+1,j);ana++;break;}
		}
	}
	return ana;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>mm1>>mm2;
	for(int i=1;i<=mm1;i++)
	{
		int x,y;
		cin>>x>>y;
		nei[x]=y;
		maxxx=max(maxxx,x);
	}
	for(int i=1;i<=mm2;i++)
	{
		int x,y;
		cin>>x>>y;
		wai[x]=y;
		maxxx=max(maxxx,x);
	}
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,work(i));
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
