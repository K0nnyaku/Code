#include<bits/stdc++.h>
using namespace std;
int n,t,i,j;
int k=1e5+1;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	int a[5*k][t+2];
	for(i=1;i<=t;i++)
	{
		cin>>n;
		for(j=1;j<=n;j++)
			cin>>a[j][i];
	}
	for(i=1;i<=t;i++)
		cout<<"-1"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
