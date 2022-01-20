#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,q,qq,o[200500],ysz[200500],ent,eent,yszz[200500],qjz[200500],qjzz[200500],Min=99999999,l,r,ans,sjz[100000000];
struct as
{
	long long ks,js;
}a[200500];
struct sa
{
	long long ks,js;
}b[200500];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&mm);
	ent=1;
	for(int i=1;i<=m;i++)
	{
		l=max(ent,l);
		scanf("%lld%lld",&q,&qq);
		for(int j=1;j<=ent;j++)
		{			
			if(j==ent)
			{
				a[ent].js=qq;
				a[ent].ks=q;
				o[ent]++;
				ent++;
				break;
			}
			if(q>=a[j].js)
			{
				a[j].js=qq;
				a[j].ks=q;
				o[j]++; 
				break;
			}

		}
	}
	for(int i=l;i>=1;i--)
	{
		qjz[l-i+1]=qjz[l-i]+o[i];
		o[i]=0; 
	 }
	qjz[0]=0;
	ent=1;
	for(int i=1;i<=mm;i++)
	{
		r=max(ent,r);
		scanf("%lld%lld",&q,&qq);
		for(int j=1;j<=ent;j++)
		{			
			if(j==ent)
			{
				b[ent].js=qq;
				b[ent].ks=q;
				o[ent]++;
				ent++;
				break;
			}
			if(q>=b[j].js)
			{
				b[j].js=qq;
				b[j].ks=q;
				o[j]++;
				break;
			}

		}
	}
	for(int i=r;i>=1;i--)
	{
		qjzz[r-i+1]=qjzz[r-i]+o[i];
		o[i]=0; 
	 } 
	qjzz[0]=0;
	long long ll=0;
	ll=l+r;
	ll-=n;
	for(int i=ll-r;i<=ll&&i<=l&&r-ll+i>=0;i++)
	{
		Min=min(Min,qjz[i]+qjzz[ll-i]);
	}
	ans=(m+mm)-Min;
	printf("%lld",ans);
}
