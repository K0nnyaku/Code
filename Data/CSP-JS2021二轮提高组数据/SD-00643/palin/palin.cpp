#include<iostream>
#include<cstdio>
using namespace std;
int a[1000005];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,temp=0;
		cin>>n>>a[1];
		n=2*n;
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==a[i-1])
				temp++;
		}
		if(temp>=3)
		{
			cout<<-1<<endl;
			continue;
		}
		if(temp==2)
		{
			int l,r;
			for(l=1;l<=n&&a[l]!=a[l-1];l++)
				cout<<"L";
			for(r=n;r>0&&a[r]!=a[1];r--)
				cout<<"R";
			for(;l<=r;l++)
				cout<<"L";
		}
		else
			for(int i=1;i<=n;i++)
				cout<<"L";
		cout<<endl;
	}
	return 0;
}
