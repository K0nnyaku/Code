#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
int n,m,T;
int d[605][605],b[605][605];//weixian  jingxian 
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>d[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			cin>>b[i][j];
		}
	}
	while(T--)
	{
		int k,p,t;
		cin>>k;
		int ans1=0,ans2=0;
		for(int i=1;i<=k;i++)
		{
			int w,p,q;
			cin>>w>>p>>q;
			if(q==1) ans1+=w;
			if(q==0) ans2+=w;
			cout<<max(ans1,ans2)<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
