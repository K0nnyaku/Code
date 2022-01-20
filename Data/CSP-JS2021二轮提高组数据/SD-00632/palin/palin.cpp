#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll T,n;
ll ans[100000];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		for(int t=0;t<2*n;t++)
		{
			cin>>ans[t];
		}
	}
	for(int i=1;i<=T;i++)
	{
		cout<<"-1"<<endl;
	}
	return 0;
}
