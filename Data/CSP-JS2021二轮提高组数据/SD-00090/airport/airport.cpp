#include<iostream> 
#include<iomanip> 
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int ans,gn,gw,lq[1005][1005],n,m1,m2,a1[2][1005],a2[2][1005],gnn,gww;
int mmax(int a,int b){
	return a > b ? a : b;
};

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>a1[0][i]>>a1[1][i];
	}
	for(int i=0;i<m2;i++){
		cin>>a2[0][i]>>a2[1][i];
	}
	sort(a1[0],a1[0]+m1+1);
	sort(a2[0],a2[0]+m2+1);
	for(int i=0;i<=n;i++)
	{
		gn=i;gw=n-i;
		for(int j=0;j<m1;j++)
		{
			
			if(gn==0&&j==0){break;}
			else if(j==0)
			{
				gnn++;
				for(int k=a1[0][j];k<=a1[1][j];k++)
				{
					lq[0][k]=1;
				}
			}
			else
			{
				for(int k=0;k<gn;k++)
				{
					if(lq[k][a1[0][j]]==0)
					{
						gnn++;
						for(int z=a1[0][j];z<=a1[1][j];z++)
						{
							lq[j][z]=1;
						
						}
					}
				}
			}
		}
		lq[1005][1005]=0;
		for(int j=0;j<m2;j++)
		{
			
			if(gw==0&&j==0){break;}
			else if(j==0)
			{
				gww++;
				for(int k=a2[0][j];k<=a2[1][j];k++)
				{
					lq[0][k]=1;
				}
			}
			else
			{
				for(int k=0;k<gw;k++)
				{
					if(lq[k][a2[0][j]]==0)
					{
						gww++;
						for(int z=a2[0][j];z<=a2[1][j];z++)
						{
							lq[j][z]=1;
						}
					}
				}
			}
		}
		lq[1005][1005]=0;
		ans=mmax(gww+gnn,ans);
		gnn=0;gww=0;
	}
	printf("%d",ans);
	return 0;
}
