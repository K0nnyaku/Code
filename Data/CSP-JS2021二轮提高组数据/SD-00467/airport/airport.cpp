#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
int maxn;
priority_queue<int > q1,q2;
 struct uuu{
	int s;int e;
}a1[100006],a2[100006];
bool cmp(uuu x,uuu y)
{
	return x.s<y.s;
}
int pre1[100006],pre2[100006];

int n,m1,m2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a1[i].s=a;
		a1[i].e=b;
	}
		for(int i=1;i<=m2;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a2[i].s=a;
		a2[i].e=b;
	}
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
//		for(int i=1;i<=m1;i++) cout<<a1[i].s<<" "<<a1[i].e<<endl;
//		for(int i=1;i<=m2;i++) cout<<a2[i].s<<" "<<a2[i].e<<endl;
	
	for(int u=0;u<=n;u++)
	{
		int v=n-u;
     	while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
	int cnt1=0,cnt2=0,ans=0;
	if(u!=0)
	{
		for(int i=1;i<=m1;i++)
		{
			if(cnt1<u)
			{
				q1.push(a1[i].e*(-1));
				ans++;
				cnt1++;
				continue;
			}
			int t=(-1)*q1.top();
			if(a1[i].s>t)
			{
				q1.pop();
				q1.push(a1[i].e*(-1));
				ans++;
			}	
		}
	}
	if(v!=0)
	{
		for(int i=1;i<=m2;i++)
		{
			if(cnt2<v)
			{
				q2.push(a2[i].e*(-1));
				ans++;
				cnt2++;
				continue;
			}
			int t=(-1)*q2.top();
			if(a2[i].s>t)
			{
				q2.pop();
				q2.push(a2[i].e*(-1));
				ans++;
			}	
		}
	}	
	//   printf("%d\n",ans);
		maxn=max(maxn,ans);
	}
	
	printf("%d",maxn);
	return 0;
	
}
