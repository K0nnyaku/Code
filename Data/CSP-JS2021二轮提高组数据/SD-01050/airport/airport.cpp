#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int in,out;
}a[100001],b[100001];
int ans=0,sum1=0,sum2=0;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	int n1=n,n2=0;
	for(int i=1;i<=m1;i++)
		cin>>a[i].in >>a[i].out ;
	for(int i=1;i<=m2;i++)
		cin>>b[i].in >>b[i].out ;
	while(n2<=n)
	{
		int tot1=0;
		for(int i=1;i<=m1;i++)
		{
			if(tot1<=n1)
			{
				if(a[i].out <=a[i+1].in )
				{
					sum1++;
					
					tot1++;
				}
			}
		}
		int tot2=0;
		for(int i=1;i<=m2;i++)
		{
			if(tot2<=n2)
			{
				if(b[i].out <=b[i+1].in )
				{
					sum2++;
					
					tot2++;
				}
			}
		}
		ans=max(ans,sum1+sum2);
		n1--;
		n2++;
	}
	cout<<n;
	return 0;
}

