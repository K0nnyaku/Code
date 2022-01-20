#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define pii pair<int,int>
using namespace std;
int n,m1,m2;struct fly{
	int a,l;
	friend bool operator >(fly aa,fly bb)
	{
	return	aa.l>bb.l;
	}
};
fly a[100006],b[100006];

bool cmp(fly aa,fly bb)
{
	return aa.a<bb.a;
}
int ans;
void work(int li,int wai)
{
	int cnt=0;
	priority_queue<fly,vector<fly>, greater<fly> >q1;
	int cur=0;
//	q1.push(a[1]);
//	cnt++;
	for(int i=1;i<=m1;i++)
	{
		if(li==0) break;
		if(q1.size()>=li&&a[i].a<q1.top().l)
		{
			cur=a[i].a; 
			continue;
		}
		q1.push(a[i]);
		
		cnt++;
		cur=a[i].a;
		while(cur>=q1.top().l)
		{
			q1.pop();
		}
//		cout<<q1.top().a<<" "<<q1.top().l<<" "<<cur<<" "<<q1.size()<<endl;
		// if cur val of size q1 == li-1 de val , ze li-1 deshihou genghao  
	}
//	cout<<q1.top().a<<" "<<q1.top().l<<endl;
//	cout<<"     "<<cnt<<endl;
	int cnt2=0;
	priority_queue<fly,vector<fly>, greater<fly> >q2;
	cur=0;
//	q1.push(a[1]);
//	cnt++;
	for(int i=1;i<=m2;i++)
	{
		if(wai==0) break;
		if(q2.size()>=wai&&b[i].a<q2.top().l)
		{
			cur=b[i].a; 
			continue;
		}
		q2.push(b[i]);
		
		cnt2++;
		cur=b[i].a;
		while(cur>=q2.top().l)
		{
			q2.pop();
		}
	//	cout<<q2.top().a<<" "<<q2.top().l<<" "<<cur<<" "<<q2.size()<<endl;
		// if cur val of size q1 == li-1 de val , ze li-1 deshihou genghao  
	}
	//cout<<"     "<<cnt2<<endl;
	ans=max(ans,cnt+cnt2);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a[i].a>>a[i].l;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>b[i].a>>b[i].l;
	}
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=m1;i++)
	{
	//	cout<<a[i].first<<" "<<a[i].second<<endl;
	}
	for(int i=1;i<=m2;i++)
	{
//		cout<<b[i].first<<" "<<b[i].second<<endl;
	}
	for(int i=0;i<=n;i++)
	{
	//	cout<<i<<"\n";
		work(i,n-i);
	//	cout<<endl;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

3 5 4
1 10
2 9
3 11
4 5
7 8
2 11
4 15
7 17
12 16


*/
