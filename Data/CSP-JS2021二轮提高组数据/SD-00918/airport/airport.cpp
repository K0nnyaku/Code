#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const long long N=1e5+5;

typedef pair<long long,long long> pii;

struct zqz{
	long long arr,lea;
	long long qwq;
}p[N];

long long n,m1,m2;

bool cmp(zqz x,zqz y)
{
	if(x.arr==y.arr)
	{
		return x.lea<y.lea;
	}
	return x.arr<y.arr;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	cin>>n>>m1>>m2;
	
	long long cnt;
	for(long long i=1;i<=m1;i++)
	{
		long long a,b;
		cin>>a>>b;
		p[++cnt].arr=a;
		p[cnt].lea=b;
		p[cnt].qwq=0;
	}
	for(long long i=1;i<=m2;i++)
	{
		long long a,b;
		cin>>a>>b;
		p[++cnt].arr=a;
		p[cnt].lea=b;
		p[cnt].qwq=1;
	}
	
	sort(p+1,p+cnt+1,cmp);
	
	cnt=m1+m2;
	
	long long maxs=0;
	for(long long i=0;i<=n;i++)
	{
		long long l1=i;
		long long l2=n-i;
		
		long long s=0;
		
		priority_queue<pii,vector<pii>,greater<pii> > q1;
		priority_queue<pii,vector<pii>,greater<pii> > q2;
		
		for(long long j=1;j<=cnt;j++)
		{
			if(!p[j].qwq)
			{
				if(!q1.empty())
				{
					pii u=q1.top();
					if(p[j].arr>u.first)
					{
						s++;
						q1.pop();
						
						long long t1=p[j].lea;
						long long t2=p[j].arr;
						
						q1.push(make_pair(t1,t2));
						
						continue;
					}
				}
				
				if(l1>0)
				{
					s++;
					l1--;
					
					long long t1=p[j].lea;
					long long t2=p[j].arr;
						
					q1.push(make_pair(t1,t2));
				}
			}
			else
			{
				if(!q2.empty())
				{
					pii u=q2.top();
					if(p[j].arr>u.first)
					{
						s++;
						q2.pop();
						
						long long t1=p[j].lea;
						long long t2=p[j].arr;
						
						q2.push(make_pair(t1,t2));
						
						continue;
					}
				}
				
				if(l2>0)
				{
					s++;
					l2--;
					
					long long t1=p[j].lea;
					long long t2=p[j].arr;
						
					q2.push(make_pair(t1,t2));
				}
			}
		}
		maxs=max(s,maxs);
	}
	cout<<maxs;
	fclose(stdin);
	fclose(stdout);

	return 0;
}

