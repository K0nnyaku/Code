#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath> 
#include<algorithm>
#include<vector>
#define MAXN 100000007
using namespace std;
int n,m1,m2,hx[100010],i,j,aaa[100000],bbb[100000],ffmax;
struct nFJ{
	int dd;
	int lk;
}gn[100010];
struct wFJ{
	int dd;
	int lk;
}gw[100010];
bool cmp(nFJ a,nFJ b)
{
	return a.dd<b.dd;
}
bool cMp(wFJ a,wFJ b)
{
	return a.dd<b.dd;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(i=1;i<=m1;i++)
		{
		scanf("%d",&gn[i].dd);
		scanf("%d",&gn[i].lk);
		}
	for(i=1;i<=m2;i++) 
		{
		scanf("%d",&gw[i].dd);
		scanf("%d",&gw[i].lk);
		}
	sort(gn+1,gn+1+m1,cmp);
	sort(gw+1,gw+1+m2,cMp);
	for(int kk=1;kk<=m1;kk++)
		{
		aaa[kk]=gn[kk].lk;
		}
	for(int kk=1;kk<=m1;kk++)
		{
		bbb[kk]=gn[kk].lk;
		}	
	for(int gnlq=0;gnlq<=n;gnlq++)
		{
		if(gnlq==2)
			{
			for(int kk=1;kk<=m1;kk++)
				{
				gn[kk].lk=aaa[kk];
				}
			}
		if(gnlq==n-2)
			{
			for(int kk=1;kk<=m1;kk++)
				{
				gw[kk].lk=bbb[kk];
				}
			}
		int gnzd=gnlq,gwzd=n-gnlq,fjs=0;
		int gndq=0,gwdq=0;
		memset(hx,0,sizeof(hx));
		for(i=1;i<=m1;i++) 		//guonei 
			{
			int bj=0; 
			for(j=1;j<=i-1;j++)
				{
				if((gn[i].dd>=gn[j].lk&&hx[j]==0&&gnzd!=0))
					{
					
					fjs++;
					hx[j]=1;
					bj=1;
					if(gnlq==1)
						{
						for(int kk=1;kk<=i-1;kk++)
							{
							gn[kk].lk=MAXN;
							}	
						}
					break;
					}
				}
			if(bj==0)
				{
				if(gndq<gnzd)
					{
					gndq++;
					fjs++;
					}
				}
			}
		memset(hx,0,sizeof(hx));
		for(i=1;i<=m2;i++) 		//guowai
			{
			int bj=0; 
			for(j=1;j<=i-1;j++)
				{
				if((gw[i].dd>=gw[j].lk&&hx[j]==0&&gwzd!=0))
					{
					
					fjs++;
					hx[j]=1;
					bj=1;
					if(n-gnlq==1)
						{
						for(int kk=1;kk<=i-1;kk++)
							{
							gw[kk].lk=MAXN;
							}	
						}
					break;
					}
				}
			if(bj==0)
				{
				if(gwdq<gwzd)
					{
					gwdq++;
					fjs++;
					}
				}
			}
		ffmax=max(fjs,ffmax);
		}
	cout<<ffmax;
	return 0;
}
//	int low=n,high=m1+m2,middle;	
//	while(low<high)
//		{
//		int kk=1,ij,lq=0;
//		memset(lks,0,sizeof(lks));
//		middle=(high+low)/2;
//		for(i=1;i<=m1+m2;i++)
//			{
//			if(i!=1) 
//				{
//				lks[1][kk]=fj[i-1].lk;
//				lks[0][kk]=fj[i-1].gnw;
//				}
//			sort(lks[1]+1,lks[1]+1+kk);
//			for(ij=1;ij<=kk;ij++)
//				{
//				if(fj[i].dd>=lks[1][ij]&&!hx[ij]&&lks[0][ij]==fj[i].gnw)
//					{
//					hx[ij]=1;
//					break;
//					}
//				}
//			if(ij==kk) lq++;
//			
//			if(i!=1) kk++;
//			if(i==middle) break;
//			}
//		if(lq>n) high=middle;
//		else if(lq<n) low=middle;
//		else if(lq==n) ffmax=max(ffmax,middle);
//		cout<<low<<" "<<high<<endl;
//		if(low==high-1) 
//			{
//			cout<<233;
//			break;
//			}		
//		}
//	cout<<endl;
//	cout<<middle;
