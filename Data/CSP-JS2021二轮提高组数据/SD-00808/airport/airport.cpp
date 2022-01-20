#include<iostream>
#include<cstdio>
#define MAXN 10000
using namespace std;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,a1[MAXN],b1[MAXN],a2[MAXN],b2[MAXN];
	int nei=0,wai=0; 
	int i,c;
	cin>>n>>m1>>m2;
	int in=0,out=n-in;
	int all[n];
	for(i=1;i<=m1;i++)
	{
		cin>>a1[i]>>b1[i];
	}
	for(i=1;i<=m2;i++)
	{
		cin>>a2[i]>>b2[i];
	}
	for(i=0;i<=n;i++)
	{
		for(int j=1;j<=m1;j++)
		{
			if(b1[j-in]<a1[j]||nei<=in)
			{
				nei++;
			}
		}
		for(int j=1;j<=m2;j++)
		{
			if(b2[j-out]<a2[j]||wai<=out)
			{
				wai++;
			}
		}
		all[i]=nei+wai;
		nei=0;
		wai=0;
		in++;
		out--;
	}
	for(i=1;i<=n;i++)
	{
		if(all[i-1]<all[i])
		{
			c=all[i];
		}
	}
	cout<<c<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
