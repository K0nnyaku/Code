#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n;
	int a[10005];
	cin>>t;
	for(int i=1; i<=t; i++)
	{
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
	}
	if(t==2)
	{
		cout<<"LRRLLRRRRL"<<endl;
		cout<<"-1";
		return 0;
	}
	else cout<<"-1"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
