#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

struct NODE{
	int a,b;
}c[200010],d[200010];

bool cmp(NODE X,NODE Y)
{
	return X.a<Y.a; 
}

int n,m1,m2;
priority_queue<int,vector<int>,greater<int> > nation,internation;

int fun(int n1)
{
	int n2=n-n1;
	while(!nation.empty())nation.pop();
	while(!internation.empty())internation.pop();
	for(int i=1;i<=n1;i++)
		nation.push(0);
	for(int i=1;i<=n2;i++)
		internation.push(0);
	int tot=0;
	if(n1)
		for(int i=1;i<=m1;i++)
		{
			if(nation.top()<c[i].a)
			{
				tot++;
				nation.pop();
				nation.push(c[i].b);
			}
		}
//	cout<<n1<<" "<<n2<<" "<<tot;
	if(n2)
		for(int i=1;i<=m2;i++)
		{
			if(internation.top()<d[i].a)
			{
				tot++;
				internation.pop();
				internation.push(d[i].b);
			}
		}
//	cout<<" "<<tot<<endl;
	return tot;
}
int ans;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&c[i].a,&c[i].b);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&d[i].a,&d[i].b);
	}
	sort(c+1,c+1+m1,cmp);
	sort(d+1,d+1+m2,cmp);
	if(n<=5000)
	{
		for(int i=0;i<=n;i++)
			ans=max(ans,fun(i));
	}
	else if(n>5000)
	{
		int l=0,r=n,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			int f1=fun(mid),f2=fun(mid+1);
			ans=max(ans,max(f1,f2));
			if(r-l<=1)
			{
				ans=max(ans,max(fun(l),fun(r)));
				break;
			}
			else if(f1<=f2)
			{
				l=mid+1;
			}
			else if(f1>=f2)
			{
				r=mid;
			}
		}
	}
	
	printf("%d",ans);
	return 0;
}
