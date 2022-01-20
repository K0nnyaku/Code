#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n;
	cin>>t;
	if(t==1)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		cin>>a[i];
		cout<<-1;
		return 0;
	}
	while(t--)
	{
		cin>>n;
		int k=0;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
			if(a[i]==a[i-1])
			k++;
		}
		if(k>2)
		{
			cout<<-1;
			break;
		}
		int x=a[1];
		int y=a[n];
		if(a[n]>a[1])
		for(int i=1;i<n;i++)
		cout<<"L";
		else
		for(int i=1;i<n;i++)
		cout<<"R";
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
