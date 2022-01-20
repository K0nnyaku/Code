#include<bits/stdc++.h>
using namespace std;

int m,n,M,an,ans;

pair<int,int> a[100010],A[100010];

int lq(int k,int N,pair<int,int> x[100010])
{	
	if(k==0)	return 0;
	int xyjh[k+10],I=1; 
	xyjh[1]=1;xyjh[0]=0;

	for(int i=1;i<=N;i++)
	{	 
		for(int j=1;j<=k;j++)
			{	
			if(x[xyjh[j]].second<x[i].first)
				{	
					xyjh[j]=i;
					I++;
					break;
				}
			}	cout<<"";
	}
	return I;	
}

int main()
{
	freopen("airport3.in","r",stdin);
	freopen("airport3.out","w",stdout);
	
	cin>>n>>m>>M;
	
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	for(int i=1;i<=M;i++)
		scanf("%d%d",&A[i].first,&A[i].second);	
	
	sort(a+1,a+m+1);
	sort(A+1,A+m+1);
		 	 
	for(int i=0;i<=n;i++)
	{	
		int j=n-i;
		an=lq(i,m,a)+lq(j,M,A);
		if(an>ans)
			ans=an;
	}
	cout<<ans;
	
	return 0;		
} 
