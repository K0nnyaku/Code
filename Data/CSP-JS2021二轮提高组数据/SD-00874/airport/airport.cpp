#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
int mgn,mgw,n,maxn=-1000,bridge[100001],siz;
struct QUE{
	int a,l;
};
QUE gn[100001],gw[100001];
int cmp(QUE a,QUE b){
	return a.a<b.a||(a.a==b.a&&a.l<b.l);
}
int cmpp(int a,int b){
	return a<b;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&mgn,&mgw);
	for(int i=1;i<=mgn;i++){
		scanf("%d%d",&gn[i].a,&gn[i].l);
	}
	for(int i=1;i<=mgw;i++){
		scanf("%d%d",&gw[i].a,&gw[i].l);
	}
	sort(gn+1,gn+mgn+1,cmp);
	sort(gw+1,gw+mgw+1,cmp);
	for(int i=0;i<=n;i++){//i为国内航班所用的廊桥数 
		int j=n-i,cnt=0;
		memset(bridge,0x3f,sizeof(bridge));
		for(int k=1;k<=i;k++){
			bridge[k]=gn[k].l;
		}
		sort(bridge+1,bridge+n+1,cmpp);
		cnt+=i;
		for(int k=i+1;k<=mgn;k++){
			if(gn[k].a>bridge[1]){
				cnt++;bridge[1]=gn[k].l;
				sort(bridge+1,bridge+n+1,cmpp);
			}
		}
		for(int k=1;k<=j;k++){
			bridge[k]=gw[k].l;
		}
		sort(bridge+1,bridge+j+1,cmpp);
		cnt+=j;
		for(int k=j+1;k<=mgw;k++){
			if(gw[k].a>bridge[1]){
				cnt++;bridge[1]=gw[k].l;
				sort(bridge+1,bridge+j+1,cmpp);
			}
		}
		maxn=max(maxn,cnt);
	//	cout<<maxn<<endl;
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

