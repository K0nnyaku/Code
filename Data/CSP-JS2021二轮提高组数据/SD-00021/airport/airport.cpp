#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{ll r,l;}a[N],b[N]; //到达和离开时间 a国内 b国际 
ll n,m1,m2,ans;
bool cmp(node x,node y){return x.l<y.l;}
inline ll Read()
{
	ll s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return f*s;
}
priority_queue<ll,vector<ll>,greater<ll> >q;
ll guonei(ll num) //求给国内分num个桥廊能停靠的飞机数量 
{
	while(!q.empty()) q.pop();
	ll tot=0;
	for(int i=1;i<=m1;i++) //枚举第几架飞机
	{
		ll temp=0;
		while(!q.empty()&&temp<=q.size()) 
		{
			if(a[i].l>q.top())	q.pop();
			temp++;
		}
		if(q.size()<num) 
		{
			if(i==1||q.size()<num) q.push(a[i].r),tot++;
			else if(q.size()==num-1)
			{
				if(a[i].l>q.top()) q.push(a[i].r),tot++; //>=还是>
			}
		}
	} 
	return tot;
}
ll guoji(int num) 
{
	while(!q.empty()) q.pop();
	ll tot=0;
	for(int i=1;i<=m2;i++) //枚举第几架飞机
	{
		ll temp=0;
		while(!q.empty()&&temp<=q.size()) 
		{
			if(b[i].l>q.top())	q.pop();
			temp++;
		}
		if(q.size()<num) 
		{
			if(i==1||q.size()<num) q.push(b[i].r),tot++;
			else if(q.size()==num-1)
			{
				if(b[i].l>q.top()) q.push(b[i].r),tot++;
			}
		}
	} 
	return tot;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=Read(),m1=Read(),m2=Read(); //桥廊个数，国内航班个数，国外航班个数
	for(int i=1;i<=m1;i++)
		a[i].l=Read(),a[i].r=Read();
	for(int i=1;i<=m2;i++)
		b[i].l=Read(),b[i].r=Read();
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;i++) //把n个桥廊分为2份，分别给国内和国际 
	{ 
		ll ans1=0,ans2=0;
		if(i!=0) ans1=guonei(i); //给国内分i个桥廊能停靠的飞机数量 
		if(n-i!=0) ans2=guoji(n-i); //给国际分n-i个桥廊能停靠的飞机数量
		ans=max(ans,ans1+ans2);
	}
	cout<<ans<<endl;
	return 0;
}
