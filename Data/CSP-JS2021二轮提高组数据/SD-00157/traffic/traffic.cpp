#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

long long t,n,m,ans;

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	long long i,j,u,v;
	cin>>n>>m>>t;
	ans=1e9;
	for(i=1;i<n;i++)
		for(j=1;j<=m;j++)
			cin>>u,ans=min(ans,u);
	for(i=1;i<=n;i++)
		for(j=1;j<m;j++)
			cin>>u,ans=min(ans,u);
	while(t--)
		cout<<ans<<endl;
		return 0;	
			
}
