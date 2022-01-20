#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,m1,m2;
struct Node{
	int t;
	bool p;
}Map1[N],Map2[N];
int ans;
bool cmp(Node a,Node b)
{
	return a.t<b.t; 
} 
int main()
{
	//左右大马猴 保佑不爆零 
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	m1*=2,m2*=2;
	ans=0x3f3f3f3f;
	for(int i=1;i<=m1;i++)
	{
		scanf("%d",&Map1[i].t);
		Map1[i].p=(i%2==0);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d",&Map2[i].t);
		Map2[i].p=(i%2==0);
	}
	sort(Map1+1,Map1+m1+1,cmp);
	sort(Map2+1,Map2+m2+1,cmp);
	int R=0,L=n,Nowval=0;
	for(int i=1;i<=m1;i++)
	{
		if(Map1[i].p)
			Nowval--;
		else
			Nowval++;
		R=max(Nowval,R);
	}
	Nowval=m2;
	for(int i=1;i<=m2;i++)
	{
		if(Map2[i].p)
			Nowval++;
		else
			Nowval--;
		L=min(Nowval,L);
	}
	int L114514=min(R,min(L,n)),R114514=min(R,n);
	for(int i=L114514;i<=R114514;i++)
	{
		int j=n-i;
		int NowNum=0,val=0;
		for(int k=1;k<=m1;k++)
		{
			if(Map1[k].p&&val)
				val--;
			else if(!Map1[k].p)
			{
				if(val+1<=i)
					val++;
				else
					NowNum++;
			}
		}
		val=0;
		for(int k=1;k<=m2;k++)
		{
			if(Map2[k].p&&val)
				val--;
			else if(!Map2[k].p)
			{
				if(val+1<=j)
					val++;
				else
					NowNum++;
			}
		}
		ans=min(NowNum,ans);
	}
	printf("%d",m1/2+m2/2-ans);
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
