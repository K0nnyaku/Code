#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
long long quickpower(int a,int b)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)	ans*=base;
		base*=base;
		b>>=1;
	}
	return ans;
}
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
struct node
{
	int jin,chu;
};
node a[100100],b[100100];
bool cmp(node a,node b)
{
	return a.jin<b.jin;
}
int vis[100000010];
int n,m1,m2;
long long ans;
long long sech1(int x)
{
	long long total=0;
	for(int i=0;i<m1;i++)
	{
		if(vis[a[i].jin]<x)
		{
			for(int j=a[i].jin;j<=a[i].chu;j++) vis[j]++;
			total++;
		}
	}
	for(int i=a[i].jin;i<=a[m1-1].chu;i++)
		vis[i]=0;
	return total;
}
long long sech2(int x)
{
	long long total=0;
	for(int i=0;i<m2;i++)
	{
		if(vis[b[i].jin]<x)
		{
			for(int j=b[i].jin;j<=b[i].chu;j++) vis[j]++;
			total++;
		}
	}
	for(int i=b[i].jin;i<=b[m2-1].chu;i++)
		vis[i]=0;
	return total;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1;i++)
		scanf("%d%d",&a[i].jin,&a[i].chu);
	for(int i=0;i<m2;i++)
		scanf("%d%d",&b[i].jin,&b[i].chu);
	sort(a,a+m1,cmp);
	sort(b,b+m2,cmp);
	for(int i=0;i<=n;i++)
		if(ans<sech1(i)+sech2(n-i))	ans=sech1(i)+sech2(n-i);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

