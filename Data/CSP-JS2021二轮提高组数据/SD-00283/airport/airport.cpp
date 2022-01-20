#include<iostream>
#include<cstdio>
using namespace std;
int n,m1,m2,ans,cnt,vis[100000],vis2[100000];
struct shike{
	int a,b;
}g[100000],w[100000];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i=0;i<m1;i++)
	{
		scanf("%d%d",&g[i].a,&g[i].b);
	}
	for (int i=0;i<m2;i++)
	{
		scanf("%d%d",&w[i].a,&w[i].b);
	}
	int r=0;
	if (m1>m2) r=m1;
		else r=m2;
	for (int i=0;i<m1;i++)
	{
		for (int j=i+1;j<m1;j++)
		{
			if (g[i].a>g[j].a){
				shike t;
				t=g[i];g[i]=g[j];g[j]=t;
			}
		}
	}		
	for (int i=0;i<m2;i++){
		for (int j=i+1;j<m2;j++)
		{
			if(w[i].a>w[j].a)
			{
				shike t;
				t=w[i];w[i]=w[j];w[j]=t;
			}
		}
	}
	for (int i=0;i<=n;i++)
	{
		if (i!=n){
			for (int j=0;j<m2;j++)
			{
				if (j<n-i){
					vis[j]=w[j].b;
					cnt++;
				}
				else{
					for (int k=0;k<n-i;k++)
					{
						if (w[j].a>vis[k]){
							vis[k]=w[j].b;
							cnt++;
							break; 
						}
					}
				}
			}
		}
		if (i!=0){
			for (int j=0;j<m1;j++)
			{
				if (j<i){
					vis2[j]=g[j].b;
					cnt++;
				}
				else{
					for (int k=0;k<i;k++)
					{
						if (g[j].a>vis2[k]){
							vis2[k]=g[j].b;
							cnt++;
							break;
						}
					}
				}
			}	
		}
		if (ans<cnt){
			ans=cnt;
		}
		cnt=0;	
		for (int j=0;j<r;j++)
		{
			vis[j]=vis2[j]=0;
		}
	}
	printf("%d",ans);
	return 0;
} 
