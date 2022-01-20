#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int,int> pii;

inline int read()
{
	int a,flag;
	a=0;
	flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			flag=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a*flag;
}

int n,m1,m2;

pii a1[101010];
pii a2[101010];

int ans=0;

void check(int x)
{
	priority_queue<int,vector<int>,greater<int> > q1;
	priority_queue<int,vector<int>,greater<int> > q2;
	int sum=0;
	int s11=0;
	int s22=0;
	for(int i=1; i<=m1; ++i)
	{

		if(s11<x)
		{
			sum++;
			s11++;
			q1.push(a1[i].second);
		}
		else if(!q1.empty())
		{
			if(a1[i].first>=q1.top())
			{
				q1.pop();
				q1.push(a1[i].second);
				sum++;
			}
		}
	}

	for(int i=1; i<=m2; ++i)
	{
		if(s22<n-x)
		{
			sum++;
			s22++;
			q2.push(a2[i].second);
		}
		else if(!q2.empty())
			if(a2[i].first>=q2.top())
			{
				q2.pop();
				q2.push(a2[i].second);
				sum++;
			}
	}

	ans=max(ans,sum);
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	if(n>=(m1+m2))
	{
		printf("%d",m1+m2);
		return 0;
	}
	for(int i=1; i<=m1; ++i)
	{
		a1[i].first=read();
		a1[i].second=read();
	}
	for(int i=1; i<=m2; ++i)
	{
		a2[i].first=read();
		a2[i].second=read();
	}

	sort(a1+1,a1+m1+1);
	sort(a2+1,a2+m2+1);

	for(int i=0; i<=n; ++i)
	{
		check(i);
	}

	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
