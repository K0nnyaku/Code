#include<bits/stdc++.h>
using namespace std;
struct nair{
	int s,e;
}a[100001];
struct iair{
	int s,e;
}b[100001];
struct grn{
	int maxn,nu;
}gn[100001];
struct gri{
	int maxn,nu;
}gi[100001];
int n,mn,mi,fl;
bool cmpn(nair x,nair y)
{
	return x.s<y.s;
}
bool cmpi(iair x,iair y)
{
	return x.s<y.s;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&mn,&mi);
	for(int i=1;i<=mn;i++)
		scanf("%d%d",&a[i].s,&a[i].e);
	for(int i=1;i<=mi;i++)
		scanf("%d%d",&b[i].s,&b[i].e);
	sort(a+1,a+mn+1,cmpn);
	sort(b+1,b+mi+1,cmpi);
	gn[1].maxn=a[1].e;
	gn[1].nu=1;
	int numn=1,numi=1;
	gi[1].nu=1;
	gi[1].maxn=b[1].e;
	for(int i=2;i<=mn;i++)
	{
		for(int j=1;j<=numn;j++)
		{
			if(a[i].s>gn[j].maxn)
			{
				gn[j].nu++;
				gn[j].maxn=a[i].e;
				fl=1;
				break;
			}
		}
		if(fl==0)
		{
			numn++;
			gn[numn].nu=1;
			gn[numn].maxn=a[i].e;
		}
		fl=0;
	}
	fl=0;
	for(int i=2;i<=mi;i++)
	{
		for(int j=1;j<=numi;j++)
		{
			if(b[i].s>gi[j].maxn)
			{
				gi[j].nu++;
				gi[j].maxn=b[i].e;
				fl=1;
				break;
			}
		}
		if(fl==0)
		{
			numi++;
			gi[numi].nu=1;
			gi[numi].maxn=b[i].e;
		}
		fl=0;
	}
	int ans=-1;
	for(int i=0;i<=n;i++)
	{
		int temp=0;
		for(int j=1;j<=i;j++)temp+=gn[j].nu;
		for(int j=1;j<=n-i;j++)temp+=gi[j].nu;
		ans=max(ans,temp);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
