#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,m1,m2;
struct a1{
	long long shu1,shu2;
};a1 diyi[100010];

struct a2{
	long long shu3,shu4;
};a2 dier[100010];

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%lld%lld",&diyi[i].shu1,&diyi[i].shu2);
	for(int i=1;i<=m2;i++)
		scanf("%lld%lld",&dier[i].shu3,&dier[i].shu4);
	for(int i=1;i<m1;i++)
		for(int j=1;j<=m1;j++){
			if(diyi[i].shu1>diyi[j].shu1){
				long long sd=diyi[i].shu1;
				diyi[i].shu1=diyi[j].shu1;
				diyi[j].shu1=sd;
				sd=diyi[i].shu2;
				diyi[i].shu2=diyi[j].shu2;
				diyi[j].shu2=sd;
			}
		}
	for(int i=1;i<m1;i++)
		for(int j=1;j<=m1;j++){
			if(dier[i].shu3>dier[j].shu3)
			{
				long long sd=dier[i].shu3;
				dier[i].shu3=dier[j].shu3;
				dier[j].shu3=sd;
				sd=dier[i].shu4;
				dier[i].shu4=dier[j].shu4;
				dier[j].shu4=sd;
			}
		}
	long long jishu,da1=-999,k1,k2,cc,ji,jia=0;
	for(int i=0;i<=n;i++){
		da1=-999;k1=1;k2=1;cc=i;ji=0,jia=0;
		bool v=true,baaa1[100001],baaa2[100001];
		for(int j=1;j<=m1;j++)
			baaa1[j]=true;
		for(int j=1;j<=m2;j++)
			baaa2[j]=true;
		if(cc!=0){
				for(int j=1;j<=m1;j++){
				if(cc==0)
					baaa1[j]=false;
				if(cc>0){
					cc--;
					ji++;
				}
				if(diyi[j].shu1>diyi[k1].shu2&&baaa1[k1]==true){
					k1++;
					cc++;
				}
			}
		}
		cc=n-i;
		if(cc!=0){
			for(int j=1;j<=m2;j++){
				if(cc==0)
					baaa2[j]=false;
				if(cc>0){
					cc--;
					ji++;
				}
				if(dier[j].shu3>dier[k2].shu4&&baaa2[k2]==true){
					k2++;
					cc++;
				}
			}	
		}
		if(ji>da1) da1=ji;
	}
	printf("%lld",da1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
