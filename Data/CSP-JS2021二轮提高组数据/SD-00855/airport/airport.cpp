#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int air1[200005],air2[200005],sum1,sum2;
int n,m1,m2,tt,maxn=0;//n为总廊桥数，m1是国内，m2是国外,tt是总时间 ,maxn是最大时间 
int a1,a2;//国内航班数，国外航班数 
int t1i[200005],t1o[200005],t2i[200005],t2o[200005],flag;//t1i是国内飞机进入时间，t1o是国内飞机出站时间 flag是有没有进入飞机 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&t1i[i],&t1o[i]);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&t2i[i],&t2o[i]);
	}
	for(a1=0;a1<=n;a1++){
		a2=n-a1;
		for(int k=1;k<=m1;k++){//k是判断飞机的 
			for(int j=1;j<=a1;j++){
				if(t1i[k]>air1[j]) {
					air1[j]=t1o[k];
					sum1++;
					break;
				}
			}
		} 
		for(int k=1;k<=m2;k++){//k是判断飞机的 
			for(int j=1;j<=a2;j++){
				if(t2i[k]>air2[j]){
					air2[j]=t2o[k];
					sum2++;
					break;
				}
			}
		} 	
		maxn=max(maxn,sum1+sum2);
		sum1=0;
		sum2=0;
		for(int k=1;k<=a1;k++){
			air1[k]=0;
		}
		for(int k=1;k<=a2;k++){
			air2[k]=0;
		}
	}
	cout<<maxn;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

