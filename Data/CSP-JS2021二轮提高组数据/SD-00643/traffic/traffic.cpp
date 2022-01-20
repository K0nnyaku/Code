#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t,temp;
	cin>>n>>m>>t;
	for(int i=1;i<n;i++) 
		for(int j=1;j<=m;j++)
			cin>>temp;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			cin>>temp;
	int cnt0=0,cnt1=0;
	while(t--)
	{
		int ttt;
		cin>>ttt;
		for(int i=1;i<=ttt;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			if(w)
				cnt1+=v;
			else
				cnt0+=v;
		}
		cout<<min(cnt1,cnt0)<<endl;
	}
	return 0;
}
