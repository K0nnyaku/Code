#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm> 
#include<queue>
#include<vector>
using namespace std;
#define N 100010
struct node{
	int t;
	int l;
}a[N],b[N];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch-48);
		ch=getchar(); 
	}
	return x*f;
}
int n,p1,p2,maxx,d1[N],d2[N];
int check(int w1,int w2)
{
	int l1=0,r1=1,l2=0,r2=1,ans=0;
	for(int i=1;i<=p1;i++)
	{
		for(int j=r1-1;j>l1+1;j--)
		{
			if(d1[j]<d1[j-1])
			{
				int tp=d1[j];
				d1[j]=d1[j-1];
				d1[j-1]=tp;
			}
		}
		if(r1-l1>1&&a[i].t>=d1[l1+1])
		l1++;
		if(r1-l1-1<w1)
		{
			d1[r1++]=a[i].l;
			ans++;
		}
		/*for(int i=l1+1;i<r1;i++)
		cout<<d1[i]<<' ';
		cout<<endl;*/
	}
//	cout<<endl<<"ewqrihfpqiu "<<ans<<' ';
	for(int i=1;i<=p2;i++)
	{
		for(int j=r2-1;j>l2+1;j--)
		{
			if(d2[j]<d2[j-1])
			{
				int tp=d2[j];
				d2[j]=d2[j-1];
				d2[j-1]=tp;
			}
		}
		if(r2-l2>1&&b[i].t>=d2[l2+1])
		l2++;
		if(r2-l2-1<w2)
		{
			d2[r2++]=b[i].l;
			ans++;
		}
	/*	for(int i=l2+1;i<r2;i++)
		cout<<d2[i]<<' ';
		cout<<endl;*/
	}
	//cout<<"ewqrihfpqiu "<<ans<<endl;
	return ans;
}
int cmp(node a,node b)
{
	return a.t<b.t;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();p1=read();p2=read();
	for(int i=1;i<=p1;i++)
	{
		a[i].t=read();
		a[i].l=read();
	}
	for(int i=1;i<=p2;i++)
	{
		b[i].t=read();
		b[i].l=read();
	}
	sort(a+1,a+p1+1,cmp);
	sort(b+1,b+p2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		maxx=max(maxx,check(i,n-i));
		//cout<<maxx<<' '<<i<<' '<<n-i<<endl;
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16*/
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
9 10*/
