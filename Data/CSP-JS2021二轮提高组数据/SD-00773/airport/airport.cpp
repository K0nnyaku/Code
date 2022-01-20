#include<bits/stdc++.h>
using namespace std;
int n,mq1,mq2;
int v1[100001*4],v2[100001*4];
struct pl1
{
	int l,r;
}a[100001*4];
struct pl2
{
	int l,r;
}b[100001*4];
map<int,int> mp1;
map<int,int> mp2;
int tg1[100001*2];
int cf1[100001*2];
int t1[100001*2];
int qz1[100001*2];

int tg2[100001*2];
int cf2[100001*2];
int t2[200001];
int qz2[100001*2];

int bd1[100001*2];
int bd2[100001*2];
bool cmp1(pl1 q,pl1 p)
{
	return q.l<p.l;
}
bool cmp2(pl2 q,pl2 p)
{
	return q.l<p.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>mq1>>mq2;
	for(int i=1;i<=mq1;i++)
	{
		cin>>a[i].l>>a[i].r;
		v1[2*i-1]=a[i].l;
		v1[2*i]=a[i].r;
	}
	
	sort(v1+1,v1+1+mq1*2);
	for(int i=1;i<=mq1*2;i++)
	{
		mp1[v1[i]]=i;
	}
	for(int i=1;i<=mq1;i++)
	{
		a[i].l=mp1[a[i].l];
		a[i].r=mp1[a[i].r];
		
		cf1[a[i].l]++;
		bd1[a[i].l]=a[i].r+1;
		tg1[a[i].l]++;
		cf1[a[i].r+1]--;
	}
	sort(a+1,a+1+mq1,cmp1);
	int now1=0;
	for(int k=1;k<=n;k++)
	{
		now1=0;
		int tot=0;
		memset(bd1,0,sizeof(bd1));
		memset(cf1,0,sizeof(cf1));
		memset(tg1,0,sizeof(bd1));
		for(int i=1;i<=mq1;i++)
		{
			cf1[a[i].l]++;
			bd1[a[i].l]=a[i].r+1;
			tg1[a[i].l]++;
			cf1[a[i].r+1]--;
		}
		for(int i=1;i<=mq1*2;i++)
		{
			now1+=cf1[i];
			if(now1>k)
			{
				now1=k;
				cf1[bd1[i]]++;
				continue;
			}
			tot+=tg1[i];
		}
		t1[k]=tot;
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		cout<<t1[i]<<" ";
//	}
	//------
	for(int i=1;i<=mq2;i++)
	{
		cin>>b[i].l>>b[i].r;
		v2[2*i-1]=b[i].l;
		v2[2*i]=b[i].r;
	}
	
	sort(v2+1,v2+1+mq2*2);
	for(int i=1;i<=mq2*2;i++)
	{
		mp2[v2[i]]=i;
	}
	for(int i=1;i<=mq2;i++)
	{
		b[i].l=mp2[b[i].l];
		b[i].r=mp2[b[i].r];
		
		cf2[b[i].l]++;
		bd2[b[i].l]=b[i].r+1;
		tg2[b[i].l]++;
		cf2[b[i].r+1]--;
	}
	sort(b+1,b+1+mq2,cmp2);
	int now2=0;
	for(int k=1;k<=n;k++)
	{
		now2=0;
		int tot=0;
		memset(bd2,0,sizeof(bd2));
		memset(cf2,0,sizeof(cf2));
		memset(tg2,0,sizeof(bd2));
		for(int i=1;i<=mq2;i++)
		{
			cf2[b[i].l]++;
			bd2[b[i].l]=b[i].r+1;
			tg2[b[i].l]++;
			cf2[b[i].r+1]--;
		}
		for(int i=1;i<=mq2*2;i++)
		{
			now2+=cf2[i];
			if(now2>k)
			{
				now2=k;
				cf2[bd2[i]]++;
				continue;
			}
			tot+=tg2[i];
		}
		t2[k]=tot;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<t2[i]<<" ";
//	}

	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,t1[i]+t2[n-i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
