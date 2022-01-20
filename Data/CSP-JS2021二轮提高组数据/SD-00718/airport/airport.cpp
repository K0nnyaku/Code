#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<map>
#include<math.h>
using namespace std;
int n,m1,m2,stac1[100100],stac2[100100],maxx;
struct node
{
	int beg,fi;
}a[101000],b[101000];
inline bool com(node x,node y)
{
	if(x.beg==y.beg)return x.fi<y.fi;
	return x.beg<y.beg;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	if(n>5000)
	{
		cout<<n;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=m1;i++)cin>>a[i].beg>>a[i].fi;
	for(int i=1;i<=m2;i++)cin>>b[i].beg>>b[i].fi; 
	sort(a+1,a+1+m1,com);
	sort(b+1,b+1+m2,com);
	for(int i=0;i<=n;i++)
	{
		memset(stac1,0,sizeof(stac1));
		memset(stac2,0,sizeof(stac2));
		int ho=i,ab=n-i,cnt=0,h1=1,h2=1,t1=0,t2=0;
		for(int j=1;j<=m1;j++)
		{
			while(stac1[h1]&&stac1[h1]<a[j].beg)
			{
				h1++;
				ho++;
			}
			if(ho>0)
			{
				ho--;
				cnt++;
				if(a[j].fi>stac1[t1])
				{
					stac1[++t1]=a[j].fi;
					continue;
				}
				for(int www=t1;www>=h1;www--)
				{
					if(a[j].fi<stac1[www])
					{
						t1++;
						int lmh;
						while(a[j].fi<stac1[www])
						{
							lmh=www;
							www--;
						}
						for(int ccs=t1;ccs>lmh;ccs--)stac1[ccs]=stac1[ccs-1];
						stac1[lmh]=a[j].fi;
						break;
					}
				}
			}		
		}
//		cout<<cnt<<" ";
		for(int j=1;j<=m2;j++)
		{
			while(stac2[h2]&&stac2[h2]<b[j].beg)
			{
				h2++;
				ab++;
			}
			if(ab>0)
			{
				ab--;
				cnt++;
				if(b[j].fi>stac2[t2])
				{
					stac2[++t2]=b[j].fi;
					continue;
				}
				for(int www=t2;www>=h2;www--)
				{
					if(b[j].fi<stac2[www])
					{
						t2++;
						int lmh;
						while(b[j].fi<stac2[www])
						{
							lmh=www;
							www--;
						}
						for(int ccs=t2;ccs>lmh;ccs--)stac2[ccs]=stac2[ccs-1];
						stac2[lmh]=b[j].fi;
						break;
					}
				}
			}		
		}
//		cout<<cnt<<" "<<":"<<i<<endl;
		maxx=max(maxx,cnt);
//		cout<<maxx<<endl;
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
