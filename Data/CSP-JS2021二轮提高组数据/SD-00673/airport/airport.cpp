#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define N 100050
using namespace std;
int n;
int maxn;
int a,b;
struct node
{
	int st;
	int en;
}benguo[N],guowai[N];
priority_queue<int ,vector<int >,greater<int > >q;
void cleaning()
{
	while(!q.empty())
	q.pop();
	return ;
}
bool check(int mid)
{
	int cout=mid,nati=n-mid;
	int cnt=0;
	if(cout>0)
	{
		cout--,cnt++;
		cleaning();
		q.push(benguo[1].en);
		for(int i=2;i<=a;i++)
		{
			if(benguo[i].st>=q.top())
			{
				cnt++;
				q.pop();
				q.push(benguo[i].en);
			}
			else if(cout>0)
			{
				cout--;
				cnt++;
				q.push(benguo[i].en);
			}
		}
	}
	
	cleaning();
	if(nati<=0)
	{
		if(maxn<cnt)
		{
			maxn=cnt;
			return true;
		}
		return false;
	}
	cnt++,nati--;
	q.push(guowai[1].en);
	for(int i=2;i<=b;i++)
	{
		if(guowai[i].st>=q.top())
		{
			cnt++;
			q.pop();
			q.push(guowai[i].en);
		}
		else if(nati>0)
		{
			nati--;
			cnt++;
			q.push(guowai[i].en);
		}
	}
	if(maxn<cnt)
	{
		maxn=cnt;
		return true;
	}
	return false;
}
bool cmp(node a,node b)
{
	return a.st<b.st;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=a;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		benguo[i].st=l;benguo[i].en=r;
	}
	for(int i=1;i<=b;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		guowai[i].st=l;guowai[i].en=r;
	}
	if(n>=a+b)
	{
		int ans1=a+b;
		printf("%d",ans1);
		return 0;
	}
	sort(benguo+1,benguo+n+1,cmp);
	sort(guowai+1,guowai+n+1,cmp);
	int cnt=n-1;
	maxn+=1;
	q.push(benguo[1].en);
	for(int i=2;i<=a;i++)
	{
		if(benguo[i].st>=q.top())
		{
			maxn++;
			q.pop();
			q.push(benguo[i].en);
		}
		else if(cnt>0)
		{
			maxn++;
			q.push(benguo[i].en);
		}
	}
	cleaning();
	int anss=0;
	int aa=n-1;
	anss=1;
	q.push(guowai[1].en);
	for(int i=2;i<=b;i++)
	{
		if(guowai[i].st>=q.top())
		{
			anss++;
			q.pop();
			q.push(guowai[i].en);
		}
		else if(aa>0)
		{
			aa--;
			anss++;
			q.push(guowai[i].en);
		}
	}
	maxn=max(maxn,anss);
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		l=mid;
		else 
		r=mid;
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
