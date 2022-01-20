#include<bits/stdc++.h>
using namespace std;
const int MAX=100005;
int n,m1,m2,m;
int N[MAX]; 
struct plan{
	int ru,chu;
};
plan ch1[MAX];
plan ch2[MAX];
bool cmp(plan x1,plan x2)
{
	return x1.ru<x2.ru;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	m=m1+m2;
	if(n>=m)
	{
		cout<<m;
		return 0;
	}
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&ch1[i].ru,&ch1[i].chu);
	sort(ch1+1,ch1+1+m1,cmp);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&ch2[i].ru,&ch2[i].chu);
	sort(ch2+1,ch2+1+m2,cmp);
	int p=m-n+1;
	p=min(p,n);
	int t=1;
	int max_=0;
	while(t<=p)
	{
		int ans=0;
		memset(N,0,sizeof(N));
		for(int i=1;i<=m1;i++)
		{
			for(int j=1;j<=t;j++)
			{
				if(ch1[i].ru>N[j])
				{
					N[j]=ch1[i].chu;
					ans++;
					break;
				}
			}
		}
		for(int i=1;i<=m2;i++)
		{
			for(int j=t+1;j<=n;j++)
			{
				if(ch2[i].ru>N[j])
				{
					N[j]=ch2[i].chu;
					ans++;
					break;
				}
			}
		}
		max_=max(max_,ans);
		t++;
	}
	cout<<max_;
	return 0;
}
