#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
ll t,a[15];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ll n; cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n==1) cout<<"L"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
