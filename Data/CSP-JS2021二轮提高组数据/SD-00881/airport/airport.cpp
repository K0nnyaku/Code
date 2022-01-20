#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 100010
using namespace std;
int n,ma,mb;
int ans=-1;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int e[MAXN],f[MAXN],g[MAXN],h[MAXN];
int nei[MAXN],wai[MAXN];
//queue <int> q;
int find(int x)
{
	int y=n-x;
	int opa=0,opb=0;
	for(int i=1;i<=x;i++)
	{
		nei[i]=1;
		opa++;
	}
	for(int i=x+1;i<=ma;i++)
	{
		int minn=10000000,mini;
		for(int j=1;j<=i;j++)
		{
			if((minn>b[j])&&nei[j])
			{
				mini=j;
				minn=b[j];
			}
		}
		if(minn<=a[i])
		{
			nei[i]=1;
			nei[mini]=0;
			opa++;
		}
	}
	for(int i=1;i<=y;i++)
	{
		wai[i]=1;
		opb++;
	}
	for(int i=y+1;i<=mb;i++)
	{
		int minn=10000000,mini;
		for(int j=1;j<=i;j++)
		{
			if((minn>f[j])&&wai[j])
			{
				mini=j;
				minn=f[j];
			}
		}
		if(minn<=e[i])
		{
			wai[i]=1;
			wai[mini]=0;
			opb++;
		}
	}
	return opa+opb;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>ma>>mb;
	for(int i=1;i<=ma;i++)
	{
		cin>>c[i]>>d[i];
		a[i]=c[i];
		b[i]=d[i]; 
	}
	sort(a+1,a+ma+1);
	for(int i=1;i<=ma;i++)
	{
		for(int j=1;j<=mb;j++)
		{
			if(a[i]==c[j])
			{
				b[i]=d[j];
			}
		}
	}
	for(int i=1;i<=mb;i++)
	{
		cin>>g[i]>>h[i];
		e[i]=g[i];
	}
	sort(e+1,e+mb+1);
	for(int i=1;i<=mb;i++)
	{
		for(int j=1;j<=mb;j++)
		{
			if(e[i]==g[j])
			{
				f[i]=h[j];
			}
		}
	}
	/*for(int i=1;i<=ma;i++)
	{
		for(int j=i;j<=ma;j++)
		{
			if(b[i]<=a[j])
			{
				nei[i]=j;
			}
		}
	}
	for(int i=1;i<=mb;i++)
	{
		for(int j=i;j<=mb;j++)
		{
			if(f[i]<=e[j])
			{
				wai[i]=j;
			}
		}
	}*/
	for(int i=0;i<=n;i++)
	{
		//cout<<find(i)<<' ';
		ans=max(ans,find(i));
	}
	cout<<ans;
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
