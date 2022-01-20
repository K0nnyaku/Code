#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>

using namespace std;

struct sj
{
	long long dao,li;
};
const long long N = 100001;
const long long M = 10e7+1;
long long a,b,c;
sj gn[N],gw[N];

int gnz[M];
int gnsf[M];
int gwz[M];
int gwsf[M];

int  gnd(int li)
{	
	if(li==0) return 0;
	int p[100001];
	int u=1;
	int k=0;
	memset(p,-1,sizeof(p));
	for(int i=0;i<b;++i)
	{
		if(gnsf[i]==0){
			for(int j=gn[i].dao;j<=gn[i].li;++j)
			{
				if(p[j]==0)
				{
					u=0;
					break;
				}
				
			}
			if(u==0)
				{
					u=1;
					continue;
				}
				++k;
				gnsf[i]=1;
				for(int j=gn[i].dao;j<=gn[i].li;++j){
					p[j]=0;
				}
			
		}
	}
	gnz[li]=gnz[li-1]+k;
	return 0;
 } 


int  gwd(int li)
{	
	if(li==0) return 0;
	int p[100001];
	int u=1;
	int k=0;
	memset(p,-1,sizeof(p));
	for(int i=0;i<c;++i)
	{
		if(gwsf[i]==0){
			for(int j=gw[i].dao;j<=gw[i].li;++j)
			{
				if(p[j]==0)
				{
					u=0;
					break;
				}
			}
			if(u==0)
				{
					u=1;
					continue;
				}
				++k;
				gwsf[i]=1;
				for(int j=gw[i].dao;j<=gw[i].li;++j){
					p[j]=0;
				}
		}
	}
	gwz[li]=gwz[li-1]+k;
	return 0;
 } 



int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.ans","w",stdout);
	scanf("%lld %lld %lld",&a,&b,&c);
	for(int i=0;i<b;++i)
	{
		scanf("%lld %lld",&gn[i].dao,&gn[i].li);
	}
	for(int i=0;i<c;++i)
	{
		scanf("%lld %lld",&gw[i].dao,&gw[i].li);
	}
	memset(gnsf,0,sizeof(gnsf));
	memset(gnz,0,sizeof(gnz));
	memset(gwz,0,sizeof(gwz));
	memset(gwsf,0,sizeof(gwsf));
	for(int x=0;x<=a;++x)
	{	
		gwd(x);
		gnd(x);
	}
	int ans=0;
	for(int i=0;i<a;++i)
	{
		ans=max(ans,gwz[i]+gnz[a-i]);
	}
	cout<<ans;
	
	return 0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
