#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100001;
int n,m1,m2;
ll a1[maxn],b1[maxn],a2[maxn],b2[maxn];
ll l1[maxn],r1[maxn],l2[maxn],r2[maxn];//l1[i],r1[i]第i号廊桥的区间 
int guonei,guoji;
bool pas1(int x)//x为飞机号
{
	for(int t=1;t<=guonei;t++)//t为廊桥号 
	{
		if(a1[x]>r1[t]||b1[x]<l1[t])
		{
			l1[t]=a1[x],r1[t]=b1[x];
			return true;
		}
	}
	return false;
 } 
bool pas2(int x)//x为飞机号
{
	for(int t=1;t<=guoji;t++)//t为廊桥号 
	{
		if(a2[x]>r2[t]||b2[x]<l2[t])
		{
			l2[t]=a2[x],r2[t]=b2[x];
			return true;
		}
	}
	return false;
 } 
 int ans=0;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%lld%lld",&a1[i],&b1[i]);
	for(int i=1;i<=m2;i++) scanf("%lld%lld",&a2[i],&b2[i]);
	for(int i=0;i<=m1;i++)//i为廊桥个数 
	{
		guonei=i;
		guoji=n-guonei;
		int sm1=0,sm2=0;
		for(int j=1;j<=m1;j++)
		{
			if(pas1(j))
			sm1++;
			
		}
		for(int j=1;j<=m2;j++)
		{
			if(pas2(j))
			sm2++;
			
		}
		ans=max(ans,sm1+sm2);
	}
	printf("%d",ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
