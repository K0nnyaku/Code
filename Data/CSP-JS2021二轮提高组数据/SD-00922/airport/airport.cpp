#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[100005],b[100005];
priority_queue<int,vector<int>,greater<int>> q;
bool cmp(node c,node d)
{
	return c.x<d.x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) cin>>a[i].x>>a[i].y;
	for(int i=1;i<=m2;i++) cin>>b[i].x>>b[i].y;
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	int ans=0;
	for(int m=0;m<=n;m++)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=m1;i++)
		{
		    bool flag=false;
			if(cnt<m)
			{
				++cnt;++sum;
				flag=true;
				q.push(a[i].y);
			}
			else
			{
				while(!q.empty())
				{
					if(q.top()<a[i].x)
					{
						q.pop();cnt--;
						if(!flag)
						{
							q.push(a[i].y);
							cnt++;
							sum++;
							flag=true;
						}
					}
					if(q.top()>a[i].x) break;
				} 
			}
		}
		while(!q.empty()) q.pop();
		cnt=0;
		for(int i=1;i<=m2;i++)
		{
			bool flag=false;
			if(cnt<n-m)
			{
				++cnt;++sum;
				q.push(b[i].y);
				flag=true;
			}
			else
			{
				while(!q.empty())
				{
					if(q.top()<b[i].x)
					{
						q.pop();cnt--;
						if(!flag)
						{
							q.push(b[i].y);
							cnt++;
							sum++;
							flag=true;
						}
					}
					if(q.top()>b[i].x) break;
				} 
			}
		}
		ans=max(ans,sum); 
		while(!q.empty()) q.pop();
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
