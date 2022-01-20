#include<bits/stdc++.h>
using namespace std;
int a[5000],b[5000];
struct shike{
	int bn;
	int ed;
};
bool f(shike a,shike b){
	return a.bn<b.bn;
}
shike aira[100005],airb[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,ma,mb,ib;
	scanf("%d %d %d",&n,&ma,&mb);
	for(int i=1;i<=ma;i++) scanf("%d %d",&aira[i].bn,&aira[i].ed);
	for(int i=1;i<=mb;i++) scanf("%d %d",&airb[i].bn,&airb[i].ed);
	sort(aira+1,aira+1+ma,f);
	sort(airb+1,airb+1+mb,f);
	int sum=0;
	for(int ia=0;ia<=n;ia++){
		ib=n-ia;
		int bj=0,pj=0,tj=0;
		for(int i=0;i<=5000;i++){
			a[i]=0;
			b[i]=0;
		}
		for(int j=1;j<=ma;j++){
			for(int r=1;a[r];r++){
				if(aira[j].bn>a[r]){
					tj++;
					a[r]=aira[j].ed;
					bj++;
				}
			}
			if(!bj){
				if(pj<ia){
					pj++;
					tj++;
					a[pj]=aira[j].ed;
				}
			}
		}
		bj=0,pj=0;
		for(int j=1;j<=mb;j++){
			for(int r=1;b[r];r++){
				if(airb[j].bn>b[r]){
					tj++;
					b[r]=airb[j].ed;
					bj++;
				}
			}
			if(!bj){
				if(pj<ib){
					pj++;
					tj++;
					b[pj]=airb[j].ed;
				}
			}
		}
		sum=max(tj,sum);
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
