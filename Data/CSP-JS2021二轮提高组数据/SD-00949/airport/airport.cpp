#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring> 
using namespace std;


namespace name
{
	#define ll long long
	const ll N=2e5+5; 
	
	ll n,m1,m2;
	ll able[N];
	ll sum[N];
	ll sumv[N];
	ll atten[N];
	ll able1[N];
	ll ans=0;
	
	struct node1
	{
		ll st,en;	
	}t1[N];
	
	bool cmp1(node1 a,node1 b)
	{
		return a.st<b.st;
	}
	
	struct node2
	{
		ll st,en;	
	}t2[N];
	
	bool cmp2(node2 a,node2 b)
	{
		return a.st<b.st;
	}
	
	struct edge
	{
		ll data,num;
	}a[N*2];
	
	bool cm(edge a,edge b)
	{
		return a.data<b.data; 
	}
	
	void ini1()
	{
		ll bnt=0;
		
		for(ll i=1;i<=m1;++i)
		{
			a[++bnt].data=t1[i].st;
			a[bnt].num=bnt;
			
			a[++bnt].data=t1[i].en;
			a[bnt].num=bnt; 
		}
		
		sort(a+1,a+bnt+1,cm);
		ll index=0;
		for(ll i=1;i<=bnt;++i)
		{
			if(a[i].num%2==1)
			{
				t1[(a[i].num+1)/2].st=++index;
			}
			else if(a[i].num%2==0)
			{
				t1[(a[i].num+1)/2].en=++index;
			}
		}
	/*	for(ll i=1;i<=m1;++i)
		{
			printf("\n%lld %lld",t1[i].st,t1[i].en);
		}*/
	}

ll vis[N];

	void work1()
	{
		ini1();
		
		for(ll i=1;i<=m1;++i)
		{
			ll x=t1[i].st;
			ll v=t1[i].en;
	//		++sum[x];
	//		--sum[v+1];
			atten[x]=1;
			atten[v]=2;
	//		++sum[v];
		}
		
/*		for(ll i=1;i<=m1*2;++i)
		{
			sum[i]+=sum[i-1];
	//		sumv[i]+=sumv[i-1];
		}
		
		for(ll i=1;i<=m1*2;++i)
		{
			if(atten[i]==1)
			{
				++able[sum[i]-sumv[i]];
			}
		}
		
		for(int i=1;i<=m1;++i)
		{
			able[i]+=able[i-1];
		}*/
		
		for(int i=1;i<=m1;++i)
		{
			for(int j=1;j<=m1*2;++j)
			{
				sum[j]=0;
			}
			bool bo=1;
			for(int j=1;j<=m1;++j)
			{
				if(vis[j]) continue;
				
				ll x=t1[j].st;
				ll v=t1[j].en;
				
				if(sum[x]==0)
				{	
					bo=0;
					vis[j]=1;
					++able[i];
					for(int k=x;k<=v;++k)
					{
						sum[k]=1;
					}
				}
			}
			if(bo)
			{
				break;
			}
		}
		for(int i=1;i<=m1;++i)
		{
			able[i]+=able[i-1];
		}
	/*	for(int i=0;i<=m1;++i)
		{
			printf("%lld ",able[i]);
		}
		printf("\n");*/
	}
	
	void mymain()
	{
		scanf("%lld%lld%lld",&n,&m1,&m2);
		
		for(ll i=1;i<=m1;++i)
		{
			scanf("%lld%lld",&t1[i].st,&t1[i].en);
		}
		
		sort(t1+1,t1+m1+1,cmp1);
		
		for(ll i=1;i<=m2;++i)
		{
			scanf("%lld%lld",&t2[i].st,&t2[i].en);
		}
		
		sort(t2+1,t2+m2+1,cmp2);
		
/*		for(ll i=1;i<=m1;++i)
		{
			printf("\n%lld %lld",t1[i].st,t1[i].en);
		}for(ll i=1;i<=m2;++i)
		{
			printf("\n%lld %lld",t2[i].st,t2[i].en);
		}*/
		
		if(n>=m1+m2)
		{
			printf("%lld",m1+m2);
			return;
		}
		
		work1();
	
		for(int i=1;i<=m1;++i)
		{
			able1[i]=able[i];
		}
	
		m1=m2;
		for(int i=1;i<=m2;++i)
		{
			t1[i].st=t2[i].st;
			t1[i].en=t2[i].en;
		}
		memset(sum,0,sizeof(sum));
		memset(able,0,sizeof(able));
		memset(atten,0,sizeof(atten));
		memset(sumv,0,sizeof(sumv));
		memset(vis,0,sizeof(vis));
		
		work1();
		
		for(int i=0;i<=n;++i)
		{
			ans=max(ans,able1[i]+able[n-i]);
		}
		
		printf("%lld",ans);
		return; 
	}
	
}


int main()
{
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	name::mymain();
	
	return 0;
}
/*

3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16


7



3 4 5
2 11
4 15
7 17
12 16
1 5
3 8
6 10
9 14
13 18

7
*/
/*
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
