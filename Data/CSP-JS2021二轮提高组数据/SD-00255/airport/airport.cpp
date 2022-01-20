#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long i;
int ans=0,ans1=0;
long long gnj[100000],gnc[100000],gwj[100000],gwc[100000];
long long gwjc,gnjc,s,z,q,p;
long long abc[100000];
void gn(long long a,long long b,long long i,long long z)
{
	if(a==i&&gnjc>0)
	{
		gnjc--;
		ans1++;
		abc[z]=1;
	}
	if(b==i&&abc[z]==1)
	{
	gnjc++;
	abc[z]==0;
}
}
void gw(long long a,long long b,long long i,int s)
{
	if(a==i&&gwjc>0)
	{
		gwjc--;
		ans1++;
		abc[s]==1;
	}
	if(b==i&&abc[s]==1)
	{
	gwjc++;
	abc[s]==0;
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,cx;
	cin>>n>>m1>>m2;
	long long MAXN1=0,MAXN2=0; 
	for(int i=0;i<m1;i++)
	{
		cin>>gnj[i]>>gnc[i];
		MAXN1=max(MAXN1,gnc[i]);
	 } 
	for(int i=0;i<m2;i++)
	{
		cin>>gwj[i]>>gwc[i];
		MAXN2=max(MAXN2,gwc[i]);
	}
		for(int y=0;y<n;y++)
		{
			gnjc=y;
			ans1=0;
			gwjc=n-gnjc;
			cx=gwjc;
			for(q=0;q<MAXN1;q++)
			{
				if(y==0)
				break;
				for(z=0;z<m1;z++)
				gn(gnj[z],gnc[z],q,z);
			}
			for(p=0;p<MAXN2;p++)
			{
				if(cx==0)
				break;
				for(s=0;s<m2;s++)
				gw(gwj[s],gwc[s],p,s);
			}
			if(ans<ans1)
			ans=ans1;
		}
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
