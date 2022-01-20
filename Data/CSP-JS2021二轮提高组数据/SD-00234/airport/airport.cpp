#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<stack>
#include<queue>
#include<map>
#include<utility>
using namespace std;
int n,m1,m2,daisy1[100010],daisy2[100010],rose1[100010],rose2[100010];
int StarDream1[100010],StarDream2[100010];//答案 
int qz1[100010],qz2[100010];
int v;
bool pd1[100010],pd2[100010];
int xz1,xz2,sum1=0,sum2=0;
struct Daisy{
	int came1,went1;
}daisy[100010];
struct Rose{
	int came2,went2;
}rose[100010];
bool cmp1(Daisy a,Daisy b){
	return a.came1<b.came1;
}
bool cmp2(Rose a,Rose b){
	return a.came2<b.came2;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&daisy[i].came1,&daisy[i].went1);
		pd1[i]=true;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&rose[i].came2,&rose[i].went2);
		pd2[i]=true;
	}
	sort(daisy+1,daisy+m1+1,cmp1);
	sort(rose+1,rose+m2+1,cmp2);
	//对于每架飞机只需要维护可以和它共用一个廊桥的飞机数
	for(int i=1;i<=m1;i++){
		xz1=daisy[i].went1;
		for(int j=i+1;j<=m1;j++){
			if(xz1<daisy[j].came1&&pd1[j]){
				StarDream1[i]++;
				xz1=daisy[j].went1;
				pd1[j]=false;
			}
		}
		if(pd1[i])StarDream1[i]++,sum1++;//还有它自己 
	}
	for(int i=1;i<=m2;i++){
		xz2=rose[i].went2;
		for(int j=i+1;j<=m2;j++){
			 if(xz2<rose[j].came2&&pd2[j]){
			 	StarDream2[i]++;
			 	xz2=rose[j].went2;
			 	pd2[j]=false;
			 }
		}
		if(pd2[i])StarDream2[i]++,sum2++;
	}
	for(int i=1;i<=sum1;i++)qz1[i]=StarDream1[i]+qz1[i-1];
	for(int i=1;i<=sum2;i++)qz2[i]=StarDream2[i]+qz2[i-1];
	for(int i=min(n,sum1);i>=0;i--){
		v=max(v,qz1[i]+qz2[n-i]);
	}
	printf("%d",v);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
