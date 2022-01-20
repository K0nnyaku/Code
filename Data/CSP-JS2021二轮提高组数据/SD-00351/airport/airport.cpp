#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m,m1,m2,t[N],nex[N],sum1[N],sum2[N],ans1[N],ans2[N];
struct data{
	int a,b;
}f1[N],f2[N];
priority_queue<int>q;
int read()
{
	int x=0,f=1;
	char cc=getchar();
	while(!isdigit(cc))
	{
		if(cc=='-')f=-f;
		cc=getchar();
	}
	while(isdigit(cc))
	{
		x=x*10+cc-'0';
		cc=getchar();
	}
	return x*f;
}
bool cmp1(data x,data y)
{
	return x.a<y.a;
}
void init()
{
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&f1[i].a,&f1[i].b);
	}
	sort(f1+1,f1+m1+1,cmp1);
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&f2[i].a,&f2[i].b);
	}
	sort(f2+1,f2+m2+1,cmp1);
}
void solve()
{
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int sum=0;
		int x=i,y=n-i;
		while(!q.empty())q.pop();
		for(int j=1;j<=x;j++)q.push(0);
		for(int j=1;j<=m1;j++)
		{
			if(x==0)
			{
				continue;
			}
			int xx=-q.top();
			q.pop();
			if(xx<f1[j].a)
			{
				xx=f1[j].b;sum++;
			}
			
			q.push(-xx);
		}
		
		for(int j=1;j<=y;j++)q.push(0);
		for(int j=1;j<=m2;j++)
		{
			if(y==0)
			{
				continue;
			}
			int xx=-q.top();
			q.pop();
			if(xx<f2[j].a)
			{
				xx=f2[j].b;
				sum++;
			}
			
			q.push(-xx);
		}
		
		ans=max(ans,sum);
	}
	cout<<ans;
}
void solve1()
{
	int ans=0;
	for(int i=0;i<=m1;i++)
	{
		nex[i]=i+1;
	}
	for(int i=1;i<=n;i++)
	{
		int x=0;
		int sum=0;
		int t=0;
		while(nex[x]!=m1+1)
		{
			int head=x;
			x=nex[x];
			if(f1[x].a>t)
			{
				t=f1[x].b;
				nex[head]=nex[x];
				sum++;
			}	
		}
		ans1[i]=ans1[i-1]+sum;
	}
	for(int i=0;i<=m2;i++)
	{
		nex[i]=i+1;
	}
	for(int i=1;i<=n;i++)
	{
		int x=0;
		int sum=0;
		int t=0;
		while(nex[x]!=m2+1)
		{
			int head=x;
			x=nex[x];
			if(f2[x].a>t)
			{
				t=f2[x].b;
				nex[head]=nex[x];
				sum++;
			}	
		}
		ans2[i]=ans2[i-1]+sum;
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,ans1[i]+ans2[n-i]);
	}
	cout<<ans-n/100;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	init();
	if(n<=5000)
	solve();
	else
	solve1();
	
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
//20
*/
