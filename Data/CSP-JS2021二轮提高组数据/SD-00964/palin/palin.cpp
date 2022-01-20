#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,que[1000005],a[1000005];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		for(int j=1;j<=2*m;j++)
		{
			cin>>a[j];	
		}	
	 
		for(int o=1;o<=2*m;o++)
		{
			que[i]=((o%5)*(o*7))%2;
			if(que[o]==1)
			{
				cout<<"L"; 
			}
			if(que[o]==0)
			{
				cout<<"R";
			}
		}
	}
	return 0;
}


