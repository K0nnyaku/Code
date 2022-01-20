#include<bits/stdc++.h> 
using namespace std;
const int N=114514;
int n,m,t,st[505],tot,c[505],c2[505],a,ans,sum;
string s;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			cin>>a;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			cin>>a;
	while(t--){
		cin>>tot;
		for(int i=1;i<=tot;i++)cin>>c[i]>>a>>a;
		for(int i=1;i<=tot;i++)ans=max(c[i],tot),sum+=c[i];
		cout<<sum-ans<<endl;
		ans=0;sum=0;
	}
	return 0;
}
	 
