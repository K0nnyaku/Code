#include <cstdio>
#include <iostream>
using namespace std;
int n,m1,m2,maxx1=0,maxx2=0,jw,ans,maxxz=0;
struct node1
{
	int a1;
	int b1;
	int c1;
	int d;
}gn[100010];
struct node2
{
	int a2;
	int b2;
	int c2;
	int d;
}gw[100010];
int hb1[100000010],hb2[100000010];
int gnhb(int x)
{
	gn[x].c1=0;
	for(int i=1;i<=maxx1;i++)
	{
		if(hb1[i]>0)
		{
			if(jw<x)
			{
				jw++;
				gn[x].c1++;
				gn[hb1[i]].d++;
			}
		}
		else if(hb1[i]<0)
		{
			if(jw>0&&gn[0-hb1[i]].d!=0)
			{
				jw--;
			}
		}
	}
	jw=0;
	return gn[x].c1;
}
int gwhb(int y)
{
	gw[y].c2=0;
	for(int i=1;i<=maxx2;i++)
	{
		if(hb2[i]>0)
		{
			if(jw<y)
			{
				jw++;
				gw[y].c2++;
				gw[hb2[i]].d++;
			}
		}
		else if(hb2[i]<0)
		{
			if(jw>0&&gw[0-hb2[i]].d!=0)
			{
				jw--;
			}
		}
	}
	jw=0;
	return gw[y].c2;
}int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n;
	cin>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>gn[i].a1>>gn[i].b1;
		hb1[gn[i].a1]=i;
		hb1[gn[i].b1]=-i;
		if(gn[i].b1>maxx1)
		{
			maxx1=gn[i].b1;
		}
	}
	
	for(int i=1;i<=m2;i++)
	{
		cin>>gw[i].a2>>gw[i].b2;
		hb2[gw[i].a2]=i;
		hb2[gw[i].b2]=-i;
		if(gw[i].b2>maxx2)
		{
			maxx2=gw[i].b2;
		}	
	}
	for(int i=0;i<=n;i++)
	{
		ans=gnhb(i)+gwhb(n-i);
		if(maxxz<=ans)
		{
			maxxz=ans;
		}
	}
	cout<<maxxz<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
