#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
struct plane {
	int in,out;
}a1[100010],a2[100010];
int t1=1,t2=1;
int n,m1,m2;
priority_queue <int> q;
bool cmp (plane a,plane b)
{
	return a.in<b.in;
}
void qpush (int a)
{
	q.push(-a);
	return ;
}
int qtop ()
{
	return -(q.top());
}
int check (int x)
{
	int rt=0;
	if (x!=0)
	{
		qpush(a1[1].out); rt++;
		for (int i=2;i<=m1;i++)
		{
			if (qtop()<a1[i].in){
				q.pop();
			}
			if (q.size()<x){
				qpush(a1[i].out);
				rt++;
			}
		}
	}
	
	
//	cout<<"111111111111111111111";
	while (!q.empty()) q.pop();
	
	if (n-x!=0)
	{
		qpush(a2[1].out); rt++;
		for (int i=2;i<=m2;i++)
		{
			if (qtop()<a2[i].in){
				q.pop();
			}
			if (q.size()<n-x){
				qpush(a2[i].out);
				rt++;
			}

		}
	}
	
	while (!q.empty()) q.pop();
	return rt;
}



//airport
int main()
{
	freopen ("airport.in","r",stdin);
	freopen ("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for (int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a1[t1].in,&a1[t1].out);
		t1++;
	}
	for (int i=1;i<=m2;i++)
	{
		scanf("%d%d",&a2[t2].in,&a2[t2].out);
		t2++;
	}
	sort (a1+1,a1+m1+1,cmp); sort (a2+1,a2+m2+1,cmp);
	/*for (int i=0;i<=n;i++)
	{
		cout<<i<<"  "<<check(i)<<endl;
	}*/

	int l=0,r=n,mid,ans=0;
	for (;;)
	{
		int yes=2;
		mid=(r-l+1)/2+l;
		int x=check (mid);
		for (int i=mid-1;i>=0;i--)
		{
			if (check (i)>x)
			{
				r=i;
				yes--;
				break;
			}
			if (check (i)<x) 
			{
				
				break;
			}
		}
		for (int i=mid+1;i<=n;i++)
		{
			if (x<check (i))
			{
				l=i;
				yes--;
				break;
			}
			if (x>check (i))
			{
				
				break;
			}
		}
		if (yes==2)
		{
			ans=x;
			break;
		}
//		cout<<mid<<"   "<<check(mid)<<endl;
	}
	cout<<ans;
	return 0;
}
