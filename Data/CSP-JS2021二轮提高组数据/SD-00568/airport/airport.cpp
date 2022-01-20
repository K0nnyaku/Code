#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int n,m1,m2;
struct node
{
	int a;
	int b;
}gn[100001],gw[100001];
int xfind(int x,int y)
{
	int ans=0,v1=0,v2=0,a,b;
	for(int i=1;i<=m1;i++)
	{
		if(x==0) break;
		if(v1<x)
		{
			q.push(gn[i].b);
			ans++;
			v1++;
		}
		else
		{
			if(gn[i].a>q.top())
			{
				q.pop();
				q.push(gn[i].b);
				ans++;
			}
			else continue;
		}
	}
	for(int i=1;i<=x;i++)
		q.pop();
	for(int i=1;i<=m2;i++)
	{
		if(y==0) break;
		if(v2<y)
		{
			q.push(gw[i].b);
			ans++;
			v2++;
		}
		else
		{
			if(gw[i].a>q.top())
			{
				q.pop();
				q.push(gw[i].b);
				ans++;
			}
			else continue;
		}
	}
	for(int i=1;i<=y;i++)
		q.pop();
	return ans;
}
bool cmp(node xx,node yy)
{
	return xx.a<yy.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int answer=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>gn[i].a>>gn[i].b;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>gw[i].a>>gw[i].b;
	}
	sort(gn+1,gn+m1+1,cmp);
	sort(gw+1,gw+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		answer=max(answer,xfind(i,n-i)); 
	}
	cout<<answer;
	fclose(stdin);
	fclose(stdout);
}
