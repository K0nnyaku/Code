#include<iostream>
#include<cstdio>
using namespace std;
int a[500005],b[500005],o[500005],t[500005];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n,left,right,ans1,ans2;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ans1=0,ans2=0;
		cin>>n;
		left=1;
		right=2*n;
		if(n>1000)
		{
			for(int i=0;i<n;i++)
				cout<<"L";
			cout<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
