#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int l,r;
}p1[N],p2[N];
int n,m1,m2,ans,res;
priority_queue<int,vector<int>,greater<int> > q;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
		p1[i].l=read(),p1[i].r=read();
	for(int i=1;i<=m2;i++)
		p2[i].l=read(),p2[i].r=read();
	sort(p1+1,p1+1+m1,cmp);
	sort(p2+1,p2+1+m2,cmp);
	int minr=p1[1].r,used=1,ans=1;//特判num=n的情况 
	q.push(p1[1].r);
	for(int i=2;i<=m1;i++)
	{
		if(p1[i].l>minr)
		{
			q.pop();
			q.push(p1[i].r);
			minr=q.top();
			ans++;
			continue;
		}
		if(p1[i].l<=minr)
		{
			used++;
			if(used>n) used--;
			else
			{
				q.push(p1[i].r);
				minr=q.top();
				ans++;
				continue;
			}
		}
	}
	res=max(res,ans);
	ans=1;
	while(q.size()) q.pop();
	minr=p2[1].r,used=1;   //特判num=0的情况 
	q.push(p2[1].r); 
	for(int i=2;i<=m2;i++)
	{
		if(p2[i].l>minr)
		{
			q.pop();
			q.push(p2[i].r);
			minr=q.top();
			ans++;
			continue;
		}
		if(p2[i].l<=minr)
		{
			used++;
			if(used>n) used--;
			else
			{
				q.push(p2[i].r);
				minr=q.top();
				ans++;
				continue;
			}
		}
	}
	res=max(res,ans);
	for(int num=1;num<n;num++)
	{
		minr=p1[1].r,used=1,ans=1;
		q.push(p1[1].r);
		for(int i=2;i<=m1;i++)
		{
			if(p1[i].l>minr)
			{
				q.pop();
				q.push(p1[i].r);
				minr=q.top();
				ans++;
				continue;
			}
			if(p1[i].l<=minr)
			{
				used++;
				if(used>num) used--;
				else
				{
					q.push(p1[i].r);
					minr=q.top();
					ans++;
					continue;
				}
			}
		}
		while(q.size()) q.pop();
		int num2=n-num;
		minr=p2[1].r,used=1,ans++;
		q.push(p2[1].r); 
		for(int i=2;i<=m2;i++)
		{
			if(p2[i].l>minr)
			{
				q.pop();
				q.push(p2[i].r);
				minr=q.top();
				ans++;
				continue;
			}
			if(p2[i].l<=minr)
			{
				used++;
				if(used>num2) used--;
				else
				{
					q.push(p2[i].r);
					minr=q.top();
					ans++;
					continue;
				}
			}
		}
		res=max(res,ans);
	}
	cout<<res<<endl;
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

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
*/
