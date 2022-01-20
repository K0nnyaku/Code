#include<bits/stdc++.h>
using namespace std;
struct hb{
	int dd;
	int lk;
};
hb gn[100010],gj[100010];
int jq[100010];
int px(hb x,hb y)
{
	return x.dd<y.dd;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,maxx=0,gnjq,gjjq;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	  scanf("%d%d",&gn[i].dd,&gn[i].lk);
	for(int i=1;i<=m2;i++)
	  scanf("%d%d",&gj[i].dd,&gj[i].lk);
	gnjq=0;gjjq=n;
	sort(gn+1,gn+m1+1,px);
	sort(gj+1,gj+m2+1,px);
	while((gjjq>=0)&&(gnjq>=0))
	{
		int zs=0;
		memset(jq,0,sizeof(jq));
		for(int i=1;i<=m1;i++)
		{
			int sj=gn[i].dd;
			for(int j=1;j<=gnjq;j++)
			{
				if((jq[j]!=0)&&(gn[jq[j]].lk<sj))
				  jq[j]=0;
			}
			for(int j=1;j<=gnjq;j++)
			{
				bool pd=false;
				if(jq[j]==0)
				{
					jq[j]=i;
					zs++;
					pd=true;
				}
				if(pd==true)
				  break;
			}
		}
		for(int i=1;i<=m2;i++)
		{
			int sj=gj[i].dd;
			for(int j=gnjq+1;j<=n;j++)
			{
				if((jq[j]!=0)&&(gj[jq[j]].lk<sj))
				  jq[j]=0;
			}
			for(int j=gnjq+1;j<=n;j++)
			{
				bool pd=false;
				if(jq[j]==0)
				{
					jq[j]=i;
					zs++;
					pd=true;
				}
				if(pd==true)
				  break;
			}
		}
		if(maxx<zs)
		  maxx=zs;
		gnjq++;
		gjjq--;
	}
	printf("%d",maxx);
	return 0;
}
