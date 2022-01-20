#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
int ans[5011]={0};
//int a1[5010],b1[5010],a2[5010],b2[5010];
struct sdf
{
	int dao,li;
}a[5051];
struct sdfsdf
{
	int dao,li;
}b[5051];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>a[i].dao >>a[i].li;
	for(int i=1;i<=m2;i++)
		cin>>b[i].dao >>b[i].li ;
	for(int i=1;i<=m1;i++)
		for(int j=i+1;j<=m1;j++)
		{
			if(a[i].dao>a[j].dao)
			swap(a[i],a[j]);
			if(a[i].dao ==a[j].dao )
				if(a[i].li >a[j].li )
				swap(a[i],a[j]);
		}
	for(int i=1;i<=m2;i++)
		for(int j=i+1;j<=m2;j++)
		{
			if(b[i].dao>b[j].dao)
			swap(b[i],b[j]);
			if(b[i].dao ==b[j].dao )
				if(b[i].li >b[j].li )
				swap(b[i],b[j]);
		}
		
	for(int i=0;i<=n;i++)
	{
		ans[i]+=n;
		int ios=i;
		while(ios>0)
		{
			for(int j=1;j<=m1;j++)
			for(int k=j+1;k<=m1;k++)
			if(a[j].li <=a[k].dao &&(a[j].li !=0||a[k].dao !=0))
			{
				ans[i]++;
				a[j].li=0;a[k].dao =0;
			}
			ios--;
		}
		int oi=n-i;
		while(oi>0)
		{	
			for(int j=1;j<=m2;j++)
			for(int k=j+1;k<=m2;k++)
			if(b[j].li <=b[k].dao &&(b[j].li !=0||b[k].dao !=0))
			{
				ans[i]++;
				b[j].li=0;b[k].dao =0;
			}
			oi--;
		}
	}
	sort(ans,ans+n+1);
	cout<<ans[n]+1;
/*	for(int i=0;i<=n;i++)
	{
		ans[i]+=n;
		for(int j=1;j<=m1;j++)
		for(int k=j+1;k<=m1;k++)
		if(a[k].dao >=a[j].li&&a[j].li !=0&&a[k].dao !=0)
		{
			ans[i]++;
			a[j].li=0;a[k].dao =0;
		}
		for(int j=1;j<=m2;j++)
		for(int k=j+1;k<=m2;k++)
		if(b[k].dao >=b[j].li&&b[j].li !=0&&b[k].dao !=0)
		{
			ans[i]++;
			b[j].li=0;b[k].dao =0;
		}
	}
	sort(ans,ans+n+1);
	cout<<ans[n];*/
	return 0;
}
