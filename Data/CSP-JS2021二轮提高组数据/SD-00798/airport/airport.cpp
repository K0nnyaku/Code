#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int n,m1,m2,cnt1,cnt2; 
struct Flight
{
	int l,r;
}ft1[maxn],ft2[maxn];
int ans,time1[maxn*2],time2[maxn*2],mp1[maxn*2],mp2[maxn*2],max1[maxn],max2[maxn];
int vis1[maxn*2],vis2[maxn*2];
int tree1[maxn*2],tree2[maxn*2];
int lowbit(int x)
{
	return x&(-x);
}
void add1(int x,int val)
{
	for(int i=x;i<=cnt1;i+=lowbit(i))
	{
		tree1[i]+=val;
	}
}
void add2(int x,int val)
{
	for(int i=x;i<=cnt2;i+=lowbit(i))
	{
		tree2[i]+=val;
	}
}
int sum1(int x)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		sum+=tree1[i];
	}
	return sum;
}
int ask1(int l,int r)
{
	return sum1(r)-sum1(l-1);
}
int sum2(int x)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		sum+=tree2[i];
	}
	return sum;
}
int ask2(int l,int r)
{
	return sum2(r)-sum2(l-1);
}
int read()
{
	int x=0,f=1;
	char c;
	c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
bool cmp(const Flight &x,const Flight &y)
{
	return x.l<y.l;
}
int sh1(int x)
{
	int l=1,r=cnt1;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(mp1[mid]==x)
		{
			return mid;
		}
		if(x>mp1[mid])
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return 0;
}
int sh2(int x)
{
	int l=1,r=cnt2;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(mp2[mid]==x)
		{
			return mid;
		}
		if(x>mp2[mid])
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return 0;
}
int ssh1(int p,int l,int r)
{
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(ask1(p,mid)==0)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return l;
}
int ssh2(int p,int l,int r)
{
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(ask2(p,mid)==0)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=m1;i++)
	{
		ft1[i].l=read();
		mp1[++cnt1]=ft1[i].l;
		ft1[i].r=read();
		mp1[++cnt1]=ft1[i].r;
	}
	for(int i=1;i<=m2;i++)
	{
		ft2[i].l=read();
		mp2[++cnt2]=ft2[i].l;
		ft2[i].r=read();
		mp2[++cnt2]=ft2[i].r;
	}
	sort(mp1+1,mp1+cnt1+1);
	sort(ft1+1,ft1+m1+1,cmp);
	for(int i=1;i<=m1;i++)
	{
		ft1[i].l=sh1(ft1[i].l);
		ft1[i].r=sh1(ft1[i].r);
		time1[ft1[i].l]=i;
		vis1[ft1[i].l]=1; 
		add1(ft1[i].l,1);
	}
	for(int i=1;i<=n;i++)
	{
		max1[i]=max1[i-1];
		int p=1;
		while(p<=cnt1)
		{
			int t=ssh1(p,p,cnt1);
			if(t>cnt1) break;
			max1[i]++;
			vis1[t]=0;
			add1(t,-1);
			p=ft1[time1[t]].r+1;
		}
		if(max1[i]==m1) break;
	}
	sort(mp2+1,mp2+cnt2+1);
	sort(ft2+1,ft2+m2+1,cmp);
	for(int i=1;i<=m2;i++)
	{
		ft2[i].l=sh2(ft2[i].l);
		ft2[i].r=sh2(ft2[i].r);
		time2[ft2[i].l]=i;
		vis2[ft2[i].l]=1; 
		add2(ft2[i].l,1);
	}
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		max2[i]=max2[i-1];
		int p=1;
		while(f==0&&p<=cnt2)
		{
			int t=ssh2(p,p,cnt2);
			if(t>cnt2) break;
			max2[i]++;
			vis2[t]=0;
			add2(t,-1);
			p=ft2[time2[t]].r+1;
		}
		if(max2[i]==m2) f=1;
		ans=max(ans,max1[n-i]+max2[i]);
	}
	ans=max(ans,max1[n]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
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
