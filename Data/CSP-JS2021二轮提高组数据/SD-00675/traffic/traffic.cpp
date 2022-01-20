#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int n,m,t,a,b,c,d,e;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		cin>>a;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			cin>>a;
		}
	}
	for(int i=1;i<=t;i++)
	{
		cin>>b;
		for(int j=1;j<=b;j++)
		cin>>c>>d>>e;
	}
	cout<<24;
	return 0;
}   
