#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int n,a[200001],b[200001],c[200001];
int main()
{
	freopen("conv.in","r",stdin);
	freopen("conv.out","w",stdout);
	scanf("%d",&n);
	for(register int i=0;i<n;i++) scanf("%d",&a[i]);
	for(register int j=0;j<n;j++) scanf("%d",&b[j]);
	for(register int i=0;i<n;i++)
		for(register int j=0;j<n;j++)
			c[i]=max(c[i],a[j]+b[(i-j+n)%n]);
	for(register int k=0;k<n;k++) printf("%d ",c[k]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
