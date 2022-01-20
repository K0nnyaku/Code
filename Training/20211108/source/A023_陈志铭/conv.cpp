#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,a[N],b[N];
int c[N];

int main()
{
	freopen("conv.in","r",stdin);
	freopen("conv.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);	
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i]=max(a[j]+b[(i-j+n)%n],c[i]);
		}
	}
	for(int i=0;i<n;i++) printf("%d ",c[i]);
	return 0;
}
