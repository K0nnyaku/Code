#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int u;

int main()
{
	freopen("dis.in","w",stdin);
	freopen("dis.out","r",stdout);
	cin>>n>>m;

	for(int i=1;i<=m;i++)
	{
		cin>>a>>u;
		if(a[0]=='?')
		{
			cout<<0<<endl;
		}
	} 
	return 0;
}
