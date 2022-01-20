#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>

typedef long long ll;
const int maxn=1e5+3;

using namespace std;

struct node{
	int l,r,sum,jin,xi;
}a[maxn];
int n,m1,m2,x,y,z,ans1[maxn],ans2[maxn];
bool b[maxn];

int cmp(node x,node y)
{
	return x.l<y.l; 
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	scanf("%d%d",&a[i].l,&a[i].r),a[i].jin=1;
	for(int i=m1+1;i<=m1+m2;i++)
	scanf("%d%d",&a[i].l,&a[i].r),a[i].jin=2;
	sort(a+1,a+1+m1,cmp);
	sort(a+1+m1+1,a+1+m1+1+m2,cmp);
	for(int j=1;j<=m1;j++)
	{
		int ans=0,maxx=a[j].r;
		for(int k=j+1;k<=m1;k++)
		{
			if(a[k].l>maxx) break;
			ans++;
		 } 
		a[j].sum=ans; 
	}
	for(int j=m1+1;j<=m1+m2;j++)
	{
		int ans=0,maxx=a[j].r;
		for(int k=j+1;k<=m1+m2;k++)
		{
			if(a[k].l>maxx) break;
			ans++;
		} 
		a[j].sum=ans;
	}
	int max1=0;
	for(int i=1;i<=m1;i++)
	max1=max(max1,a[i].sum);
	int max2=0;
	for(int j=m1+1;j<=m1+m2;j++)
	max2=max(max1,a[j].sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

