#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+1;
struct ss
{
	int st,et;
};
ss a[N],b[N];
int n,m1,m2;
bool cmp(ss x,ss y)
{
	return x.st<y.st;
}
int maxn=-1;
void solve()
{
	for(int i=0;i<=n;i++)
	{
		int n1=i;
		int n2=n-i;
		int ans=0;
		priority_queue<int,vector <int>,greater<int> > q;
		for(int j=1;j<=m1;j++)
		{
			if(j==1 && !n1)
			{
				break;
			}
			if(n1)
			{
				ans++;
				n1--;
				q.push(a[j].et);
				if(a[j].st>q.top())
				while(!q.empty() && q.top()<a[j].st)
				{
					q.pop();
					n1++;
				}
				continue;
			}
			if(a[j].st>q.top())
			{
				ans++;
				while(!q.empty() && q.top()<a[j].st)
				{
					q.pop();
					n1++;
				}
				n1--;
				q.push(a[j].et);
			}
		}
		while(!q.empty())
		{
			q.pop();
		}
		for(int j=1;j<=m2;j++)
		{
			if(j==1 && !n2)
			{
				break;
			}
			if(n2)
			{
				ans++;
				n2--;
				q.push(b[j].et);
				if(b[j].st>q.top())
				while(!q.empty() && q.top()<b[j].st)
				{
					q.pop();
					n2++;
				}
				continue;
			}
			if(b[j].st>q.top())
			{
				ans++;
				while(!q.empty() && q.top()<b[j].st)
				{
					q.pop();
					n2++;
				}
				n2--;
				q.push(b[j].et);
			}
		}
		if(maxn<ans)
		{
			maxn=ans;
		}
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a[i].st,&a[i].et);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&b[i].st,&b[i].et);
	}
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	solve();
	printf("%d",maxn);
	return 0;
}
