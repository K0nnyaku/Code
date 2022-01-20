#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m1,m2,ans1,ans2,ans;
int q[100005],head,tail;
struct note1
{
	int l1;
	int r1;
}h[100005];
struct note2
{
	int l2;
	int r2;
}a[100005];
int mycmp1(note1 aa,note1 bb)
{
	if(aa.l1<bb.l1)return 1;
	return 0;
}
int mycmp2(note2 aa,note2 bb)
{
	if(aa.l2<bb.l2)return 1;
	return 0;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>h[i].l1>>h[i].r1;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>a[i].l2>>a[i].r2;
	}
	if(n>=m1+m2)
	{
		cout<<m1+m2;
		return 0;
	}
	sort(h+1,h+m1+1,mycmp1);
	sort(a+1,a+m2+1,mycmp2);
	for(int i=0;i<=n;i++)
	{
		int sum1=i,sum2=n-i,head=1,tail=2,f1=1,f2=1,ans1=1,ans2=1;
		memset(q,0,sizeof(q));
		q[1]=h[1].r1;
		for(int j=2;j<=m1;j++)
		{
			int book=0;
			if(i==0)
			{
				ans1=0;
				break;	
			}
			while(h[j].l1>=q[head]&&head<tail)
			{
				head++;
				f1--;
				book=1;
			}
			if(book==1)
			{
				f1++;
				q[tail++]=h[j].r1;
				ans1++;  
			}
			else
			if(f1<sum1)
			{
				q[tail++]=h[j].r1;
				f1++;
				ans1++; 
			}
			sort(q+head,q+tail);
		}
		head=1,tail=2;
		memset(q,0,sizeof(q));
		q[1]=a[1].r2;
		for(int k=2;k<=m2;k++)
		{
			int book=0;
			if(i==n)
			{
				ans2=0;
				break;
			}
			while(a[k].l2>=q[head]&&head<tail)
			{
				head++;
				f2--;
				book=1;
			}
			if(book==1)
			{
				f2++;
				q[tail++]=a[k].r2;
				ans2++;  
			}
			else
			if(f2<sum2)
			{
				q[tail++]=a[k].r2;
				f2++;
				ans2++; 
			}
			sort(q+head,q+tail);
		}
		ans=max(ans,ans1+ans2);
	}
	cout<<ans;
	return 0;
}
