#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	int hin,hut;
}H[100005];
int n,m1,m2;
int ans=0;
bool parking[100005];
bool cmp(node a,node b)
{
	return a.hin<b.hin;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	memset(parking,0,sizeof(parking));
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) {
		scanf("%d%d",&H[i].hin,&H[i].hut);
	}
	for(int i=m1+1;i<=m1+m2;i++) {
		scanf("%d%d",&H[i].hin,&H[i].hut);
	}
	sort(H+1,H+1+m1,cmp);
	sort(H+1+m1,H+1+m1+m2,cmp);
	for(int i=0;i<=n;i++) {
		memset(parking,0,sizeof(parking));
		int guonei=i,guowai=n-i,sum=0;
		for(int j=1;j<=m1;j++) {
			for(int k=j-1;k>=1;k--) {
				if(parking[k]==1) {
					if(H[j].hin>=H[k].hut)
					{
						guonei++;
						parking[k]=0;
					}
				}
			}
			if(guonei>0){
				guonei--;
				parking[j]=1;
				sum++;
			}
		}
		for(int j=m1+1;j<=m1+m2;j++) {
			for(int k=j-1;k>=m1+1;k--) {
				if(parking[k]==1) {
					if(H[j].hin>=H[k].hut)
					{
						guowai++;
						parking[k]=0;
					}
				}
			}
			if(guowai>0){
				guowai--;
				parking[j]=1;
				sum++;
			}
		}
		if(sum>ans)
		{
			ans=sum;
		}
	}
	printf("%d\n",ans);
	return 0;
}

