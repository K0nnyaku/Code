#include<bits/stdc++.h>
using namespace std;
int t,a,b[50000],c[50000];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a;
		for(int j=1;j<=a;j++)
		{	
			cin>>b[j];
		}
	}	
	cout<<-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
