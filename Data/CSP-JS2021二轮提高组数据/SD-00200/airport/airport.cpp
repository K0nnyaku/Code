#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int size = 100001;
int n,m1,m2,ans,temp;
priority_queue< int,vector<int>,greater<int> > q;
struct node
{
	int a,b;
}air1[size],air2[size];
bool cmp(node l,node r)
{
	return l.a < r.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin >> n >> m1 >> m2;
	for(int i=1;i<=m1;i++)
		cin >> air1[i].a >> air1[i].b;
	for(int i=1;i<=m2;i++)
		cin >> air2[i].a >> air2[i].b;
	sort(air1+1,air1+1+m1,cmp);
	sort(air2+1,air2+1+m2,cmp);
	for(int i=0;i<=n;i++)
	{
		temp=0;
		for(int j=1;j<=m1;j++)
		{
			if(j<=i)
			{
				temp++;
				q.push(air1[j].b);
			}
			else if(i!=0 && air1[j].a > q.top())
			{
				temp++;
				q.pop();
				q.push(air1[j].b);
			}
		}
		while(!q.empty())
			q.pop();
		for(int j=1;j<=m2;j++)
		{
			if(j<=(n-i)) 
			{
				temp++;
				q.push(air2[j].b);
			}
			else if((n-i)!=0 && air2[j].a > q.top())
			{
				temp++;
				q.pop();
				q.push(air2[j].b);
			}
		}
		while(!q.empty())
			q.pop();
		ans=max(ans,temp);
	}
	cout << ans;
	return 0;
}
