#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<queue>
#define maxn 2000006
inline int read()
{
	int f=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
struct node
{
	int l,q;
}nei[maxn],ji[maxn];
struct noe
{
	int w,ta;
}fnei[maxn],fji[maxn];

int cmp(node x,node y)
{
	return x.l<y.l;
}
int vis1[maxn],vis2[maxn],cnt=0;
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,zui1=-9999,zui2=-9999;
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
	{
		nei[i].l=read(),nei[i].q=read();
		zui1=max(zui1,nei[i].q);
		fnei[nei[i].l].w=-1,fnei[nei[i].q].w=1;
		fnei[nei[i].l].ta = fnei[nei[i].q].ta=i;
	}
	for(int i=1;i<=m2;i++)
	{
		ji[i].l=read(),ji[i].q=read();
		zui2=max(zui2,ji[i].q);
		fji[ji[i].l].w=-1,fji[ji[i].q].w=1;
		fji[ji[i].l].ta = fji[ji[i].q].ta=i;
	}
	sort(nei+1,nei+m1+1,cmp);
	sort(ji+1,ji+m2+1,cmp);
	int ans=0,t;
	t=max(zui1,zui2);
	for(int k=0;k<=n;k++)
	{
		if(cnt>=25000000)
		{
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=t;i++)
		{
			vis1[i]=0;
			vis2[i]=0;
		}
		int cc=n-k,ans1=0,ans2=0,c=k;
		for(int i=1;i<=zui1;i++)
		{
			//cout<<fnei[i].w<<"!!"<<c<<"!!"<<vis1[fnei[i].ta]<<endl;
			if(fnei[i].w==-1&&c>0&&vis1[fnei[i].ta]==0)
			{
				vis1[fnei[i].ta]=1;
				ans1++;
				c--;
			}
			if(fnei[i].w==1&&c<k&&vis1[fnei[i].ta]==1)
			{
				//ans1++;
				c++;
			}
			cnt++;
		} 
		for(int i=1;i<=zui2;i++)
		{
			if(fji[i].w==-1&&cc>0&&vis2[fji[i].ta]==0)
			{
				vis2[fji[i].ta]=1;
				ans2++;
				cc--;
			}
			if(fji[i].w==1&&cc<n&&vis2[fji[i].ta]==1)
			{
				//ans1++;
				cc++;
			}
			cnt++;
		}
		//cout<<ans1<<"!!!"<<ans2<<endl;
		ans=max(ans,ans1+ans2);
	}
	cout<<ans;
	return 0;
}
