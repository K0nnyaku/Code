#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct feiji{
	int arr,lea;
}a[MAXN],b[MAXN];
int n,m1,m2,maxn;
bool cmp(feiji a,feiji b)
{
	return a.arr<b.arr;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
	{
		scanf("%d%d",&a[i].arr,&a[i].lea);
	}
	for(int i=1;i<=m2;++i)
	{
		scanf("%d%d",&b[i].arr,&b[i].lea);
	}
	printf("%d",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
