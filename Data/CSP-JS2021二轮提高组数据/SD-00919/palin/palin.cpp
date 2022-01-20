#include<bits/stdc++.h>
using namespace std;
int n,T;
const int N=5e5;
int a[N];
int num;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=2*n;i++)
			for(int j=2*n;j>=1;j--)
				if(a[i]=a[j]) num++;
		if(num==2*n)
		{
			for(int i=1;i<=n;i++)
			cout<<"LR";
		}
	}
	return 0;
	
}
