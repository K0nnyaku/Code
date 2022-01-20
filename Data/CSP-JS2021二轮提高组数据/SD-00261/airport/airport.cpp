#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m1,m2;
int m1min,m2min;
int winningstreak1,winningstreak2;
int peast1=1,peast2=1;
int maxx=0;
int m1mintag,m2mintag;
struct Node{
	int ar11;
	int ar12;
}m11[1000009];
struct Node2{
	int ar21;
	int ar22;
}m22[1000009];
int search(int x)
{
	for(int i=1;i<=m1;i++)
	{
		if(i==1)
		{
			if(peast1>x)
			{
				break;
			}
			m1min=min(m1min,m11[i].ar12);
			if(m1min==m11[i].ar12){
				m1mintag=i;
			}
			winningstreak1++;
		}
		else{
			if(m11[i].ar11>=m1min)
			{
				winningstreak1++;
				for(int j=1;j<=i && j!=m1mintag;j++)
				{
					m1min=min(m1min,m11[j].ar12);
					if(m1min==m11[j].ar12){
						m1mintag=j;
					}
				}
			}
			if(m11[i].ar11<m1min)
			{
				if((x-peast1)>=1)
				{
					winningstreak1++;
					peast1++;
					m1min=min(m1min,m11[i].ar12);
					if(m1min==m11[i].ar12){
						m1mintag=i;
					}
				}
			}
		}
	}
	for(int i=1;i<=m2;i++)
	{
		if(i==1)
		{
			if(peast2>(n-x))
			{
				break;
			}
			m2min=min(m2min,m22[i].ar22);
			if(m2min=m22[i].ar22)
			{
				m2mintag=i;
			}
			winningstreak2++;
		}
		if(m22[i].ar21>=m2min)
		{
			winningstreak2++;
			for(int j=1;j<=i && j!=m2mintag;j++)
				{
					m2min=min(m2min,m22[j].ar22);
					if(m2min=m22[j].ar22)
					{
						m2mintag=j;
					}
				}
		}
		if(m22[i].ar21<m2min)
		{
			if((n-x-peast2)>=1)
			{
				winningstreak2+=1;
				peast2++;
				m2min=min(m2min,m22[i].ar22);
				if(m2min=m22[i].ar22)
				{
					m2mintag=i;
				}
			}
		}
	}
	int ans=winningstreak1+winningstreak2;
	return ans;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>m11[i].ar11;
		cin>>m11[i].ar12;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>m22[i].ar21;
		cin>>m22[i].ar22;
	}
	if(n>=(m1+m2))maxx=m1+m2;
	else{
		for(int i=0;i<=n;i++)
		{
			m1min=10000009;
			m2min=10000009;
			peast1=1;
			peast2=1;
			winningstreak1=0;
			winningstreak2=0;
			maxx=max(search(i),maxx);
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

