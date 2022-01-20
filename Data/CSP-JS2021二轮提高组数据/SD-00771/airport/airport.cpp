#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m1,m2;
int finalansss;
struct planeee
{
	int arr,lea;
	bool operator <(const planeee &stt)const
	{
		return arr<stt.arr;
	}
}a[N],b[N];
struct plaq
{
	int leatim,lev;
	bool operator <(const plaq &stt)const
	{
		return leatim>stt.leatim;
	}
};
priority_queue <plaq> plaq1,plaq2;
int finnn1[N],finnn2[N],cntt1,cntt2;
struct roomq
{
	int lev;
	bool operator <(const roomq &stt)const
	{
		return lev>stt.lev;
	}
};
priority_queue<roomq> roomq1,roomq2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a[i].arr,&a[i].lea);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&b[i].arr,&b[i].lea);
	}
	
	if(n>=m1+m2)
	{
		printf("%d\n",m1+m2);
		return 0;
	}
	
	sort(&a[1],&a[m1+1]);
	sort(&b[1],&b[m2+1]);
	
	for(int i=1;i<=m1;i++)
	{
		//printf("a[%d]=%d %d\n",i,a[i].arr,a[i].lea);
		while(!plaq1.empty())
		{
			plaq outt=plaq1.top();
			if(outt.leatim<a[i].arr)
			{
				//printf("left at %d\n",outt.leatim);
				roomq1.push((roomq){outt.lev});
				plaq1.pop();
			}	
			else
			{
				break;
			}
		}
		if(!roomq1.empty())
		{
			//printf("->%d %d\n",i,cntt1);
			roomq okrooo=roomq1.top();
			int okroo=okrooo.lev;
			finnn1[okroo]++;
			plaq1.push((plaq){a[i].lea,okroo});
			roomq1.pop();
		}
		else if(cntt1<n)
		{	
			finnn1[++cntt1]++;
			plaq1.push((plaq){a[i].lea,cntt1});
		}
	}
	for(int i=1;i<=m2;i++)
	{
		//printf("a[%d]=%d %d\n",i,a[i].arr,a[i].lea);
		while(!plaq2.empty())
		{
			plaq outt=plaq2.top();
			if(outt.leatim<b[i].arr)
			{
				//printf("left at %d\n",outt.leatim);
				roomq2.push((roomq){outt.lev});
				plaq2.pop();
			}	
			else
			{
				break;
			}
		}
		if(!roomq2.empty())
		{
			//printf("->%d %d\n",i,cntt1);
			roomq okrooo=roomq2.top();
			int okroo=okrooo.lev;
			finnn2[okroo]++;
			plaq2.push((plaq){b[i].lea,okroo});
			roomq2.pop();
		}
		else if(cntt2<n)
		{	
			finnn2[++cntt2]++;
			plaq2.push((plaq){b[i].lea,cntt2});
		}
	}
//	printf("\n");
	for(int i=1;i<=n;i++)
	{
		finnn1[i]+=finnn1[i-1];
		finnn2[i]+=finnn2[i-1];
//		printf("%d ",finnn2[i]);
	}
	for(int i=0;i<=n;i++)
	{
		finalansss=max(finalansss,finnn1[i]+finnn2[n-i]);
	}
	printf("%d\n",finalansss);
	return 0;
}
