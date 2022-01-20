#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;
struct fei
{
	int beg,endd;
};
fei a1[100010],a2[100010];
int n,m1,m2,gns,gjs,gn[100010],gj[100010];
long long ans,lmax;
bool cmp(fei x,fei y)
{
	return x.beg<y.beg;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//cin>>n>>m1>>m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		//cin>>a1[i].beg>>a1[i].endd;
		scanf("%d%d",&a1[i].beg,&a1[i].endd);
	}
	for(int i=1;i<=m2;i++)
	{
		//cin>>a2[i].beg>>a2[i].endd;
		scanf("%d%d",&a2[i].beg,&a2[i].endd);
	}
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	for(int lang=0;lang<=n;lang++)
	{
		ans=0;
		gns=lang;
		gjs=n-lang;
		if(gns!=0)
		{
			ans+=gns;
			for(int i=1;i<=gns;i++)
			{
				gn[i]=a1[i].endd;
			}
			for(int i=gns;i<=m1;i++)
			{
				for(int j=1;j<=gns;j++)
				{
					if(a1[i].beg>=gn[j])
					{
						gn[j]=a1[i].endd;
						ans++;
						break;
					}
				}
			}
		}
		else ;
		if(gjs!=0)
		{
			ans+=gjs;
			for(int i=1;i<=gjs;i++)
			{
				gj[i]=a2[i].endd;
			}
			for(int i=gjs;i<=m2;i++)
			{
				for(int j=1;j<=gjs;j++)
				{
					if(a2[i].beg>=gj[j])
					{
						gj[j]=a2[i].endd;
						ans++;
						break;
					}
				}
			}
		}
		else ;
		lmax=max(lmax,ans);
	}
	cout<<lmax;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
