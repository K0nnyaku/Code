#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>

//unsigned long long Score=400

using namespace std;
typedef long long ll;
inline ll qread()
{
	char a=getchar();
	ll shu=0,Sign=1;
	while(a<'0'||a>'9'){
		if(a=='-')
			Sign=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9')
	{
		shu=(shu<<3)+(shu<<1)+a-'0';
		a=getchar();
	}
	return shu*Sign;
}
const ll maxn=100001;
struct plane
{
	int l,r;
}fj[2][maxn];
int cmp(plane X,plane Y)
{
	if(X.l!=Y.l)
	{
		return X.l<Y.l;
	}
	return X.r<Y.r;
}
ll n,m1,m2,tot[2][maxn],sum[2][5050][5050],maxx[2],qzh[2][5050];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=qread();m1=qread();m2=qread();
	for(int i=1;i<=m1;i++)
	{
		fj[0][i].l=qread();
		fj[0][i].r=qread();
	}
	for(int i=1;i<=m2;i++)
	{
		fj[1][i].l=qread();
		fj[1][i].r=qread();
	}
	sort(fj[0]+1,fj[0]+m1+1,cmp);
	sort(fj[1]+1,fj[1]+m2+1,cmp);
	bool fd=0;
	for(int i=1;i<=m1;i++)
	{
		
		ll s=fj[0][i].l,t=fj[0][i].r;
		for(int j=1;j<=n;j++)
		{
			fd=1;
			//cout<<i<<" "<<j<<endl;
			for(int k=s;k<=t;k++)
			{
				if(sum[0][j][k]!=0)
				{
				//	cout<<i<<" "<<j<<" FAILED\n";
					fd=0;
					break;
				}
			}
			if(fd)
			{
			//	cout<<s<<" "<<t<<" "<<" "<<j<<endl;
				for(int k=s;k<=t;k++)
				{
					sum[0][j][k]=1;
				}
				if(tot[0][j]==0)
				{
					maxx[0]=j;
				}
				tot[0][j]++;
				break;
			}
		}
	}
	for(int i=1;i<=m2;i++)
	{
		
		ll s=fj[1][i].l,t=fj[1][i].r;
		for(int j=1;j<=n;j++)
		{
			fd=1;
			//cout<<i<<" "<<j<<endl;
			for(int k=s;k<=t;k++)
			{
				if(sum[1][j][k]!=0)
				{
				//	cout<<i<<" "<<j<<" FAILED\n";
					fd=0;
					break;
				}
			}
			if(fd)
			{
			//	cout<<s<<" "<<t<<" "<<" "<<j<<endl;
				for(int k=s;k<=t;k++)
				{
					sum[1][j][k]=1;
				}
				if(tot[1][j]==0)
				{
					maxx[1]=j;
				}
				tot[1][j]++;
				break;
			}
		}
	}
	for(int i=1;i<=maxx[1]+maxx[0];i++)
	{
		//cout<<tot[0][i]<<" ";
		qzh[0][i]=qzh[0][i-1]+tot[0][i];
	}
	for(int i=1;i<=maxx[1]+maxx[0];i++)
	{
		//cout<<tot[1][i]<<" ";
		qzh[1][i]=qzh[1][i-1]+tot[1][i];
	}
	ll ans=-1;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,qzh[0][i]+qzh[1][n-i]);
	}
	cout<<ans<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}


